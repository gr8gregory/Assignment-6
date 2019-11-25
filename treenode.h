/* 
 * treenode.h - Header file that contains the node structure of a BST
 *
 * Copyright 2019 - Caleb Hoeksema, Gregory Huras, Laura
 *
 */

#pragma once

const int iLength = 140;

// Define the structure of nodes in a BST
typedef struct item Item;
typedef struct BSTNode* link;
typedef BSTNode Node;

// Define the Item - content of BST Nodes
struct item {
	char buff[iLength];			// Some message
	int Hash;					// sender ID
	int rid;					// user ID
	int priority;				// Priority of message
	int seqNum;
	char infoArray[15];			// useful in the project
};

struct BSTNode {
	Item msg;					// msg.buff contains the quote and other information
	link pLeft;					// Left subtree
	link pRight;				// Right subtree
};

