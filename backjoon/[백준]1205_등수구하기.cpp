#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int song, song_rank = 1, song_p = 1;
	int p;

	int rank[50];
	
	cin >> n >> song >> p;
	for (int i = 0; i < n; i++)
	{
		cin >> rank[i];
		if (rank[i] > song)song_rank++;
		if (rank[i] >= song)song_p++;
	}
	if (song_rank > p)cout << -1;
	else if (song_p > p)cout << -1;
	else
		cout << song_rank;

	return 0;
}