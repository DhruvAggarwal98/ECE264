#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pe11.h"
#define MAX_LENGTH 100

int main(int argc, char **argv) {

	char array[MAX_LENGTH] ;
	int i=0;
	int j=0;
	FILE* fp = fopen(argv[1],"r");
	if(fp==NULL){
		printf("No");
		return 0;
	}
	FILE* gp = fopen("a.txt","w+");
	struct node** head = malloc(sizeof(head));
	struct node* n = malloc(sizeof(n));
	fseek(fp,0,SEEK_SET);
	while(fscanf(fp,"%s",array)!=EOF){
	//	printf("%s\n",array);
		
		if(strcmp("insF",array)==0){
		fscanf(fp,"%d",&i);
	//	printf("%d",i);
		n->value=i;
		insertFirst(head, n);
		print(head);
		}

		else if(strcmp("insA",array)==0){    
                fscanf(fp,"%d" "%d",&i,&j);               
                //printf("%d %d",i,j);
		n->value=i;
                insertAt(head, n,j);
		print(head);
		}

		else if(strcmp("insL",array)==0){    
                fscanf(fp,"%d",&i);               
               // printf("%d",i);
		n->value=i;
                insertLast(head, n);
                print(head);
		 }
		
		else if(strcmp("delFM",array)==0){    
                fscanf(fp,"%d",&i);               
               // printf("%d",i);
		deleteFirstMatch(head, i);
                print(head);
		}
		
		else if(strcmp("delA",array)==0){
                fscanf(fp,"%d",&i);
                //printf("%d",i);
		deleteAt(head, i);
                print(head);
		}

		else if(strcmp("delAM",array)==0){
                fscanf(fp,"%d",&i);
               // printf("%d",i);
		deleteAllMatches(head, i);
                print(head);
		}
		
		else if(strcmp("L",array)==0){
		 int length = getLength(head);
               printf("%d\n", length);
		}
	}
fclose(gp);	
fclose(fp);
freeMemory(head);
	return EXIT_SUCCESS;
}
