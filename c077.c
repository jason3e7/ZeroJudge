 /*
  * @file c077.c
  * @author Jason3e7
  * @algorithm basic
  * @UVa 417
  * @date 201710171206
  */

#include <stdio.h>

int point[5] = {0, 0, 0, 0, 1};

int carry() {
	int i, j, max = 26;
	for(i = 4; i >= 1; i--, max--) {
		if(point[i] > max) {
			point[i - 1]++;
			for(j = i; j <= 4; j++) {
				point[j] = point[j - 1] + 1;
			}
		}
	}
	if(point[0] > max) {
		return 1;
	}
	return 0;
}

int output(int n) {
	printf("%d => ", n);
	int i;
	for(i = 0; i < 5; i++) {
		if(point[i] != 0) {
			printf("%c", point[i] + 96);
		}
	}
	printf("\n");
	return 0;
}

int printIndex(int n) {
	output(n);
	point[4]++;
	if(carry() == 1) {
		return 0;
	}
	printIndex(n + 1);
	return 0;
}

int main() {
	printIndex(1);
	return 0;
}

