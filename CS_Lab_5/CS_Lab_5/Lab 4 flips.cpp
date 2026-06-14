//#include<iostream>
//#include<string>
//using namespace std;
//int minFlips(string s)
//{
//    int count = 0; int cnt = 0;
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (i % 2 == 0)
//		{
//			if (s[i] != '0')
//			{
//				count++;
//			}
//		}
//		else if (i % 2 != 0)
//		{
//			if (s[i] != '1')
//			{
//				count++;
//			}
//		}
//	}
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (i % 2 == 0)
//		{
//			if (s[i] != '1')
//			{
//				cnt++;
//			}
//		}
//		else if (i % 2 != 0)
//		{
//			if (s[i] != '0')
//			{
//				cnt++;
//			}
//		}
//	}
//	return min(count, cnt);
//}
//int main()
//{
//	string s = "0101010";
//	cout<< minFlips(s);
//	return 0;
//}