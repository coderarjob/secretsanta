#include <stdio.h>
#include <stdlib.h> // for rand, srand
#include <time.h>

int random_init()
{
	time_t epoch_seconds;
	time(&epoch_seconds);
	srand(epoch_seconds);
}

int getRandom(){
	return rand();
}

