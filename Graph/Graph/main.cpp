
#include <iostream>
#include "Graph.h"
#include <vector>
using namespace std;

// Element struct
struct Element
{
    int value;
    int count;
    Element()
    {
        value = 0;
        count = 0;
    }
};

// MaxHeap template for pointers to Element
template<typename T>
class MaxHeap
{
    T* data;
    int N;
    int noe;

    bool isFull()
    {
        return noe == N;
    }

public:
    MaxHeap()
    {
        data = nullptr;
        N = 1;
        noe = 0;
    }
    MaxHeap(int s)
    {
        N = s;
        noe = 0;
        data = new T[N];
    }

    void insert(T val)
    {
        if (isFull())
        {
            cout << "Heap is full";
            return;
        }

        data[noe] = val;
        int i = noe;
        noe++;

        while (i > 0)
        {
            int par = (i - 1) / 2;
            if (data[par]->count < data[i]->count)
            {
                T temp = data[par];
                data[par] = data[i];
                data[i] = temp;
                i = par;
            }
            else
                break;
        }
    }

    T getMax()
    {
        if (isEmpty())
        {
            cout << "Heap is empty";
            exit(0);
        }
        return data[0];
    }

    T remove()
    {
        if (isEmpty())
        {
            cout << "Heap is empty";
            exit(0);
        }

        T val = data[0];
        data[0] = data[noe - 1];
        noe--;

        int i = 0;
        while (true)
        {
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left >= noe) break;

            int largest = left;
            if (right < noe && data[right]->count > data[left]->count)
                largest = right;

            if (data[i]->count < data[largest]->count)
            {
                T temp = data[i];
                data[i] = data[largest];
                data[largest] = temp;
                i = largest;
            }
            else break;
        }
        return val;
    }

    bool isEmpty()
    {
        return noe == 0;
    }

    int getNoOfElements()
    {
        return noe;
    }

    ~MaxHeap()
    {
        delete[] data;
    }

    void printHeap()
    {
        if (isEmpty())
        {
            cout << "Heap is empty\n";
            return;
        }

        cout << "Heap elements:\n";
        for (int i = 0; i < noe; i++)
        {
            cout << data[i]->value << "(" << data[i]->count << ") ";
        }
        cout << endl;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        
        int len = nums.size();
        vector<int> a(2);
        bool found = false;
        for (int i = 0; i < len; i++)
        {
            int val = nums[i];
            for (int j = 0; j < len; j++)
            {
                if (j != i)
                {
                    if (nums[i] + nums[j] == target)
                    { 
                        found = true;
                        a[0] = i;
                        a[1] = j;
                        return a;
                    }
                    
                }
            }
        }
        if (!found)
        {
            return {};
        }
    }
};
void twoSumTest()
{
     Solution t;
     vector<int> arr = { 3,2,4 };
     vector<int> a = t.twoSum(arr, 6);
     for (int i = 0; i < a.size(); i++)
     {
         cout << a[i] << " ";
     }

     /*  Solution s;
   vector<int> arr = { 1,1,2,1,3,2,4};
   vector<int> a = s.topKFrequent(arr, 2);
   for (int i = 0; i < a.size(); i++)
   {
       cout << a[i] << " ";
   }*/
}
void DFSTest()
{
    Graph grp(5);
    grp.addEdge(0, 1);
    grp.addEdge(1, 2);
    grp.addEdge(2, 3);
    grp.addEdge(3, 4);
    grp.DFS(0);
    cout << "\n\n";

    Graph cycleGraph(4);
    grp = cycleGraph; // reset graph
    grp.addEdge(0, 1);
    grp.addEdge(1, 2);
    grp.addEdge(2, 3);
    grp.addEdge(3, 0);
    cout << "DFS starting from 0: ";
    grp.DFS(0);
    cout << "\n\n";
}
void CycleDirTest()
{
    Graph g(4, true); 
        g.addEdge(0, 1);
        g.addEdge(1, 2);
        g.addEdge(2, 0); 
        g.addEdge(2, 3); 
        
        cout << "Adjacency Matrix:\n";
        g.display();
        cout << "\n\n";
        cout << "DFS Traversal starting from vertex 0:\n";
        g.DFS(0);
        cout << "\n\n";
        cout << "BFS Traversal starting from vertex 0:\n";
        g.BFS(0);
        cout << "\n\n";
        cout << "Cycle detection starting from vertex 0:\n";
        if (g.isCycle(0))
            cout << "Cycle Detected!\n";
        else
            cout << "No Cycle!\n";
}
void cycleUndirTest()
{
    Graph g1(5, false); // undirected graph with 4 vertices
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(2, 3);
    g1.addEdge(3, 1);
    g1.addEdge(3, 4);
    g1.addEdge(1, 4);
    cout << "Graph 1 (Acyclic) adjacency matrix:\n";
    g1.display();

    if (g1.isUndirCycle(0))
        cout << "Graph 1 has a cycle\n";
    else
        cout << "Graph 1 has NO cycle\n";

    cout << "-------------------------------\n";
    Graph g2(4, false); 
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 0); 
    g2.addEdge(2, 3);

    cout << "Graph 2 (Cyclic) adjacency matrix:\n";
    g2.display();

    if (g2.isUndirCycle(0))
        cout << "Graph 2 has a cycle\n";
    else
        cout << "Graph 2 has NO cycle\n";
}


    
    
    



