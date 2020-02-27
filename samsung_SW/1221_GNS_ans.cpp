#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 10000;
int arr[10] = { 0, };
string number[10] = { "ZRO","ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN"};
int main()
{
	int n;
	cin >> n;
	for (int tc = 1; tc <= 10; tc++)
	{
		for (int i = 0; i < 10; i++)
		{
			arr[i] = 0;
		}
		string temp;
		int z;
		cin >> temp >> z;

			for(int i=0;i<z;i++)
			{
					cin >> temp;
					for (int k = 0; k < 10; k++)
					{
						if (temp == number[k])
						{
							arr[k]++;
						}
					}

			}
			
		cout << "#" << tc << " "<<endl;

		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < arr[i]; j++)
			{
				cout << number[i] << " ";
			}
		}
		cout << endl;


	}
	return 0;
}