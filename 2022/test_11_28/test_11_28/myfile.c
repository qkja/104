#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<errno.h>

#include<stdio.h>

int main()
{

	FILE* pf = fopen("test.txt", "w");
	char* buffer = "我是一个学习者";

	for (int i = 0; i < 5; i++)
	{
		fwrite(buffer, strlen(buffer), sizeof(char), pf);
	}
	fclose(pf);  //关闭文件
	pf = NULL;
	return 0;
}


//int main()
//{
//
//	FILE* pf = fopen("test.txt", "w");
//	char buffer[10] = { 'a', 'b', 'c', 'd', 'e', 'f', '\n' };
//
//	for (int i = 0; i < 5; i++)
//	{
//		fputs(buffer, pf);
//	}
//	fclose(pf);  //关闭文件
//	pf = NULL;
//	return 0;
//}












//int main()
//{
//
//	FILE* pf = fopen("test.txt", "r");
//	char buffer[4] = { 0 };
//	while (fgets(buffer, sizeof(buffer), pf) != NULL)
//	{
//		printf("%s", buffer);
//		memset(buffer, '\0', sizeof(buffer));
//	}
//	fclose(pf);  //关闭文件
//	pf = NULL;
//	return 0;
//}









//int main()
//{
//
//	FILE* pf = fopen("test.txt", "a");
//
//	//写文件
//	for (int ch = 'a'; ch <= 'z'; ch++)
//	{
//		fputc(ch, pf);
//	}
//	fclose(pf);  //关闭文件
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("test.txt", "w");
//	// 这里就不判断了
//	fclose(pf);
//	pf = NULL; // 好习惯
//	return 0;
//}











//int main()
//{
//	打开一个名为test.txt的文件
//	FILE* pf = fopen("E:\\104\\test.txt", "w");
//	if (pf == NULL)
//	{
//		printf("打开文件失败\n");
//		return 0;
//	}
//	 写文件
//	return 0;
//}


















//struct Person
//{
//	char name[15];
//	int age;
//	char sex[10];
//};
//
//
//int main()
//{
//	struct Person per = { "张三", 18, "男" };
//	char buffer[100];
//	sprintf(buffer, "%s %d %s\n", per.name, per.age, per.sex);
//	struct Person s = { "张三", 18, "男" };
//
//	sscanf(buffer, "%s %d %s\n", &s.name, &s.age, &s.sex);
//
//	printf("%s\n", buffer);
//
//	return 0;
//}





//int main()
//{
//	struct Person per = { "张三", 18, "男" };
//	char buffer[100];
//	sprintf(buffer, "%s %d %s\n", per.name, per.age, per.sex);
//
//
//	printf("%s\n", buffer);
//	return 0;
//}

//int main()
//{
//	FILE* pf = fopen("test.txt", "r");
//	char ch[100] = { 0 };
//
//	fscanf(pf, "%s", ch);
//	printf("%s", ch);
//	return 0;
//}

//struct Person
//{
//	char name[15];
//	int age;
//	char sex[10];
//};
//
//int main()
//{
//
//	FILE* pf = fopen("test.txt", "r"); 
//
//
//	struct Person per ;
//
//	fscanf(pf, "%s %d %s\n", &per.name, &per.age, &per.sex);
//
//	printf("%s %d %s\n", per.name, per.age, per.sex);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//
//	FILE* pf = fopen("test.txt", "wb"); // 按照二进制写问文件
//
//
//	struct Person per = { "张三", 18, "男" };
//
//	fprintf(pf,"%s %d %s\n", per.name, per.age, per.sex);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	// 写文件
//	int arr[5] = { 1, 2, 3, 4, 5 };
//	FILE* pf = fopen("test.txt", "wb");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	fwrite(arr, sizeof(int), 5, pf);
//	fclose(pf);
//	pf = NULL;
//
//	// 读文件
//	int a[5] = { 0 };
//	int count = 5;
//	int num = 0;
//	int i = 0;
//	//打开文件
//    pf = fopen("test.txt", "rb");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	num = fread(a, sizeof(int), 5, pf);
//	if (num == count)                  //读取五个元素后正好到达文件结尾
//	{
//		for (i = 0; i < count; i++)
//		{
//			printf("%d ", a[i]);
//		}
//		puts("\nArray read successfully contents");
//	}
//	else
//	{
//		if (feof(pf))                             
//		{
//			printf("Error reading test.txt:unexpected end of file\n");
//		}
//		else if (ferror(pf))                  
//		{
//			perror("Error reading test.txt");
//		}
//	}
//	fclose(pf);
//	pf = NULL;
//
//	return 0;
//}




