#ifndef __SIGNAL_
#define __SIGNAL_

//��ʼ���ź�
int init_signal();

//SIGINT�źŴ���
void sigint_handle(int n);

//SIGQUIT�źŴ���
void sigquit_handle(int n);



#endif