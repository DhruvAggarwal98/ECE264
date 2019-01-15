#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 100 //The maximum length of string

typedef enum { false=0, true } bool;
bool IsInteger(char* str, int index);
bool IsDouble(char* str, int index,bool dot);
bool IsValidIdentifier(char* str, int index);



#ifndef INT
bool IsInteger(char* str, int index) //function will return true if integer and false if anything else
{
    if(index==strlen(str)){
        return true;
    }
    if(isdigit(str[index])){
        ++index;
        return     IsInteger(str,index);
    }
    else{
        return false;
    }
    return false;
}
#endif

#ifndef DOUBLE
bool IsDouble(char* str, int index,bool dot) //function will return true if double and false if anything else
{
    if(index==strlen(str)){
        if(dot==true){
            return true;
        }
        else{
            return false;
        }
    }
    if(isdigit(str[index])){
        ++index;
        return  IsDouble(str,index,dot);
    }
    if(ispunct(str[index])){
        if(str[index]=='.'){
            if(index-1<0){
                return false;
            }
            if(index+1==strlen(str)){
                return false;
            }
            if(dot==false){
                dot=true;
                index++;
                return IsDouble(str,index,dot);
            }
            if(dot==true){
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
    return false;
}
#endif

#ifndef VALIDID
bool IsValidIdentifier(char* str, int index) //function will return true if valid identifier
{
    if(strlen(str)==index){
        return true;
    }
    if(index==0){
        if(isalpha(str[0])||str[0]=='_'){
            index++;
            return IsValidIdentifier(str,index);
        }
        else{
            return false;
        }
    }
    if(isalnum(str[index])||str[index]=='_'){
        ++index;
        return IsValidIdentifier(str,index);
    }
    else{
        return false;
    }
    return false;
}
#endif
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



