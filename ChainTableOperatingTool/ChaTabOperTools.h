#pragma once

#define CTDateType int

typedef struct CHAINTABLE_tag {
	CTDateType data;
	struct CHAINTABLE_tag *next;
}CHAINTABLE;

int CTCreate(CHAINTABLE **CT);
int CTDestory(CHAINTABLE **CT);
int CTAppend(CHAINTABLE **CT, CTDateType data);
int CTDelete(CHAINTABLE **CT);
int CTSetPos(CHAINTABLE **CT, CHAINTABLE *pos, int n);
int CTGetLength(CHAINTABLE **CT);