 /*
  * @file b680.c
  * @author Jason3e7
  * @algorithm sort
  * @date 201711161842
  */ 
 
#include <stdio.h>

int main(void) {
	int n, point;
	float max, time[200];
	int i, j, sort[200], local;
	int player[25][8], group, groups, row, map[8] = {3, 4, 2, 5, 1, 6, 0, 7};
    while(scanf("%d", &n) != EOF) {
		for(i = 0; i < n; i++) {
			scanf("%d %f", &point, &max);
			time[point - 1] = max;
		}		
			
		for(i = 0; i < n; i++) {
			max = 0;
			for(j = 0; j < n; j++) {
				if(time[j] > max) {
					max = time[j];
					local = j;
				}
			}
			time[local] = 0;
			sort[n - 1 - i] = local;
		}

		groups = n / 8;
		for(i = 0; i < n; i++) {
			group = i % groups;
			if((i / groups) % 2 == 1) {
				group = groups - 1 - group;
			}
			row = map[i / groups];
			player[group][row] = sort[i];	
		}
	
		for(i = 0; i < groups; i++) {
			printf("%d", i + 1);
			for(j = 0; j < 7; j++) {
				printf(" %d", player[i][j] + 1);
			}
			printf(" %d\n", player[i][7] + 1);
		}
    }
    return 0;
}

