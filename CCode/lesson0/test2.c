#include<stdio.h>
#include<string.h>
int main()
{


 int arr1[] = {1,2,3,4,5,6,7,8,9,10};
 int arr2[5] = {0};
 memcpy(arr2,arr1,20);


 int i = 0;
 for(i=0;i<5;i++)
 {
   printf("%d ",arr2[i]);
 }
 printf("\n");
 //vaIiT I=0;I<5;I++
//  char p[] = "abcdef";
 // char p2[] = {0};
//  strcpy(p2,p);
 // printf("%s\n",p2);

  return 0;
}
