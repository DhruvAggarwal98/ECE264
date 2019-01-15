#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "pa06.h"
#define MAX_LEN 80
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


#ifndef TEST_CONSRUCT
/* 
	Construct SelectedField.
	1. This function returns a pointer to SelectedField object.
	2. Allocate memory for SelectedField object.
	3. Initialize all the fields in this object to "false".
	4. return NULL if you fail to allocate memory for SelectedField object.
*/
SelectedField * ConstructField() {
	SelectedField* object=malloc(sizeof(object));
	if(object==NULL){
		return NULL;
	}
	object->id=false;
        object->name=false;
        object->major=false;
        object->year=false;
        object->enrollment=false;
        object->age=false;	
	return object;
}
#endif

#ifndef TEST_PARSE
/* 
	Parse the query and store the information into ParseResult object.
	1. This function returns a pointer to ParseResult object.
	2. The ParseResult object has four fields.
		1. Pointer to SelectedField object. The SelectedField  object stores the informations of which fields are selected in the query. For example, if field id is selected, you should update that field to "true".
		2. Number of condition. 
		3. Array of pointers to Condition object. 
		4. What logic does this query specify. It should be eigther AND or OR.
	3. In this function, you should parse the qeury and store the information to ParseResult object. Similar to `Connect()` function in HW04, you should allocate memory for the required objects and then update the fields in the objects. 
*/
//ParseResult * ParseQuery(int num, char ** query) {

	ParseResult * ParseQuery(int num, char ** query) {
    ParseResult* object=malloc(sizeof(object));

	int k=0;
    int i=1;
    int j=0;
    int l = 0;
    while(k<num){
        k++;
        if(strcmp(query[k],"WHERE")==0){
            while(k<num){
                
                if(strcmp(query[k],"AND")!=0 && strcmp(query[k],"OR")!=0){
                    l++;
                }
                k++;
                
            }
            break;
        }
    }
    object->conditions=malloc(sizeof(Condition));
	l=l/3; 
object->condition_num=l;
for(k=0;k<l;k++){
        object->conditions[k]=malloc(sizeof(Condition));
  }

    object->field=ConstructField();
    while(i<num){
        if(strcmp(query[i],"SELECT")==0){
            while(strcmp(query[i],"WHERE")!=0){
                if(strcmp(query[i],"id")==0){
                                    object->field->id=true;
                }
                if(strcmp(query[i],"year")==0){
                                                  object->field->year=true;
                }
                if(strcmp(query[i],"name")==0){
                                                    object->field->name=true;
                }
                if(strcmp(query[i],"major")==0){
                                                  object->field->major=true;
                }
                if(strcmp(query[i],"enrollment")==0){
                                                object->field->enrollment=true;
                }
                if(strcmp(query[i],"age")==0){
                                              object->field->age=true;
                }
                i++;
            }
        }
        if(strcmp(query[i],"WHERE")==0){
         i++;
         
         while(i<num){
         if(strcmp(query[i],"AND")==0){
         strcpy(object->logic,query[i]);
         }
         if (strcmp(query[i],"OR")==0){
         strcpy(object->logic,query[i]);
         }
         if(strcmp(query[i],"id")==0){
         strcpy(object->conditions[j]->field,query[i]);
         i++;
         strcpy(object->conditions[j]->optr,query[i]);
         i++;
         strcpy( object->conditions[j]->val,query[i]);
        j++; 
	}
         if(strcmp(query[i],"year")==0){
         strcpy(object->conditions[j]->field,query[i]);
         i++;
         strcpy(object->conditions[j]->optr,query[i]);
         i++;
         strcpy( object->conditions[j]->val,query[i]);
        j++; 
	}
         if(strcmp(query[i],"name")==0){
         strcpy(object->conditions[j]->field,query[i]);
         i++;
         strcpy(object->conditions[j]->optr,query[i]);
         i++;
         strcpy( object->conditions[j]->val,query[i]);
        j++; 
	}
         if(strcmp(query[i],"major")==0){
         strcpy(object->conditions[j]->field,query[i]);
         i++;
         strcpy(object->conditions[j]->optr,query[i]);
         i++;
         strcpy( object->conditions[j]->val,query[i]);
	j++;  
       }
         if(strcmp(query[i],"enrollment")==0){
         strcpy(object->conditions[j]->field,query[i]);
         i++;
         strcpy(object->conditions[j]->optr,query[i]);
         i++;
         strcpy( object->conditions[j]->val,query[i]);
        j++;
	 }
         if(strcmp(query[i],"age")==0){
             strcpy(object->conditions[j]->field,query[i]);
         i++;
         strcpy(object->conditions[j]->optr,query[i]);
         i++;
         strcpy( object->conditions[j]->val,query[i]);
    j++;
	     }
         
	//printf("%d",j);
//j++;
         i++;
         }
        i++;
    }
    
    }
	
    return object;
}







#endif



