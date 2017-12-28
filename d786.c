 /*
  * @file d786.c
  * @author Jason3e7
  * @algorithm getline
  * @date 201712281857
  */

#include <stdio.h>

int main() {
	int t, n, i, temp;
	double sum;
	while(scanf("%d", &t) != EOF) {
		while(t--) {
			scanf("%d", &n);
			sum = 0;
			for(i = 0; i < n; i++) {
				scanf("%d", &temp);
				sum += temp;
			}
			printf("%.2f\n", sum / n);
		}
	}
	return 0;
}
