/*
 * treefunc.cpp - Implementation of the BST functions
 *
 * Copyright 2019 - Caleb Hoeksema, Gregory Huras, Laura
 *
 */

#include "treenode.h"
#include "treefunc.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

 // Private Variables
static link root;								// Root of the BST
static Item NullItem{ "NOT FOUND - NULL (LEAF) REACHED" };	// Indicates searched message has not been found in the BST

// Function Implementations

// Creates a new BST node
link NEW(Item item, link left, link right) {
	link pNew = (link)malloc(sizeof(Node));
	pNew->msg = item;
	pNew->pLeft = left;
	pNew->pRight = right;
	return(pNew);
}

//Initiailes a BST
void BSTInit(void) {
	root = NEW(NullItem, NULL, NULL);
}

// Private search function called by "Search()"
Item BSTSearch(link h, char* szSearchKey) {
	int rc;
	if (h == NULL) return(NullItem);				// Reached the leaf node and didn't find szSearchKey
	rc = strcmp(szSearchKey, h->msg.buff);
	if (rc == 0) return(h->msg);					// Found message in the BST

	// Recursive calls to go left or right depending on rc
	if (rc < 0) return(BSTSearch(h->pLeft, szSearchKey));		// Go left if it is less
	else		return(BSTSearch(h->pRight, szSearchKey));		// Go right if it is greater
}

// Public search function
Item Search(char* szKey) {

	return(BSTSearch(root, szKey));
}

// Private insert function called by "Insert()"
link BSTInsert(link h, Item item) {
	int rc;
	if (h == NULL) return(NEW(item, NULL, NULL));				// find the leaf and then add
	rc = item.Hash - h->msg.Hash;						// Will never be zero (we are inserting)

	// Recursive calls to go left or right depending on rc
	if (rc < 0) {
		h->pLeft = BSTInsert(h->pLeft, item);					// Go left if it is less
	}
	else {
		h->pRight = BSTInsert(h->pRight, item);					// Go right if it is greater
	}
	return(h);									// Return pointer back up to parent node
}

// Public insert function
void Insert(Item item) {
	root = BSTInsert(root, item);		// Saves location in memory and saves the buffer to an item.
}

// Private print function
void BSTPrint(link h) {
	if (h == NULL) return;			// Reached a leaf node

	// Recursive calls for Inorder traversal
	BSTPrint(h->pLeft);			// Traverse the h pointer in child tree left until reaches leaf node.
	printf("\nKey: % d\n", h->msg.Hash);	// Prints the node the pointer is currently on
	BSTPrint(h->pRight);			// traverses right until the h pointer reaches leaf node. 
}

// Returns the height of the BST
int height(link h) {
	int iLeftH, iRightH;

	//Termination Condition
	if (h == NULL) return -1;

	//Recursive calls
	iLeftH = height(h->pLeft);			// Counts the number of nodes on the left child tree
	iRightH = height(h->pRight);			// Counts the number of nodes on the right child tree
	if (iLeftH > iRightH) return (iLeftH + 1);	// Compares and prints the largest child tree.
	else return(iRightH + 1);
}

// Returns number of nodes in the BST
int count(link h) {
	if (h == NULL) return (0);				// terminal case

	//Recursive Calls
	return (count(h->pLeft) + count(h->pRight) + 1);	// Traverses and counts child tree left until it reaches leaf node,
								// then traverses right until it reaches child right node
}

// Returns a pointer to the root of the BST
link getRoot(void) {
	return root; 	// Returns root pointer
}

