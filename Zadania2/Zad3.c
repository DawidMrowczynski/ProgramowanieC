#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int x;
    int y;
} Point;

typedef struct
{
    Point x1;
    Point x2;
    Point x3;
    Point x4;
} Rectangle;

void rectValues(Rectangle r);
void move(Point *p);

int main()
{
   Point p = {3, 4};
   move(&p);
   printf("Moved x: %i\n", p.x);
   printf("Moved y: %i\n", p.y);
   
   Point p1 = {3, 4};
   Point p2 = {7, 4};
   Point p3 = {3, 1};
   Point p4 = {7, 1};
   
   Rectangle r = {p1, p2, p3, p4};
   rectValues(r);
   
}

void move(Point *p)
{
    p->x++;
    p->y++;
}

void rectValues(Rectangle r)
{
    //wyliczam boki figury
    int a = abs(r.x1.x - r.x2.x);
    int b = abs(r.x1.y - r.x3.y);
    printf("Circuit: %i\n", a*2+b*2); //obwod
    printf("Area: %i\n", a*b); //pole
}
