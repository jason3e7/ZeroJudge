 /*
  * @file b512.c
  * @author Jason3e7
  * @algorithm basic
  * @date 201710211329
  */

#include <stdio.h>

int main() {
	int d, v, i, output = 0, firstLine = 1, line[100][2], point = 0;
	while(scanf("%d:%d", &d, &v) != EOF) {
		if(d == 0 && v == 0) {
			if(firstLine == -1) {
				printf("%d\n", output);
				point = 0;
			}
			firstLine *= -1;	
			output = 0;
			continue;
		}
		if(firstLine == 1) {
			line[point][0] = d;
			line[point][1] = v;
			point++;
		} else if(firstLine == -1) {
			for(i = 0; i < point; i++) {
				if(line[i][0] == d) {
					output += (line[i][1] * v);
				}
			}
		}
	}
	return 0;
}

