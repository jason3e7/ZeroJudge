 /*
  * @file b367.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710091100
  */

#include <stdio.h>
int main() {
	int t, n, m, map[12][12], i, j, k, l, flag;
	while(scanf("%d", &t) != EOF) {
		while(t--) {
			scanf("%d %d", &n, &m);
			for(i = 0; i < n; i++) {
				for(j = 0; j < m; j++) {
					scanf("%d", &map[i][j]);
				} 
			}
			flag = 1;
			for(i = 0, k = n - 1; i < n; i++, k--) {
				for(j = 0, l = m - 1; j < m; j++, l--) {
					if(map[i][j] != map[k][l]) {
						flag = 0;
						break;
					}
				} 
				if(flag == 0) {
					break;
				}
			} 
			if(flag == 0) {
				printf("keep defending\n");
			} else {
				printf("go forward\n");
			}
		}
	}
	return 0;
}

