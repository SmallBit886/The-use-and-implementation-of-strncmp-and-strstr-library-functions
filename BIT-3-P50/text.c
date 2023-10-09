#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
//1.7 strncmp��ʹ�� --- int strncmp ( const char * str1, const char * str2, size_t num );

//int main()
//{
//	const char* p1 = "abcdaa";
//	const char* p2 = "abcdef";
//	int ret = strncmp(p1, p2, 4);//0
//	int ret1 = strncmp(p1, p2, 5);//-1
//	printf("%d\n", ret);
//	printf("%d\n", ret1);
//
//	return 0;
//}

//�����ַ���
// NULL -- ��ָ��
// Null��NUL -- '\0'
//1.8 strstr��ʹ�� --- char * strstr ( const char *str1, const char * str2);
//int main()
//{
//	char* p1 = "abcdefhig";
//	char* p2 = "def";
//	//��def���еĻ�����d��λ�ã�û�еĻ�����NULL
//	char* ret = strstr(p1, p2);
//	if (ret==NULL)
//	{
//		printf("�Ӵ�������\n");
//	}
//	else
//	{
//		printf("%s\n", ret);//defhig
//	}
//	return 0;
//}

//�Լ�ʵ��************************************************�Ƚ���
//KMP�㷨	
char* Mystrstr(const char* p1, const char* p2)
{
	assert(p1 && p2);
	char* s1 = (char*) p1;
	char* s2 = (char*) p2;
	char* cur = (char*) p1;
	if (*p2 == '\0')
	{
		return (char*)p1;
	}
	//
	while (*cur)
	{
		s1 = cur;
		s2 =(char*) p2;

		while (*s1 && *s2 && (*s1 == *s2))
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return cur;//�ҵ��Ӵ�
		}
		if (*s1 == '\0')
		{
			return NULL;//�Ҳ����Ӵ�	��ǰ�˳�
		}
		cur++;
	}
	return NULL;//�Ҳ����Ӵ�
}
int main()
{
	char* p1 = "abcdddefhig";
	char* p2 = "def";
	//��def���еĻ�����d��λ�ã�û�еĻ�����NULL
	char* ret = Mystrstr(p1, p2);
	if (ret == NULL)
	{
		printf("�Ӵ�������\n");
	}
	else
	{
		printf("%s\n", ret);//defhig
	}
	return 0;
}
