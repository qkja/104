/**
 * User: Qkj
 * Description: 结构体
 * Date: 2023-07-18
 * Time: 14:02
 */

// int main()
//{
//	printf("helo");
//	return 0;
// }
// #include <stddef.h>
// #include <stdio.h>
// struct MyStruct
//{
//	int a;
//	int b;
// };
// #define my_offsetof(struct_type,mem_name) (int)&((((struct_type*)0)->mem_name))
// int main()
//{
//	printf("%d\n", offsetof(struct MyStruct, a));
//	printf("%d\n", my_offsetof(struct MyStruct, a));
//	;
//	return 0;
// }

// #include <stdio.h>
// int main()
// {
//   union
//   {
//     short k;
//     char i[2];
//   } *s, a;
//   s = &a;
//   s->i[0] = 0x39;
//   s->i[1] = 0x38;
//   printf("%x\n", a.k);
//   return 0;
// }

// #include <stdio.h>
// union Un
// {
//   short s[7];
//   int n;
// };
// int main()
// {
//   printf("%d\n", sizeof(union Un));
//   return 0;
// }

// enum ENUM_A
// {
// 		X1,
// 		Y1,
// 		Z1 = 255,
// 		A1,
// 		B1,
// };
// enum ENUM_A enumA = Y1;
// enum ENUM_A enumB = B1;
// printf("%d %d\n", enumA, enumB);

// int main()
// {
//   unsigned char puc[4];
//   struct tagPIM
//   {
//     unsigned char ucPim1;
//     unsigned char ucData0 : 1;
//     unsigned char ucData1 : 2;
//     unsigned char ucData2 : 3;
//   } *pstPimData;
//   // printf("%d", sizeof(struct tagPIM));
//   pstPimData = (struct tagPIM *)puc;
//   memset(puc, 0, 4);
//   pstPimData->ucPim1 = 2;
//   pstPimData->ucData0 = 3;
//   pstPimData->ucData1 = 4;
//   pstPimData->ucData2 = 5;
//   printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
//   printf("%02x\n",3);
//   return 0;
// }

// #define MAX_SIZE A+B
// struct _Record_Struct
// {
//   unsigned char Env_Alarm_ID : 4;
//   unsigned char Para1 : 2;
//   unsigned char state;
//   unsigned char avail : 1;
// }*Env_Alarm_Record;
// struct _Record_Struct *pointer = (struct _Record_Struct*)malloc
// (sizeof(struct _Record_Struct) * MAX_SIZE); 

// #pragma pack(4)/*编译选项，表示4字节对齐 平台：VS2013。语言：C语言*/
// int main(int argc, char* argv[])
// {
//   struct tagTest1
//   {
//     short a;
//     char d; 
//     long b;   
//     long c;   
//   };
//   struct tagTest2
//   {
//     long b;   
//     short c;
//     char d;
//     long a;   
//   };
//   struct tagTest3
//   {
//     short c;
//     long b;
//     char d;   
//     long a;   
//   };
//   struct tagTest1 stT1;
//   struct tagTest2 stT2;
//   struct tagTest3 stT3;

//   printf("%d %d %d", sizeof(stT1), sizeof(stT2), sizeof(stT3));
//   return 0;
// }
// #pragma pack()

// struct A
// {
//  int a;
//  short b;
//  int c;
//  char d;
// };
// struct B
// {
//  int a;
//  short b;
//  char c;
//  int d;
// };

// typedef struct{
//   int a;
//   char b;
//   short c;
//   short d;
// }AA_t;