 /*
  * @file b923.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710041011
  */

#include <stdio.h>
int main() {
	int n, m, stack[100001], point, i;
	while(scanf("%d", &n) != EOF) {
		point = 0;
		for(i = 0; i < n; i++) {
			scanf("%d", &m);
			switch(m) {
				case 1 :
					point--;
					break;
				case 2 :	
					printf("%d\n", stack[point - 1]);
					break;
				case 3 :
					scanf("%d", &stack[point]);
					point++;
					break;
				default :
					break;
			}
		}
	}
	return 0;
}

