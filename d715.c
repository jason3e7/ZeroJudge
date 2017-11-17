 /*
  * @file d715.c
  * @author Jason3e7
  * @algorithm math
  * @date 201711171429
  * @note interest, set 9! => 8
  * x * 5 carry 9! / 5 => 6 => 6 * 6 => 6
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
1 2 3 4 1 6 7 8 9 2 1 2 3 4 3 6 * 5
1 2 3 4 1 6 7 8 9 1 1 2 3 4 1 6 * (1 2 3 * 5)
1 2 3 4 1 6 7 8 9 1 1 2 3 4 1 6 * (1 2 3) * 5 ^ 3
1 2 3 4 1 6 7 8 9 1 1 2 3 4 1 6 * (1 2 3) * 5 ^ 3 * 2 ^ 3 / 2 ^ 3
1 2 3 4 1 6 7 8 9 1 1 2 3 4 1 6 * (1 2 3) / 2 ^ 3

mod => {1, 1, 2, 6, 4, 4, 4, 8, 4, 6};
n < 10
f[n] =  mod / (2 ^ (n / 5))

n >= 10
f[n] = f[n / 5] * mod * 6 / 2 ^ (n / 5)

x / 2 = y => x is an even, y is an even.
x = 2 * y => 
x = 2, y = 6; x = 4; y = 2; x = 6; y = 8; x = 8, y = 4. 
6 -> 8 -> 4 -> 2

f[n] = f[n / 5] * mod * (6 / 2 ^ ((n / 5) mod 4));

  */ 
 
#include <stdio.h>

int endNumber(int n) {
	while(n % 10 == 0) {
		n /= 10;
	}
	return n % 10;
}

int num[10] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};
int base[10] = {1, 1, 2, 6, 4, 4, 4, 8, 4, 6};
int div[4] = {6, 8, 4, 2};

int f(int n) {
	if(n < 10) {
		return num[n];
	}
	return endNumber(f(n / 5) * base[n % 10] * div[(n / 5) % 4]);
}

int main() {
	int n;
    while(scanf("%d", &n) != EOF) {
		printf("%d\n", f(n));
	}
    return 0;
}

