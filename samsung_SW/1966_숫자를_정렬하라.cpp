
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{

	int test_case;
	int T;
    int arr[50],n;
  	cin >> T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int min=0;  
		cin >> n;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int i=0;i<=n-1;i++)
        {
            min=arr[i];
            int min_num=i;
            for(int j=i;j<n;j++)
            {
               if(min>arr[j])
               {
                   min=arr[j];
                   min_num=j;
               }
            }
                arr[min_num]=arr[i];
                arr[i]=min;
        }
        cout<<"#"<<test_case<<" ";
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}