#ifndef __FTP_SERVICE_
#define __FTP_SERVICE_

#include "session.h"

#define FTP_WELOCME_STRING "220 Welcome to blah FTP service.\r\n"
#define FILE_PATH "user_info.txt"

//��ʼ��ȫ�ֱ���
int init_global_state(char* argv[]);

//����ftp_service����
int start_proxy_service();

//�û��Ự
static int start_user_session(const int proxy_socket);

//���ݴ���
static int data_trans(struct session* session, int socket);

//���ƴ���
static int cmd_trans(struct session* session, int socket);

//�����û�
static int clear_user();

//�û���¼����
static int user_login(struct session* session);

//����ͻ��˵�¼����
static int process_client_login(struct session* session);

//�������˵�¼����
static int process_server_login(struct session* session);



#endif //__FTP_SERVICE_