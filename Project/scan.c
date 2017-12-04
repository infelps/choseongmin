#include<stdio.h>
#include<io.h>
#include<string.h>

typedef struct  _FileLoad {
	char name[260];
	int wordNum;
}FileLoad;

int getNumFile(void)
{
	struct _finddata_t fd;

	long handle;
	int result = 0;
	int num = 0;
	int i;

	handle = _findfirst("./*.txt", &fd);

	if (handle == -1)
		return;

	while (result == 0)
	{
		num++;
		result = _findnext(handle, &fd);
	}
	_findclose(handle);
	
	return num;
}

FileLoad* getNameFile(int num){

	struct _finddata_t fd;
	long handle;
	int i;

	FileLoad *pFileopen = malloc(sizeof(FileLoad)*num);

	handle = _findfirst("./*.txt", &fd);

	if (handle == -1)
		return;

	strcpy(pFileopen[0].name, fd.name);

	for (i = 1; i < num; i++)
	{
		_findnext(handle, &fd);
		strcpy(pFileopen[i].name, fd.name);
	}

	_findclose(handle);

	return pFileopen;
}
