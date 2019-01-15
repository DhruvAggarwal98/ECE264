#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "pe07.h"




#ifndef INT
bool IsInteger(char* str, int index)
{
	if(index==strlen(str)){
		return true;	
	}
	if(isdigit(str[index])){
		++index;
		return 	IsInteger(str,index);
	}	
	else{
		return false;	
	}
	return false;
}
#endif

#ifndef DOUBLE
bool IsDouble(char* str, int index,bool dot)
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
bool IsValidIdentifier(char* str, int index)
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
