#ifndef __ENUM_
#define __ENUM_

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

//����ö��
enum response_type {

	RERROR = 0,
	INCOMPLETE,                                // ��ǰ���Ļ��к�������
	FTP_227_RESPONSE,                          // ����ģʽ����Ӧ��
	FTP_220_RESPONSE,                          // 220��Ӧ��
	FTP_530_RESPONSE                           // ���͵�¼��Ӧ��
};

#endif