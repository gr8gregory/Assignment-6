#pragma once

int HashKey(char* v, int M);
int TestHash(char* v);
int HashColl(int msg, int hashKey, int* iMsgList, int* iHashTab);
int HashCollInit(int* iMsgList, int* iHashTab);
int HashCollEnd(int* iMsgList, int* iHashTab);

#define		NUMNODES	110
#define		HASHVAL		29