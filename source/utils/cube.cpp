// Cube
#include "entities.h"

class Cube : public PhysicalEntity
{
	public:
		Cube(double size, spoint startPos)
		{
			points = vector<int>(8);
			
		}
};