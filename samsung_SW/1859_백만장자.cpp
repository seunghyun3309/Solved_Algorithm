#include <iostream>
 
using namespace std;
long long int arr[1000000];
long long int result[1000000] = { 0, };
 
int main()
{
    int testcase;
    long long int n=0;
    long long int count = 0;
    cin >> testcase;
    for (int i = 1; i <= testcase; i++)
    {
 
        cin >> n;
        long long int start = 0;
        long long int max_num = 0;
        long long int max = 0;
        for (long long int j = 0; j < n; j++)
        {
            cin >> arr[j];
        }
        while (start < n)
        {
            max_num = start;
            max = arr[max_num];
            for (long long int j = start; j < n; j++) //최댓값과 최댓값 번호 구하기
            {
                if (max < arr[j])
                {
                    max_num = j;
                    max = arr[j];
                }   
            }
             
            for (int k = start; k < max_num; k++) //max_num이 되기 전
            {
                result[i] -= arr[k];
                count++;
            }
            while (count > 0)
            {
                result[i] += max;
                count--;
            }
            start = max_num + 1;
        }
         
    }
    for (int ii = 1; ii <= testcase; ii++)
    {
        cout << "#" << ii << " ";
        cout << result[ii] << endl;
    }
    return 0;
}