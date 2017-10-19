 /*
  * @file a528.c
  * @author Jason3e7
  * @algorithm string
  * @date 201710200918
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

int main() {
	char number[1001][105];
	int n, i, j;
	while(scanf("%d", &n) != EOF) {
		for(i = 0; i < n; i++) {
			scanf("%s", number[i]);
		}
		for(i = 1; i < n; i++) {
			for(j = 0; j < (n - i); j++) {
				if(cmp(number[j], number[j + 1]) == 1) {
					swap(number[j], number[j + 1]);
				}
			}
		}
		for(i = 0; i < n; i++) {
			printf("%s\n", number[i]);
		}
	}
	return 0;
}



