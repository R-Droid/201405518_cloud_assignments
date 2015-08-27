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
	freopen ("32_bit.asm","r",stdin);
	freopen ("64_bit_conv.asm","w",stdout);
	string s;
	bool first = true;
	getline(cin, s);
	cout<<"extern printf"<<"\n";
	while(true)
	{
	    if(s.find("	int 80h") != std::string::npos && !first)
        {
        	s.replace(s.find("	int 80h"), 8, "ret");
        	break;	
        }
		
		if(s.find("	hello:     db 'Hello world',10") != std::string::npos)
			s.replace(s.find("	hello:     db 'Hello world',10"), 31,"msg:	db 'Hello world', 0");
		
		if(s.find("helloLen:") != std::string::npos)
			s.replace(s.find("helloLen:"), 22,"fmt:    db \"%s\", 10, 0");
		
		if(s.find("	global _start") != std::string::npos)
			s.replace(s.find("	global _start"), 14,"        global main");
		
		if(s.find("_start:") != std::string::npos)
			s.replace(s.find("_start:"), 7,"main:");
		
		if(s.find("	mov eax,4") != std::string::npos)
			s.replace(s.find("	mov eax,4"), 10,"        push    rbp");
		
		if(s.find("	mov ebx,1") != std::string::npos)
			s.replace(s.find("	mov ebx,1"), 10, "	mov	rdi,fmt");

		if(s.find("	mov ecx,hello") != std::string::npos)
			s.replace(s.find("	mov ecx,hello"), 14, "	mov	rsi,msg");

		if(s.find("	mov edx,helloLen") != std::string::npos)
			s.replace(s.find("	mov edx,helloLen"), 17, "	mov	rax,0");
		
		if(s.find("	int 80h") != std::string::npos && first)
		{
			s.replace(s.find("	int 80h"), 8, "        call    printf");
			first = false;
		}

		if(s.find("	mov eax,1") != std::string::npos)
			s.replace(s.find("	mov eax,1"), 10, "pop	rbp");

		if(s.find("	mov ebx,0") != std::string::npos)
			s.replace(s.find("	mov ebx,0"), 10, "	mov	rax,0");

		cout<<s<<"\n";
		getline(cin, s);
	}
	cout<<s<<"\n";
	return 0;
}
