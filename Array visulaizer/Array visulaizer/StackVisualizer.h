#ifndef STACK_VISUALIZER_H
#define STACK_VISUALIZER_H
#include <string>
#include "COLORS.h"
#include "Data.h"
#include "Widget.h"
#include <conio.h>
#include "KEYS.h"
#include "ScreenUtil.h"
using namespace Keys;
using namespace COLORS;
using namespace std;
class StackVisualizer
{
	vector<string> algos;
	int current;
	void printAlgoLayout()
	{
		cout << screenUtil::CLEAR_SCREEN << screenUtil::CURSOR_HOME;
		Widget::ChoiceBar(algos, current, [&]() {this->printHeader(); });
	}
	void printHeader()
	{
		Widget::HeaderBar("Stack Algorithms", 7);
		cout << "\n";
	}
public:
	StackVisualizer()
	{
		algos = Data::stackAlgorithms;
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
