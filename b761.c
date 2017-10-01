 /*
  * @file b761.c
  * @author Jason3e7
  * @algorithm math
  * @date 201710011707
  */

#include <stdio.h>
int main() {
	int n;
	while(scanf("%d", &n) != EOF) {
		if(n % 4 == 0)
			printf("egg\n");
		else 
			printf("fat\n");	
	}
	return 0;
}

