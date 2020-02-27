#include <iostream>

using namespace std;

int arr[10][10];
int n;

int main()
{
	
	int testcase;
	cin >> testcase;

	for(int tc=1;tc<=testcase;tc++)
	{
		cin >> n;
		
		arr[1][1] = 1;
		arr[2][1] = 1; arr[2][2] = 1;
		for (int i = 3; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
				
		}

		cout << "#" << tc << " "<<endl;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= i; j++)
			{
				cout<<arr[i][j]<<" ";
			}
			cout << endl;
		}
		//결과
	}


	return 0;
}