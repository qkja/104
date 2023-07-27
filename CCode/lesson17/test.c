/**
 * User: Qkj
 * Description: 宏
 * Date: 2023-07-18
 * Time: 14:02
 */

// #define A 2+2
// #define B 3+3
// #define C A*B
// int main()
// {
// 	printf("%d\n", C);
//   return 0;
// }
#define offsetof(struct_type, struct_type_m) (int)&(((struct_type*)0)->struct_type_m)
#define SwapIntBit(n) (((n) & 0x55555555) << 1 | ((n) & 0xaaaaaaaa) >> 1)