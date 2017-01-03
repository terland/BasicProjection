// main.cpp
// Veldig basic vektor-operasjoner
#include "utils/entities.h"


class World
{
	private:
		Camera cam; // Anta cam.dir = (0,0,1) først
		vector<spoint> s;
		spoint v1;
		spoint v2;
		
	public:
		World(Camera c)
		{
			cam = c;
			// Find orthogonal basis
		}
		
		void addSpoint(spoint sv)
		{
			s.push_back(sv);
		}
		
		vector<point> generate()
		{
			// Project onto 2D
			vector<point> ans(s.size());
			for(int i = 0; i < s.size(); i++)
			{
				spoint cup = s[i];
				spoint diff = cup + (cam.pos * -1);
			
				// Solve certain linear equation: cam.dir.x diff.x t+ cam.dir.y * diff.y t + cam.dir.z * diff.z t = 1
				
				if (cam.dir.dot(diff)*cam.dir.dot(diff) < 0.01)
				{
					// Out of bounds
					ans[i] = point(-1,-1);
					continue;
				}
				spoint sol = diff * (1/(cam.dir.dot(diff)));
				cout << sol.z << " err..." << endl;
				cout << sol.dot(cam.dir) << endl;
				ans[i] = point(sol.x,sol.y);
			}
			
			return ans;
		}
};

int main()
{
	cout << "Hello world!" << endl;
	
	//spoint s = spoint(1,1,1);
	nvec test(4);
	
	test.print();
	
	World w(Camera(spoint(0,0,-1),spoint(0,0,1)));
	Cube c(1,spoint(-1,0,5));
	
	
	for(int i = 0; i < c.getPoints().size(); i++)
	{
		w.addSpoint(c.getPoints()[i]);
	}
	
	vector<point> p = w.generate();
	
	for(int i = 0; i < p.size(); i++)
	{
		cout << p[i].x << ", " << p[i].y << endl;
	}
	return 0;
}
