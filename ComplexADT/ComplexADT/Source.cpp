#include "Complex.h"
#include<iostream>
#include<math.h>

int main()
{
        //// Step 1: Create some Complex objects
        //Complex c1(3, 4);   // magnitude = 5
        //Complex c2(1, 1);   // magnitude ≈ 1.41
        //Complex c3(2, -2);  // magnitude ≈ 2.82

        //// Step 2: Create array of pointers
        //Complex* arr[3];
        //arr[0] = &c1;
        //arr[1] = &c2;
        //arr[2] = &c3;

        //// Step 3: Sort by magnitude
        //Complex** sortedArr = Complex::sortByMagnitude(arr, 3);

        //// Step 4: Display sorted result
        //cout << "Sorted by Magnitude:\n";
        //for (int i = 0; i < 3; i++)
        //{
        //    sortedArr[i]->display();
        //    cout << "   | magnitude = " << sortedArr[i]->magnitude() << endl;
        //}
    int n;
    cin >> n;
    for (int i = n; i >=1; i = pow(i, 1/3))
    {
        cout << "Neso Academy" << " ";
    }
   
}