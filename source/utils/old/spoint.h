// A fast vector struct

struct spoint
{
	// Double precision seems to be more than enough accuracy, at least at this point in time
	double x,y,z;
	
	spoint(double x_in, double y_in, double z_in) // Constructor
	{
	}
	
	spoint() // Empty constructor
	{
	}
	
	spoint operator+ (spoint v) // return this + v as vector
	{
	}
	
	spoint operator* (double a) // return this*a as scalar multiplication
	{
	}
	
	double dot(spoint v) // standard dotproduct
	{
	}
	
};