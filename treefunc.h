/*
 * treefunc.h - Header file (Interface) that contains the function prototypes for a BST
 *
 * Copyright 2019 - Caleb Hoeksema, Gregory Huras, Laura
 *
 */

#pragma once

#include "treenode.h"

// Function Prototypes
link NEW(Item item, link left, link right);		// Creates a new BST node
void BSTInit(void);								// Initialises a BST
Item BSTSearch(link h, char* szSearchKey);		// Private search function called by "Search()"
Item Search(char* szKey);						// Public search function
link BSTInsert(link h, Item item);				// Private insert function called by "Insert()"
void Insert(Item item);							// Public insert function
void BSTPrint(link h);							// Private print function 
int height(link h);								// Returns the height of the BST
int count(link h);								// Returns number of nodes in the BST
link getRoot(void);								// Returns a pointer to the root of the BST

