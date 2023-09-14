#ifndef __PROCESS_RESPONSE_
#define __PROCESS_RESPONSE_
struct session;
struct socket_data;
struct response_packet;
struct link;

//����ö��
enum response_type {

	RERROR = 0,
	INCOMPLETE,                                // ��ǰ���Ļ��к�������
	FTP_227_RESPONSE,                          // ����ģʽ����Ӧ��
	FTP_220_RESPONSE,                          // 220��Ӧ��
	FTP_530_RESPONSE                           // ���͵�¼��Ӧ��
};


//����FTP����
int process_response(struct response_packet* packet,struct socket_data* socket_data);

//�����Ľṹ������buf
static int pack_response_to_buf(struct socket_data* socket_data, struct response_packet* packet);

//�õ�FTP��������
static enum response_type get_response_type(struct response_packet* packet);

//����227����
static int process_227_response(struct link* cmd_link, struct link* data_link);

#endif // !__PROCESS_RESPONSE_