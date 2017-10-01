 /*
  * @file b836.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710021140
  */

#include <stdio.h>
int main() {
	long long int n, m, i;
	while(scanf("%lli %lli", &n, &m) != EOF) {
		if(n <= 1 || m == 0) {
			printf("Go Kevin!!\n");
			continue;
		}
		for(i = 0;n > 0; i++) {
			n -= (m * i + 1);
		}
		if(n == 0) {
			printf("Go Kevin!!\n");
		} else {
			printf("No Stop!!\n");
		}
	}
	return 0;
}