#ifndef TEST_COMPARE
/*
	This is a helper function we provide in this assignment.
	It checks whether a stduent meets the condition.
	You can choose not to use this function.
	Do not modify this function. If you change it, you will get zero.
*/
bool Compare(Student * stu, Condition * condition) {
	if (strcmp(condition -> field, "id") == 0) {
		int id_val = atoi(condition -> val);
		if (strcmp(condition -> optr, "<") == 0) {
			return (stu -> id < id_val);
		} else if (strcmp(condition -> optr, ">") == 0) {
			return (stu -> id > id_val);
		} else if (strcmp(condition -> optr, "=") == 0) {
			return stu -> id == id_val;
		} else if (strcmp(condition -> optr, ">=") == 0) {
			return (stu -> id >= id_val);
		} else if (strcmp(condition -> optr, "<=") == 0) {
			return (stu -> id <= id_val);
		}
	} else if (strcmp(condition -> field, "age") == 0) {
		int age_val = atoi(condition -> val);
		if (strcmp(condition -> optr, "<") == 0) {
			return (stu -> age < age_val);
		} else if (strcmp(condition -> optr, ">") == 0) {
			return (stu -> age > age_val);
		} else if (strcmp(condition -> optr, "=") == 0) {
			return (stu -> age == age_val);
		} else if (strcmp(condition -> optr, ">=") == 0) {
			return (stu -> age >= age_val);
		} else if (strcmp(condition -> optr, "<=") == 0) {
			return (stu -> age <= age_val);
		}
	} else {
		if (strcmp(condition -> field, "name") == 0	) {
			if (strcmp(stu -> name, condition -> val) == 0) {
				return true;	
			}
			return false;	
		} else if (strcmp(condition -> field, "major") == 0 ) {
			if (strcmp(stu -> major, condition -> val) == 0){
				return true;	
			}
			return false;	
		} else if (strcmp(condition -> field, "year") == 0 ) {
			if (strcmp(stu -> year, condition -> val) == 0){
				return true;	
			}
			return false;	
		} else if (strcmp(condition -> field, "enrollment") == 0 ) {
			if (strcmp(stu -> enrollment, condition -> val) == 0){
				return true;	
			}
			return false;	
		}
	} 
	return false;
}
#endif

#ifndef TEST_EXECUTE
/*
	1.This function takes two arguments:
		1. pointer to `StudentDatabase` object.
		2. pointer to `ParseResult` object.	
	2. This function returns a pointer to `ExecuteResult` object.
	3. The `ExecuteResult` object has two fields: First, an array of matched Student's index. Second, length of the array. 
*/
ExecuteResult * ExecuteQuery(StudentDatabase * db, ParseResult * res) {
	ExecuteResult* result=malloc(sizeof(result));
	
	int i=0;
	int j=0;
	int k=0;
	for(i=0;i<db->number;i++){
		while(j<res->condition_num){
			if(Compare(db->students[i],res->conditions[j])==false){
				break;
			}
			j++;	
		}	
		if(j==res->condition_num){
			result->len++;
		//	printf("%d\n",i);
		}
		j=0;
	}
	result->arr=malloc(sizeof(result->arr)*result->len);
	i=0;
	j=0;
	for(i=0;i<db->number;i++){
                while(j<res->condition_num){
                        if(Compare(db->students[i],res->conditions[j])==false){
                                break;
                        }
                        j++;
                }       
                if(j==res->condition_num){
                        result->arr[k]=i;
                       // printf("%d\n",i);
			//printf("%d\n",result->arr[k]);
			k++;
                }
                j=0;
        }
	
	return result;
}
#endif

#ifndef TEST_FREEPARSE
/*
	Free the allocated memory in ParseResult object.
*/
void FreeParseResult(ParseResult * res) {
	int i=0;
	free(res->field);
	for(i=0;i<res->condition_num;i++){
		free(res->conditions[i]);
	}
	free(res->conditions);
	free(res);
}
#endif

#ifndef TEST_FREEEXECUTE
/*
	Free the allocated memory in ExecuteResult object.
*/
void FreeExecuteResult(ExecuteResult * res) {
	free(res->arr);
	free(res);
}
#endif

#ifndef TEST_WRITE

/*
	1. Only write selected fields of students who meet specified conditions to output file.
	2. Print error message "Failed to open file\n" to monitor if the fopen fail. You should not have output file generated if fopen fail. 
	3. Follow this format "field:%s ", or "field:%d ". Add "\n" when you finish writing the selected fileds of a student. Please look at the files in `expected` folder to make sure you understand the format. We will use diff to test. Make sure your output format is correct.
	4. You should write the info of each student in the following order if that fields are selected. id -> name -> major -> year -> enrollment -> age.
	5. The order in selected fields does not affect the order you write to the file.  e.g., `SELECT id name WHERE ...` and `SELECT name id WHERE ...` should have the same output file.  
*/
void WriteDb(StudentDatabase * db, SelectedField * info, ExecuteResult * execute_res, char * filename) {
FILE* fp=fopen(filename,"w");
int i=0;
int j=0;
while(i< db->number){
	if(j==execute_res->len){
		break;
	}
	if(i==execute_res->arr[j]){
		if(info->id==true){
			fprintf(fp,"id:%d ",db->students[i]->id);
		}
		if(info->name==true){
			fprintf(fp,"name:%s ", db -> students[i] -> name);	
		}
		if(info->major==true){
			fprintf(fp,"major:%s ", db -> students[i]-> major);  
		}
		 if(info->year==true){
                        fprintf(fp,"year:%s ", db -> students[i]-> year);
                }
		if(info->enrollment){
			fprintf(fp,"enrollment:%s ", db -> students[i]-> enrollment);
		}  
		if(info->age==true){
			fprintf(fp,"age:%d ", db -> students[i]-> age);  
		}
		j++;
		fprintf(fp,"\n");
	}
	i++;
}
fclose(fp);
}

#endif
