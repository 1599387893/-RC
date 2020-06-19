#include<iostream>
#include<set>
#include<string>
using namespace std;


int main()
{
	string tiles = "AAB";
	set<string> res;
	res.insert("");
	for (int i = 0; i < tiles.size(); ++i)
	{
		int size = res.size();
		auto it = res.begin();
		for (int j = 0; j < size; ++j)
		{
			string temp = *it;
			temp.push_back(tiles[i]);
			res.insert(temp);
			it++;
		}
	}
	cout << res.size() << endl;
	return  0;
}