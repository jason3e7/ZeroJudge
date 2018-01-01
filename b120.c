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

int fPlus(int n) {
	int out[9] = {1, 2, 3, 1, -1, -1, -3, -2, -1};
	if(-1 <= n && n <= 7) {
		return out[n + 1];
	}
	int fMap[6] = {2, 7, 12, 14, 13, 12};
	if(n > 7) {
		n -= 8;
		return out[8] - 12 * (n / 6) - fMap[n % 6];
	}
	int temp = g(n);
	return fPlus(temp) - temp;
}

int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		printf("%d\n", fPlus(n));
	}
	return 0;
}

