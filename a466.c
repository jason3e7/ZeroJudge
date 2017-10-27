 /*
  * @file a466.c
  * @author Jason3e7
  * @algorithm string 
  * @UVa 12289
  * @date 201710281233
  */

#include <stdio.h>
#include <string.h>

int main() {
	int i, n, length, flag;
	char line[10001], one[3] = "one", two[3] = "two";
	while(scanf("%d", &n) != EOF) {
		while(n--) {
			scanf("%s", line);
			length = strlen(line);
			if(length == 5) {
				printf("3\n");
				continue;
			}
			flag = 0;
			for(i = 0; i < length; i++) {
				if(line[i] == one[i]) {
					flag++;
				} else if(line[i] == two[i]) {
					flag--;
				}
			}
			if(flag > 0) {
				printf("1\n");
			} else if(flag < 0) {
				printf("2\n");
			}
		}
	}
	return 0;
}

