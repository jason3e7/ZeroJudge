 /*
  * @file b900.c
  * @author Jason3e7
  * @algorithm Simulation
  * @date 201802120813
  */

#include <stdio.h>
#include <string.h>

int main() {
	int i, j, w, h, local, map[12][100], len;
	char line[20];
	while(scanf("%d %d", &w, &h) != EOF) {
		for(j = 0; j < h; j++) {
			for(i = 0; i <= w; i++) {
				map[i][j] = 0;
			}
		}
		for(j = 0; j < h; j++) {
			scanf("%s", line);
			len = strlen(line);
			for(i = 0; i < len; i++) {
				if (line[i] == '-') {
					map[(i + 1) / 2][j] = 1;
				}
			}
		}
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

