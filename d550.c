 /*
  * @file d550.c
  * @author Jason3e7
  * @algorithm sort
  * @date 201710201453
  */

#include <stdio.h>

void swap(int m, int a[m], int b[m]) {
	int i, temp;
	for(i = 0; i < m; i++) {
		temp = a[i];
    	a[i] = b[i];
    	b[i] = temp;
    }
}

int main() {
	int i, j, k, n, m, number[10001][201];
	while(scanf("%d %d", &n, &m) != EOF) {
		for(i = 0; i < n; i++) {
			for(j = 0; j < m; j++) {
				scanf("%d", &number[i][j]);
			}
		}
		for(i = 1; i < n; i++) {
			for(j = 0; j < (n - i); j++) {
				for(k = 0; k < m; k++) {
					if(number[j][k] < number[j + 1][k]) {
						break;
					}
					if(number[j][k] == number[j + 1][k]) {
						continue;
					}
					if(number[j][k] > number[j + 1][k]) {
						swap(m, number[j], number[j + 1]);
						break;
					}
				}
			}
		}

		for(i = 0; i < n; i++) {
			for(j = 0; j < m; j++) {
				if(j == 0) {
					printf("%d", number[i][j]);
				} else {
					printf(" %d", number[i][j]);
				}
			}
			printf("\n");
		}
	}
	return 0;
}

