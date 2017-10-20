 /*
  * @file a847.c
  * @author Jason3e7
  * @algorithm DFS
  * @date 201710211111
  * @note BFS better
  */

#include <stdio.h>

int route[26][26], map[26], begin, end;

int walk(int point) {
	int i;
	if(point == end) {
		return 0;
	}
	for(i = 0; i < 26; i++) {
		if(route[point][i] == -1) {
			continue;
		}
		if((map[point] + route[point][i]) > map[end]) {
			continue;	
		}
		if((map[point] + route[point][i]) < map[i]) {
			map[i] = map[point] + route[point][i];
			walk(i);
		}
	}
	return 0;
}

int main() {
	int n, t, i, j, out;
	char x[5], y[5];
	while(scanf("%d", &n) != EOF) {
		for(i = 0; i < 26; i++) {
			for(j = 0; j < 26; j++) {
				route[i][j] = -1;
			}
			map[i] = 1000000;
		}
		for(i = 0; i < n; i++) {
			scanf("%s %s %d", x, y, &t);
			route[x[0] - 'A'][y[0] - 'A'] = t;
			route[y[0] - 'A'][x[0] - 'A'] = t;
		}
		scanf("%s %s", x, y);
		begin = x[0] - 'A';
		end = y[0] - 'A';
		map[begin] = 0;
		out = walk(begin);
		if(map[end] == 1000000) {
			printf("NoRoute\n");
		} else {
			printf("%d\n", map[end]);
		}
	}
	return 0;
}

