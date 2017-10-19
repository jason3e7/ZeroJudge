 /*
  * @file a647.c
  * @author Jason3e7
  * @algorithm accuracy
  * @date 201710201024
  * @test case
20000 21797
  */

#include <stdio.h>
const double capaity = 1e-6;

int main() {
	int n;
	double m, p, out;
	while(scanf("%d", &n) != EOF) {
		while(n--) {
			scanf("%lf %lf", &m, &p);
			out = (p - m) * 100 / m;
			if(out >= 0) {
				printf("%6.2lf%% ", out + capaity);
			} else {
				printf("%6.2lf%% ", out - capaity);
			}
			if(out >= 10.00 || out <= -7.00) {
				printf("dispose\n");
			} else {
				printf("keep\n");
			}
		}
	}
	return 0;
}

