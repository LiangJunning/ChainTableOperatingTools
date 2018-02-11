// ChainTableOperatingTool.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <assert.h>
#include "ChaTabOperTools.h"


int main()
{
	int lenc;
	const int lena = 5;
	PCHAINTABLE CT;
	CTDataType arrs[] = { 1,2,3,4,5 };
	CTDataType *arrd = new CTDataType[lena];

	assert(!CTCreate(&CT));
	assert(!CTArr2CT(arrs, &CT, 5));
	assert((lenc = CTGetLength(&CT)) != -1);
	assert(CTCT2Arr(&CT, &arrd, lenc) != -1);
	assert(CTDestory(&CT) != lenc);
	puts("arr\ni data");
	for (int i = 0; i < lena; i++)
		printf("%d %d\n", i, *(arrd + i));
	printf("lenc=%d\nCT2arr\ni data\n", lenc);
	for (int i = 0; i < lenc; i++)
		printf("%d %d\n", i, *(arrd + i));
	getchar();
    return 0;
}

