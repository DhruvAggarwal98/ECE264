#include "frequency.h"

// Counting the frequencies of the characters in the frequency table
int CountFrequency(char * filename, CharFreq * freq){
	// open the file
	// get through each element of the file and get each character
	// read each character from the file
	// put the value in the freq table except for the newline character i.e '\n'
	// close the file and return success
	FILE* fp = fopen(filename,"r");
	char a='a';
	int i=0;
	int j=0;
	while(i<256){
		for(a=fgetc(fp);a!=EOF;a=fgetc(fp)){
			if(i==a&&a!='\n'){
				j+=1;
				freq[i].freq=j;
				freq[i].data=i;
				
			}
		}	
		
		fseek(fp,0,SEEK_SET);
		i++;
		j=0;
		
	}
	fclose(fp);
	return EXIT_SUCCESS;
}


// Print statement for the print the frequency table
void PrintFreq (CharFreq *charFreqArray){
int i = 0;
	while(i<256){
	if(charFreqArray[i].freq != 0){
	PrintSingleCharFreq(charFreqArray[i]);
	}
	i++;
}
}


// Sort function for sorting frequencies
void SortFrequency(CharFreq * freq){
	// sort the frequencies in the ascending order
	// if frequencies are same then the character with lower ascii value will be first
	CharFreq *temp=malloc(sizeof(temp));
	int i=0;
	int j=0;
	int h=0;
	while(i<256){
		if(freq[i].freq==0){
			h++;
		}
		
		i++;
	}

	for (i = 0; i < h-1; i++) {     
 		for (j = 0; j < h-i-1; j++) {
                    	if (freq[j].freq > freq[j+1].freq){
                         	temp[0]=freq[j];
				freq[j]=freq[j+1];
				freq[j+1]=temp[0];
			}
		}
       }
	free(temp);
}

void PrintSingleCharFreq(CharFreq charfreq){
	printf("char=%c, freq=%d\n",charfreq.data, charfreq.freq );
}
