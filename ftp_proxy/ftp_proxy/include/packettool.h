#ifndef __PACKETTOOL_
#define __PACKETTOOL_

#include "struct.h"

#define APPEND_SIZE  200
#define COMMAND_NUM  33

//FTP������Ϣ
struct command_info {
	char               command[5];                    // ��������
	int                space;                         // �Ƿ���ڿո�
	int                length;                        // �����
};

//����buf
int copy_buf(struct socket_data* socket_data, struct packet_buf* packet_buf);

//׷��buf
int append_buf(struct socket_data* socket_data, struct packet_buf* packet_buf);

//��buf����������ṹ��
int unpack_buf_to_command(struct packet_buf* packet_buf, struct command_packet* packet);

//��buf���������Ľṹ��
int unpack_buf_to_response(struct packet_buf* packet_buf, struct response_packet* packet);

//������ṹ������buf
int pack_command_to_buf(struct socket_data* socket_data, struct command_packet* packet);

//�����Ľṹ������buf
int pack_response_to_buf(struct socket_data* socket_data, struct response_packet* packet);

//����USER����
int process_user_command(struct link* link,struct session_info* info);

//����PORT����
int process_port_command(struct link* cmd_link, struct link* data_link);

//����227����
int process_227_response(struct link* cmd_link, struct link* data_link);

#endif   //__PACKETTOOL_