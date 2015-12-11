/*
 * @file d424.c
 * @author Jason3e7
 * @algorithm controlFlow
 * @date 201512110946
 */

#include <stdio.h>

int main() {
	int i, l, h, r, end = 0, high[10001] = {0};
	while(scanf("%d %d %d", &l, &h, &r) != EOF) {	
		if (r > end)
			end = r;
		for (i = l; i < r; i++) {
			if (h > high[i]) {
				high[i] = h;
			}
		}
	}

	end++;
	int temp = 0, first = 0;
	for (i = 0; i <= end; i++) {
		if (temp != high[i]) {
			if (first == 0)
				printf("%d %d", i, high[i]);
			else 
				printf(" %d %d", i, high[i]);
			temp = high[i];
			first = 1;
		}
	}
	printf("\n");

	return 0;
}

