#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    int aa[3];
    int bb[3];
    queue<int>num;
    for(int k=123;k<=987;k++)
    {
        num.push(k);
    }
    for(int i=0;i<baseball.size();i++)
    {
        int q_size=num.size();
        int temp=baseball[i][0];
        bb[2] = temp % 10;
        bb[1] = (temp/10) % 10; 
        bb[0] = (temp/100) % 10;
        if(bb[0]==0||bb[1]==0||bb[2]==0)
            {
                continue;
            }
            if(bb[0]==bb[1]||bb[0]==bb[2]||bb[1]==bb[2])
            {
                continue;
            }
        for(int j=0;j<q_size;j++)
        {
            int strike=0;
            int ball=0;
            int temp=num.front();
            aa[2] = temp % 10;
            aa[1] = (temp / 10) % 10;
            aa[0] = (temp / 100) % 10;
            if(aa[0]==0||aa[1]==0||aa[2]==0)
            {
                num.pop();
                continue;
            }
            if(aa[0]==aa[1]||aa[0]==aa[2]||aa[1]==aa[2])
            {
                num.pop();
                continue;
            }

            if(aa[0]==bb[0])
                strike++;
            if(aa[1]==bb[1])
                strike++;
            if(aa[2]==bb[2])
                strike++;
            if(aa[0]==bb[1]||aa[0]==bb[2])
                ball++;
            if(aa[1]==bb[0]||aa[1]==bb[2])
                ball++;
            if(aa[2]==bb[0]||aa[2]==bb[1])
                ball++;
            if(strike==baseball[i][1]&&ball==baseball[i][2])
                num.push(num.front());
            num.pop();
        }  
    }
    answer=num.size();
    return answer;
}