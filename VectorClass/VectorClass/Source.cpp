#include<iostream>
#include "VectorClass.h"
#include<vector>
using namespace std;
void remove(vector<int>& v,int x)
{
	for (int i = 0; i < v.size();)
	{
		if (v[i] == x)
		{
			int j = i;
			while (j < v.size() - 1)
			{
				v[j] = v[j + 1];
				j++;
			}
			v.pop_back();
		}
		else
		{
			i++;
		}
	}
	
}
int main() {
	/*Vector v;
	v.push_back(10); v.push_back(5); v.push_back(30);
	v.push_back(2);
	cout << "Vector elements: "; v.display();
	cout << "Size: " << v.getsize() << endl;
	cout << "Is Empty: " << v.isEmpty() << endl;
	cout << "Element at index 2: " << v.get(2) << endl;
	v.set(1, 15); cout << "After set operation: ";
	v.display();
	cout << endl;
	cout << "Minimum Element: " << v.minElement() << endl;
	cout << "Maximum Element: " << v.maxElement() << endl;
	v.pop_back(); cout << "After pop_back: "; v.display();*/
	vector<int>v = { 1,2,3,2,4,6,2};
	remove(v, 2);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	return 0;
}