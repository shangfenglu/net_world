#ifndef  __UTILS_
#define __UTILS_
#include <sys/types.h>

#define MEMORY_SIZE 200
struct link;
struct pollfd;
struct socket_data;
struct packet_buf;
//��ñ���ip��ַ
int get_local_ip(char* local_ip);

//��ʼ���û��ṹ��
struct session* init_session();

//��ʼ�����ӽṹ��
int init_link(struct link* link);

//��ʼ��packet_buf�ṹ��
struct packet_buf* init_packet_buf();

//����session�ṹ��
int destory_session(struct session* session);

//��ʼ��poll����
int init_pollfds(struct pollfd* fds, int num);

//��poll���������socket
int add_pollfds(struct pollfd* fds, int num, const int socket);

//��poll������ɾ��socket
int del_pollfds(struct pollfd* fds, int num, const int socket);

//���ӽ������������pid
int add_child_pid(pid_t* child_fds, int num, const pid_t child);

//���ӽ���������ɾ��pid
int del_child_pid(pid_t* child_fds, int num, const pid_t child);

//�Ƚ��ַ���
int compare_string(const char* dst, const char* src, int length);

//���index���ַ�
char get_char(const char* text, int index);

//����packet_buf
int copy_packet_buf(struct socket_data* socket_data, struct packet_buf* packet_buf);

//׷��packet_buf
int append_packet_buf(struct socket_data* socket_data, struct packet_buf* packet_buf);

#endif //__UTILS_
