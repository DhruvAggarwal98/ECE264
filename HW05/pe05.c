#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pe05.h"
//#ifndef TEST_CPRNAME
	StudentDatabase * Connect(char * filename) {
        StudentDatabase * db = NULL;
        db = malloc(sizeof(StudentDatabase));
        FILE* fp = NULL;
        fp = fopen(filename, "r");
	if(fp==NULL){
		return 0;
	}
        char a = '0';
        int length = 0;
        int i = 0;
        while (a != EOF)
        {
                a = fgetc(fp);
                if(a == '\n')
                        length++;
        }
        fseek(fp,0,SEEK_SET);
        db->students = malloc(sizeof(Student *)*length);
        db -> number = length;
        while (i < length)
        {
                db->students[i] = malloc(sizeof(Student));
                fscanf(fp,"%d,%[^,],%[^,],%[^,],%[^,],%d\n", &db -> students[i]-> id, db -> students[i] -> name, db -> students[i]-> major, db -> students[i]-> year,db -> students[i]-> enrollment, &db -> students[i]-> age);
                i++;
        }
        fclose(fp);
return db;
}
	void Close(StudentDatabase * studb) {
        for(int i = 0; i < studb ->number; i++)
        {
                free(studb -> students[i]);
        }
        free(studb -> students);
        free(studb);
}

static int CompareByName(const void * s1, const void * s2) {
const Student** ss1 = (const Student**) s1;
const Student** ss2 = (const Student**) s2;
const Student* sv1 = *ss1;
const Student* sv2 = *ss2;

return strcmp((sv2->name),(sv1->name));
}

//#endif

//#ifndef TEST_NAME
void SortDatabaseByName(StudentDatabase * studb) {
qsort(studb->students,studb->number,sizeof(Student*),CompareByName );
}
//#endif

//#ifndef TEST_CPRAGE
static int CompareByAge(const void * s1, const void * s2) {
const Student** ss1 = (const Student**) s1;
const Student** ss2 = (const Student**) s2;
const Student* sv1 = *ss1;
const Student* sv2 = *ss2;

return(( sv1 -> age ) - ( sv2 -> age )) ;
}
//#endif

//#ifndef TEST_AGE
void SortDatabaseByAge(StudentDatabase * studb) {
	
	qsort(studb->students,studb->number,sizeof(Student*),CompareByAge );
	// use qsort to sort the database.

}
//#endif

//#ifndet
 //TEST_WRITE
int WriteDatabase(char *filename, StudentDatabase * db) {
	// Write the info storing in db to filename
	FILE* output=fopen(filename,"w");
	if (output==NULL){
		return 0;
	}
	for(int i=0;i<db->number;i++){
		fprintf(output,"ID:%d, Name:%s, Major:%s, Enrollment:%s, Year:%s, Age:%d\n", db -> students[i]-> id, db -> students[i] -> name, db -> students[i]-> major, db -> students[i]-> enrollment,db -> students[i]-> year, db -> students[i]-> age);
	}
	fclose(output);
	return 1;
}
//#endif

