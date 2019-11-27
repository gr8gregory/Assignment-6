/*
 * Testing mainline
 *
 * Copyright 2019 - Caleb Hoeksema, Gregory Huras, Laura
 *
 */

#define _CRT_SECURE_NO_WARNINGS

#include "treefunc.h"
#include "treefunc.h"
#include "message.h"
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <time.h>
#include "Hash.h"

int main(void) {

	BSTInit();					// Initialize the BST and the root
	Item* p = NULL;				// Pointer to an item
	int i, userIN;				// For loop, number of BST nodes
	char buffer[2];
	int fileCount;				// number of quotes in the file
	long int* fileIndices;		// array holding quote offsets
	int* quoteLen;				// array holding quote lengths
	int quote;					// error code for GetMessageFromFile
	Item found;					// used to search for a specific message
	char HashTable[NUMNODES];

	int iMsgList[NUMNODES];				// message list array
	int iHashTab[HASHVAL];					// hash table


	/*
	// User input
	printf("Input number of nodes to put in the tree:");
	while (scanf("%d", &userIN) != 1) {
		printf("\nPlease enter an integer");
		while (getchar() != '\n');
	}
	*/


	// Setup for getting quotes
	fileCount = fnumQuotes();					// Count quotes 
	fileIndices = fquoteIndices(fileCount);				// Stores quote locations
	quoteLen = fquoteLength(fileCount, fileIndices);		// Finds the quote lengths up to 140	
	srand(time(NULL));

	// Fill the BST with random quotes
	for (i = 0; i < NUMNODES; i++) {
		p = (Item*)malloc(sizeof(Item));
		quote = GetMessageFromFile(p->buff, 140, frandNum(1, fileCount), fileCount, fileIndices, quoteLen);
		p->Hash = HashKey(p->buff, 29);
		HashTable[i] = p->Hash;
		
		HashColl(i, p->Hash, iMsgList, iHashTab);

		Insert(*p);						// Creates a node with the message quote as the buffer
	}

	// Print the BST Inorder
	//printf("\nPrinting the BST Inorder************************************\n");
	//BSTPrint(getRoot());		// Passes in a pointer to the root node and prints the nodes of the tree in order


	TestHash(HashTable);


	//printf("\nThe total number of nodes in the tree is: %d\n", count(getRoot()) - 1);// Counts the number of nodes in the tree
	//printf("\nThe total height of the tree is: %d\n", height(getRoot()));		 // Counts the left and right child tree seperatly and prints the greatest lenght
	/*
	printf("\nSearching the BST for the last inserted item**************\n");
	found = Search(p->buff);							 // p.buff is pointing at the last item in the message list
											 // It is searching the tree to find the last node (p.buff)
	if (found.buff) printf("\nThe last inserted item is: %s\n", found.buff);	 // found is a pointer to the node of the last item, .buff is the char attached to the node
	else printf("\nItem not found - Error\n");

	system("pause");
	*/
	free(getRoot());								// Free nodes in tree.
}
