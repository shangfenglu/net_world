#ifndef __PROCESS_COMMAND_
#define __PROCESS_COMMAND_

struct session;
struct socket_data;
struct command_packet;
struct session_info;
struct link;

//����ö��
enum command_type {
	CERROR = 0,
	PASV,                                      // ����ģʽ
	PORT,                                      // ����ģʽ
	USER,                                      // ָ���û�
	MODE,                                      // ���ô������ݵ�ģʽ��
	PASS,                                      // ָ����¼���롣
	RETR,                                      // �ӷ��������أ��������ļ���
	STOR,                                      // ���ļ��ϴ����洢����������
	STOU,                                      // ���ļ��ϴ����洢�������ڷ�����������Ψһ���ļ���
	AUTH                                       // �����֤�Ͱ�ȫ����
};

//����FTP����
int process_command(struct command_packet* packet,struct socket_data* socket_data);

//������ṹ������buf
static int pack_command_to_buf(struct socket_data* socket_data, struct command_packet* packet);

//�õ�FTP��������
static enum command_type get_command_type(struct command_packet* packet);

//����USER����
static int process_user_command(struct link* link, struct session_info* info);

//����PORT����
static int process_port_command(struct link* cmd_link, struct link* data_link);


#endif // !__PROCESS_COMMAND_
