#include "list_node.h"

// Create the list node from treenode as input
#ifndef LIST_CREATE
ListNode * ListNodeCreate(TreeNode * treenode){
  ListNode* ln = malloc(sizeof(ListNode));
			ln -> next = NULL;
			ln -> treeNodePtr = treenode;
  return ln;
}

#endif

#ifndef LIST_BUILD
ListNode * ListBuild(CharFreq * freqArray){
  // find the first index with non-zero frequency
  // if all are character have zero freq then return nothing
 
	int index = 0;
	while(freqArray[index].freq ==0){
		index++;
	}
	if(index == NUMLETTER){
		return NULL;
	}
 
	 ListNode * head = NULL;
	while(index < NUMLETTER){
		TreeNode* treeNode = TreeNodeCreate(freqArray[index].data,freqArray[index].freq);
ListNode* ln = ListNodeCreate(treeNode);
head = ListInsert(head, ln);
index++;
return head;
  // build the linked list such that lower frequency comes first and then higher
  
}
}
#endif




#ifndef LIST_INSERT

ListNode * ListInsert(ListNode * head, ListNode * listNode){
  // insert such that lower frequency comes before the already inserted frequency
  // if the frequencies are same for the nodes, then inserted node should come after the compared node
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

#endif

#ifndef LIST_CLEAN

void CleanList(ListNode *head){
  // clean the ListNode
}

#endif

#ifndef HUFFMAN_BUILD
// builds the huffman tree from the linked list
ListNode * BuildHuffmanTree(ListNode *head){
  	
	return NULL;
}

#endif
