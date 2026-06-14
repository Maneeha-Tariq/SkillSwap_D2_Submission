#include "Array.h"
#include <iostream>
#include <cmath>
#include "String.h"
#include "Element.h"
using namespace std;

Array<int> topKFrequent(Array<int> nums, int k)
{
	int len = nums.getSize();
	
	Array<Element* > arr;
	if (len <= pow(10, 5))
	{
		for (int i = 0; i < len; i++)
		{
			int count = 1;
			int val = nums[i];
			for (int j = i + 1; j < len; j++)
			{
				if (val == nums[j])
				{
					count++;
				}
			}
			arr.reSize(1);
			
			
		}
	}
	
}
int main()
{
	Array<int> arr = {1,2,1,2,1,2,3,1,3,2};
	cout<< topKFrequent(arr, 2);
}
