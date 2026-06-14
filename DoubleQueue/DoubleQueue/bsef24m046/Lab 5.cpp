#include <iostream>
#include "String.h"
#include< fstream>
using namespace std;
int main()
{
	ofstream ofs("lab4");
	if (!ofs.is_open())
	{
		cout << "File not open\n";
	}
	cout << "Enter number to put on file: ";
	char x;
	cin >> x;
	ofs.put(x);
	cin.ignore();
	cout << "Enter choice: ";
	int choice;
	cin >> choice;
	if (choice)
	{
		char cho;
		cin >> cho;
		if (cho == 'y' || 'Y')
		{
			do
			{
				String t;
				cout << "Please enter String if you want\n";
				t.input();

				int i = 0;
				while (t[i] != '\0')
				{
					ofs.put(t[i]);
					i++;
				}
				String a("add");
				if (t.compare(a) == 0)
				{
					char s;
					cin >> s;
					ofs.put(s);
				}

				cout << "Do you want to try again? Y or N: ";
				cin >> cho;

			} while (cho == 'y' || 'Y');
		}
	}
	ofs.close();
	
	
	
}