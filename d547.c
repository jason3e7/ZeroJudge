/*
 * @file d547.c
 * @author Jason3e7
 * @date 201510131435
 */

#include <stdio.h>

int abs(int n) {
	if (n < 0)
		return -1 * n;
	return n;
}

int getBool(int a1, int a2, int a3, int ans) {
	if (abs(a3 - a2) > a1 && ans == 1) 
		return 1;
	if (abs(a3 - a2) <= a1 && ans == 0) 
		return 1;
	return 0;
}

int main() {
	int n, m, i, j, ans[100], door[100], flag;
	while(scanf("%d %d", &n, &m) != EOF) {	
		for (i = 0; i < m; i++) 
			scanf("%d", &ans[i]);
		for (i = 0; i < n; i++) {
			for (j = 0; j <= m; j++) {
				scanf("%d", &door[j]);
			}
			flag = 1;
			for (j = 0; j <= (m - 2); j++) {
				if (getBool(door[j], door[j + 1], door[j + 2], ans[j]) == 0) {
					flag = 0;
					break;
				}
			}
			if (getBool(door[m - 1], 0, door[m], ans[m - 1]) == 0) {
				flag = 0;
			}
			if (flag == 1) {
				printf("%d", door[0]);
				for (j = 1; j <= m; j++) {
					printf(" %d", door[j]);
				}
				printf("\n");
			}
		}		
	}
	return 0;
}

/*
	printf("%d %d %d %d \n", a1, a2, a3, ans);
	printf("%d %d %d \n", abs(a3 - a2), a1, ans);
*/
