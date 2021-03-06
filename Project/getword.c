#include<stdio.h>
#include<io.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<ctype.h>

typedef struct  _FileLoad {
	char name[260];
	int wordNum;
}FileLoad;

int getWordNum(char* fileName,char* keyword,int wordlength)
{
	int size;
	char* str;
	char* foundstr;
	int num = 0;
	
	FILE* fp = fopen(fileName, "r");
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	str = (char *)malloc(sizeof(char)*(size + 1));

	fread(str, sizeof(char), size, fp);
	str[size] = NULL;
	fclose(fp);
	strlwr(str);
	

	foundstr = strstr(str, keyword);

	while (foundstr != NULL) {
		num+=10;
		if (foundstr != str) {
			if (isalpha((int)*(foundstr - 1)) == 0)
				num += 3;
		}
		else
			num += 3;
		if (foundstr != NULL) {
			if (isalpha((int)*(foundstr + wordlength)) == 0)
				num += 3;
		}
		foundstr += wordlength;
		foundstr = strstr(foundstr, keyword);
	}
	
	return num;
}