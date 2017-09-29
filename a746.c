 /*
  * @file a746.c
  * @author Jason3e7
  * @algorithm IO
  * @date 201709301034
  */

#include <stdio.h>
int main() {
	int n, m, i, j, x1, y1, x2, y2, tempX, tempY, swap;
	char map[502][502];
	while(scanf("%d %d", &n, &m) != EOF) {
		n++;
		for(i = 0; i <= n; i++) {
			for(j = 0; j <= n; j++) {
				if (i == 0 || i == n) {
					map[i][j] = '-';
					continue;
				}
				if(j == 0 || j == n) {
					map[i][j] = '|';
					continue;
				} 
				map[i][j] = ' ';
			}
		}
		scanf("%d %d", &x1, &y1);
		for(i = 1; i < m; i++) {
			scanf("%d %d", &tempX, &tempY);
			x2 = tempX;
			y2 = tempY;
			if(x1 > x2)	{
				swap = x1;
				x1 = x2;
				x2 = swap;
			}
			if(y1 > y2)	{
				swap = y1;
				y1 = y2;
				y2 = swap;
			}
			if (x1 == x2) {
				for(;y1 <= y2; y1++) {
					map[x1][y1] = '*';
				}
			} else if (y1 == y2) {
				for(;x1 <= x2; x1++) {
					map[x1][y1] = '*';
				}
			}
			x1 = tempX;
			y1 = tempY;
		}
		for(i = 0; i <= n; i++) {
			for(j = 0; j <= n; j++) {
				printf("%c", map[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
