#include "linear.h"

// Points in 3D
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
	
// Points in 2D
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
point point::operator+ (point v)
{
	return point(x + v.x,y + v.y);
}
point point::operator* (double a)
{
	return point(x*a,y*a);
}

double point::dot(point v)
{
	return x*v.x + y*v.y; 
}

// Points in nD
nvec::nvec(int nv)
{
	n = nv;
	pos = vector<double>(n);
	
	for(int i = 0; i < n; i++)
	{
		pos[i] = -1;
	}
}

void nvec::setAllPos(vector<double> p)
{
	for(int i = 0; i < n; i++)
	{
		pos[i] = p[i];
	}
}

void nvec::setPos(int i, double val)
{
	pos[i] = val;
}

nvec nvec::operator+(nvec p) // implement crucial check
{
	nvec ans(n);
	if (p.n != n)
	{
		cout << "Fatal error. Attempted addition between " << n << "-vec and " << p.n << "-vec!" << endl;
	}
	for(int i = 0; i < n; i++)
	{
		ans.setPos(i,pos[i] + p.pos[i]);
	}
	
	return ans;
}
nvec nvec::operator*(double a) // scalar multiplication
{
	nvec ans(n);
	
	for(int i = 0; i < n; i++)
	{
		ans.setPos(i, pos[i]*a);
	}
}

void nvec::print()
{
	cout << n << ": ";
	for(int i = 0; i < n; i++)
	{
		cout << pos[i] << " ";
	}
	
	cout << endl;
}
