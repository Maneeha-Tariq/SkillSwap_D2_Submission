#include<iostream>
using namespace std;
#include "COLORS.h"
#include "Interface.h"
#include "StringVisualizer.h"
using namespace COLORS;
#include "ScreenUtil.h"
#include <chrono>
using namespace std::chrono;
#include "SoundManager.h"
#include <thread>
int main()
{
	ios::sync_with_stdio(false);
	cout.tie(nullptr);
	Interface obj;
	obj.start();

	return 0;
}
