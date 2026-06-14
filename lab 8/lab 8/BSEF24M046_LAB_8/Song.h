#ifndef SONG_H
#define SONG_H
#include<iostream>
#include "String.h"
using namespace std;
template<typename T>

struct Song
{
	String title;
	String path;
	Song* next;
	Song* prev;
	Song() : next(nullptr),prev(nullptr)
	{ }
	Song(String t,String p): title(t),path(p),next(nullptr),prev(nullptr)
	{ }
};
#endif