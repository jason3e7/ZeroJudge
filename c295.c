 /*
  * @file c295.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201803052151
  */

#include <stdio.h>

int main() {
	int n, m, i, j, sum, tmp, max[21], flag;
	while(scanf("%d %d", &n, &m) != EOF) {
		flag = 0;
		sum = 0;
		for(i = 0; i < n; i++) {
			max[i] = -1;
			for(j = 0; j < m; j++) {
				scanf("%d", &tmp);
				if(tmp > max[i]) {
					max[i] = tmp;
				}
			}
			sum += max[i];
		}
		
		printf("%d\n", sum);
		for(i = 0; i < n; i++) {
			if(sum % max[i] == 0) {
				if(flag == 0) {
					printf("%d", max[i]);
					flag = 1;
				} else {
					printf(" %d", max[i]);
				}
			}
		}
		if(flag == 0) {
			printf("-1");
		}	
		printf("\n");
	}
	return 0;
}
