 /*
  * @file arrayfunction.c
  * @author Jason3e7
  * @algorithm array
  * @date 201710171039
  */

#include <stdio.h>

int arrayCompare(int a[], int b[], int n) {
	int i;
	for(i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			return 0;
		}
	}
	return 1;
}

int arrayCopy(int a[], int b[], int n) {
	int i;
	for(i = 0; i < n; i++) {
		a[i] = b[i];
	}
	return 0;
}

int main() {
	int n, i, tempX[5], tempY[5];
	while(scanf("%d", &n) != EOF) {
		for(i = 0; i < n; i++) {
			scanf("%d %d %d %d %d", &tempX[0], &tempX[1], &tempX[2], &tempX[3], &tempX[4]);
			scanf("%d %d %d %d %d", &tempY[0], &tempY[1], &tempY[2], &tempY[3], &tempY[4]);
			printf("%d\n", arrayCompare(tempX, tempY, 5));
			arrayCopy(tempY, tempX, 5);
			printf("%d %d %d %d %d\n", tempY[0], tempY[1], tempY[2], tempY[3], tempY[4]);
		}
	}
	return 0;
}

