#ifndef __SIGNAL_
#define __SIGNAL_

#include <signal.h>
#define CLEAR_USER 35

//��ʼ���ź�
int init_signal();

//SIGINT�źŴ���
void sigint_handle(int n);

//SIGQUIT�źŴ���
void sigquit_handle(int n);

//�ӽ��������ź�
void sigclear_handle(int n);

#endif