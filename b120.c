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

int map[6] = {2, 5, 5, 2, -1, -1};
int h(int n) {
	if(n < 2) {
		return -1;
	}
	return map[(n - 2) % 6];
}

int out[610];
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
	int temp, i;
	out[-1 + 300] = 1;
	out[0 + 300] = 2;
	out[1 + 300] = 3;
	out[2 + 300] = 1;
	out[3 + 300] = -1;
	out[4 + 300] = -1;
	out[5 + 300] = -3;
	for(i = 6; i <= 299; i++) {
		out[i + 300] = out[i + 299] - h(i);
	}
	int n;
	while(scanf("%d", &n) != EOF) {
		if(-1 <= n && n <= 299) {
			printf("%d\n", out[n + 300]);
		} else { 
			printf("%d\n", f(n));
		}
	}
	return 0;
}

