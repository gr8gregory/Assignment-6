/*
 * HashCollision.cpp - file that contains functions handling collisions in a hash table
 *
 * Copyright 2019 - Caleb Hoeksema, Gregory Huras, Laura
 *
 */

#include "Hash.h"
#include <stdio.h>

/* 
 * int HashColl(int msg, int hashKey, int *iMsgList, int *iHashTab);
 * 
 * This function deals with collisions in a hash table by
 * creating a secondary array.
 *
 * Input:	int msg: number of the message to add to the hash table
 *			int hashKey: value the message hashed to
 *			int *iMsgList: secondary array for overflow
 *			int *iHashTab: hash table
 * Output:	0: indicates proper functionality
 */

int HashColl(int msg, int hashKey, int *iMsgList, int *iHashTab) {

	if (msg == 0) {
		HashCollInit(iMsgList, iHashTab);	// set the contents of the array	
	}

	if (iHashTab[hashKey] == -1) {
		iHashTab[hashKey] = msg;			// if unused, write the message number to the hash table
	}
	else {
		iMsgList[msg] = iHashTab[hashKey];	// write the past message number to the overflow
		iHashTab[hashKey] = msg;			// write the current message to the hash table
	}
	
	if (msg == NUMNODES-1) {
		HashCollEnd(iMsgList, iHashTab);	// print the results of the hash
	}

	return(0);
}


/*
 * int HashCollInit(int *MsgList, int *iHashTab);
 *
 * This function initializes the hash table and overflow array
 * for dealing with hash collisions.
 *
 * Input:	int *iMsgList: secondary overflow array
 *			int *iHashTab: hash table
 * Output:	0: indicates proper functionality
 */

int HashCollInit(int *iMsgList, int *iHashTab) {

	int* charp = iMsgList;					// useful character pointer
	int i = 0;								// loop counter

	// Initialize the arrays
	for (i = 0; i < NUMNODES; i++) {
		*charp++ = -1;						// "-1" indicates unused
	}
	charp = iHashTab;
	for (i = 0; i < HASHVAL; i++) {
		*charp++ = -1;
	}

	return(0);
}


/*
 * int HashCollEnd(int *MsgList, int *iHashTab);
 *
 * This function prints the contents of the hash table 
 * and overflow array so the programmer knows what hashed
 * to where.
 *
 * Input:	int *iMsgList: secondary overflow array
 *			int *iHashTab: hash table
 * Output:	0: indicates proper functionality
 */

int HashCollEnd(int* iMsgList, int* iHashTab) {

	int i = 0;								// Loop counter
	int value;								// intermediate value for dealing with indices

	for (i = 0; i < HASHVAL; i++) {

		value = iHashTab[i];				// store the current hash value

		if (value == -1) {
			printf("Hash Key %d: Unused\n", i);
		}
		else  {								// The hash key was used
			printf("Hash Key %d: Message Numbers:", i);
			while (value != -1) {
				printf(" %d", value);		// Print the message number
				value = iMsgList[value];
			}
			printf("\n");
		}
	}

	return(0);
}
