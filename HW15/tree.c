#include "tree.h"

#ifndef USIGN_TO_BIN
// function to create binary values from the input char values
char * UnSig2Bin(unsigned char value) {
	// determine the number of bits needed ("sizeof" returns bytes)
	// create mask which you would use for the getting each bit value
	// for loop to mast values and creating char array of bits
	int i=0;
	char* tmp=malloc(sizeof(char)*NUM_BITS);
	unsigned char mask=0x80;
	for(i=0;i<NUM_BITS;i++){
		if((mask&value)==mask){
			tmp[i]='1';
		}
		else{
			tmp[i]='0';
		}
		mask=mask>>1;
	}
	return tmp;
}
#endif

#ifndef WRITE_BINARY

// WriteInOrderBinary takes root and file * as input
// and creates binary representation of the tree as specified in the example
int WritePreOrderBinary(TreeNode * root, FILE *outptr){
	char a[2]={'0','1'};	
	if(root == NULL)
	{ 
		return EXIT_SUCCESS;
	}
	if(root->leftChild==NULL&&root->rightChild==NULL){
		fwrite(&a[1],1,1,outptr);
		fwrite(UnSig2Bin(root->data),sizeof(char),8,outptr);
	}
	else{
		fwrite(&a[0],1,1,outptr);
	}
	WritePreOrderBinary(root->leftChild, outptr);
	WritePreOrderBinary(root->rightChild, outptr);

	/*
	   if(root->leftChild!=NULL){
	   fwrite(&a[0],1,1,outptr);
	   WritePreOrderBinary(root->leftChild, outptr);
	   }
	   if(root->rightChild!=NULL){
	   fwrite(&a[0],1,sizeof(char),outptr);

	   WritePreOrderBinary(root->rightChild, outptr);
	   }*/
	return EXIT_SUCCESS;
}

int CreateBinaryFromTree(TreeNode * root, const char *outfile){
	FILE* output = fopen(outfile,"wb");  
	FILE* fp=tmpfile();
	if(output == NULL){
		return EXIT_FAILURE;
	}
	if(fp == NULL) 
	{
	return EXIT_FAILURE;
	}
	
	WritePreOrderBinary(root,fp);
	char stop = '0';
	fwrite(&stop,1,1,fp);
	int stop2 = fseek(fp,0,SEEK_SET);
	if(stop2 == 1)
	{
		fclose(output);
		return EXIT_FAILURE;
	}
	int i = fgetc(fp);
	int j = 0;
	int z = 0;
	int k = 0;
	char one = '1';
	int actual = 1;
	int fake = 0;
	unsigned char a = 0x80;
	unsigned char masks = a;
	while(i!= EOF){
		if(i == one){
			j = j | (masks >> z);
			z++;
			for(k = fake; k < NUM_BITS; k++){
				i = fgetc(fp);
				if(z == NUM_BITS)
				{
					fwrite(&j,actual,actual,output);
					z = fake;
					j =fake;
				}
				if(i == one){
					j = j |(masks >> z);
					z ++;
				}
				else
					z++;
			}
		}
		else
			z++;
		if(z == NUM_BITS)
		{
			fwrite(&j,actual,actual,output);
			j = fake;
			z = fake;
		}
		i = fgetc(fp);
	}
	fwrite(&j,actual,actual,output);
	fclose(fp);
	fclose(output);
	return EXIT_SUCCESS;
}


#endif





#ifndef CLEAN_TREE

void CleanTree(TreeNode * root){
	if (root== NULL){
		return ;

	}
	CleanTree(root -> leftChild);
	CleanTree(root-> rightChild);

	free(root);


}
#endif





#ifndef BINARY_SEARCH_TREE

int IntCompare(const void * val1, const void * val2){
	return (*(unsigned char*)val1 - *(unsigned char*)val2);
}

TreeNode * CreateBinarySearchTree(long randomSeed, long numNodes){
	unsigned char * binArray = malloc(sizeof(unsigned char)*numNodes);
	if(binArray == NULL){
		printf("Memory allocation to array failed\n" );
		return NULL;
	}
	srand(randomSeed);
	// allocate values to array
	for(int index = 0; index < numNodes ; index++){
		binArray[index] = rand() % 256;
	}
	// sort the array
	qsort(binArray, numNodes, sizeof(unsigned char), IntCompare);

	// create bst from the sorted array
	TreeNode * root = CreateBST(binArray, 0, numNodes-1);
	free(binArray);
	return root;

}
// TreeNode *CreateBSTHelper()
TreeNode* CreateTreeNode(unsigned char value){
	TreeNode *newNode = malloc(sizeof(TreeNode));
	newNode->data = value;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	return newNode;
}

TreeNode *CreateBST(unsigned char *sortedArray, int start , int end){
	// int len = sizeof(sortedArray)/sizeof(int);
	if(start > end) return NULL;
	int mid = (start+end)/2;
	TreeNode *newNode = CreateTreeNode(sortedArray[mid]);
	newNode->leftChild = CreateBST(sortedArray, start, mid -1);
	newNode->rightChild = CreateBST(sortedArray, mid +1, end);
	return newNode;

}
#endif
