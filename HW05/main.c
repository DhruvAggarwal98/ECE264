#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pe05.h"


/*
	Complete the main function and meet the followin specifications of argc and argv.
	1. argc: If argc is not 4, you should return `EXIT_FAILURE` and print "Wrong arguments\n".
	2. argv[1]: name of the input file. i.e., database.txt
	3. argv[2]: should be either "-a", or "-n".
		When argv[2] is "-a", you should sort the database by age in ascending order and print the database and return `EXIT_SUCCESS`.
		When argv[2] is "-n", you should sort the database by name in descending order and print the dataabse and return `EXIT_SUCCESS`. 
		For example, Student "Allen" should come after "Bob".
	  	If argv[2] is neither "-a" nor "-s", you should print "Wrong arguments\n" and return `EXIT_FAILURE`.
	4. argv[3]: This is the output filename. You should write the output of database into this file.
	5. print "Write to db\n" if `WriteDatabase()` work. Otherwise, print "Fail to write to db\n"

*/ 

int main(int argc, char ** argv) {
	
	if(argc!=4){
		printf("Wrong arguments\n");
		return EXIT_FAILURE;
	}
	if(strcmp(argv[2],"-n")==0){		
		StudentDatabase* db;
		db=Connect(argv[1]);
		if(db==NULL){
			printf("fail to open database.\nFail to connect to db.\n");
			return EXIT_FAILURE;
		}
		SortDatabaseByName(db);
		int i=WriteDatabase(argv[3],db);
		if(i==1){
			printf("Write to db\n");		
		}
		else if(i==0){
			
			printf("Fail to open a file\nFail to write to db\n");
			return EXIT_FAILURE;
		}
		Close(db);
	}	
	else if(strcmp(argv[2],"-a")==0){
		//CompareByName("gsfdg","gsdgs");
	StudentDatabase* db;
                db=Connect(argv[1]);
                if(db==NULL){
                        return EXIT_FAILURE;
                }
                SortDatabaseByAge(db);
                int i=WriteDatabase(argv[3],db);
                if(i==1){
                        printf("Write to db\n");
                }
                else if(i==0){
                        printf("Fail to open a file\nFail to write to db\n");
                        return EXIT_FAILURE;
                }
                Close(db);
		
	}
	else{
		printf("Wrong arguments\n");
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

