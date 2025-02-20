// Entities
#include "linear.h"

class PhysicalEntity // So far - physical entity is a vector of points. Triangulation later?
{
	public:
		//String getSignature();
		//void rotateX(double rad);
		//void rotateY(double rad);
		//void rotateZ(double rad);
		vector<spoint> getPoints()
		{
			return points;
		}
		vector<vector<int> > triangles;
		
	protected:
		spoint pos;
		vector<spoint> points;
};

class Camera
{
	
	
	public:
		spoint pos;
		spoint dir; // size 1!
		Camera(spoint p, spoint d);
		Camera();
};

class Cube : public PhysicalEntity
{
	public:
		Cube(double size, spoint startPos);
		void RotateX(double rad);
		void RotateY(double rad);
		
};