/*
	TreeFunction.h - Headerfile that contains the function prototypes for a BST

	Copyright: 2019 Gregory Huras
*/

#pragma once
#include "TreeNode.h"

// Function Prototypes
link NEW(Item, link left, link right);		// Creates a new BST Node
void BSTInit(void);							// Initialize a BST
Item BSTSearch(link h, char* szSearchKey);	// Private Search function called by 'Search()'
Item Search(char* szKey);					// Public search Function
link BSTInsert(link h, Item item);			// Private Insert Function called by 'Insert()'
void Insert(Item item);						// Public Insert function - inserts into a node
void BSTPrint(link h);						// Private print function called by print()
int height(link h);							// Returns the height of th BST
int count(link h);							// Returns number of nodes in the BST
link getRoot(void);							// Returns a pointer to the root of the BST