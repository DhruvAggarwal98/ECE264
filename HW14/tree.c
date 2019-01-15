#include <stdbool.h>

#include "tree.h"


#ifndef TREE_CREATE

TreeNode * TreeNodeCreate(unsigned char val, int freq)
{
	//creates a tree node from the input and returns the TreeNode *
	// change NULL in return  to the newly created TreeNode *
	TreeNode * tree = malloc(sizeof(TreeNode));	
	tree -> left = NULL;
	tree -> right = NULL;
	tree -> data = val;
	tree -> freq = freq;
	return tree;
}
#endif



#ifndef TREE_MERGE
// Following code merges two treenodes into one treenode and retun the new tree node
TreeNode * TreeMerge(TreeNode * treeNode1, TreeNode * treeNode2){
	// This function merges two TreeNode*s by creating a new TreeNode*. 
	// It uses HUFF_ELEM as `data` for new TreeNode and 
	// sum of the frequencies of two TreeNode*s becomes the value of frequency variable of the new TreeNode\*.
	// smaller of the two frequencies of input TreeNode* should become the left child of this newly created TreeNode.
	// change NULL in return to the newly created TreeNode *

  TreeNode* tree = malloc(sizeof(tree));
  if(treeNode1 -> freq < treeNode2 -> freq){
  tree -> left = treeNode1;
  tree -> right = treeNode2;
  tree -> data = 0;
  tree -> freq = treeNode1 -> freq + treeNode2 -> freq;
  }
  else{
  tree -> right = treeNode1;
  tree -> left = treeNode2;
  tree -> data = 0;
  tree -> freq = treeNode1 -> freq + treeNode2 -> freq;
  }
  
  return tree;
}
#endif


#ifndef TREE_PREFIX_PRINT
// Prefix/Preorder Tree Print
void PrefixTreePrint(TreeNode *treeNode, int level){
  	// Print the tree in Pre-order
	// use PrintSingleHelper function to print the values
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

#endif

#ifndef TREE_CLEAN

void CleanTree(TreeNode *treeNode){
	// Clean the tree
}

#endif
/******************** DO NOT MODIFY THE BELOW HELPER FUNCTION *********************/

#ifndef SOL
void PrintSingleHelper(TreeNode *treeNode){
  printf("Char: %c, Freq: %d\n", treeNode->data, treeNode->freq);
}
#endif
