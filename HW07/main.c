#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "pe07.h"
#define MAX_LENGTH 100 //The maximum length of string


int main(int argc, char *argv[]) 
{
	int i=0;
	if(argc==2){
		FILE* fp=fopen(argv[1],"r");
		if(fp == NULL)
		  return EXIT_FAILURE;
		char string[MAX_LENGTH];
		int counter=0;
		while(fgets (string,MAX_LENGTH,fp)!=NULL){
			counter++;
		}
		fseek(fp,0,SEEK_SET);
		for(i=0;i<counter;i++){
			fscanf(fp,"%s",string);
			if(IsInteger(string, 0)==true){
				fprintf(stdout,"Integer\n");
			}
			else if(IsDouble(string,0,false)==true){
				fprintf(stdout,"Double\n");
			}
			else if(IsValidIdentifier(string,0)==true){
				fprintf(stdout,"Identifier\n");
			}
			else{
				fprintf(stdout,"None\n");
			}
		}
		fclose(fp);
		return EXIT_SUCCESS;	
	}			
	if (argc==3){
		if(strcmp(argv[2],"-I")==0){
			FILE* fp=fopen(argv[1],"r");
			if(fp == NULL)
			  return EXIT_FAILURE;
			char string[MAX_LENGTH];
			int counter=0;

			while(fgets (string,MAX_LENGTH,fp)!=NULL){
				counter++;
			}
			fseek(fp,0,SEEK_SET);
			for(i=0;i<counter;i++){
				fscanf(fp,"%s",string);
				if(IsInteger(string, 0)==true){	
					fprintf(stdout,"Integer\n");
				}
				else{
					fprintf(stdout,"Not integer\n");
				}
			}
			fclose(fp);
			return EXIT_SUCCESS; 	
		}
		else if(strcmp(argv[2],"-D")==0){
			FILE* fp=fopen(argv[1],"r");
			if(fp == NULL)
			  return EXIT_FAILURE;
			char string[MAX_LENGTH];
			int counter=0;

			while(fgets (string,MAX_LENGTH,fp)!=NULL){
				counter++;
			}
			fseek(fp,0,SEEK_SET);
			for(i=0;i<counter;i++){
				fscanf(fp,"%s",string);
				if(IsDouble(string, 0,false)==true){
					fprintf(stdout,"Double\n");
				}
				else{
					fprintf(stdout,"Not double\n");
				}
			}
			fclose(fp);
			return EXIT_SUCCESS;	
		}
		else if(strcmp(argv[2],"-VID")==0){
			FILE* fp=fopen(argv[1],"r");
			if(fp == NULL)
			  return EXIT_FAILURE;
			char string[MAX_LENGTH];
			int counter=0;

			while(fgets (string,MAX_LENGTH,fp)!=NULL){
				counter++;
			}
			fseek(fp,0,SEEK_SET);
			for(i=0;i<counter;i++){
				fscanf(fp,"%s",string);
				if(IsValidIdentifier(string,0)==true){
					fprintf(stdout,"Identifier\n");
				}
				else{
					fprintf(stdout,"Not identifier\n");
				}
			}
			fclose(fp);
			return EXIT_SUCCESS;

		}
		else{
			return EXIT_FAILURE;
		}
	}				
	else{
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}
