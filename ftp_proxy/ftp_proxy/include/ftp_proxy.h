#ifndef __FTP_SERVICE_
#define __FTP_SERVICE_

#include "enum.h"
#include "struct.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <sys/time.h>
#include <netinet/tcp.h>

#define FTP_WELOCME_STRING "220 Welcome to blah FTP service.\r\n"
#define FILE_PATH "user_info.txt"

//��ʼ��ȫ�ֱ���
int init_global_state(char* argv[]);

//����ftp_service����
int start_proxy_service();

//�û��Ự
int start_user_session(struct session* session);

//�û���¼����
int user_login(struct session* session);

//����ͻ��˵�¼����
int process_client_login(struct session* session);

//�������˵�¼����
int process_server_login(struct session* session);

//���ƴ���
int cmd_trans(struct session* session, int socket);

//���ݴ���
int data_trans(struct session* session, int socket);

//��ȡ����
int extract_packet_buf(struct socket_data* socket_data, struct packet_buf* packet_buf);

//����FTP����
int process_command(struct session* session);

//����FTP����
int process_response(struct session* session);

//�õ�FTP��������
enum command_type get_command_type(struct command_packet* packet);

//�õ�FTP��������
enum response_type get_response_type(struct response_packet* packet);


#endif  //__FTP_SERVICE_