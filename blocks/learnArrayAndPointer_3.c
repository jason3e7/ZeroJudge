 /*
  * @file learnArrayAndPointer_3.c
  * @author Jason3e7
  * @algorithm array and pointer
  * @date 201710202324
  * @ref https://stackoverflow.com/questions/41647445/incompatible-pointer-types-passing-int55-to-parameter-of-type-int
  */

#include <stdio.h>

void pr_1(int **a) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%3d", a[i][j]);
		}
        putchar('\n');
    }
    putchar('\n');
}
void pr_2(int a[][5]) {
	int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%3d", a[i][j]);
		}
        putchar('\n');
    }
    putchar('\n');
}
void pr_3(int n, int a[n][n]) {
	int i, j;
	for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
			printf("%3d", a[i][j]);
		}
        putchar('\n');
    }
    putchar('\n');
}
void swap(int **a, int **b) {
	int* temp = *a;
	*a = *b;
	*b = temp;
}

int main(void)
{
    int *a1[] =
    {
        (int[]){  1,  4,  7, 11, 15 },
        (int[]){  2,  5,  8, 12, 19 },
        (int[]){  3,  6,  9, 16, 22 },
        (int[]){ 10, 13, 14, 17, 24 },
        (int[]){ 18, 21, 23, 26, 30 },
    };
    int a2[5][5] =
    {
        {  1,  4,  7, 11, 15 },
        {  2,  5,  8, 12, 19 },
        {  3,  6,  9, 16, 22 },
        { 10, 13, 14, 17, 24 },
        { 18, 21, 23, 26, 30 },
    };

    pr_1(a1);
    pr_2(a2);
    pr_3(5, a2);
    
	int *b1[] =
    {
        (int[]){  0,  0,  0,  0,  0 },
        (int[]){  0,  0,  0,  0,  0 },
        (int[]){  0,  0,  0,  0,  0 },
        (int[]){  0,  0,  0,  0,  0 },
        (int[]){  0,  0,  0,  0,  0 },
    };   
	swap(a1, b1);
    pr_1(a1);
    pr_1(b1);
	
	swap(&a1[1], &b1[1]);
    pr_1(a1);
    pr_1(b1);
    
	int *c1[] = {(int[]){  1,  1,  1,  1,  1 }};
    int *d1[] = {(int[]){  2,  2,  2,  2,  2 }};
	
	swap(c1, d1);
	int i;
	for(i = 0; i < 5; i++) {
		printf("%d", c1[0][i]);
	}
	printf("\n");
	for(i = 0; i < 5; i++) {
		printf("%d", d1[0][i]);
	}
	printf("\n");

	return 0;
}

