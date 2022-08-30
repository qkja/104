#define A(x) (x) * (x) * (x) 
int main()
{
	int a = 1;
	printf("%d", A(++a));
	return 0;
}
