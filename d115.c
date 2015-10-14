/*
 * @file d115.c
 * @author Jason3e7
 * @date 201510141209
 * @algorithm sort, backtracking
 */

#include <stdio.h>

int num[101], ans[101], used[101], m, n; 

void printAll(int digit, int begin) {
	int i;
	if (digit == m) {
		printf("%d", ans[0]);	
		for (i = 1; i < m; i++) {
			printf(" %d", ans[i]);	
		}
		printf("\n");
		return ;
	}
	for (i = begin; i < n; i++) {
		if (used[i] != 1) {
			ans[digit] = num[i];
			used[i] = 1;
			printAll(digit + 1, i);
			used[i] = 0;
		}
	}
}

int main() {
	int i, j, temp;
	while(scanf("%d", &n) != EOF) {
		if (n == 0)
			break;
		for (i = 0; i < n; i++) 
			scanf("%d", &num[i]);
		scanf("%d", &m);
		for (i = 0; i < n; i++) {
			for (j = 0; j < (n - 1 - i); j++) {
				if (num[j] > num[j + 1]) {
					temp = num[j];
					num[j] = num[j + 1];
					num[j + 1] = temp;
				}
			}
		}
		for (i = 0; i < n; i++)
			used[i] = 0;
		printAll(0, 0);
		printf("\n");
	}
	return 0;
}

/*
	for (i = 0; i < n; i++) { 
		printf(" %d ", num[i]);
	}
*/
