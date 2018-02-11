#include "stdafx.h"
#include "ChaTabOperTools.h"
#include <stdlib.h>

int CTCreate(PCHAINTABLE * CT)
{
	if ((*CT = (PCHAINTABLE)malloc(CTSize)) == NULL)
		return -1;
	memset(*CT, 0, CTSize);
	return 0;
}

int CTDestory(PCHAINTABLE * CT)
{
	int i=1;
	PCHAINTABLE pos,last;

	if (CT == NULL)
		return -1;
	pos = (**CT).next;
	free(*CT);
	while (pos == NULL)
	{
		last = pos;
		pos = pos->next;
		free(last);
		i++;
	}
	return i;
}

int CTAppend(PCHAINTABLE * CT, CTDataType data)
{
	if (CT == NULL)
		return -1;
	if ((**CT).next == NULL)
		if (CTCreate(CT))
			return -1;
	(*CT) = (**CT).next;//Forward
	(**CT).data = data;//Assignment
	return 0;
}

int CTDelete(PCHAINTABLE * CT)
{
	PCHAINTABLE nn = NULL;

	if (CT == NULL || (**CT).next == NULL)
		return -1;
	if ((**CT).next->next != NULL)
		nn = (**CT).next->next;
	free((**CT).next);
	(**CT).next = nn;
	return 0;
}

int CTSetPos(PCHAINTABLE * CT, PCHAINTABLE * pos, int n)
{
	int i;

	if (CT == NULL)
		return -1;
	pos = CT;
	for (i = 0; i < n && ((*pos) = (**pos).next) != NULL; i++)
		continue;
	return i;
}

int CTGetLength(PCHAINTABLE * CT)
{
	int i;
	PCHAINTABLE pos;

	if (CT == NULL)
		return -1;
	pos = *CT;
	for (i = 1; (pos = pos->next) != NULL; i++)
		continue;
	return i;
}

int CTArr2CT(CTDataType src[], PCHAINTABLE * dst, int len)
{
	int i;
	PCHAINTABLE pos;

	if (CTCreate(dst))
		return -1;
	pos = (*dst);
	//(**dst).data = *src;
	for (i = 0; i < len; i++)
	{
		pos->data = *(src + i);
		if (i != len - 1)
		{
			if (CTCreate(&(pos->next)))
				return -1;
			pos = pos->next;
		}
	}

	return 0;
}

int CTCT2Arr(PCHAINTABLE * src, CTDataType ** dst, int len)
{
	int i;
	PCHAINTABLE cur = *src;

	if (src == NULL || dst == NULL)
		return -1;
	for (i = 0; i < len; i++)
	{
		*((*dst) + i) = cur->data;
		if (cur->next == NULL)
			break;
		cur = cur->next;
	}
	return i;
}
