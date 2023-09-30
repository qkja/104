/**
 * User: Qkj
 * Description: 指针进阶
 * Date: 2023-07-18
 * Time: 14:02
 */
//【题目名称】
//
//字符串左旋
//
//【题目内容】
//
//实现一个函数，可以左旋字符串中的k个字符。
//
//
//
//例如：
//
//
//
//ABCD左旋一个字符得到BCDA
//
//ABCD左旋两个字符得到CDAB
//void reverse(char* str, int left, int right)
//{
//	while (left < right)
//	{
//		char ret = str[left];
//		str[left] = str[right];
//		str[right] = ret;
//		left++;
//		right--;
//	}
//}
//
//void counter_clockwise(char* str, int k)
//{
//	int len = strlen(str);
//	k = k%len;
//	reverse(str, 0, k - 1);
//	reverse(str, k, len - 1);
//	reverse(str, 0, len - 1);
//}
//
//int is_counter_clockwise()
//{
//
//}
//int main()
//{
//	char arr[] = "abcd";
//	counter_clockwise(arr, 4);
//	printf("%s\n", arr);
//	return 0;
//}
//
//int findRound(const char * src, char * find)
//{
//	char tmp[256] = { 0 }; //用一个辅助空间将原字符串做成两倍原字符串
//	strcpy(tmp, src); //先拷贝一遍
//	strcat(tmp, src); //再连接一遍
//	return strstr(tmp, find) != NULL; //看看找不找得到
//}
//
//int main()
//{
//	int aa[2][5] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
//	int *ptr1 = (int *)(&aa + 1);
//	int *ptr2 = (int *)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//	return 0;
//}

int main()
{
	int a[5] = { 5, 4, 3, 2, 1 };
	int *ptr = (int *)(&a + 1);
	printf("%d,%d", *(a + 1), *(ptr - 1));
	return 0;
}