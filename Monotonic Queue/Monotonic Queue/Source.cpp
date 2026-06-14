#include <iostream>
using namespace std;



int main() {
    int a= 1691;
    int b= 90;
    char* p = (char*)&a;
    cout << (void*)(*p)<< '\n';
    cout <<(void *) p << endl;
    cout << (void *)( p + 1);
    
  

}
