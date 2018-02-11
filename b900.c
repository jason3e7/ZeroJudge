 /*
  * @file b900.c
  * @author Jason3e7
  * @algorithm Simulation
  * @date 201802120813
  */

#include <stdio.h>

int main() {
	int i, j, w, h, local, map[12][100];
	char c;
	while(scanf("%d %d", &w, &h) != EOF) {
		for(j = 0; j < h; j++) {
			map[0][j] = 0;
			map[w][j] = 0;
		}
		for(j = 0; j < h; j++) {
			i = 1;
			while(i < w) {
				c = getchar();
				if (c == '.') {
					map[i][j] = 0;
					i++;
				} else if (c == '-') {
					map[i][j] = 1;
					i++;
				}
			}
		}
		/*	
		for(j = 0; j < h; j++) {
			for(i = 0; i < w + 1; i++) {
				printf("%d", map[i][j]);
			}
			printf("\n");
		}
		*/
		for(i = 1; i <= w; i++) {
			local = i;
			for(j = 0; j < h; j++) {
				if(map[local - 1][j] == 1) {
					local--;
				} else if(map[local][j] == 1) {
					local++;
				} 
			}
			if(i == 1) {
				printf("%d", local);
			} else {
				printf(" %d", local);
			}
		}
		printf("\n");
	}
	return 0;
}

