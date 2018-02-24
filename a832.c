 /*
  * @file a832.c
  * @author Jason3e7
  * @algorithm array
  * @date 201802241713
  * @note
1 2 3 4 5 
2 1 4 3 5
1 4 2 5 3
4 2 5 1 3
2 5 1 3 4
  */

#include <stdio.h>

int n, num[1001], tmp[1001];

int f(int k) {
	int i, j, temp;
	for(i = 1; i <= n; i += k) {
		temp = i + k - 1;
		if(temp > n) {
			temp = n;
		}
		tmp[temp] = num[i]; 
		for(j = i; j < temp; j++) {
			tmp[j] = num[j + 1];
		}
	}

	for(i = 1; i <= n; i++) {
		num[i] = tmp[i];
	}
	return 0;
}

int main() {
	int i;
	while(scanf("%d", &n) != EOF) {
		for(i = 0; i <= n; i++) {
			num[i] = i;
		}
		for(i = 2; i <= n; i++) {
			f(i);
		}
		
		for(i = 1; i <= n; i++) {
			if(i == 1) {
				printf("%d", num[i]);
			} else {
				printf(" %d", num[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
