#include "ProcBar.h"

void process_bar()
{
  
  const char* p = "|/-\\";
	int i = 0;
	char arr[101] = { 0 };
	memset(arr, '\0', sizeof(arr));
	while (i <= 100)
	{
		printf("[%-100s][%d%%][%c]\r", arr, i, p[i % 4]);
    fflush(stdout);
		arr[i++] = '#';
		usleep(80000);
    
	}
  printf("\n");
}
