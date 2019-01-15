#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pe10.h"




#ifndef PRINT
// This function will print the boolean array with length=len in the following format.
// It will print out the index if its corresponding value in the array is true, Otherwise it will print X instead.
// If the array is of length 4, and it has values of true(index=0),false(index=1),true(index=2),false(index=3)
// the output looks like this: 0,X,2,X
// ::::::::IMPORTANT NOTES:::::::
// 1- There should be no extra comma at the end nor at the beginning, "Violating this format will get you zero".
// 2- Make sure that there is a new line at the end of the output (i.e printf("\n")). 
void print(bool * arr,int len)
{
	int i=0;
	int j=len-2;
	for(i=0;i<len;i++){
		if(arr[i]==true){
			printf("%d",i);
		}
		else{
			printf("X");
		}
		if(j>=i){
			printf(",");	
		}
	}	
	printf("\n");

}
#endif


#ifndef JOSEPHUS
// arr: a boolean array which you should initialized to 1's in the main.c.
// len: the length of the array
// k:   the numbers of elements you should skip
// p:   if the number of remaining elements in the array after each step is divisible by p, then you need to print the array.
// Your function should stop when it has only one element left.
void josephus(bool * arr, int len, int k,int p){
	int i=0;
	int skip=k;
	int available=len;
	int counter=len;
	while(len>0){
		for(i=0;i<counter;i++){

			if(arr[i]==false){
				skip++;
			}
		
			if(skip>=counter){
			      skip=skip-counter;
			}


			if(i==skip){
				if(arr[i]==true){
					arr[i]=false;
					available --;
					if((available)%p==0){
			      	print(arr,counter);
					}
				}
				skip+=k+1;

			if(available==1){
				break;
			}

}
}
			len--;	
			if(available==1){
				break;
			}
		
}
}
#endif
