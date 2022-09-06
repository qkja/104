#define _CRT_SECURE_NO_WARNINGS 1
#include"contact.h"

void SaveContact(Contact* pc)
{
	FILE* pf = fopen("Contact.txt", "w");
	if (pf == NULL)
	{
		printf("%s", strerror(errno));
		return 0;
	}
	//写文件
	for (int i = 0; i < pc->sz; i++)
	{

	}
	//关闭文件
	fclose(pf);
	pf = NULL;
}

void InitContact(Contact* pc)
{
	assert(pc);
	pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));
}
int ComByName(const void* e1, const void* e2)
{
	return strcmp(((const PeoInfo*)e1)->name, ((const PeoInfo*)e2)->name);
}

void SortContact(Contact* pc)
{
	//按字母排序
	assert(pc);
	if (pc -> sz == 0)
	{
		printf("空通讯录\n");
		return;
	}
	//void qsort( void *base, size_t num, size_t width, 
	//int (__cdecl *compare )(const void *elem1, const void *elem2 ) );
	
	qsort(pc->data, pc->sz, sizeof(PeoInfo),ComByName);
}

int FindByName(Contact* pc,char *name)
{
	for (int i = 0; i < pc->sz; i++)
	{
		if(strcmp(pc->data[i].name, name)== 0)
		{
			return i;
		}
	}
	return -1;
}

void ModifyContact(Contact* pc)
{
	assert(pc);
	printf("请输入要修改的名字：>");
	char name[NAME_Max] = { 0 };
	scanf("%s", name);
	if (-1 == FindByName(pc, name))
	{
		printf("没有这个人，找不到\n");
		return;
	}
	int i = FindByName(pc, name);
	printf("找到了，这个人的信息是\n");
	printf("%-10s\t%-5s\t%-5s\t%-13s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
	printf("%-10s\t%-5d\t%-5s\t%-13s\t%-20s\n",
		pc->data[i].name,
		pc->data[i].age,
		pc->data[i].sex,
		pc->data[i].tele,
		pc->data[i].addr);
	printf("请输入姓名:>");
	scanf("%s", pc->data[i].name);
	printf("请输入年龄:>");
	scanf("%d", &pc->data[i].age);
	printf("请输入性别:>");
	scanf("%s", pc->data[i].sex);
	printf("请输入电话:>");
	scanf("%s", pc->data[i].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[i].addr);
	printf("修改成功\n");
}

void AddContact(Contact* pc)
{
	assert(pc);
	if (pc->sz == Max)
	{
		printf("已满\n");
		return;
	}
	printf("请输入姓名:>");
	scanf("%s", pc->data[pc->sz].name);
	printf("请输入年龄:>");
	scanf("%d", &pc->data[pc->sz].age);
	printf("请输入性别:>");
	scanf("%s", pc->data[pc->sz].sex);
	printf("请输入电话:>");
	scanf("%s", pc->data[pc->sz].tele);
	printf("请输入地址:>");
	scanf("%s", pc->data[pc->sz].addr);
	pc->sz++;
	printf("增加成功\n");
}

void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%-10s\t%-5s\t%-5s\t%-13s\t%-20s\n", "名字", "年龄", "性别", "电话","地址");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%-10s\t%-5d\t%-5s\t%-13s\t%-20s\n",
			pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}
void DelContact(Contact* pc)
{
	assert(pc);
	if (pc->sz == 0)
	{
		printf("空通讯录");
		return;
	}
	printf("请输入要删除的名字：>");
	char name[NAME_Max] = { 0 };
	scanf("%s", name);
	if (-1 == FindByName(pc, name))
	{
		printf("没有这个人，找不到\n");
		return;
	}
	else
	{
		int j = 0;
		for (j = FindByName(pc, name); j < pc->sz -1; j++)
		{
			pc->data[j] = pc->data[j + 1];
		}
		printf("删除成功\n");
		pc->sz--;
	}

}

void SearchContact(Contact* pc)
{
	assert(pc);
	printf("请输入要查找的名字：>");
	char name[NAME_Max] = { 0 };
	scanf("%s", name);
	if (-1 == FindByName(pc, name))
	{
		printf("没有这个人，找不到\n");
		return;
	}
	int i = FindByName(pc, name);
	printf("%-10s\t%-5s\t%-5s\t%-13s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
	printf("%-10s\t%-5d\t%-5s\t%-13s\t%-20s\n",
		pc->data[i].name,
		pc->data[i].age,
		pc->data[i].sex,
		pc->data[i].tele,
		pc->data[i].addr);
}
