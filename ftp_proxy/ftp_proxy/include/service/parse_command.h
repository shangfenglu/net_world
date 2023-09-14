#ifndef __PARSE_COMMAND_
#define __PARSE_COMMAND_

#define COMMAND_NUM  33
struct socket_data;
struct command_packet;
struct packet_buf;

//FTP������Ϣ
struct command_info {
	char               command[5];                    // ��������
	int                space;                         // �Ƿ���ڿո�
	int                length;                        // �����
};

//��������
int parse_command(struct socket_data* socket_data,struct command_packet* packet);

//��ȡ�����
static int extract_command_packet(struct socket_data* socket_data, struct packet_buf* packet_buf);

//��buf����������ṹ��
static int unpack_buf_to_command(struct packet_buf* packet_buf, struct command_packet* packet);


#endif // !__PARSE_COMMAND_
