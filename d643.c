 /*
  * @file d643.c
  * @author Jason3e7
  * @algorithm backtracking
  * @date 201710261019
  */

#include <stdio.h>

int n, v[10001], s[10001], max = 0, volume = 0, satiate = 0;

int eatFeed(int point) {
	int i;
	for(i = point; i < n; i++) {
		if(volume + v[i] > 100) {
			if(satiate > max) {
				max = satiate;
			}
		} else {
			volume += v[i];
			satiate += s[i];
			eatFeed(i + 1);
			volume -= v[i];
			satiate -= s[i];
		}
		eatFeed(i + 1);
	}
	return 0;
}

int main() {
	int i;
	while(scanf("%d", &n) != EOF) {
		max = 0, volume = 0, satiate = 0;
		for(i = 0; i < n; i++) {
			scanf("%d %d", &v[i], &s[i]);
		}
		eatFeed(0);
		printf("%d\n", max);
	}
	return 0;
}

