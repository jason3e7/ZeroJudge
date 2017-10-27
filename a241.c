 /*
  * @file a241.c
  * @author Jason3e7
  * @algorithm math
  * @date 201710272033
  */

#include <stdio.h>

int main() {
	int n, temp, i, j, t, f, tempT, tempF, mix;
	while(scanf("%d", &n) != EOF) {
		while(n--) {
			t = 0, f = 0, mix = 0;
			scanf("%d", &temp);
			tempT = temp;
			while(tempT /= 2) {
				t++;
			}
			tempF = temp;
			while(tempF /= 5) {
				f++;
			}
			tempT = 1;
			for(i = 1; i <= t; i++) {
				tempT *= 2;
				tempF = 1;
				for(j = 1; j <= f; j++) {
					tempF *= 5;
					if(tempT * tempF <= temp) {
						mix++;
					} else {
						break;
					}
				}
			}
			printf("%d\n", mix + f + t);
		}
	}
	return 0;
}

