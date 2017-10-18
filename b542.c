 /*
  * @file b542.c
  * @author Jason3e7
  * @algorithm 
  * @date 201710181627
  */

#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main() {
	int n, q, high[100001], i, j, temp, count, match;
	while(scanf("%d %d", &n, &q) != EOF) {
		for(i = 0; i < n; i++) {
			scanf("%d", &high[i]);
		}
		qsort(high, n, sizeof(int), cmpfunc); 
		for(i = 0; i + 1 < n; i++) {
			high[i] = high[i + 1] - high[i]; 
		}
		n--;
		
		while(q--) {
			scanf("%d", &temp);
			match = 0;
			for(i = 0; i < n; i++) {
				count = 0;
				for(j = i; j < n; j++) {
					count += high[j];
					if(count == temp) {
						printf("YES\n");
						match = 1;
						break;
					}
					if(count > temp) {
						break;
					}
				}
				if(match == 1) {
					break;
				}
			}
			if(match == 0) {
				printf("NO\n");
			}
		}
	}
	return 0;
}



