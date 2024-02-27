#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
} point;

typedef struct
{
    point x1;
    point x2;
    point x3;
    point x4;
} rect;

void rectValues(rect r);
void move(point *p);

int main()
{
   point p = {3, 4};
   move(&p);
   printf("Moved x: %i\n", p.x);
   printf("Moved y: %i\n", p.y);
   
   point p1 = {3, 4};
   point p2 = {7, 4};
   point p3 = {3, 1};
   point p4 = {7, 1};
   
   rect r = {p1, p2, p3, p4};
   rectValues(r);
   
}

void move(point *p)
{
    p->x++;
    p->y++;
}

void rectValues(rect r)
{
    //wyliczam boki figury
    int a = abs(r.x1.x - r.x2.x);
    int b = abs(r.x1.y - r.x3.y);
    int c = abs(r.x2.y - r.x4.y);
    int d = abs(r.x3.x - r.x4.x);
    printf("Circuit: %i\n", a+b+c+d); //obwod
    printf("Area: %i\n", a*b); //pole
}
