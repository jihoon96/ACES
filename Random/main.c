#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i;
	srand((int)time(NULL));
	for(i = 0; i < 20; i++)
		printf("random value %d : %d\n", i, (rand()%10)+1);

	return 0;

}
