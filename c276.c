 /*
  * @file c276.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201802281011
  */

#include <stdio.h>

int main() {
	int n, m, temp, a, b, nn[4], t[4], i, j;
	while(scanf("%d", &n) != EOF) {
		for(i = 3; i >= 0; i--) {
			nn[i] = n % 10;
			n /= 10;
		}
		scanf("%d", &m);
		while(m--) {
			scanf("%d", &temp);
			for(i = 3; i >= 0; i--) {
				t[i] = temp % 10;
				temp /= 10;
			}
			a = 0, b = 0;
			for(i = 0; i < 4; i++) {
				for(j = 0; j < 4; j++) {
					if(nn[i] == t[j]) {
						if(i == j) {
							a++;
						} else {
							b++;
						}
						break;
					}
				}
			}
			printf("%dA%dB\n", a, b);
		}
	}
	return 0;
}
