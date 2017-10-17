 /*
  * @file c077.c
  * @author Jason3e7
  * @algorithm basic
  * @UVa 417
  * @date 201710171206
  */

#include <stdio.h>
#include <string.h>

int point[5] = {0, 0, 0, 0, 1};
int map[23][24][25][26][27];

int carry() {
	int i, j, max = 26;
	for(i = 4; i >= 1; i--, max--) {
		if(point[i] > max) {
			point[i - 1]++;
			for(j = i; j <= 4; j++) {
				point[j] = point[j - 1] + 1;
			}
		}
	}
	if(point[0] > max) {
		return 1;
	}
	return 0;
}

int getMap(int n) {
	map[point[0]][point[1]][point[2]][point[3]][point[4]] = n;
	point[4]++;
	if(carry() == 1) {
		return 0;
	}
	getMap(n + 1);
	return 0;
}

int main() {
	getMap(1);
	char line[10];
	int length, i, flag;
	while(scanf("%s", line) != EOF) {
		length = strlen(line);
		flag = 0;
		for(i = 1; i < length; i++) {
			if(line[i - 1] > line[i]) {
				flag = 1;
				break;
			}
		}
		if(flag == 1) {
			printf("0\n");
			continue;
		}
		for(i = 0; i < 5; i++) {
			point[i] = 0;
		}
		for(i = 0; i < length; i++) {
			point[(5 - length) + i] = line[i] - 96;
		}
		printf("%d\n", map[point[0]][point[1]][point[2]][point[3]][point[4]]);
	}
	return 0;
}

