#include <iostream>
#include "Stack.h"
#include "String.h"
using namespace std;

// Structure for each maze position
struct Cell {
    int r, c;       // current row, column
    String path;    // path taken to reach here
};

void findPath(int maze[10][10], int n)
{
    Stack<Cell> st;              // your Stack class
    bool visited[10][10] = { 0 };  // to avoid loops

    // Check if start or end is blocked
    if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0) {
        cout << "No path possible!\n";
        return;
    }

    // Push the starting cell
    Cell start = { 0, 0, "" };
    st.push(start);
    visited[0][0] = true;

    // While there are still cells to explore
    while (!st.isEmpty())
    {
        Cell cur = st.pop();   // get current position

        // If we reached the goal, print path
        if (cur.r == n - 1 && cur.c == n - 1) {
            cout << "Path found: " << cur.path << endl;
            return;
        }

        // Try 4 possible moves: Down, Right, Up, Left
        // (simpler order for clarity)
        int rowMove[4] = { 1, 0, -1, 0 };
        int colMove[4] = { 0, 1, 0, -1 };
        char dir[4] = { 'D','R','U','L' };

        for (int i = 0; i < 4; i++)
        {
            int nr = cur.r + rowMove[i];
            int nc = cur.c + colMove[i];

            // Check if inside maze and open path
            if (nr >= 0 && nc >= 0 && nr < n && nc < n &&
                maze[nr][nc] == 1 && !visited[nr][nc])
            {
                visited[nr][nc] = true;    // mark visited
                Cell next;
                next.r = nr;
                next.c = nc;
                next.path = cur.path;      // copy old path
                next.path += dir[i];       // add this move
                st.push(next);             // push new cell
            }
        }
    }

    cout << "No path exists!\n"; // if stack becomes empty
}


