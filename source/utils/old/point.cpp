#include "linear.h"

point::point(double x_v,double y_v)
{
	x = x_v;
	y = y_v;
}
point::point() 
{
	x = -1;
	y = -1;
}
point::point operator+ (point v)
{
	return point(x + v.x,y + v.y);
}
point::point operator* (double a)
{
	return point(x*a,y*a);
}

point::double dot(point v)
{
	return x*v.x + y*v.y; 
}
