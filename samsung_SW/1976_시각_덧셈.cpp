#include<iostream>

using namespace std;

int main()
{
	int test_case;
	int T;

	cin>>T;

    int a,b,c,d;
    int hour=0;
    int min=0;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cin >>a>>b>>c>>d;
        hour=a+c+(b+d)/60;
          hour%=12;
        if(hour==0)
            hour=12;
        min=(b+d)%60;

		cout<< "#"<<test_case<<" "<<hour<<" "<<min<<" "<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}