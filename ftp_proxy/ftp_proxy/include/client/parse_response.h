#ifndef __PARSE_COMMAND_
#define __PARSE_COMMAND_

#define APPEND_SIZE  200

struct socket_data;
struct response_packet;
struct packet_buf;

//FTP������Ϣ
struct command_info {
	char               command[5];                    // ��������
	int                space;                         // �Ƿ���ڿո�
	int                length;                        // �����
};

//��������
int parse_resonse(struct socket_data* data,struct response_packet* packet);

//��ȡ����buf
static int extract_response_packet(struct socket_data* socket_data, struct packet_buf* packet_buf);

//��buf���������Ľṹ��
static int unpack_buf_to_response(struct packet_buf* packet_buf, struct response_packet* packet);

#endif //__PARSE_COMMAND_