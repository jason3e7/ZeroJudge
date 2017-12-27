 /*
  * @file b005.c
  * @author Jason3e7
  * @algorithm array
  * @date 201712281159
  */

#include <stdio.h>

int main() {
	int row[100], col[100];
	int n, i, j, temp, rFlag, cFlag;
	while(scanf("%d", &n) != EOF) {
		for(i = 0; i < 100; i++) {
			row[i] = 0;
			col[i] = 0;
		}
		for(i = 0; i < n; i++) {
			for(j = 0; j < n; j++) {
				scanf("%d", &temp);
				row[i] += temp;
				col[j] += temp;
			}
		}
		rFlag = -1, cFlag = -1;
		for(i = 0; i < n; i++) {
			if(row[i] % 2 == 1) {
				if(rFlag == -1) {
					rFlag = i;
				} else {
					rFlag = -2;
				}
			}
			if(col[i] % 2 == 1) {
				if(cFlag == -1) {
					cFlag = i;
				} else {
					cFlag = -2;
				}
			}
		}
		if(rFlag == -1 && cFlag == -1) {
			printf("OK\n");
		} else if(rFlag == -2 || cFlag == -2) {
			printf("Corrupt\n");
		} else {
			printf("Change bit (%d,%d)\n", rFlag + 1, cFlag + 1);
		}
	}
	return 0;
}
