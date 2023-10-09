#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
//1.7 strncmp的使用 --- int strncmp ( const char * str1, const char * str2, size_t num );

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

//查找字符串
// NULL -- 空指针
// Null和NUL -- '\0'
//1.8 strstr的使用 --- char * strstr ( const char *str1, const char * str2);
//int main()
//{
//	char* p1 = "abcdefhig";
//	char* p2 = "def";
//	//找def，有的话返回d的位置；没有的话返回NULL
//	char* ret = strstr(p1, p2);
//	if (ret==NULL)
//	{
//		printf("子串不存在\n");
//	}
//	else
//	{
//		printf("%s\n", ret);//defhig
//	}
//	return 0;
//}

//自己实现************************************************比较绕
//KMP算法	
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
			return cur;//找到子串
		}
		if (*s1 == '\0')
		{
			return NULL;//找不到子串	提前退出
		}
		cur++;
	}
	return NULL;//找不到子串
}
int main()
{
	char* p1 = "abcdddefhig";
	char* p2 = "def";
	//找def，有的话返回d的位置；没有的话返回NULL
	char* ret = Mystrstr(p1, p2);
	if (ret == NULL)
	{
		printf("子串不存在\n");
	}
	else
	{
		printf("%s\n", ret);//defhig
	}
	return 0;
}
