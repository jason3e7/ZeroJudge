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
	if(point[4] >= 27) {
		point[3]++;
		point[4] = point[3] + 1;
	}
	if(point[3] >= 26) {
		point[2]++;
		point[3] = point[2] + 1;
		point[4] = point[3] + 1;
	}
	if(point[2] >= 25) {
		point[1]++;
		point[2] = point[1] + 1;
		point[3] = point[2] + 1;
		point[4] = point[3] + 1;
	}
	if(point[1] >= 24) {
		point[0]++;
		point[1] = point[0] + 1;
		point[2] = point[1] + 1;
		point[3] = point[2] + 1;
		point[4] = point[3] + 1;
	}
	if(point[0] >= 23) {
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

