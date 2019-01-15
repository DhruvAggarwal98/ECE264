#include "tree.h"
#include "list_node.h"
#include "frequency.h"

#ifndef MAIN_FUNC

int main(int argc, char **argv){
  // Create CharFreq array
  // initialize all the frequencies inside freq array to be 0
  // count frequency by calling CountFrequency function and passing the input filename
  // sort frequencies by calling SortFrequency function
  // build linked list sorted linked list
  // Get two minimum frequencies and merge them and reduce one list node - do this in main file
  // Print the final huffman tree in prefix by calling the print function - call the function
  // Free all the memory allocated
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
	for(i=0;i<256;i++){
		if(a[i].freq!=0){
			TreeNodeCreate(i,a[i].freq);	
		}
	}
        free(a);

  return EXIT_SUCCESS;
}
#endif
