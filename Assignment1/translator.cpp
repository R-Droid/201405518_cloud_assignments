#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>
#include <stack>
#include <bitset>
using namespace std;

typedef long long int ll;
typedef pair<int, int > pii;

#define MOD 1000000007
#define pb push_back

int main()
{
	std::ios::sync_with_stdio(false);
	freopen ("G:\\Assignments\\Semester3\\CloudComputing\\Assignment1\\add_32.asm","r",stdin);
	freopen ("G:\\Assignments\\Semester3\\CloudComputing\\Assignment1\\add_64_out.asm","w",stdout);
	string s;
	getline(cin, s);
	while(true)
	{
	    if(s.find(".note.GNU-stack") != std::string::npos)
            break;
		if(s.find("pushl") != std::string::npos)
			s.replace(s.find("pushl"), 5,"pushq");
		if(s.find(" 8") != std::string::npos)
			s.replace(s.find(" 8"), 2," 16");
		if(s.find("-8") != std::string::npos)
			s.replace(s.find("-8"), 2,"-16");
		if(s.find(" 5") != std::string::npos)
			s.replace(s.find(" 5"), 2," 6");
		if(s.find("movl") != std::string::npos)
			s.replace(s.find("movl"), 4,"movq");
		if(s.find("%e") != std::string::npos)
		{
			s.replace(s.find("%e"), 2, "%r");
			if(s.find("%e") != std::string::npos)
				s.replace(s.find("%e"), 2, "%r");
		}
		if(s.find("addl") != std::string::npos)
			s.replace(s.find("addl"), 4, "addq");
		if(s.find("subl") != std::string::npos)
			s.replace(s.find("subl"), 4,"subq");

		cout<<s<<"\n";
		getline(cin, s);
	}
	cout<<s<<"\n";
	return 0;
}
