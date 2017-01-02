// Implementation of entities
#include "entities.h"


Cube::Cube(double size, spoint startPos)
{
	points = vector<spoint>(8);
			
	points[0] = spoint(0,0,0);
	points[1] = spoint(0,0,1);
	points[2] = spoint(0,1,0);
	points[3] = spoint(0,1,1);
	points[4] = spoint(1,0,0);
	points[5] = spoint(1,0,1);
	points[6] = spoint(1,1,0);
	points[7] = spoint(1,1,1);
			
	for(int i = 0; i < 8; i++)
	{
		points[i] = points[i] * size;
		points[i] = points[i] + startPos;
	}
			
	// Lage trekanter
	triangles = vector<vector<int> >(12);
			
			
	// Under
	triangles[0] = vector<int>(3);
	triangles[0][0] = 0;
	triangles[0][1] = 1;
	triangles[0][2] = 2;	
}

Camera::Camera(spoint p, spoint d)
{
	spoint dir2 = d * (1/(sqrt(d.dot(d))));	
	pos = p;
}