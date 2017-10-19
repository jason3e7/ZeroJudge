 /*
  * @file b557.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710191619
  */

#include <stdio.h>

int main() {
	int t, n, i, j, k, number[101], out, temp;
	while(scanf("%d", &t) != EOF) {
		while(t--) {
			for(i = 0; i < 101; i++) {
				number[i] = 0;
			}
			scanf("%d", &n);
			for(i = 0;i < n; i++) {
				scanf("%d", &temp);
				number[temp]++; 
			}
			out = 0;
			for(i = 1;i < 99; i++) {
				if(number[i] == 0) {
					continue;
				}
				for(j = i + 1;j < 100; j++) {
					if(number[j] == 0) {
						continue;
					}
					for(k = j + 1;k < 101; k++) {
						if(number[k] == 0) {
							continue;
						}
						if((i + j) <= k) {
							continue;
						}
						if((i * i + j * j) == (k * k)) {
							out += (number[i] * number[j] * number[k]);
						}
					}
				}
			}
			printf("%d\n", out);
		}
	}
	return 0;
}

