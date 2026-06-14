#ifndef MEDIAN_FINDER_H
#define MEDIAN_FINDER_H
#include "MaxHeap.h"
#include "MinHeap.h"
#include "Array.h"
#include <iostream>
using namespace std;
class MedianFinder
{
	MinHeap<int>min;
	MaxHeap<int>max;

public:
	MedianFinder() : max(100), min(100)
	{

	}
	void addNumber(int num)
	{
		if (max.isEmpty())
		{
			max.insert(num);
			return;
		}
		int maxVal = max.getMax();
		if (num <= maxVal)
		{
			max.insert(num);
		}
		else if (num > maxVal)
		{
			min.insert(num);
		}

		int sizeMax = max.getNoOfElements();
		int sizeMin = min.getNoOfElements();
		int diff = sizeMax - sizeMin;
		if (diff < 0)
		{
			diff = (-1) * diff;
		}
		if (diff > 1)
		{
			if (sizeMax > sizeMin)
			{
				min.insert(max.getMax());
				max.remove();
			}
			else if (sizeMin > sizeMax)
			{
				max.insert(min.getMin());
				min.remove();
			}
		}
	}
	float findMedian()
	{
		float median;
		int sizeMax = max.getNoOfElements();
		int sizeMin = min.getNoOfElements();
		
		if (sizeMax == sizeMin)
		{
			median = ((max.getMax() + min.getMin()) / 2.0);
		}
		else if (sizeMax == sizeMin + 1)
		{
			median = max.getMax();
		}
		else
		{
			median = min.getMin();
		}

		return median;
	}
};
#endif