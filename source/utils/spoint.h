// A fast vector struct

struct spoint
{
	// Double precision seems to be more than enough accuracy, at least at this point in time
	double x,y,z;
	
	spoint(double x_in, double y_in, double z_in) // Constructor
	{
		x = x_in;
		y = y_in;
		z = z_in;
	}
	
	
};