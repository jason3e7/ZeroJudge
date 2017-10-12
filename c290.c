 /*
  * @file c290.c
  * @author Jason3e7
  * @algorithm math
  * @date 201710131118
  */

#include <stdio.h>
#include <string.h>

int main() {
	char line[1001];
	int length, out, i;
	while(scanf("%s", line) != EOF) {
		length = strlen(line);
		out = 0;
		for(i = 0; i < length; i++) {
			if(i % 2 == 0) {
				out += (line[i] - '0');
			} else {
				out -= (line[i] - '0');
			}
		}
		if(out < 0) {
			out *= -1;
		}
		printf("%d\n", out);
	}
	return 0;
}