#include "Graph.h"
#include <iostream>
using namespace std;

#include "Graph.h"
#include <iostream>
using namespace std;

int main() {
    // Directed graph example
    Graph g(5, true);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);

    cout << "Adjacency Matrix:\n";
    g.display();

    cout << "\nDFS with timestamps:\n";
    g.DFS_with_Time();

    cout << "\nCycle detection (directed): ";
    if (g.isCycleUsingTimestamps(0))
        cout << "Cycle exists\n";
    else
        cout << "No cycle\n";

    cout << "Undirected cycle detection: ";
    if (g.isUndirCycle(0))
        cout << "Cycle exists\n";
    else
        cout << "No cycle\n";

    cout << "\nCount of connected components (undirected view): "
        << g.countUndirConnectedComponents() << endl;

    cout << "Count of strongly connected components (SCCs): "
        << g.countSCC() << endl;

    return 0;
}














//#include "Graph.h"
//#include<cmath>
//#include "Element.h"
//#include "MaxHeap.h"
//#include<iostream>
//using namespace std;
//int uniqueC(Array<int>arr)
//{
//	int len = arr.getSize();
//	int count = 0;
//	for (int i = 0; i < len; i++)
//	{
//		bool alreadyseen = false;
//		for (int j = i + 1; j < len; j++)
//		{
//			if (arr[i] == arr[j])
//			{
//				alreadyseen = true;
//				break;
//			}
//		}
//		if (alreadyseen)
//		{
//			continue;
//		}
//		count++;
//	}
//	return count;
//}
//Array<int> freq(Array<int> nums, int k)
//{
//	int len = nums.getSize();
//	if (len <= 100000)
//	{
//		Array<int> a(k);
//		if (len == 1)
//		{
//			a[0] = nums[0];
//		}
//		else
//		{
//			int uniqueCount = uniqueC(nums);
//			Array<Element* > arr(uniqueCount);
//			int indx = 0;
//			for (int i = 0; i < len; i++)
//			{
//				bool alreadyCounted = false;
//				for (int k = 0; k < indx; k++)
//				{
//					if (arr[k]->value == nums[i])
//					{
//						alreadyCounted = true;
//						break;
//					}
//				}
//				if (alreadyCounted)
//				{
//					continue;
//				}
//
//				int val = nums[i];
//				int count = 1;
//				for (int j = i + 1; j < len; j++)
//				{
//					if (val == nums[j])
//					{
//						count++;
//					}
//				}
//				arr[indx] = new Element();
//				arr[indx]->value = val;
//				arr[indx]->count = count;
//				indx++;
//			}
//			MaxHeap<Element*> h(uniqueCount);
//			for (int j = 0; j < uniqueCount; j++)
//			{
//				h.insert(arr[j]);
//			}
//			for (int l = 0; l < k; l++)
//			{
//				if (h.isEmpty()) break;
//
//				Element * e =  h.remove();
//				a[l] = e->value;
//			}
//			/*int i = 0;
//			int size = arr.getSize();
//			while (i < size)
//			{
//				int max = i;
//				for (int j = i + 1; j < size; j++)
//				{
//					if (arr[max]->count < arr[j]->count)
//					{
//						max = j;
//					}
//				}
//				if (max != i)
//				{
//					Element* temp = arr[i];
//					arr[i] = arr[max];
//					arr[max] = temp;
//				}
//				i++;
//			}
//			for (int i = 0; i < k; i++)
//			{
//				int val = arr[i]->value;
//				a[i] = val;
//			}*/
//		}
//		return a;
//	}
//}

