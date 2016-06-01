/*
 * @file d056.c
 * @author Jason3e7
 * @date 201606011317
 */

#include <stdio.h>

int main() {
	int n, m, a, b, mTemp, i;
	char output[1000001];
	while(scanf("%d", &n) != EOF) {
		while(n--) {
			scanf("%d", &m);
			mTemp = m;
			for (i = 0; i < 1000001; i++) 
				output[i] = 0;
			while(mTemp--) {
				scanf("%d %d", &a, &b);
				output[mTemp] = a + b + '0';
			}
			for (i = 0; i < m; i++) {
				if (output[i] > '9') {
					output[i] = output[i] - 10;
					output[i + 1]++;
				}
			}
			for (i = m - 1; i >= 0; i--) 
				printf("%c",  output[i]);
			printf("\n");
			if (n != 0)
				printf("\n");
		}
	}
	return 0;
}

