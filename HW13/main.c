#include<stdlib.h>
#include <stdio.h>
//#include "frequency.h"
#define NUMLETTER 256
int main(int argc, char* argv[]){
	if(argc!=2){
	printf("Wrong arguments");
	return EXIT_FAILURE;
	}
	struct CharFreq* a=malloc(sizeof(a)*NUMLETTER);
	CountFrequency(argv[1],a);
	SortFrequency(a);
	PrintFreq(a);
	free(a);
}
