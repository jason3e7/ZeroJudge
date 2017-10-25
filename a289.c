 /*
  * @file a289.c
  * @author Jason3e7
  * @algorithm math(Modular multiplicative inverse)
  * @date 201710241904
  * @note
ax + by = gcd(a, b)
exgcd(a, n) => ax + ny = g
ax + ny = 1

coprime ? times gcd

3x + 11y = 1

11 = 3 * 3 + 2
3 = 2 * 1 + 1

a = 3, n = 11
rx = 1, ry = 0, lx = 0, ly = 1;
rx = rx - a/n * lx; => 1 
ry = ry - a/n * ly; => 0

change

a = 11, n = 3
rx = 1, ry = 0, la = 0, ly = 1;
la = la - a/n * rx; => -3 
ly = ly - a/n * ry; => 1

2 = 11 * 1 + 3 * -3

la = la - 11/3 * 1; => -3 
ly = ly - 11/3 * 0; => 1

a = 3, n = 2
rx = 1, ry = 0, la = -3, ly = 1;
rx = rx - a/n * lx; => 4
ry = ry - a/n * ly; => -1

3 = 2 * 1 + 1 * 1

rx = rx - 3/2 * -3; => 4
ry = ry - 3/2 * 1; => -1

a = 2, n = 1
exit

retury (rx%mod + mod)%mod;

over mod and negative !?

  */

#include <stdio.h>

int mmi(int a, int n) {
	int swap, mod = n;
	int rx = 1, lx = 0, step = 1;
	while(a % n) {
		if(step) {
			rx -= (a / n * lx);
		} else {
			lx -= (a / n * rx);
		}
		swap = n;
		n = a % n;
		a = swap;
		step = 1 - step;
	}
	if(n == 1) {
		if(step) {
			return (lx%mod + mod)%mod;
		} else {
			return (rx%mod + mod)%mod;
		}
	} else {
		return 0;
	}
}

int main() {
	int a, n, temp; 
	while(scanf("%d %d", &a, &n) != EOF) {
		temp = mmi(a, n);
		if(temp == 0) {
			printf("No Inverse\n");
		} else {
			printf("%d\n", temp);
		}
	}
	return 0;
}

