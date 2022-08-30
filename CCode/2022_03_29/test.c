#include <stdio.h>

//#define type  float
#define GENERRIC_MAX(type)      \
type type##_max(type x,type y)  \
{                               \
     return x > y ? x : y;      \
}                            

GENERRIC_MAX(float)

int main()
{
  //GENERRIC_MAX(float);
	float ret = float_max(1.2, 3.7);
	printf("%.1f\n", ret);
	return 0;
}
