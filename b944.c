 /*
  * @file b944.c
  * @author Jason3e7
  * @algorithm control flow
  * @date 201710182153
  */

#include <stdio.h>

int number[23] = {0}, time[23] = {0}, n = 0;

void printToilet() {
	int i;
	printf("Number: ");
	for(i = 1; i <= n; i++) {
		if(i == 1) {
			printf("%d", number[i]);
		} else {
			printf(" %d", number[i]);
		}
	}
	printf("\n");
	printf("  Time: ");
	for(i = 1; i <= n; i++) {
		if(i == 1) {
			printf("%d", time[i]);
		} else {
			printf(" %d", time[i]);
		}
	}
	printf("\n\n");
}

int intoToilet(int a, int b) {
	int i;
	for(i = 1; i <= n; i++) {
		if(time[i] == 0 && time[i - 1] == 0 && time[i + 1] == 0) {
			number[i] = a;
			time[i] = b;
			return 1;
		}
	}
	for(i = 1; i <= n; i++) {
		if(time[i] == 0) {
			number[i] = a;
			time[i] = b;
			return 1;
		}
	}
	return 0;
}

void sub() {
	int i;
	for(i = 1; i <= n; i++) {
		if(time[i] > 0) {
			time[i]--;
		}
		if(time[i] == 0) {
			number[i] = 0;
		}
	}
}

int main() {
	int a, b, i;
	while(scanf("%d", &n) != EOF) {
		for(i = 0; i < 23; i++) {
			number[i] = 0;
			time[i] = 0;
		}
		while(scanf("%d %d", &a, &b) != EOF) {
			if(intoToilet(a, b) == 0) {
				printf("  Not enough\n");
			}
			printToilet();
			sub();
		}
	}
	return 0;
}



