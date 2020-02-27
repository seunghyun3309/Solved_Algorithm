#include<iostream>
 
using namespace std;
 
const int MAX = 1004;
const int BUILD = 256;
 
int main(int argc, char** argv)
{
    int test_case;
    int T=10;
     
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int result=0;
        int arr[MAX][256] = { 0, }; //높이만큼 색칠 했는지
        int high[MAX] = { 0, };
        int n; //가로 길이
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> high[i];
        }
 
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < high[i]; j++)
            {
                arr[i][j] = 1;
            }
        }
 
        for (int i = 2; i <= n+1; i++)
        {
            for (int j = 0; j < high[i]; j++)
            {
                if (arr[i + 1][j] == 0 && arr[i + 2][j] == 0 && arr[i - 1][j] == 0 && arr[i - 2][j] == 0)
                    result++;
            }
        }
        cout << "#" <<test_case << " " << result <<endl;
    }
 
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}