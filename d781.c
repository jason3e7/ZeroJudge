 /*
  * @file d781.c
  * @author Jason3e7
  * @algorithm backtracking
  * @date 201512021044
  */

#include <stdio.h>
#include <string.h>
#define max 1000

int len, charNum[53], ans[max];

char getChar(int n) {
	if (n % 2 == 0)
		return (n / 2) + 'A';
	return ((n - 1) / 2) + 'a';	
}

void DFS(int count) {
	int i;
	if (count == len) {
		for (i = 0; i < len; i++)
			printf("%c", ans[i]);
		printf("\n");
		return;
	}
	for (i = 0; i < 53; i++) {
		if (charNum[i] > 0) {
			charNum[i]--;
			ans[count] = getChar(i);
			DFS(count + 1);
			charNum[i]++;
		}
	}	
}

int main() {
	int n, i;
	char temp[max];
	scanf("%d", &n);
	while (n--) {
		scanf("%s", &temp);
		for (i = 0; i < 53; i++)
			charNum[i] = 0;
		for (i = 0; i < max; i++)
			ans[i] = '\0';
		
		len = strlen(temp);
		for (i = 0; i < len; i++) { 
			if ('A' <= temp[i] && temp[i] <= 'Z')
				charNum[ ((temp[i] - 'A') * 2) ]++;
			else if ('a' <= temp[i] && temp[i] <= 'z')
				charNum[ (((temp[i] - 'a') * 2) + 1) ]++;
		}
		DFS(0);
	}
	return 0;
}
