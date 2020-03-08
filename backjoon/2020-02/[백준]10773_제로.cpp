#include <iostream>

using namespace std;
int n, k;
int stack_data[100010];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	int sum_data = 0;
	int s_size = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		if (k != 0)
		{
			stack_data[s_size++] = k;
		}

		else
		{
			stack_data[s_size - 1] = 0;
			s_size--;
		}
	}
	for (int i = 0; i < s_size; i++)
	{
		sum_data += stack_data[i];
		//cout << stack_data[i];
	}
	cout << sum_data;
	return 0;
}