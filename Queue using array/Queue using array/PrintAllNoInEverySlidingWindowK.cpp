//#include<iostream>
//#include<queue>
//using namespace std;
////void printNo(queue<int>& q,int k)
////{
////	queue<int>q2;
////	bool first = false;
////	while (!q.empty())
////	{
////
////			if (!first && q2.empty())
////			{
////				for (int i = 0; i < k; i++)
////				{
////					cout << q.front() << " ";
////					q2.push(q.front());
////					q.pop();
////				}
////				cout << endl;
////				first = true;
////
////			}
////			else if (first && !q2.empty())
////			{
////				q2.pop();
////				if (!q.empty())
////				{
////					q2.push(q.front());
////				}
////				for (int i = 0; i < k; i++)
////				{
////					cout << q2.front() << " ";
////					q2.push(q2.front());
////					q2.pop();
////				}
////				first = true;
////				cout << endl;
////				q.pop();
////			}
////		
////		
////	}
////}
//void printNo(queue<int> q, int k)
//{
//    int n = q.size();
//
//    for (int i = 0; i <= n - k; i++)
//    {
//        queue<int> temp = q;
//
//        for (int j = 0; j < k; j++)
//        {
//            cout << temp.front() << " ";
//            temp.pop();
//        }
//        cout << endl;
//
//        q.push(q.front());
//        q.pop();
//    }
//}
//void display(queue<int>q)
//{
//    while (!q.empty())
//    {
//        cout << q.front()<<" ";
//        q.pop();
//    }
//    cout << endl;
//}
//void printNoArr(int k, int* arr, int size)
//{
//    queue<int>q;
//    for (int i = 0; i < k - 1; i++)
//    {
//        q.push(arr[i]);
//    }
//    for (int i = k - 1; i < size; i++)
//    {
//        q.push(arr[i]);
//        display(q);
//        q.pop();
//    }
//}
//vector<int> printFirstNegative(int* arr, int size, int k)
//{
//    queue<int> q;
//    vector<int> ans;
//
//    for (int i = 0; i < k - 1; i++)
//    {
//        if (arr[i] < 0)
//        {
//            q.push(i);
//        }
//    }
//
//    for (int i = k - 1; i < size; i++)
//    {
//        if (arr[i] < 0)
//        {
//            q.push(i);
//        }
//         //remove indices outside window
//        while (!q.empty() && q.front() <= i - k)
//        {
//            q.pop();
//        }
//        if (q.empty())
//        {
//            ans.push_back(0);
//        }
//        else
//        {
//            ans.push_back(arr[q.front()]);
//        }
//    }
//
//    return ans;
//}
////using vector/array
//string firstNonRepeatChar(string s)
//{
//    string b; string str;
//    vector<int>v(26, 0);
//    for (int i = 0; i < s.size(); i++)
//    {
//        str += s[i];
//        v[s[i] - 'a']++;
//        int j = 0; int found = false;
//        while (j < str.size())
//        {
//            if (v[str[j] - 'a'] == 1)
//            {
//                b += str[j];
//                found = true;
//                break;
//            }
//            j++;
//        }
//        if (!found)
//        {
//            b += "#";
//        }
//    }
//    return b;
//}
////using queue optimized code
//string firstNonRepeated(string s)
//{
//    queue<int>q; string br;
//    vector<int>v(26, 0);
//    for (int i = 0; i < s.size(); i++)
//    {
//        v[s[i] - 'a']++;
//        if (v[s[i] - 'a'] == 1)
//        {
//            q.push(s[i]);
//        }
//        int j = 0; int size = q.size();
//        if (!q.empty())
//        {
//            while (j < size)
//            {
//                int fr = q.front();
//                if (v[fr - 'a'] > 1)
//                {
//                    q.pop();
//                    if (q.empty())
//                    {
//                        br += "#";
//                        break;
//                    }
//                }
//                else if (v[fr - 'a'] == 1)
//                {
//                    br += fr;
//                    break;
//                }
//                j++;
//            }
//        }
//        else
//        {
//            br += "#";
//        }
//    }
//    return br;
//}
//int firstUniqChar(string s)
//{
//    vector<int>v(26, 0);
//    queue<int>repeated;
//    for (int i = 0; i < s.size(); i++)
//    {
//        v[s[i] - 'a']++;
//        if (v[s[i] - 'a'] == 1)
//        {
//            repeated.push(i);
//        }
//        else if (!repeated.empty() && v[s[i] - 'a'] > 1)
//        {
//            int size = repeated.size();
//            while (size--)
//            {
//                if (v[s[repeated.front()] - 'a'] > 1)
//                {
//                    repeated.pop();
//                }
//                else
//                {
//                    repeated.push(repeated.front());
//                    repeated.pop();
//                }
//            }
//
//        }
//
//    }
//    return repeated.empty()?-1:repeated.front();
//}
//void flip(vector<int>& nums, int ind2, int ind3)
//{
//    if (nums[ind2] == 1)
//        nums[ind2] = 0;
//    else
//        nums[ind2] = 1;
//
//    if (nums[ind3] == 1)
//        nums[ind3] = 0;
//    else
//        nums[ind3] = 1;
//}
////without queue
//int minOperations(vector<int>& nums)
//{
//    int operations = 0;
//    for (int i = 0; i <= nums.size()-3; i++)
//    {
//        if (nums[i] == 0)
//        {
//            int ind2 = i + 1;
//            int ind3 = i + 2;
//         
//            nums[i] = 1;
//
//            flip(nums,ind2,ind3);
//
//            operations++;
//        }
//        else
//        {
//            continue;
//        }
//    }
//    for (int i = 0; i < nums.size(); i++)
//    {
//        if (nums[i] != 1)
//        {
//            return -1;
//        }
//    }
//    return  operations;
//}
////with queue
//int minOperation(vector<int>& nums)
//{
//    queue<int>q;
//    int flip = 0;
//    for (int i = 0; i < nums.size(); i++)
//    {
//        if (!q.empty() && q.front() < i)
//        {
//            q.pop();
//        }
//        int curr = nums[i];
//        if (q.size() % 2 == 1)
//        {
//            if (curr == 0) curr = 1;
//            else curr = 0;
//        }
//        if (curr == 0)
//        {
//            if (i + 2 >= nums.size()) return -1;
//            q.push(i + 2);
//            flip++;
//        }
//            
//        
//    }
//    return flip;
//}
//int main()
//
//{
// //   // -3,-3,-4,-2,
// //   int arr[7] = { -1, -2, -3, -4, 5, 6, 7 };
//	//vector<int>v = printFirstNegative(arr,7,2);
// //   for (int i = 0; i < v.size(); i++)
// //   {
// //       cout << v[i] << " ";
// //   }
//    /*string a = "leetcode";
//    int s = firstUniqChar(a);
//    cout << s;*/
//    vector<int> s;
//    s.push_back(0);
//    s.push_back(1);
//    s.push_back(1);
//    s.push_back(1);
//    /*s.push_back(0);
//    s.push_back(0);*/
//    cout << minOperation(s);
//    return 0;
//}