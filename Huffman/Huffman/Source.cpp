#include "Huffman.h"
#include <iostream>
using namespace std;

int main()
{
    String msg = "abcdefg";
    Huffman h(msg);
    h.build();
    cout << "Huffman Codes:\n";
    h.showCodes();
    return 0;
}