#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
 
using namespace std;
 
int arr[10][10];
int n;
 
int main()
{
     
    int testcase;
    cin >> testcase;
    bool result=true;
    stack<char> s;
    queue<char> q;
     
    for(int tc=1;tc<=testcase;tc++)
    {
        char arr[10] = {0,}; //reset
        bool result = true;
        cin >> arr;
        for (int i = 0; i < strlen(arr); i++)
        {
            s.push(arr[i]);
            q.push(arr[i]);
        }
        for (int i = 0; i < strlen(arr); i++)
        {
            if (s.top() != q.front())
                result = false;
            s.pop(); q.pop();
        }
 
 
        cout << "#" << tc << " "<< result << endl;
    }
 
    return 0;
}