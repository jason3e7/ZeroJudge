 /*
  * @file b120.c
  * @author Jason3e7
  * @algorithm math 
  * @date 201801021106
  * @note h => 2 + h(n - 1) - h(n - 2)
  */

#include <stdio.h>

int g(int n) {
	if(n <= 2) {
		return n * n - 1;
	}
	return 2;
}

int h(int n) {
	if(n < 2) {
		return -1;
	}
	return 2 + h(n - 1) - h(n - 2);
}

int f(int n) {
	int temp = h(n), temp2;
	if(n > temp) {
		return f(n - 1) - temp;
	}
	if(n < temp) {
		temp2 = g(n);
		return f(temp2) - temp2;
	}
	return 1;
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		printf("%d\n", f(n));
	}
	return 0;
}

