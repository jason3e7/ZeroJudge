/*
 * @file d573.c
 * @author Jason3e7
 * @date 201510051756
 */

#include <stdio.h>

int main() {
	int n, i, j, nTeam[100001], teamNum, memNum, locate, q;
	while(scanf("%d", &n) != EOF) {
		for (i = 0; i < n; i++) {
			scanf("%d", &teamNum);
			scanf("%d", &memNum);
			for (j = 0; j < memNum; j++) {
				scanf("%d", &locate);
				nTeam[locate] = teamNum;
			}
		}
		scanf("%d", &q);
		printf("%d\n", nTeam[q]);
	}
	return 0;
}

/*
		for (i = 1; i < 17; i++) {
			printf("%d ", nTeam[i]);
		}
*/
