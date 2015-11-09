/*
 * @file a417.c
 * @author Jason3e7
 * @date 201511091404
 */

#include <stdio.h>

int num[101][101], j, k, count;

void setNum(int iTemp, char direct) {	
	while (iTemp--) { 
		if (direct == 'U') 
			num[j--][k] = count++;
		if (direct == 'D') 
			num[j++][k] = count++;
		if (direct == 'R') 
			num[j][k++] = count++;
		if (direct == 'L') 
			num[j][k--] = count++;
	}
}

int main() {
	int t, n, m, i;
	while(scanf("%d", &t) != EOF) {
		while (t--) {
			scanf("%d %d", &n, &m);
			j = 0, k = 0, count = 1;
			num[j][k] = count;
			if (m == 1) {
				setNum(n - 1, 'R'); 	
				for(i = n - 1; i > 0; i -= 2) { 	
					setNum(i, 'D');
					setNum(i, 'L');
					setNum(i - 1, 'U'); 	
					setNum(i - 1, 'R'); 	
				}
			} else if (m == 2) {
				setNum(n - 1, 'D'); 	
				for(i = n - 1; i > 0; i -= 2) { 	
					setNum(i, 'R');
					setNum(i, 'U');
					setNum(i - 1, 'L'); 	
					setNum(i - 1, 'D'); 	
				}	
			}
			num[j][k] = count;

			for (j = 0; j < n; j++) {
				for (k = 0; k < n; k++) {
					printf("%5d", num[j][k]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
