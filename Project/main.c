#include<stdio.h>
#include<io.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef struct  _FileLoad {
	char name[260];
	int wordNum;
}FileLoad;

int getWordNum(char* filaName,char* keyword,int wordlength);
int getNumFile();
FileLoad *getNameFile(int num);
int comparesize(void* a, void* b);

void main()
{
	clock_t start = clock();
	int num;
	int *arr;
	int i;
	int size;
	char keyword[100];
	int wordSize;
	FILE *fp;

	num = getNumFile();
	FileLoad* pFileName;
	pFileName = getNameFile(num);

	scanf("%s", keyword);
	wordSize = strlen(keyword);

	for (i = 0; i < num; i++) {
		pFileName[i].wordNum = getWordNum(pFileName[i].name,keyword,wordSize);
	}

	qsort(pFileName, num, sizeof(FileLoad), comparesize);

	for (i = 0; i < num; i++) {
		if(pFileName[i].wordNum>0)
		printf("%s, %d\n", pFileName[i].name, pFileName[i].wordNum);
	}

	free(pFileName);
	return 0;
}

int comparesize(void* a, void* b)
{
	FileLoad* ptr_a = (FileLoad*)a;
	FileLoad* ptr_b = (FileLoad*)b;

	if (ptr_a->wordNum < ptr_b->wordNum)
		return 1;
	else if (ptr_a->wordNum == ptr_b->wordNum)
		return 0;
	else return -1;
}