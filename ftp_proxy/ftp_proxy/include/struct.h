#ifndef __STRUCT_
#define __STRUCT_

#define BUF_SIZE  1024
#define NUM       10

//��ʱpacket_buf
struct packet_buf {
	char*              packet_buf;                    // buf
	int                memory_size;                   // ���ٿռ��С
	int                buf_length;                    // buf����
	int                is_complete;                   // �Ƿ�����
	int                is_signal;                     // �Ƿ��ǵ�������
};

struct {
	int                keep_on;                       // while��־ 
	char               local_ip[16];                  // ����ip
	char               server_ip[16];                 // �����ip
	int                user_flag;                     // ���յ�user��־
	struct packet_buf* packet_buf;                    // FTP��ʱ������ṹ��
}global_state;

//FTP�����
struct command_packet {
	char               command[4];                    // ��������
	char               space;                         // �ո�
	char*              arguements;                    // ��������
	char               split[2];                      // �ָ�

	int                memory_size;                   // �����ڴ��С
	int                arguement_length;              // �������ݳ���
};

//FTP��Ӧ����
struct response_packet {
	char               code[3];                       // ��Ӧ��
	char               space;                         // �ո�
	char*              message;                       // ��Ӧ��Ϣ
	char               split[2];                      // �ָ�

	int                memory_size;                   // �����ڴ��С
	int                message_length;                // ��Ӧ��Ϣ����
};

//�շ����ݽṹ��
struct socket_data {
	char               trans_buf[BUF_SIZE * 6 + 1];   // �շ�buf
	int                trans_length;                  // �շ�����
	int                index_begin;                   // ��ʼ����
	int                index_end;                     // ��������
};

//����˽ṹ��
struct server {
	int                 proxy_socket;                 // ���ӿͻ���socket
	struct socket_data* socket_data;                  // �շ�buf�ṹ��
	struct command_packet* packet;                    // ����� 
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
};

//����״̬�ṹ��
struct link_status {
	int                 first_login;                  // ��һ�ε�¼
	int                 get_flag;                     // �ϴ���־λ
	int                 put_flag;                     // �ϴ���־λ
};

//���ӽṹ��
struct link {
	struct server* server;                            // �������Ϣ                 
	struct client* client;                            // �ͻ�����Ϣ

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
