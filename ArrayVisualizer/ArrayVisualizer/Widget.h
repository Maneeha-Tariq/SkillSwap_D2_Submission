#ifndef WIDGET_H
#define WIDGET_H
#include <vector>
#include "COLORS.h"
#include <string>
#include <iostream>
#include <functional>
using namespace std;
using namespace COLORS;
#include "ScreenUtil.h"
#include <iomanip>
using namespace screenUtil;
class Widget
{
public:
	static void ChoiceBar(vector<string> features, int toChose,function<void ()> fn)
	{
		cout << CLEAR_SCREEN << CURSOR_HOME;
		fn();
		for (int i = 0; i < features.size(); i++)
		{
			if (i + 1 == toChose)
			{
				cout <<RED<<"*"<<RESET<<" "<< BG_BRIGHT_BLACK << features[i] << RESET << "\n";
			}
			else {
				cout <<RED << "*" << RESET << " " << BOLD << features[i] << '\n';
			}
		}
	}
	static void HeaderBar(string title, int beforeSpaces = 0)
	{
		cout << BOLD << BLUE << setfill('-') << setw(35) << "";
		string sp = string(beforeSpaces, ' ');
		cout << "\n|" << RESET << setfill(' ') << sp<<title << left << string(35-beforeSpaces-title.length()-1,' ') << right << BLUE << "|\n";
		cout << BOLD << setfill('-') << setw(35) << "" << RESET;
	}
};
#endif // !WIDGET_H
