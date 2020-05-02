#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int alpha[26] = { 0, };
    bool check[26] = { false, };
    char str[110];
    cin >> str;
    for (int i = 0; i < strlen(str); i++)
    {
        int temp = str[i] - '0' - 49;
        if (!check[temp])
        {
            check[temp] = true;
            alpha[temp] = i;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (!check[i])
            cout << -1 << " ";
        else
            cout << alpha[i] << " ";
    }
        return 0;
}
