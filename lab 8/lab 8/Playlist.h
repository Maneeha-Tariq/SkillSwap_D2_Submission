#ifndef PLAYLIST_H
#define PLAYLIST_H
#include<iostream>
#include "Song.h"
#include<stdlib.h>
using namespace std;
template<typename T>
class Playlist
{
	Song<T>* current;
	bool isEmpty()
	{
		return current == nullptr;
	}

	void fisher_Yates(Song<T> * arr)
	{
		srand(time(0));
		Song<T>* p = current;
		Song<T>* prevM = current;
		int count = 1;
		do
		{
			prevM = p;
			p = p->next;
			count++;

		} while (p != current);

		int N = count;
		for (int i = N - 1; i >= 1;i--)
		{
			int j = rand() % i;

			for ( ; j <= i; j++)
			{
				swapNodes(i, j);
			}
		}
	}
	void swapNodes(int m, int n)
	{
		if (m == n) return;

		Song<T>* p = current;
		Song<T>* prevM = current;
		int count = 1;
		do
		{ 
			prevM = p;
			p = p->next;
			count++;

		} while (p != current && count < m);
		

		Song<T>* q = current;
		Song<T>* prevN = current;
		int count1 = 1;
		do
		{
			prevN = q;
			q = q->next;
			count1++;

		} while (q != current && count1 < n);
		
		if (!p || !q)
		{
			return;
		}

		if (prevM != current)
		{
			prevM->prev = prevN;
			prevM->next = q;
		}
		else
		{
			current = q;
		}


		if (prevN != current)
		{
			prevN->prev = p->next;
			prevN->next = prevM;
			
		}
		else
		{
			current = p;
		}

		if (p->next == q)
		{
			if (prevM) prevM->next = q;
			else current = q;

			p->next = q->next;
			q->next = p;
		}
		else
		{
			Song<T>* temp = p->next;
			p->next = q->next;
			q->next = temp;
		}
	}
	

public:

	Playlist() : current(nullptr)
	{
	}

	bool addSong(const Song<T>& s)
	{
		Song<T>* p = current;
		if (isEmpty())
		{
			Song<T>* p = new Song<T>(s);
			if (current)
			{
				p->next = current;
				p->prev = current->prev;
				current->prev->next = p;
				current->prev = p;
				current = p;
			}
			else
			{
				p->next = p;
				p->prev = p;
				current = p;
				return;
				
			}
			return true;
		}
		while (p->next != current)
		{
			p = p->next;
		}
		Song<T>* x = new Song<T>(s);
		p->next = x;
		x->prev = p;
		x->next = current;
		current->prev = x;
		return true;
	}

	bool removeSong(const String& title)
	{
		if (isEmpty())
		{
			return false;
		}

		Song<T>* p = current;

		do
		{
			if (p->title.compare(title) == 0)
			{
				p->next->prev = p->prev;
				p->prev->next = p->next;
				if (current == p)
				{
					current = p->next;
				}
				delete p;
				return;
			}
			p = p->next;
		} while (p != current);

		return true;

	}

	void playCurrent()
	{
		if (isEmpty())
		{
			return;
		}
		if (current)
		{
			cout << "Now Playing: " << current->title;
			current->path = current->path;
		}

	}

	void nextSong()
	{
		if (isEmpty())
		{
			return;
		}
		if (current)
		{
			current->path = current->path;
			current = current->next;
			cout << "Now Playing: " << current->title;
		}

	}

	void prevSong()
	{
		if (isEmpty())
		{
			return;
		}
		if (current)
		{
			current->path = current->path;
			current = current->prev;
			cout << "Now Playing: " << current->title;
		}
	}

	void showPlaylist()
	{
		if (isEmpty())
		{
			exit(0);
		}
		Song<T>* p = current;
		do
		{
			cout << "Playlist: " << p->title << "->";
			p = p->next;

		} while (p != current);
	}

	void shuffleNodes()
	{
		Song<T>* p = current;
		fisher_Yates(p);
	}
	
	void shuffleData()
	{
      
	}

	
};
#endif