#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
string str[26]; //A B C D E F G H
int score[26] = { 0, }; //A B C D E F G H 점수
int sc = 0;
int result = 0;

bool comp(int n1, int n2)
{
	return n1 > n2;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		sc = 0;
		cin >> str[i];
		for (int j = str[i].length()-1; j >=0; j--)
		{
			//j는 2 1 0 순서로
			//cout << str[i][j] - 'A' << " ";
			score[str[i][j]-'A'] += pow(10,sc);
			sc++;
		}
	}

	sort(score, score + 26, comp);

	int num = 9;
	for (int i = 0; i < 10; i++)
	{
		result +=( num * score[i]);
		num--;
	}

	cout << result;
	return 0;
}