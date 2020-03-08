#include <iostream>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	//bn은 n번쨰 숫자
	int b1 = b % 10; //5
	int b2 = (b / 10) % 10;//8
	int b3 = (b / 100) % 10;//3
	cout << a * b1 << "\n";
	cout << a * b2 << "\n";
	cout << a * b3 << "\n";
	cout << a * (b1 + 10 * b2 + 100 * b3);
	return 0;

}
