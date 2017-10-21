 /*
  * @file b603.c
  * @author Jason3e7
  * @algorithm math
  * @date 201710211536
  * @note
(x-h)^2=4c(y-k)

import top point

c = ((c1 - a1) * (c1 - a1)) / (4 * (d1 - b1)) 

(d1 - b1)(x-a1)^2=((c1 - a1) * (c1 - a1))(y-b1)

xHead = (d1 - b1);
yHead = ((c1 - a1) * (c1 - a1));
xHead x^2 - xHead * 2 * a1 * x + xHead * a1 * a1 + yHead * b1 = yHead y 

a2= d1 - b1, b2 = a1 * a2 * -2, d2 = (c1 - a1) * (c1 - a1), c2 = a2 * a1 * a1 + d2 * b1;
  */

#include <stdio.h>

int GCD(int a, int b) {
	if(b) while((a %= b) && (b %= a)); 
	return a + b;
}

int main() {
	int x1, y1, x2, y2, gcd, a, b, c, d;
	while(scanf("%d %d %d %d", &x1, &y1, &x2, &y2) != EOF) {			
		a = (y2 - y1);
		b = (a * x1 * -2);
		d = ((x2 - x1) * (x2 - x1));
		c = ((a * x1 * x1) + (d * y1));
		
		gcd = GCD(a, b);
		gcd = GCD(gcd, c);
		gcd = GCD(gcd, d);
		if(gcd < 0) {
			gcd *= -1;
		}
		a/=gcd;
		b/=gcd;
		c/=gcd;
		d/=gcd;
		printf("%dy = %dx^2 + %dx + %d\n", d, a, b, c);
	}
	return 0;
}

