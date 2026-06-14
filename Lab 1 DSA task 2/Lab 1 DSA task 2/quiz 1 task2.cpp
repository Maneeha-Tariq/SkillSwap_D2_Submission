//#include<iostream>
//using namespace std;
//int keyPresent(int C, int matrix[][4], int R, int key)
//{
//	int col = C - 1;
//	for (int i = 0; i < R && col>=0; i++)
//	{
//		if ( matrix[i][col] == key)
//		{
//			return true;
//		}
//		else if (matrix[i][col] > key)
//		{
//			col--;
//		}
//		else 
//		{
//			R++;
//		}
//	}
//	return false;
//}
//int main()
//{
//	int mat[3][4] = { {1,4,7,11},{2,5,8,12},{3,6,9,16} };
//	cout << keyPresent(4, mat, 3, 15);
//}


//int maxCols = 0;
//for (int i = 0; i < jagged.getSize(); i++)
//    if (jagged[i].getSize() > maxCols) maxCols = jagged[i].getSize();
//
//Array<Array<int>> transposed(maxCols);
//
//for (int c = 0; c < maxCols; c++) {
//    Array<int> colVals;
//    int cnt = 0;
//    for (int r = 0; r < jagged.getSize(); r++) {
//        if (c < jagged[r].getSize()) cnt++;
//    }
//    colVals.reSize(cnt);
//
//    int idx = 0;
//    for (int r = 0; r < jagged.getSize(); r++) {
//        if (c < jagged[r].getSize())
//            colVals[idx++] = jagged[r][c];
//    }
//    transposed[c] = colVals;
//}
//
//// Print
//for (int i = 0; i < transposed.getSize(); i++) {
//    cout << transposed[i] << "\n";
//}