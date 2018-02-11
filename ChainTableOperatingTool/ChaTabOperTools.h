#pragma once

#define CTDataType int
#define CTSize sizeof(CHAINTABLE)

typedef struct CHAINTABLE_tag {
	CTDataType data;
	struct CHAINTABLE_tag *next;
}CHAINTABLE,*PCHAINTABLE;

//Basic

//Create a thain table node.
int CTCreate(PCHAINTABLE *CT);

//Destory whole chain table.
int CTDestory(PCHAINTABLE *CT);

//Append data in a new node.
int CTAppend(PCHAINTABLE *CT, CTDataType data);

//Delete NEXT node.
int CTDelete(PCHAINTABLE *CT);

//Set position in chain table.
int CTSetPos(PCHAINTABLE *CT, PCHAINTABLE *pos, int n);

//Get length of chain table.
int CTGetLength(PCHAINTABLE *CT);


//Extended

//Array to Chain Table
int CTArr2CT(CTDataType src[], PCHAINTABLE *dst, int len);

//Chain Table to Array
int CTCT2Arr(PCHAINTABLE *src, CTDataType **dst, int len);