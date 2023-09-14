#ifndef __STR_
#define __STR_

struct mystr {
	char* data;                   // �ַ�������
	unsigned int alloc_length;          // ������ֽڿռ��С
	unsigned int data_length;            // �ַ�������
};

//�����ַ����ռ�
int str_alloc(struct mystr* str, int alloc_length);

//�ͷ��ַ����ռ�
int str_free(struct mystr* str);

//׷���ַ����ռ�
int str_append_alloc(struct mystr* str, int cat_length);

//�ж��Ƿ�Ϊ��
int str_isempty(const struct mystr* str);

//�õ�����
int str_getlen(const struct mystr* str);

//�õ�����
const char* str_getbuf(const struct mystr* str);

//�±���ַ�
char str_at(const struct mystr* str, const unsigned int index);

//תΪ��д
int str_upper(struct mystr* str);

//תΪСд
int str_lower(struct mystr* str);

//תһ�����ȴ�д
int str_upper_length(struct mystr* str, const unsigned int length);

//תһ������Сд
int str_lower_length(struct mystr* str, const unsigned int length);

//�����ַ���
int str_copy_str(struct mystr* str_dest, const struct mystr* str_src);
int str_copy_text(struct mystr* str_dest, const char* text, unsigned int length);

//�Ƚ��ַ�string
int str_equal_str(const struct mystr* str1, const struct mystr* str2);
int str_equal_text(const struct mystr* str, const char* text);

//׷��
int str_append_str(struct mystr* str_dst, const struct mystr* str_src);
int str_append_text(struct mystr* str_dst, const char* text_src, unsigned int length);

//�ָ�


#endif  //__STR_
