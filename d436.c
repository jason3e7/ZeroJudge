 /*
  * @file d436.c
  * @author Jason3e7
  * @algorithm backtracking
  * @date 201512031539
  */

#include <stdio.h>
#include <string.h>
#define maxSize 11
#define maxChar 123

int len, charNum[maxChar], ans[maxSize];

void DFS(int count) {
	int i;
	if (count == len) {
		for (i = 0; i < len; i++)
			printf("%c", ans[i]);
		printf("\n");
		return;
	}
	for (i = 48; i < maxChar; i++) {
		if (charNum[i] > 0) {
			charNum[i]--;
			ans[count] = i;
			DFS(count + 1);
			charNum[i]++;
		}
	}	
}

int main() {
	int n, i;
	char temp[maxSize];
	scanf("%d", &n);
	while (n--) {
		scanf("%s", &temp);
		for (i = 0; i < maxChar; i++)
			charNum[i] = 0;
		for (i = 0; i < maxSize; i++)
			ans[i] = '\0';
		
		len = strlen(temp);
		for (i = 0; i < len; i++) 
			charNum[temp[i]]++;
		DFS(0);
		printf("\n");
	}
	return 0;
}
