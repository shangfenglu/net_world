#ifndef __CONNECT_
#define __CONNECT_
struct link;

//��ʼ��socket����
static int init_socket(int socket);

//��ʼ������socket
int init_socket_listen(int port, int init_type);

//�ȴ�����socket
int accept_socket(int socket);

//���ӵ������
int connect_to_server(struct link* link);

#endif //__CONNECT_