 /*
  * @file b972.c
  * @author Jason3e7
  * @algorithm bisic
  * @date 201709301240
  */

#include <stdio.h>
int main() {
	int n, t, m, s, time[21], i, j, min;
	while(scanf("%d %d", &n, &t) != EOF) {
		for(i = 0; i < 21; i++) {
			time[i] = 0;
		}
		for(i = 0; i < n; i++) {
			for(j = 0; j < t; j++) {
				scanf("%d:%d", &m, &s);
				time[j] += (m * 60 + s);
			}
		}
		for(i = 0; i < t; i++) {
			min = 0;
			for(j = 1; j < t; j++) {
				if((time[min] == 0) || (time[j] != 0 && time[min] > time[j])) {
					min = j;
				}
			}
			printf("%d\n", time[min]);
			time[min] = 0;
		}
	}
	return 0;
}

