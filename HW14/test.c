#define NUMLETTER 256
#include <stdio.h>
#include <stdlib.h>
#define HUFF_ELEM '#'
typedef struct TreeNode {
    
    unsigned char data;
    
    int freq;
    
    struct TreeNode *left;
    struct TreeNode *right;
    
} TreeNode ;

typedef struct ListNode {
    
    struct ListNode *next;
    
    TreeNode *treeNodePtr;
    
} ListNode;





ListNode * ListNodeCreate(TreeNode * treeNode);


ListNode * ListInsert(ListNode * head, ListNode * listNode);


void CleanList(ListNode *head);

ListNode * BuildHuffmanTree(ListNode *head);

void PrintListBuild(ListNode *head);



typedef struct {
    unsigned char data;
    int freq;
} CharFreq;



int CountFrequency(char * filename, CharFreq * freq);


void SortFrequency(CharFreq * freq);



void PrintSingleHelper(TreeNode *treeNode);

TreeNode * TreeNodeCreate(unsigned char val, int freq);
TreeNode * TreeMerge(TreeNode * treenode1, TreeNode * treenode2);
void PrefixTreePrint(TreeNode *treeNode, int level);
void CleanTree(TreeNode *treeNode);

ListNode * ListNodeCreate(TreeNode * treenode){
    ListNode* ln = malloc(sizeof(ListNode));
    ln -> next = NULL;
    ln -> treeNodePtr = treenode;
    return ln;
}


ListNode * ListBuild(CharFreq * freqArray){
   
    
    int index = 0;
    while(freqArray[index].freq ==0){
        index++;
    }
    if(index == NUMLETTER){
        return NULL;
    }
    
    ListNode * head = NULL;
    /*while(index < NUMLETTER){
        TreeNode* treeNode = TreeNodeCreate(freqArray[index].data,freqArray[index].freq);
        ListNode* ln = ListNodeCreate(treeNode);
        head = ListInsert(head, ln);
        index++; 
	}*/
    return head;
}


ListNode * ListInsert(ListNode * head, ListNode * listNode){
    
    if(head == NULL){
        return listNode;
    }
    if(listNode == NULL){
        return NULL;
    }
    if((listNode-> next) != NULL)
    {
        return NULL;
    }
    int freq1 = (head -> treeNodePtr) -> freq;
    int freq2 = (listNode -> treeNodePtr) -> freq;
    if(freq1 > freq2)
    {
        listNode -> next = head;
        return listNode;
    }
    head-> next = ListInsert(head->next, listNode);
    return head;
    
}


void CleanList(ListNode *head){
    
}

ListNode* pq_dequeue(ListNode* pq){
    ListNode* temp=NULL;
    temp=pq;
    if(pq==NULL){
        return NULL;
    }
    pq=temp->next;
    temp->next=NULL;
    return temp;
}

ListNode * BuildHuffmanTree(ListNode *head){
    
        ListNode* left=NULL;
        ListNode* right=NULL;
        TreeNode* root=NULL;
        while((head)->next!=NULL){
            left=pq_dequeue(head);
            right=pq_dequeue(head);
            root = malloc(sizeof(TreeNode));
            //root->left=left->treeNodePtr;
           // root->right=right->treeNodePtr;
            //root->freq = left->treeNodePtr->freq + right->treeNodePtr->freq;
            root=TreeMerge(left->treeNodePtr,right->treeNodePtr);
            free(left);
            free(right);
        }
    
    PrefixTreePrint(root, 2);
    return NULL;
}



void PrintFreq(CharFreq * charFreqArray);
void PrintSingleCharFreq(CharFreq charfreq);


int CountFrequency(char * filename, CharFreq * freq){
   
    
    FILE* fp = fopen(filename,"r");
    char a='a';
    int i=0;
    int j=0;
    while(i<256){
        for(a=fgetc(fp); a!=EOF; a=fgetc(fp)){
            if(i==a){
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





void SortFrequency(CharFreq * freq){
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
        }
    }
}

            

            void PrintFreq (CharFreq *charFreqArray){
                int i = 0;
                while(i<256){
                    if(charFreqArray[i].freq != 0){
                        PrintSingleCharFreq(charFreqArray[i]);
                    }
                    i++;
                }
            }
            
            
            void PrintSingleCharFreq(CharFreq charfreq){
                printf("char=%c, freq=%d\n",charfreq.data, charfreq.freq );
            }
            

            
            TreeNode * TreeNodeCreate(unsigned char val, int freq)
            {
                
                TreeNode * tree = malloc(sizeof(TreeNode));
                tree -> left = NULL;
                tree -> right = NULL;
                tree -> data = val;
                tree -> freq = freq;
                return tree;
            }


            TreeNode * TreeMerge(TreeNode * treeNode1, TreeNode * treeNode2){
               
                
                TreeNode* tree = malloc(sizeof(tree));
                //if(treeNode1 -> freq < treeNode2 -> freq){
                    tree -> left = treeNode1;
                    tree -> right = treeNode2;
                    tree -> data = 0;
                    tree -> freq = treeNode1 -> freq + treeNode2 -> freq;
               // }
               // else{
                 //   tree -> right = treeNode1;
                   // tree -> left = treeNode2;
                   // tree -> data = 0;
                   // tree -> freq = treeNode1 -> freq + treeNode2 -> freq;
                //}
                
                return tree;
            }


            void PrefixTreePrint(TreeNode *treeNode, int level){
                
                if(treeNode == NULL)
                {
                    return;
                }
                
                TreeNode * lc = treeNode -> left;
                TreeNode * rc = treeNode -> right;
                int i = 0;
                for(i = 0;i<level;i++){
                    PrintSingleHelper(treeNode);
                    PrefixTreePrint(lc,i);
                    PrefixTreePrint(rc,i);
                }
                
                return;
            }
            

            
            void CleanTree(TreeNode *treeNode){
                
            }

            
            

            void PrintSingleHelper(TreeNode *treeNode){
                printf("Char: %c, Freq: %d\n", treeNode->data, treeNode->freq);
            }

            int main(int argc, char **argv){
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
//                PrintFreq(a);
               	ListNode* list = ListBuild(a);
                BuildHuffmanTree(list);
                
                free(a);
                
                return EXIT_SUCCESS;
            }

    

