#ifndef  __UTILS_
#define __UTILS_

#include "struct.h"

#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <poll.h>

#define MEMORY_SIZE 200

//��ñ���ip��ַ
int get_local_ip(char* local_ip);

//��ʼ���û��ṹ��
struct session* init_session();

//��ʼ�����ӽṹ��
int init_link(struct link* link);

//��ʼ��packet_buf�ṹ��
struct packet_buf* init_packet_buf();

//��ʼ��poll����
int init_pollfds(struct pollfd* fds, int num);

//��poll���������socket
int add_pollfds(struct pollfd* fds, int num, const int socket);

//��poll������ɾ��socket
int del_pollfds(struct pollfd* fds, int num, const int socket);

//׷��memory�ռ�
void* append_memory(void* addr, unsigned int size, unsigned int append_length);

//�Ƚ��ַ���
int compare_string(const char* dst, const char* src, int length);

//����Ƿ�����
int is_complete(char* src);

//���ַ�������Ϊ��д
int string_upper(char* str, int length);

#endif  //__UTILS_