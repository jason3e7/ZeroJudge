 /*
  * @file stringfunction.c
  * @author Jason3e7
  * @algorithm string and bignumber
  * @date 201710201018
  */

#include <stdio.h>
#include <string.h>

int cmp(char* a, char* b) {
	int aLen, bLen, i, flag = 1;
	if(a[0] != '-' && b[0] == '-') {
		return 1;
	}
	if(a[0] == '-' && b[0] != '-') {
		return -1;
	}
	if(a[0] == '-' && b[0] == '-') {
		flag = -1;
	}
	aLen = strlen(a);
	bLen = strlen(b);
	if(aLen > bLen) {
		return flag;
	}
	if(bLen > aLen) {
		return (flag * -1);
	}
	for(i = 0; i < aLen; i++) {
		if(a[i] > b[i]) {
			return flag;
		}
		if(b[i] > a[i]) {
			return (flag * -1);
		}
	}
	return 0;
}

void swap(char *str1, char *str2) {
	char temp[105];
	strncpy(temp, str1, 105);
	strncpy(str1, str2, 105);
	strncpy(str2, temp, 105);
}

char* strrev(char* str)  {  
    char* begin = str;      
    char* end = str + strlen(str) - 1;  
    char swap;  
  
    while(begin < end) {
        swap = *begin;  
        *begin++ = *end;
        *end-- = swap;
    }   
    return str;  
} 

int main() {
	char a[105], b[105];
	while(scanf("%s %s", a, b) != EOF) {
		printf("%d\n", cmp(a, b)); 
		swap(a, b);
		printf("%s %s\n", a, b);
		printf("%s\n", strrev(a));
	}
	return 0;
}



