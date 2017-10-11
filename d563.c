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
		for(i = 0; i < n; i++) {
			scanf("%d", &number[i]);
		}
		sum = 0;
		begin = number[0];
		end = number[n - 1];
		for(i = 1, j = n - 2; i < n && j >= 0;){
			if(begin == end) {
				sum++;	
				begin += number[i];
				i++;
				end += number[j];
				j--;
			} else if(begin < end) {
				begin += number[i];
				i++;
			} else if(begin > end) {
				end += number[j];
				j--;
			}
		}
		sum++;
		printf("%d\n", sum);
	}
	return 0;
}



