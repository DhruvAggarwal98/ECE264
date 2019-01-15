#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa08.h"


	int main(int argc,char* argv[]){
		if(strcmp(argv[1],"-D")==0){
			int i=0; 
			if(argc!=5){
				return EXIT_FAILURE;
			}
			DoubleVar* var=malloc(sizeof(var));
			if(var==NULL){
				return EXIT_FAILURE;
			}
			var->digit_start=argv[2][0];
			var->digit_end=argv[3][0];
			int length=atoi(argv[4]);
			char* string=malloc(sizeof(string)*length);
			for(i=3;i<=length;i++){
				createDouble(string,var,0,false,i);
			}
			free(string);
			free(var);
		}
		return EXIT_SUCCESS;
	}

