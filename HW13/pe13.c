#include "frequency.h"

// Step 1. - Create/ Define data structre in frequency.h such that it can hold character of 256 bytes
// Step 2. - Complete function in frequency.c file
// Step 3. - Complete main function
// Step 4. - Test all the test cases 


int main(int argc, char **argv){
  //0. Create array of CharFreq
  //1. initialize all the frequencies inside freq array to be 0
  //2. Count Frequency from the the input file
  //2a. if return value from the function is not success, return exit failure
  //3. Sort frequencies that you get
  //4. Print the frequencies on terminal
	if(argc!=2){
        printf("Wrong arguments");
        return EXIT_FAILURE;
        }
        int i=0;
	CharFreq* a=malloc(sizeof(a)*NUMLETTER);
	for(i=0;i<256;i++){
		a[i].freq=0;
	}
	CountFrequency(argv[1],a);
        SortFrequency(a);
        PrintFreq(a);
        free(a);

  return EXIT_SUCCESS;
}
