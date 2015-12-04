 /*
  * @file a469.c
  * @author Jason3e7
  * @algorithm backtracking
  * @date 201512040937
  */

#include <stdio.h>
#include <string.h>
#define maxSize 11

int len, ans[maxSize][maxSize];
char str[maxSize];

void DFS(int next) {
	int i, j;
	if (next == len) {
		for (i = 0; i < len; i++)
			printf("%c", str[ans[next - 1][i]]);
		printf("\n");
		return;
	}
	
	for (i = 0; i <= next; i++) {
		for (j = 0; j < next; j++) {
			if (j < i)
				ans[next][j] = ans[next - 1][j];
			else
				ans[next][j + 1] = ans[next - 1][j];
		}	
		ans[next][i] = next;
		DFS(next + 1);
	}
	return;
}

int main() {
	int i, j, flag = 0;
	char temp;
	while (scanf("%s", &str) != EOF) {
		if (flag == 1)
			printf("\n");
		for (i = 0; i < maxSize; i++) 
			for (j = 0; j < maxSize; j++) 
				ans[i][j] = 0;
		len = strlen(str);
		ans[0][0] = 0;
		DFS(1);
		flag = 1;
	}
	return 0;
}
