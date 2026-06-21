#include <stdio.h>
#include <stdlib.h>

#define MAX_POINTS 1000


typedef struct {
    double x; 
    double y;
    int id;
} POINT;

POINT points[MAX_POINTS];
int hull[MAX_POINTS];
int hull_size = 0;


double vector_multiply(POINT O, POINT A, POINT B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}


void build_hull(int n) {
    int start_idx = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].x < points[start_idx].x) {
            start_idx = i;
        }
    }

    int current_idx = start_idx;
    int next_idx;

    do {
        hull[hull_size++] = current_idx;
        
        next_idx = (current_idx + 1) % n;

        for (int i = 0; i < n; i++) {
            double c = vector_multiply(points[current_idx], points[next_idx], points[i]);
            
            if (c > 0) {
                next_idx = i; 
            } else if (c == 0) {
                double dx1 = points[next_idx].x - points[current_idx].x;
                double dy1 = points[next_idx].y - points[current_idx].y;
                double dx2 = points[i].x - points[current_idx].x;
                double dy2 = points[i].y - points[current_idx].y;
                
                if (dx2*dx2 + dy2*dy2 > dx1*dx1 + dy1*dy1) {
                    next_idx = i;
                }
            }
        }

        current_idx = next_idx;

    } while (current_idx != start_idx);
}

int main(int argc, char *argv[]) {
    FILE *inp = fopen("IN.txt", "r");

    int n = 0, num;
    double x, y;
    while (fscanf(inp, "%d %lf %lf", &num, &x, &y) == 3 && n < MAX_POINTS) {
        points[n].x = x;
        points[n].y = y;
        points[n].id = num;
        n++;
    }
    fclose(inp);

    build_hull(n);
    
    FILE *out = fopen("output.dat", "w");
    printf("Hull consists of %d points:\n", hull_size);
    
    for (int i = 0; i < hull_size; i++) {
        int idx = hull[i];
        printf("Point num%d: (%.1f, %.1f)\n", points[idx].id, points[idx].x, points[idx].y);
        fprintf(out, "%d\n", points[idx].id);
    }
    
    fclose(out);
    
    return 0;
}
