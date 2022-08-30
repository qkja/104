#include<stdio.h>

struct Stu
{
  char name[20];
  char sex[5];
  int age;
  int hight;
};

typedef struct Stu Stu;
struct S1
{
  //char c1;
  int i;
  char c2;
};
#pragma pack(1)
struct S2
{
  char c2;
  int i;
};
#pragma pack()

int main()
{

  printf("%d",sizeof(struct S2));
  //printf("%d \n",sizeof(struct S2));
  //printf("%d \n",sizeof(struct S1));
  //Stu s2;
  //  Stu s1 = {"zhangsan","man",18,182};
  // printf("%s %s %d %d\n",s1.name,s1.sex,s1.age,s1.hight);
  // s1.age = 10;
  // s1.name[20] = "lisi";
  // printf("%s %s %d %d\n",s1.name,s1.sex,s1.age,s1.hight); 
  //printf("%s %d\n",s2.sex,s2.age);
  return 0;
}