//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "wb"); // 按照二进制写问文件
//	fwrite(&a, 4, 1, pf);
//
//	fclose(pf);
//	return 0;
//}


//struct Person
//{
//	char name[15];
//	int age;
//	char sex[10];
//};
//
//int main()
//{
//	int ch = 0;
//	FILE* pf = fopen("test.txt", "rb"); // 按照二进制写问文件
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//
//	struct Person p = { "张三", 18, "男" };
//	struct Person per;
//	fread(&per, sizeof(struct Person), 1, pf);
//
//	printf("%s %d %s\n", per.name, per.age, per.sex);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//int main()
//{
//	int ch = 0;
//	FILE* pf = fopen("test.txt", "wb"); // 按照二进制写问文件
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	
//	struct Person p = { "张三", 18, "男" };
//	fwrite(&p, sizeof(struct Person), 1, pf);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	int ch = 0;
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	// 初识位置偏移 3个
//	fseek(pf, 3, SEEK_SET);
//	long len = ftell(pf);
//	printf("偏移量 %d\n", len);
//
//	rewind(pf);
//
//	len = ftell(pf);
//	printf("回归偏移量 %d\n", len);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	int ch = 0;
//	FILE* pf = fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		perror("fopen");
//		return 1;
//	}
//	// 初识位置偏移 3个
//	fseek(pf, 3, SEEK_SET);             
//	ch = fgetc(pf);                    
//	printf("初始位置 %c\n", ch);    
//
//	fseek(pf, 3, SEEK_CUR);
//	ch = fgetc(pf);
//	printf("当前位置 %c\n", ch);
//
//
//	fseek(pf, -3, SEEK_END);
//	ch = fgetc(pf);
//	printf("结束位置 %c\n", ch);
//
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//int main()
//{
//
//	FILE* pf = fopen("test.txt", "r");
//	char buffer[1024] = { 0 };
//	memset(buffer, '\0', sizeof(buffer));
//
//	int s = fread(buffer, sizeof(char), sizeof(buffer), pf);
//	// abcde -- 5个有效字符
//	buffer[s] = '\0'; //  C语言模式
//	printf("%d\n", s);
//	printf("%s\n", buffer);
//	fclose(pf);  //关闭文件
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//
//	FILE* pf = fopen("test.txt", "w");
//	char* buffer = "我是一个学习者";
//
//	for (int i = 0; i < 5; i++)
//	{
//		fwrite(buffer, strlen(buffer), sizeof(char), pf);
//	}
//	fclose(pf);  //关闭文件
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//
//	FILE* pf = fopen("test.txt", "w");
//	char buffer[10] = { 'a', 'b', 'c', 'd', 'e', 'f','\n'};
//
//	for (int i = 0; i < 5; i++)
//	{
//		fputs(buffer, pf);
//	}
//	fclose(pf);  //关闭文件
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//
//	FILE* pf = fopen("test.txt", "r");
//	char buffer[4] = { 0 };
//	while (fgets(buffer, sizeof(buffer),pf) != NULL)
//	{
//		printf("%s", buffer);
//		memset(buffer, '\0', sizeof(buffer));
//	}
//	fclose(pf);  //关闭文件
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//
//	FILE* pf = fopen("test.txt", "r");
//
//	fgetc(pf);
//	printf("pf->_ptr  %p char %c\n", pf->_ptr, *pf->_ptr);
//	fgetc(pf);
//	printf("pf->_ptr  %p char %c\n", pf->_ptr, *pf->_ptr);
//
//	fgetc(pf);
//	printf("pf->_ptr  %p char %c\n", pf->_ptr, *pf->_ptr);
//	fclose(pf);  //关闭文件
//	pf = NULL;
//	return 0;
//}
//int main()
//{
//
//	FILE* pf = fopen("test.txt", "r");
//	fgetc(pf);
//
//	fclose(pf);  //关闭文件
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//
//	FILE* pf = fopen("test.txt", "r");
//	printf("pf->_ptr  %p\n", pf->_ptr);
//
//    fgetc(pf);
//	printf("pf->_ptr  %p char %c\n", pf->_ptr, *pf->_ptr);
//	fgetc(pf);
//	printf("pf->_ptr  %p char %c\n", pf->_ptr, *pf->_ptr);
//
//	fgetc(pf);
//	printf("pf->_ptr  %p char %c\n", pf->_ptr, *pf->_ptr);
//
//	fgetc(pf);
//	printf("pf->_ptr  %p char %c\n", pf->_ptr, *pf->_ptr);
//	fclose(pf);  //关闭文件
//	pf = NULL;
//	return 0;
//}