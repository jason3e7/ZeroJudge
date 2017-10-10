 /*
  * @file d555.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710111040
  */

#include <stdio.h>
int main() {
	int n, map[100001][2], i, j, point, flag, x, y, c = 1, temp;
	while(scanf("%d", &n) != EOF) {
		point = 0;
		for(i = 0; i < n; i++) {
			flag = 1;
			scanf("%d %d", &x, &y);
			for(j = 0; j < point; j++) {
				if(x <= map[j][0] && y <= map[j][1]) {
					flag = 0;
					break;	
				}
				if(x >= map[j][0] && y >= map[j][1]) {
					map[j][0] = x;
					map[j][1] = y;
					flag = 0;
				}
			}
			if(flag == 1) {
				map[point][0] = x;
				map[point][1] = y;
				point++;
			}
		}
		for(i = 0; i < point; i++) {
			for(j = 0; j < (point - 1 - i); j++) {
				if(map[j][0] > map[j + 1][0]) {
					temp = map[j][0];
					map[j][0] = map[j + 1][0];
					map[j + 1][0] = temp;
					temp = map[j][1];
					map[j][1] = map[j + 1][1];
					map[j + 1][1] = temp;
				}
			}
		}
		temp = point;
		for(i = 0; i < temp; i++) {
			if(map[i][0] == -1 && map[i][1] == -1) {
				continue;
			}
			for(j = i + 1; j < temp; j++) {
				if(map[i][0] == map[j][0] && map[i][1] == map[j][1]) {
					map[j][0] = -1;
					map[j][1] = -1;
					point--;
				} else {
					break;
				}
			}
		}
		printf("Case %d:\n", c);
		printf("Dominate Point: %d\n", point);
		for(i = 0; i < 100001; i++) {
			if(map[i][0] == -1 && map[i][1] == -1) {
				continue;
			}
			printf("(%d,%d)\n", map[i][0], map[i][1]);
			point--;
			if(point == 0) {
				break;
			}
		}
		c++;
	}
	return 0;
}


