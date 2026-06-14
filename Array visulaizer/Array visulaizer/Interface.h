#ifndef INTERFACE_H
#include <vector>
#include<iostream>
#include <thread>
#include <chrono>
#include "COLORS.h"
#include "KEYS.h"
#include "StringVisualizer.h"
#include "ScreenUtil.h"
#include <conio.h>
#include "Data.h"
#include "Widget.h"
#include <iomanip>
#include "SortingVisualizer.h"
#include "BitManipVisualizer.h"
#include "ArrayVisualizer.h"
#include "DPVisualizer.h"
#include "GraphVisualizer.h"
#include "MatrixVisualizer.h"
#include "NumberTheoryVisualizer.h"
#include "QueueVisualizer.h"
#include "recursionBacktrackingVisualizer.h"
#include "StackVisualizer.h"
#include  "TreeVisualizer.h"
#include "TrieVisualizer.h"
#include "HashVisualizer.h"
#include "SoundManager.h"
using namespace std::chrono;
using namespace std;
using namespace Keys;
using namespace COLORS;
using namespace screenUtil;
enum ft { SORT = 1, STR, ARR, STK, QUEUE, TREE, GRAPH, TRIE, HASH, DP, RECURSION_B, MATRIX, NUMBER_T, BIT_MANIP };
class Interface
{
	// data Members 
	int current;
	SoundManager soundMgr;
	string splshScrMsg;
	vector<string> features;
	void printLayout()
	{
		cout << CLEAR_SCREEN << CURSOR_HOME;
		Widget::ChoiceBar(features, current, [&]() {printHeader(); });
	}
	void printHeader()
	{
		Widget::HeaderBar("DSA Visulizer : Home Screen", 3);
		cout << "\n";
	}
	void printSplashScreen(milliseconds timeGapOfChar = milliseconds(170)) // done
	{
		soundMgr.play(L"kb.wav");
		cout << "\033[15;30H";
		for (char& ch : splshScrMsg)
		{
			cout << ch;
			this_thread::sleep_for(timeGapOfChar);
		}
		soundMgr.stop();
	}


	void handleTheFeature(int ftNum)
	{
		//cout << ftNum;
		//Sleep(2000);
		switch (ftNum)
		{
		case SORT:
		{
			SortingVisualizer vis;
			vis.start();
			break;
		}
		case STR:
		{
			StringVisualizer vis;
			vis.start();
			break;
		}
		case  ARR:
		{
			ArrayVisualizer vis;
			vis.start();
			break;
		}
		case STK:
		{
			StackVisualizer vis;
			vis.start();
			break;
		}
		case QUEUE:
		{
			QueueVisualizer vis;
			vis.start();
			break;
		}
		case TREE:
		{
			TreeVisualizer vis;
			vis.start();
			break;
		}
		case GRAPH:
		{
			GraphVisualizer vis;
			vis.start();
			break;
		}
		case TRIE:
		{
			TrieVisualizer vis;
			vis.start();
			break;
		}
		case HASH:
		{
			HashVisualizer vis;
			vis.start();
			break;
		}
		case DP:
		{
			DPVisualizer vis;
			vis.start();
			break;
		}
		case RECURSION_B:
		{
			RecurionBacktrackingVisualizer vis;
			vis.start();
			break;
		}
		case MATRIX:
		{
			NatrixVisualizer vis;
			vis.start();

			break;
		}
		case NUMBER_T:
		{
			NumberTheoryVisualizer vis;
			vis.start();
			break;
		}
		case BIT_MANIP:
		{
			BitManipVisualizer vis;
			vis.start();
			break;
		}
		}
	}
public:
	Interface() :current(1)
	{
		features = Data::features;
		splshScrMsg = "DSA Visulizer By Mudassir Ashraf <3 ";
	}
	void start()
	{
		// basic interface 
		this->printSplashScreen();   // un comment this 
		while (true)
		{
			printLayout();
			//this_thread::sleep_for(milliseconds(700));  // no need update instatly 
		getinput:
			if (_kbhit()) {
				int key = _getch();
				switch (key)
				{
				case ARROW_PREFIX:
				{
					key = _getch();
					//cout << "under<<" << key;
					if (key == Keys::DOWN)
						current = (current == (features.size())) ? 1 : ++current;
					else if (key == Keys::UP)
						current = (current == 1) ? features.size() : --current;
					break;
				}
				case ENTER:
				{
					handleTheFeature(current);
					break;
				}
				}
			}
			else {
				goto getinput; /// input loop me phnsa do 
			}
		}
		cout << BLUE << "Current Selected is " << current << "\n";
	}
};
#endif // !INTERFACE_H