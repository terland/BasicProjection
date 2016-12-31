#include "linear.h"



spoint::spoint(double x_in, double y_in, double z_in) // Constructor
{
	x = x_in;
	y = y_in;
	z = z_in;
}
	
spoint::spoint() // Empty constructor
{
	x = -1;
	y = -1;	
	z = -1;
}

spoint spoint::operator+ (spoint v) // return this + v as vector
{
	return spoint(x + v.x, y + v.y, z + v.z);
}

spoint spoint::operator* (double a) // return this*a as scalar multiplication
{
	return spoint(x*a,y*a,z*a);
}

double spoint::dot(spoint v) // standard dotproduct
{
	return x*v.x + y*v.y + z*v.z;
}
	