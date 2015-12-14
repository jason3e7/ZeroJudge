/*
 * @file d279.c
 * @author Jason3e7
 * @algorithm enumeration
 * @date 201512141010
 */

//backtracking !?

#include <stdio.h>

int n, map[101][101], ans[101], count;

void setAns(int begin) {
	int i;
	for (i = 1; i <= n; i++) {
		if (map[begin][i] == 1 && ans[i] == 0) {
			count++;
			ans[i] = 1;
			setAns(i);
		}
	}
}

int main() {
	int beginP, endP, testNum, ansP;
	while(scanf("%d", &n) != EOF) {	
		int i, j;
		if (n == 0)
			break;
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				map[i][j] = 0;

		while(scanf("%d", &beginP)) {	
			if (beginP == 0)
				break;
			while(scanf("%d", &endP)) {	
				if (endP == 0)
					break;
				map[beginP][endP] = 1;
			}
		}

		scanf("%d", &testNum);
		while(testNum--) {
			scanf("%d", &ansP);
			for (i = 1; i <= n; i++)
				ans[i] = 0;
			count = 0;
			setAns(ansP);
			printf("%d", n - count);
			for (i = 1; i <= n; i++)
				if (ans[i] == 0)
					printf(" %d", i);
			printf("\n");
		}
	}
	return 0;
}

