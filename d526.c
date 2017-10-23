 /*
  * @file d526.c
  * @author Jason3e7
  * @algorithm Binary Search Tree
  * @date 201710232011
  */

#include <stdio.h>

int num[1001], n, out[1001], point;

int findLeftTree(int locate, int number) {
	int i, temp;
	for(i = locate; i < n; i++) {
		if(num[i] == -1) {
			continue;
		}
		if(num[i] < number) {
			temp = num[i];
			out[point] = num[i];
			num[i] = -1;
			point++;
			findLeftTree(i + 1, temp);
		}
	}
	return 0;
}

int findRight(int locate, int number) {
	int i, temp;
	for(i = locate; i < n; i++) {
		if(num[i] == -1) {
			continue;
		}
		if(num[i] > number) {
			temp = num[i];
			out[point] = num[i];
			num[i] = -1;
			point++;
			findLeftTree(i + 1, temp);
			findRight(i + 1, temp);
			return 0;	
		}
	}
	return 0;
}

int main() {
	int i; 
	while(scanf("%d", &n) != EOF) {
		for(i = 0; i < n; i++) {
			scanf("%d", &num[i]);
		}
		point = 0;
		findRight(0, 0);
		printf("%d", out[0]);
		for(i = 1; i < n; i++) {
			printf(" %d", out[i]);
		}
		printf("\n");
	}
	return 0;
}

