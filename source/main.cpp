// main.cpp
// Veldig basic vektor-operasjoner
#include "utils/entities.h"

int main()
{
	cout << "Hello world!" << endl;
	
	//spoint s = spoint(1,1,1);
	nvec test(4);
	
	test.print();
	return 0;
}

class World
{
	private:
		Camera cam;
		vector<spoint> s;
		
	public:
		World(Camera c)
		{
			cam = c;
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
				spoint diff 
			}
		}
};