 /*
  * @file b701.c
  * @author Jason3e7
  * @algorithm brute force
  * @date 201710211016
  */

#include <stdio.h>

int map[513][513];
int w = 0, n = 0, e = 0, s = 0, a = 0;
int x = 0, y = 0;
int d[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int walk(int xLocate, int yLocate) {
	if(xLocate > s) {
		s = xLocate;
	}
	if(yLocate > e) {
		e = yLocate;
	}
	if(yLocate < w) {
		w = yLocate;
	}
	int j, k;
	for(j = 0; j < x; j++) {
		for(k = 0; k < y; k++) {
			printf("%d ", map[j][k]);
		}
		printf("\n");
	}
	printf("\n");
	printf("%d %d %d %d %d\n", w, n ,e, s, a);
	printf("\n");
	int i;
	for(i = 0; i < 4; i++) {
		if(map[xLocate + d[i][0]][yLocate + d[i][1]] == 1) {
			map[xLocate + d[i][0]][yLocate + d[i][1]] = 0;
			a++;
			walk(xLocate + d[i][0], yLocate + d[i][1]);
		}
	}	
	return 0;
}

int main() {
	int i, j;
	while(scanf("%d %d", &x, &y) != EOF) {
		for(i = 0; i < x; i++) {
			for(j = 0; j < y; j++) {
				scanf("%d", &map[i][j]);
			}
		}
		for(i = 0; i < x; i++) {
			for(j = 0; j < y; j++) {
				if(map[i][j] == 1) {
					map[i][j] = 0;
					n = i;
					w = j, e = j, s = i;
					a = 1;
					walk(i, j);
					printf("%d %d %d %d %d\n", w, n ,e, s, a);
				}
			}
		}
	}
	return 0;
}

