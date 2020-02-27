#include <iostream>

using namespace std;
int n;
bool flag = true;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	string arr;
	char parthness;
	int s_size;

	for (int i = 0; i < n; i++)
	{
		s_size = 0;
		flag = true;
		cin >> arr;
		for (int t = 0; t < arr.size(); t++)
		{
			parthness = arr[t];

			if (parthness == '(')
			{
				s_size++;
			}

			else if (parthness == ')')
			{
				s_size--;
				if (s_size < 0)
					flag = false;
			}
		}
		if (s_size == 0 && flag == true)
		{
			cout << "YES" << "\n";
		}
		else
		{
			cout << "NO" << "\n";
		}
	}

	return 0;
}