#include <iostream>
#include "Deque.h"
#include "String.h"
#include<fstream>
using namespace std;
void  putOnFile()
{
	ofstream ofs("lab4.txt");
	if (!ofs.is_open())
	{
		cout << "File not open\n";
	}
	int x;
	cout << "Enter number to put on file: ";
	cin >> x;
	cin.ignore();
	ofs << x << "\n";

	for (int j = 0; j < x; j++)
	{
		String t;
		cout << "Please enter String if you want\n";
		t.input();

		int i = 0;
		while (i < t.getLength() && t[i] != '\0')
		{
			ofs.put(t[i]);
			i++;
		}
		ofs.put(' ');
		String a("add");
		if (t.compare(a) == 0)
		{
			int s;
			cout << "Enter a number to add: ";
			cin >> s;
			cin.ignore();
			ofs << s;
		}
		ofs.put('\n');

	}
	ofs.close();
}
void takeInputFromFile()
{ 
	ifstream ifs("lab4.txt");
	String command;
	String str = "add";
	String st = "jerry!";
	String s = "take";
	DECK<int> cookies;
	int n;
	ifs >> n;
	for (int i = 0; i < n; i++)
	{
		ifs >> command;
		if (command.compare(str)==0)
		{
			int t;
			ifs >> t; 
			cookies.insertElementAtRear(t);
		}
		else if (command.compare(s) == 0)
		{
			if (!cookies.isEmpty())
			{
				cookies.removeElementFromRear();
			}
		}
		else if (command.compare(st) == 0)
		{
			if (!cookies.isEmpty())
			{
				int n = cookies.getNoOfElements();
				int half = n / 2;
				for (int j = 0; j < half; j++)
				{
					int element = cookies.removeElementFromFront();
					cookies.insertElementAtRear(element);
				}
			}
		}
	}
	ifs.close();

	ofstream of("out.txt");
	if (!of.is_open())
	{
		cout << "File not open\n";
		exit(0);
	}
	of << cookies.getNoOfElements()<< "\n";
	while (!cookies.isEmpty())
	{
		of << cookies.removeElementFromFront()<< " ";
	}
	of.close();

}
int main()
{
	putOnFile();
	takeInputFromFile();
	
}