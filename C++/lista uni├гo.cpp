#include <iostream>
#include <list>
using namespace std;
int main()
{
	list<int> primeira;
	list<int> segunda;
	list<int> terceira;
	list<int>::iterator p1;
	list<int>::iterator p2;
	list<int>::iterator p3;
	int x = 1;
	int y = 1;
	while(x != 0)
	{
		cin >> x;
		if(x != 0)
		{
			primeira.push_back(x);
		}
	}
	while(y != 0)
	{
		cin >> y;
		if(y != 0)
		{
			segunda.push_back(y);
		}
	}
	p1 = primeira.begin();
	p2 = segunda.begin();

	while(p1 != primeira.end() && p2 != segunda.end())
	{
		if(*p1 == *p2)
		{
			terceira.push_back(*p1);
			p1++;
			p2++;
		}
		else if(*p2 < *p1)
		{
			terceira.push_back(*p2);
			p2++;
		}
		else if(*p2 > *p1)
		{
			terceira.push_back(*p1);
			p1++;
		}
		else if(p1 == primeira.end() && p2 != segunda.end())
		{
			terceira.push_back(*p2);
			p2++;
		}
		else if(p1 != primeira.end() && p2 == segunda.end())
		{
			terceira.push_back(*p1);
			p1++;
		}

	}
	for( p3 = terceira.begin(); p3 != terceira.end(); p3++)
	{
		cout << *p3 << " ";
	}
	return 0;
}
