#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	printf("%d\n", 'A'+32);
//	printf("%d\n", 'a');
//	printf("%c\n", 'A'+32);
//	printf("%d\n", 'a'-'A');
//	return 0;
//}

//int main()
//{
//    char arr[1001] = { 0 };
//    char ch = 0;
//    int ret = 0;
//    int j = 0;
//    while ((ret = getchar()) != '\n')
//    {
//        arr[j++] = ret;
//    }
//    scanf("%c", &ch);
//
//    printf("%s\n", arr);
//    printf("%c\n", ch);
//    /*int ret2 = 0;
//    printf("%d\n", ret2);*/
//    return 0;
//}

#include <stdio.h>
#include <string.h>
#include <assert.h>
int func(char* str, char ch)
{
    assert(str);
    int len = strlen(str);
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            if (ch == str[i])
            {
                count++;
            }
        }
        else if ((str[i] >= 'a' && str[i] <= 'z')|| (str[i] >= 'A' && str[i] <= 'Z'))
        {
            if (!(ch>='0'&&ch<='9') && (ch == str[i] || ch == (str[i] - 32) || ch == (str[i] + 32)))
            {
                count++;
            }
        }
       
    }
    return count;
}

int fun(char* p)
{
    int count = 0;
    for (int i = 0; i < strlen(p); i++)
    {
        
        if (p[i] == '1')
        {
            count++;
        }
    }
    return count;
}

int main()
{
    char* p = "655b203khDc79w76239SC60Yx5O634244O8oNKw2g5c122dt9M17197FQ9fR0fC8619q00cC156NJQ958ZAH8qe76G024Xvy74ETiO10WgQmOuNx104B9L8Euod682x6hVX941DUalUwb20nyD6IX6IM57Jvypu2mtZ8fpk9Z72AU9g0zob32W7J427VT50P7x40d6QF1067yYMioy6E037e2fTDTse6Z983873849KSB3t93t1wR14717iDi9ybw76h9410q345Z4882zWY3v7C0jD33NlLiF53Hp69067Dzvu1s4Er0G24MhcAHEq151Y339jyfbP6w9j1dX72DEv7L02764f2K7XVf7tWNYGqU5iNlS5RpV619vg7zR96D8jMsO5xN223W97CMuHHWBX806AD732q42h1bwpSb923V3Q73D3g3O0100tk948693d67nxrd7LB6He5O9qG2i9xJ0U1x9054y20039V9uD61HF9eP825JJ79M200X3zH1pW99QeG40kR4275p5P96S3J6mj60z278C1K685As6CX35rcY70qI5810i3rt5WB1C6H74118433Z8wsfE9s2M82q7TN7Q6Zz3047W99g56kLK58NqPfSuhSfEs0W4u1D720A3jqpG7aD0Be3N18395zS037T0Rg47K3O90H5w5660bNW58O8TK3l38xyN7R36kH4l21VYDx3waZK8kf5O3ySWJQdN7eVnf778GIa70Fan34v0owxkg4N5keNbaxh044l67Vimm110i7N8614Xj4667rQd6R67aHlm5z6N51jtbAm22305l9p83Uu6l8pBOaxQL56c5M76SUUKv9538FVD28WT1046sPQ1eHf5e65tk3Q6Lub314FBNv2C4Q12e6oPcX95jC06g8oFj7q7V20ciEO73m00U8v8342H1w86yS298r094x2y8O24e8p6j685D9a539930DQ6s6813uF8D34i6E1x5j2v9";
    printf("%d\n", fun(p));
    printf("%d\n", func(p,'1'));
    return 0;
}

//int main()
//{
//    char arr[1001] = { 0 };
//    char ch = 0;
//    int ret = 0;
//    int j = 0;
//    while ((ret = getchar()) != '\n')
//    {
//        arr[j++] = ret;
//    }
//    scanf("%c", &ch);
//    int ret2 = func(arr, ch);
//    printf("%d\n", ret2);
//    return 0;
//}
//#include<stdio.h>
//int main()
//{
//    char str[1000] = { 0 }, ch, count = 0;/*数组保存字符串，ch是第二次输入的字符，count统计个数*/
//    scanf("%[^\n]\n", str);//读入输入字符，遇到回车停止读入
//    scanf("%c\n", &ch);//输入要统计数量的字符
//    for (int i = 0; i < strlen(str); i++)//遍历数组
//    {
//        if ((ch >= '0' && ch <= '9') && (ch == str[i]))//若是数字
//        {
//            count++;
//        }//若不是数字
//        else if (((ch == str[i]) || (ch == (str[i] + 32)) || (ch == (str[i] - 32))) && !(ch >= '0' && ch <= '9'))
//        {
//            count++;//字符个数加一
//        }
//    }
//    printf("%d", count);
//    return 0;
//}

