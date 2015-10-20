/*
 * @file d574.c
 * @author Jason3e7
 * @date 201510200919
 */

#include <stdio.h>

int main() {
	int k, x, c, max, now;
	while(scanf("%d", &k) != EOF) {
		max = 0;
		now = 0;
		while (k--) {
			scanf("%d %d", &x, &c);
			if (c == 1) {
				now++;	
			} else {
				now--;
			}
			if (now > max) {
				max = now;
			}
		}
		printf("%d\n", max);
	}
	return 0;
}
