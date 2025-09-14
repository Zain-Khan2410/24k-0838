#include <stdio.h>
#include <math.h>

struct coordinates {
    float x1, y1; 
    float x2, y2; 
    float bx[4];  
    float by[4];  
};

void calculateDistance(struct coordinates g) {
    float distance = sqrtf(powf(g.x2 - g.x1, 2) + powf(g.y2 - g.y1, 2));
    printf("Distance: %.2f\n", distance);
}


void checkBoundary(struct coordinates g) {
    int xFlag = 0, yFlag = 0;

    for (int i = 0; i < 2; i++) {
        if (!(g.bx[0] <= (i == 0 ? g.x1 : g.x2) && (i == 0 ? g.x1 : g.x2) <= g.bx[3])) {
            xFlag = 1;
            break;
        }
    }
    for (int i = 0; i < 2; i++) {
        if (!(g.by[0] <= (i == 0 ? g.y1 : g.y2) && (i == 0 ? g.y1 : g.y2) <= g.by[3])) {
            yFlag = 1;
            break;
        }
    }
    if (xFlag == 0 && yFlag == 0) {
        printf("Within boundary.\n");
    } else {
        printf("Out of boundary.\n");
    }
}

int main() {
    struct coordinates geo;
    printf("Enter x-coordinate of point 1: ");
    scanf("%f", &geo.x1);
    printf("Enter y-coordinate of point 1: ");
    scanf("%f", &geo.y1);
    printf("Enter x-coordinate of point 2: ");
    scanf("%f", &geo.x2);
    printf("Enter y-coordinate of point 2: ");
    scanf("%f", &geo.y2);
    for (int i = 0; i < 4; i++) {
        printf("Enter boundary x-coordinate %d: ", i + 1);
        scanf("%f", &geo.bx[i]);
    }
    for (int i = 0; i < 4; i++) {
        printf("Enter boundary y-coordinate %d: ", i + 1);
        scanf("%f", &geo.by[i]);
    }
    calculateDistance(geo);
    checkBoundary(geo);
}
