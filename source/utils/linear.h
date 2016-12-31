// Basic linear algebra classes and structs needed for the main application

#include <vector>
#include <iostream>
using namespace std;

struct spoint
{
	// Double precision seems to be more than enough accuracy, at least at this point in time
	double x,y,z;
	
	spoint(double x_in, double y_in, double z_in); // Constructor
	
	spoint();
	
	spoint operator+ (spoint v); 
	
	spoint operator* (double a);
	
	double dot(spoint v);
	
};

struct point
{
	double x,y;
	
	point(double x_v,double y_v);
	point();
	
	point operator+ (point v);
	point operator* (double a);
	double dot(point v);
	
};

struct nvec // Might be useful for experimenting with 
{
	vector<double> pos;
	int n;
	
	nvec(int n);
	
	void setAllPos(vector<double> p);
	void setPos(int i, double val);
	
	nvec operator+(nvec p); // implement crucial check
	nvec operator*(double a); // scalar multiplicatio
	
	void print();
};