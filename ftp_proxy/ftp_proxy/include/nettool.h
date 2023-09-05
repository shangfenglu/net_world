#ifndef __NET_TOOLS_
#define __NET_TOOLS_

#include "struct.h"
#include <string.h>


//��ʼ��socket����
int init_socket(int socket);

//��ʼ������socket
int init_socket_listen(int port, int init_type);

//�ȴ�����socket
int accept_socket(int socket);

//���ӵ������
int connect_to_server(struct link* link);

//��������
int nSend(int fd, char* buf, int buf_size, int* sendLength);

//��������
int nRecv(int fd, char* buf, int buf_size, int* recvLength);

#endif //__NET_TOOLS_
