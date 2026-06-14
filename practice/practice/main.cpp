//#include "Queue.h"
//#include "customerServiceSystem.h"
//#include<iostream>
//using namespace std;
//int main() 
//{
//     CustomerServiceSystem system;
//     system.runMenu();   // menu-driven interface
//     return 0;
//}

//#include <iostream>
//#include "Browser.h"
//#include "String.h"
//using namespace std;
//
//int main()
//{
//    Browser b(5); // limit history to 5 pages
//
//    b.visitPage("google.com");
//    b.visitPage("github.com");
//    b.visitPage("stackoverflow.com");
//    b.visitPage("youtube.com");
//    b.visitPage("facebook.com");
//    b.visitPage("linkedin.com");  // oldest (Home) will be trimmed
//
//    b.showHistory();
//
//    b.goBack();
//    b.goBack();
//    b.showHistory();
//
//    b.goForward();
//    b.showHistory();
//
//    b.visitPage("openai.com");
//    b.showHistory();
//
//    b.goBack();
//    b.showHistory();
//   
//    return 0;
//}

//#include "mazeTraversal.h"
//#include<iostream>
//using namespace std;
//int main()
//{
//    int n;
//    cout << "Enter maze size (max 10): ";
//    cin >> n;
//
//    int maze[10][10];
//    cout << "Enter maze (0 = wall, 1 = open):\n";
//    for (int i = 0; i < n; i++)
//        for (int j = 0; j < n; j++)
//            cin >> maze[i][j];
//
//    findPath(maze, n);
//    return 0;
//}

#include<iostream>
using namespace std;
void swap(char* fir, char* sec)
{
	char temp = *fir;
	*fir = *sec;
	*sec = temp;
}
void p(char* a, int curr, int size)
{
	if (curr == size - 1)
	{
		for (int i = 0; i< size; i++)
		{
			cout << a[i] << "\t";
		}
		cout << endl;
	}
	else
	{
		for (int i = curr; i < size; i++)
		{
			swap(&a[curr], &a[i]);
			p(a, curr + 1, size);
			swap(&a[curr], &a[i]);
		}
	}
}
int main()
{
	char str[] = "ABC";
	p(str, 0, sizeof(str) - 1);
	return 0;
	
	return 0;
}
