 /*
  * @file b837.c
  * @author Jason3e7
  * @algorithm basic 
  * @date 201711141031
  */ 
 
#include <stdio.h>

int main() {
	int f[35], point;
	int t, a, b, i, count, first;
	f[0] = 0;
	f[1] = 1;
	point = 2;
	while(f[point - 1] < 1000001) {
		f[point] = f[point - 1] + f[point - 2];
		point++;
	}
	point--;

	while(scanf("%d", &t) != EOF) {	
		first = 1;
		while(t--) {
			if (first == 0) {
				printf("------\n");
			}
			scanf("%d %d", &a, &b);
			if(a > b) {
				i = a;
				a = b;
				b = i; 
			}
			count = 0;
			for(i = 0; i < point; i++) {
				if(a <= f[i] && f[i] <= b) {
					printf("%d\n", f[i]);
					count++;
				}
			}
			printf("%d\n", count);
			first = 0;
		}
	}
	return 0;
}

