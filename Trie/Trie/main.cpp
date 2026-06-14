#include "Trie.h"
#include <iostream>
using namespace std;

int main()
{
    Trie trie;

    // Insert words
    trie.insert(String("cat"));
    trie.insert(String("car"));
    trie.insert(String("care"));
    trie.insert(String("call"));
    trie.insert(String("dog"));

    // Test search
    cout << "Search 'cat': " << trie.search(String("cat")) << endl;   // 1
    cout << "Search 'car': " << trie.search(String("car")) << endl;   // 1
    cout << "Search 'cap': " << trie.search(String("cap")) << endl;   // 0
    cout << "Search 'dog': " << trie.search(String("dog")) << endl;   // 1
    cout << "Search 'do': " << trie.search(String("do")) << endl;     // 0

    // Test autocomplete
    Array<String> result;

    result = trie.autoComplete(String("ca"));
    cout << "\nAutocomplete 'ca': " << result << endl;  // {cat , car , care , call}

    result = trie.autoComplete(String("car"));
    cout << "Autocomplete 'car': " << result << endl;    // {car , care}

    result = trie.autoComplete(String("do"));
    cout << "Autocomplete 'do': " << result << endl;     // {dog}

    result = trie.autoComplete(String("x"));
    cout << "Autocomplete 'x': " << result << endl;      // {} empty

    return 0;
}
