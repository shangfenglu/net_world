#include "connect.h"
#include "session.h"

#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <unistd.h>
#include <string.h>

int init_socket(int socket)
{
    int res = -1;
    //���÷�����
    int flags = fcntl(socket, F_GETFL, 0);
    flags = flags | O_NONBLOCK;
    fcntl(socket, F_SETFL, flags);

    //���ÿɸ���
    int reuse = 1;
    res = setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    //���ñ������
    int keepalive = 1;
    res = setsockopt(socket, SOL_SOCKET, SO_KEEPALIVE, &keepalive, sizeof(keepalive));

    //��������
    int keepalive_idle = 60;    // ����ʱ��Ϊ60��
    int keepalive_interval = 5; // ���ʱ��Ϊ5��
    int keepalive_count = 3;    // ̽�����Ϊ3��

    res = setsockopt(socket, IPPROTO_TCP, TCP_KEEPIDLE, &keepalive_idle, sizeof(keepalive_idle));
    res = setsockopt(socket, IPPROTO_TCP, TCP_KEEPINTVL, &keepalive_interval, sizeof(keepalive_interval));
    res = setsockopt(socket, IPPROTO_TCP, TCP_KEEPCNT, &keepalive_count, sizeof(keepalive_count));

    //���ó�ʱʱ��
    struct timeval timeout;
    timeout.tv_sec = 5;  // ���ó�ʱʱ��Ϊ 5 ��
    timeout.tv_usec = 0;
    res = setsockopt(socket, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

    int recvbuf_size = 1024 * 18;
    int sendbuf_size = 1024 * 18;
    res = setsockopt(socket, SOL_SOCKET, SO_RCVBUF, &recvbuf_size, sizeof(recvbuf_size));
    res = setsockopt(socket, SOL_SOCKET, SO_SNDBUF, &sendbuf_size, sizeof(sendbuf_size));
    return res;
}

int init_socket_listen(int port, int init_type)
{
    int res = 0;
    int length = 0;
    int socket_ret = 0;

    socket_ret = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == socket_ret) {
        printf("%s:%d %s\n", __FUNCTION__, __LINE__, strerror(errno));
        return -1;
    }

    //��������
    if (1 == init_type) {
        init_socket(socket_ret);
    }

    //��Э���ַ��
    struct sockaddr_in  addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);
    length = sizeof(addr);

    //��ʼ��
    res = bind(socket_ret, (struct sockaddr*)&addr, length);
    if (-1 == res) {
        printf("%s:%d %s\n", __FUNCTION__, __LINE__, strerror(errno));
        close(socket_ret);
        return -1;
    }

    res = listen(socket_ret, 10);
    if (-1 == res) {
        printf("%s:%d %s\n", __FUNCTION__, __LINE__, strerror(errno));
        close(socket_ret);
        return -1;
    }

    return socket_ret;
}

int accept_socket(int socket)
{
    int client_socket;
    do {
        client_socket = accept(socket, NULL, NULL);

        if (client_socket > 0) {
            break;
        }
        else {

            if (errno == EINTR) {
                continue;
            }
            else if (errno == EAGAIN) {
                break;
            }
            else {
                printf("%s:%d %s\n", __FUNCTION__, __LINE__, strerror(errno));
                close(socket);
                return -1;
            }
        }

    } while (1);

    //��ʼ��socket
    init_socket(client_socket);

    return client_socket;
}

int connect_to_server(struct link* link)
{
    int res = 0;
    struct sockaddr_in addr;
    socklen_t length = 0;

    link->client->connect_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == link->client->connect_socket) {
        printf("%s:%d %s\n", __FUNCTION__, __LINE__, strerror(errno));
        return -1;
    }

    //��Э���ַ��
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(link->client->server_ip);
    addr.sin_port = htons(link->client->server_port);
    length = sizeof(addr);

    //��ʼ����
    res = connect(link->client->connect_socket, (struct sockaddr*)&addr, length);
    if (-1 == res) {
        printf("%s:%d %s\n", __FUNCTION__, __LINE__, strerror(errno));
        close(link->client->connect_socket);
        return -1;
    }

    //��ʼ��socket
    init_socket(link->client->connect_socket);

    return 0;
}