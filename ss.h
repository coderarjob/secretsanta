#ifndef SECRET_SANTA_H
#define SECRET_SANTA_H
	
	#include<stdio.h>

	#define PANIC(s) do{perror(s);}while(0)
	
	#define MAX_NAME_LENGTH 30
	#define NAMES_BLOCK_MULTIPLE 50

	int random_init();
	int getRandom();
	int readNames(char ***names); // read names from stdin

#endif // GET_RANDOM_H
