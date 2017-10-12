 /*
  * @file a229.c
  * @author Jason3e7
  * @algorithm brute force
  * @date 201710131016
  */

#include <stdio.h>

char out[30] = {'\0'};
int n = 0;

int printNext(int left, int right) {
	int point = left + right;
	if(left == right && point == n * 2) {
		printf("%s\n", out);
		return 0;		
	}
	if(left == right) {
		out[point] = '(';
		printNext(left + 1, right);
	}
	if(left > right && left != n) {
		out[point] = '(';
		printNext(left + 1, right);
	}
	if(left > right) {
		out[point] = ')';
		printNext(left, right + 1);
	}
	return 0;
} 

int main() {
	while(scanf("%d", &n) != EOF) {
		printNext(0, 0);
		printf("\n");	
	}
	return 0;
}



