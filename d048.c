/*
 * @file d048.c
 * @author Jason3e7
 * @date 201605261022
 */

#include <stdio.h>

int check(int h, int m) {
	int sum, reverse;
	sum = h * 100 + m;
	reverse = 0;
	while (sum) {
		reverse *= 10;
		reverse += sum % 10;
		sum /= 10;
	}
	sum = h * 100 + m;
	if (sum == reverse)
		return 1;
	else 
		return 0;
}

int main() {
	int t, h, m, i;
	while(scanf("%d", &t) != EOF) {
		while(t--) {
			scanf("%d:%d", &h, &m);
			for (i = 1; i <= 1440; i++) {
				m++;
				if (m >= 60) {
					m = 0;
					h++;
					if (h >= 24) 
						h = 0;
				}
				if (check(h, m) == 1) 
					break;
			}
			printf("%02d:%02d\n", h, m);
		}
	}
	return 0;
}

