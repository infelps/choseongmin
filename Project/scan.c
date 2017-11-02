#include<stdio.h>
#include<io.h>

int scan(void)
{
	struct _finddata_t fd;
	long handle;
	int result = 1;
	int num = 0;

	handle = _findfirst("./*.txt", &fd);
	if (handle == -1)
		return;
	while (result != -1)
	{
		num++;
		result = _findnext(handle, &fd);
	}

	return num;
	_findclose(handle);	

}