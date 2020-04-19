#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;
int solution(string answer_sheet, vector<string>sheets);
int main()
{
	string answer_sheet;
	vector<string>sheets;
	answer_sheet = "4132315142";
	sheets.push_back("3241523133");
	sheets.push_back("4121314445");
	sheets.push_back("3243523133");
	sheets.push_back("4433325251");
	sheets.push_back("2412313253");
	cout<<solution(answer_sheet, sheets);
}

int solution(string answer_sheet, vector<string> sheets) {
	int answer = -1;
	int cnt = 0, seq = 0, max_seq = 0;
	int getMax = -1;
	set<string> s;

	for (int i = 0; i < sheets.size(); i++)
	{
		for (int j = i + 1; j < sheets.size(); j++)
		{
			cnt = 0;
			seq = 0;
			max_seq = 0;
			for (int k = 0; k < answer_sheet.length(); k++)
			{
				if (sheets[i][k] == sheets[j][k] && answer_sheet[k] != sheets[i][k]) //각 문자열 1개 추출해서 비교
				{
					cnt++;
					seq++;
				}
				else
				{
					seq = 0;
				}
				max_seq = max(max_seq, seq);

			}
			cout << sheets[i] << " " << sheets[j] << " " << cnt << " " << max_seq << "\n";
			int max_cnt = cnt + (max_seq * max_seq);
			getMax = max(max_cnt, getMax);

			//cout<<getMax<<"\n";
		}

	}

	if (getMax == -1)
		answer = 0;
	else
		answer = getMax;

	return answer;
}

