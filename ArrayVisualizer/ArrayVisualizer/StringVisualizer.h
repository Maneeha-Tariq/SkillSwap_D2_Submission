#ifndef STRING_H
#define STRING_H
#include <string>
#include "COLORS.h"
#include "Data.h"
#include "Widget.h"
#include <conio.h>
#include "KEYS.h"
#include "ScreenUtil.h"
enum algoString { REVERSE=1 };
using namespace Keys;
using namespace COLORS;
using namespace std;
#include<chrono>
using namespace std::chrono;
#include <thread>
class StringVisualizer
{
	vector<string> algos;
	int current;
	void printAlgoLayout()
	{
		cout << screenUtil::CLEAR_SCREEN << screenUtil::CURSOR_HOME;
		Widget::ChoiceBar(algos, current, [&]() {this->printHeader();});
	}
	void printHeader()
	{
		Widget::HeaderBar("String Algorithms", 7);
		cout << "\n";
	}
	
	void handleAlgo(int algo)
	{
		switch (algo)
		{
		case REVERSE:
		{
			reverseString(); // all the data class and other thingd should be done so make a roadmap before this
			break;
		}
		}
	}

	// algoss
	void reverseString()
	{
		string  str = Data::strToRev;
		cout << screenUtil::CLEAR_SCREEN<<screenUtil::CURSOR_HOME;
		string msg = "We just take two pointers"+YELLOW+" first pointer" + RESET + " pointing first character, and " + YELLOW + "last" + RESET + " to Last\033[4;20H Swap and do it recursivly";
		cout << "\033[3;20H";
		for (auto& ch : msg)
		{
			this_thread::sleep_for(milliseconds(7));
			cout << ch;
		}

		// swap logic 
		int fp = 0,lp=str.length()-1;
		int l = lp+1;
		while (fp < lp)
		{
			cout << screenUtil::CLEAR_SCREEN << screenUtil::CURSOR_HOME;
			cout << "\033[3;20H";
			for (int i = 0; i < l; i++)
			{
				if (i != fp && i != lp)
					cout << str[i];
				else
					cout << RED << str[i] << RESET;
	
			}
			this_thread::sleep_for(milliseconds(700));
			cout << screenUtil::CLEAR_SCREEN << screenUtil::CURSOR_HOME;
			cout << "\033[3;20H";
			for (int i = 0; i < l; i++)
			{
				if (i != fp && i != lp)
					cout << str[i];
				else
					cout << GREEN << str[i] << RESET;

			}
			this_thread::sleep_for(milliseconds(700));
			int temp = str[fp];
			str[fp] = str[lp];
			str[lp] = temp;
			fp++;
			lp--;
		}
	}

public:
	StringVisualizer()
	{
		algos = Data::stringAlgorithms;
		current = 1;
	}
	// if wanna add features to String then do here 
	void start()
	{
		trueLoop:
		while (true)
		{
			printAlgoLayout();
			bool exit = false;
			getInput:
			if (_kbhit())
			{
				int key = _getch();
				switch (key)
				{
				case ARROW_PREFIX:
				{
					key = _getch();
					if (key == Keys::UP)
					{
						current = (current == 1) ? algos.size() : --current;
					}
					else if (key == Keys::DOWN)
					{
						current = (current == algos.size()) ? 1 : ++current;
					}
					break;
				}
				case ENTER :
				{
					handleAlgo(current);
					break;
				}
				case ESC:
				{
					exit = true;
					break;
				}
				}
			}
			else {
				goto getInput;
			}
			if (exit)
				break;

		}
	}
};
#endif // !STRING_H
