#ifndef __TRANSPORT_
#define __TRANSPORT_
#define BUF_SIZE 1024
struct socket_data;

//ftp�������ݽӿ�
int ftp_recv_data(struct socket_data* socket_data, int recv_socket);

//ftp�������ݽӿ�
int ftp_send_data(struct socket_data* socket_data, int send_socket);


//��������
int safe_send(int fd, char* buf, int buf_size, int* send_length);

//��������
int safe_recv(int fd, char* buf, int buf_size, int* recv_length);

#endif  //__TRANSPORT_
