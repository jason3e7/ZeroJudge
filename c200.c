 /*
  * @file c200.c
  * @author Jason3e7
  * @algorithm math
  * @date 201803101650
  * @note
(a + b) % c
=> (a % c + b % c) % c

(a * b) % c
=> (a % c * b % c) % c

(a1 * p1 + a2 * p2 + ...) % m
=> [(a1 * p1) % m + (a2 * p2) % m + ...] % m
=> [(a1 % m * p1 % m) % m + ...] % m
  */

#include <stdio.h>
#include <string.h>

int main() {
	int n, i, len, base, r, pow;
	char line[101];
	while(scanf("%d", &n) != EOF) {
		while(n--) {
			scanf("%s", line);
			len = strlen(line);
			r = 0;
			pow = 1;
			for(i = len - 1; i >= 0; i--) {
				if('0' <= line[i] && line[i] <= '9') {
					base = line[i] - '0';
				}
				if('A' <= line[i] && line[i] <= 'Z') {
					base = (line[i] - 'A' + 10);
				}
				r += base * pow;
				pow *= 36;
				pow %= 1688;
			}
			printf("%d\n", (r % 1688) + 1);
		}
	}
	return 0;
}
