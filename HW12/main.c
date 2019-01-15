#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pa12.h"




int main(int argc, char **argv)
{
  struct node** head = malloc(sizeof(head));
  if(argc != 5)
    {
      return 0;
    }
  
  else if(strcmp("-J",argv[1])==0){
    init(head,atoi(argv[2]));
   josp(head, atoi(argv[3]), atoi(argv[4]),atoi(argv[2]));
	 free(head);

  }

}
