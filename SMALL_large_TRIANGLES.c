#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
void sort_by_area(triangle* tr, int n) {
    float areas[n]; // array storing triangle areas
    double p, S; // for calculating arrays

    // Calculate triangle areas
    for (int i = 0; i < n; i++) {
        p = (tr[i].a + tr[i].b + tr[i].c) / 2.0;
        S = sqrt(p * (p - tr[i].a) * (p - tr[i].b) * (p - tr[i].c));
        areas[i] = S;
    }

    
    for (int i = 1; i < n; i++) {
        if (areas[i] < areas[i - 1]) {
            int j = i;
        
            while (j > 0 && areas[j] < areas[j - 1]) {
                double temp = areas[j];
                triangle temp_tr = tr[j];

                areas[j] = areas[j - 1];
                tr[j] = tr[j - 1];

                areas[j - 1] = temp;
                tr[j - 1] = temp_tr;
                --j;
            }
        }
    }


	
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}