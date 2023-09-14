#ifndef __STRUCT_
#define __STRUCT_
#include"str.h"
#include <sys/types.h>
#define BUF_SIZE  1024
#define NUM       10

//��ʱpacket_buf
struct packet_buf {
	struct mystr*      string;                        // �ַ���
	int                is_complete;                   // �Ƿ�����
	int                is_signal;                     // �Ƿ��ǵ�������
};

struct {
	int                child_keep_on;                 // �ӽ���while��־
	int                keep_on;                       // while��־ 
	int                user_flag;                     // ���յ�user��־
	int                server_socket;                 // �������socket
	pid_t              father_pid;                    // ������pid
	pid_t              child_pids[BUF_SIZE];          // �ӽ���pids

	char               local_ip[16];                  // ����ip
	char               server_ip[16];                 // �����ip
	struct packet_buf* packet_buf;                    // FTP��ʱ������ṹ��

}global_state;

//FTP�����
struct command_packet {
	char               command[4];                    // ��������
	char               space;                         // �ո�
	struct mystr*      arguements;                    // ��������

	void*              father;                        // ���ṹ��
};

//FTP��Ӧ����
struct response_packet {
	char               code[3];                       // ��Ӧ��
	char               space;                         // �ո�
	struct mystr*      message;                       // ��Ӧ��Ϣ

	void*              father;                        // ���ṹ��
};

//�շ����ݽṹ��
struct socket_data {
	char               trans_buf[BUF_SIZE * 8 + 1];   // �շ�buf
	unsigned int       trans_length;                  // �շ�����
	unsigned int       index_begin;                   // ��ʼ����
	unsigned int       index_end;                     // ��������
};

//����˽ṹ��
struct server {
	int                 proxy_socket;                 // ���ӿͻ���socket
	struct socket_data* socket_data;                  // �շ�buf�ṹ��
	struct command_packet* packet;                    // ����� 
	void*               father;                       // ���ṹ��

};

//�ͻ��˽ṹ��
struct client {
	int                 connect_socket;               // ���ӷ����socket
	int                 accept_socket;                // �ȴ�����socket
	char                server_ip[16];                // �����ip
	unsigned int        server_port;                  // ����˶˿�
	unsigned int        listen_port;                  // ���ڼ����Ķ˿�

	struct socket_data* socket_data;                  // �շ�buf�ṹ��
	struct response_packet* packet;                   // ��Ӧ�ṹ��
	void*               father;                       // ���ṹ��

};

//���ӽṹ��
struct link {
	struct server* server;                            // �������Ϣ                 
	struct client* client;                            // �ͻ�����Ϣ
	void*          father;                            // ���ṹ��
};

//�û���Ϣ�ṹ��
struct session_info {
	char                user_name[40];                // �û���
	long int            get_bytes;                    // �����ֽ���
	int                 get_file_nums;                // �����ļ�����

	long int            put_bytes;                    // �ϴ��ֽ���
	int                 put_file_nums;                // �ϴ��ļ�����
};

//�Ự״̬��Ϣ�ṹ��
struct session_status {
	int                 first_login;                   // ��һ�ε�¼
	int                 get_flag;                      // ���ر�־
	int                 put_flag;                      // �ϴ���־
};

//�Ự�ṹ��
struct session {
	struct link* cmd_link;                            // ��������
	struct link* data_link;                           // ��������
	struct session_info* session_info;                // �û���Ϣ�ṹ��
	struct session_status* session_status;            // �Ự״̬�ṹ��
};

#endif
