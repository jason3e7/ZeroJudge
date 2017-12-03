 /*
  * @file d292.c
  * @author Jason3e7
  * @algorithm memory
  * @UVa 386
  * @date 201712032229
  */

#include <stdio.h>

int main() {
	int cube[201], point, i, j, k, temp;
	for(i = 0; i <= 200; i++) {
		cube[i] = i * i * i;
	}
	for(point = 6; point <= 200; point++) {
		for(i = 2; cube[point] > cube[i] * 3; i++) {
			for(j = i; cube[point] > (cube[i] + cube[j] * 2); j++) {
				for(k = j; cube[point] >= (cube[i] + cube[j] + cube[k]); k++) {
					if(cube[point] == (cube[i] + cube[j] + cube[k])) {
						printf("Cube = %d, Triple = (%d,%d,%d)\n", point, i, j, k);
					}
				}
			}
		}
	}
	return 0;
}
