 /*
  * @file b542.c
  * @author Jason3e7
  * @algorithm 
  * @date 201710181627
  */

#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, q, i, j, k, high[100001], diff[100001], point, temp, match;
	while(scanf("%d %d", &n, &q) != EOF) {
		for(i = 0; i < 100001; i++) {
			diff[i] = 0;
		}
		point = 0;
		for(i = 0; i < n; i++) {
			scanf("%d", &high[i]);
			for(j = i - 1; j >= 0; j--) {
				temp = abs(high[i] - high[j]);
				match = 0;
				for(k = 0; k < point; k++) {
					if(temp == diff[k]) {
						match = 1;
						break;
					}
				}
				if(match == 0) {
					diff[point] = temp;
					point++;
				}
			}
		} 
		while(q--) {
			scanf("%d", &temp);
			match = 0;
			for(k = 0; k < point; k++) {
				if(temp == diff[k]) {
					printf("YES\n");
					match = 1;
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



