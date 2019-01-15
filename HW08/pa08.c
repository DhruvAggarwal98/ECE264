#include <stdio.h>
#include <stdlib.h>
#include "pa08.h"

#ifndef CDOUBLE

void createDouble(char * string,DoubleVar* var,int index,bool dot,int len){
	if(index+1==len){
		int i=0;
		int j=len-2;
		while(j!=0){
			for(i=0;i<len-1;i++){
				if(j==i){
					printf(".");
				}
				printf("%c",string[i]);
			}
			printf("\n");
			j--;
		}
	}
	else{
		int j=0;
		for(j=var->digit_start-48;j<=var->digit_end-48;j++){
			string[index]=j+48;
			createDouble(string,var,index+1,false,len);
		}
	}
}

#endif


