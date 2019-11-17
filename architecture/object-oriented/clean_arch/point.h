#ifndef _POINT_H
#define _POINT_H

struct Point;

struct Point* makePoint(double x, double y);
double distance(struct Point *p1, struct Point *p2);

#endif
