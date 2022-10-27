#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<vector <char> >ss[5];

	for(int i = 0; i < 5; i++)
	{
		vector <char> o;
		// o.push_back('j');
		// o.push_back('o');
		// o.push_back('k');
		ss[i].push_back(o);
	}
	
	string res;
	ss[0][0].push_back('l');
	// for(int i = 0; i < 5; i++)
	// {
	// 	string h;
	// 	h = string(ss[i][0].begin(), ss[i][0].end());
	// 	res += h;
	// }
	
	return 0;
}