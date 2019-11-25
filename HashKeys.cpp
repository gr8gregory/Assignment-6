#include "TreeNode.h"
#include "TreeFn.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "Hash.h"

int HashKey(char *v, int M) {

	int h, a = 31415, b = 27183;
	for (h = 0; *v != '\0'; v++) {
		a = (a * b) % (M - 1);   // base changes randomly (via a)
		h = (h * a + *v) % M;
	}
	return h;
}

/************ This Tests the duplicate hash numbers **************/
int TestHash(char *v) {
	int counter = 0, var = 0;
	char Test[31];
	for (int i = 0; i < 29; i++) {
		Test[i] = '\0';
	}

	for (int i = 0; i < NUMNODES; i++) {
		var = v[i];
		if (Test[var] != NULL) {
			counter = Test[var];
			counter++;
			Test[var] = counter;

		}
		else{
			Test[var] = 1;
		}
	}

	for (int i = 0; i < 29; i++) {

		printf("\nNumber of Hash repeats for %d is: %d\n", i, Test[i]);
	}
	return(0);

}