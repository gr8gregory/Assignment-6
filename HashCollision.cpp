/*
 * HashCollision.cpp - file that contains functions handling collisions in a hash table
 *
 * Copyright 2019 - Caleb Hoeksema, Gregory Huras, Laura
 *
 */

#include "Hash.h"
#include <stdio.h>

/* 
 * int HashColl(int msg, int hashKey);
 * 
 * This function deals with collisions in a hash table by
 * creating a secondary array.
 *
 * Input:	int msg: number of the message to add to the hash table
 *			int hashKey: value the message hashed to
 * Output:	0: indicates proper functionality
 */

int HashColl(int msg, int hashKey, int *iMsgList, int *iHashTab) {

	if (msg == 0) {
		HashCollInit(iMsgList, iHashTab);
	}

	if (iHashTab[hashKey] == -1) {
		iHashTab[hashKey] = msg;
	}
	else {
		iMsgList[msg] = iHashTab[hashKey];
		iHashTab[hashKey] = msg;
	}
	
	if (msg == NUMNODES-1) {
		HashCollEnd(iMsgList, iHashTab);
	}

	return(0);
}




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

int HashCollEnd(int* iMsgList, int* iHashTab) {

	int i = 0;								// Loop counter
	int value;

	for (i = 0; i < HASHVAL; i++) {

		value = iHashTab[i];				// Reset the thing

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
