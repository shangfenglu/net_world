#include "../include/ftp_proxy.h"
#include "../include/signal.h"

int main(int argc,char* argv[])
{
	if (argc != 2) {
		printf("please enter the server_ip\n");
		return;
	}

	printf("version is 6.8\n");
	
	/*��ʼ��ȫ�ֱ���*/
	init_global_state(argv);

	/*�źŴ���*/
	init_signal();

	/*�����������*/
	start_proxy_service();

	return 0;
}