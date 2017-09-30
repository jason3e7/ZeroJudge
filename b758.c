 /*
  * @file b758.c
  * @author Jason3e7
  * @algorithm math
  * @date 201710011153
  */

#include <stdio.h>
int main() {
	int x, y;
	while(scanf("%d %d", &x, &y) != EOF) {
		x += 2;
		y += 30;
		if(y >= 60)	{
			x++;
			y -= 60;
		}
		if(x >= 24) {
			x -= 24;
		}
		printf("%02d:%02d\n", x, y);
	}
	return 0;
}

