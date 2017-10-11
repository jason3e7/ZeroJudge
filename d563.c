 /*
  * @file d563.c
  * @author Jason3e7
  * @algorithm array
  * @date 201710121006
  */

#include <stdio.h>
int main() {
	int n, number[100001], i, j, sum, begin, end;
	while(scanf("%d", &n) != EOF) {
		sum = 0;
		begin = 0;
		end = 0;
		for(i = 0; i < n; i++) {
			scanf("%d", &number[i]);
		}
		for(i = 0; i < n; i++) {
			begin += number[i];
			end = 0;
			for(j = n - 1; j >= 0; j--) {
				end += number[j];
				if(begin == end) {
					sum++;
				}
				if(end >= begin) {
					break;
				}
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}


