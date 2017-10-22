 /*
  * @file a159.c
  * @author Jason3e7
  * @algorithm basic
  * @UVa 11743
  * @date 201710221312
  */

#include <stdio.h>

int main() {
	int n, num[4], i, j, out, temp;
	while(scanf("%d", &n) != EOF) {			
		while(n--) {
			out = 0;
			scanf("%d %d %d %d", &num[0], &num[1], &num[2], &num[3]);
			for(i = 0; i < 4; i++) {
				for(j = 1; j <= 4; j++) {
					if (j % 2 == 1) {
						out += (num[i] % 10);
					} else {
						temp = ((num[i] % 10)) * 2;
						if(temp != 0) {
							out += ((temp / 10) + (temp % 10));
						}
					}
					num[i] /= 10;
				}
			}
			if(out % 10 == 0) {
				printf("Valid\n");
			} else {
				printf("Invalid\n");
			}
		}
	}
	return 0;
}

