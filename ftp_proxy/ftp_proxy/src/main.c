#include "ftp_proxy.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
	if (2 != argc) {
		printf("please enter the server_ip\n");
		return -1;
	}
	printf("version is 9.9\n");

	/*��ʼ��ȫ�ֱ���*/
	init_global_state(argv);

	/*�źŴ���*/
	init_signal();

	/*�����������*/
	start_proxy_service();

	return 0;
}