#include <bits/stdc++.h>
using namespace std;

string solution(string num)
{
    int ind_even = 0;
    int ind_odd = 0;
    string answer = "";
    while ((int)num[ind_even] % 2 != 0 && ind_even < num.size())
    {
        ++ind_even;
    }
    while ((int)num[ind_odd] % 2 != 1 && ind_odd < num.size())
    {
        ++ind_odd;
    }
    while ((ind_even != num.size()) && (ind_odd != num.size()))
    {
        if (num[ind_odd] < num[ind_even])
        {
            answer += num[ind_odd++];
            while ((int)num[ind_odd] % 2 != 1 && ind_odd < num.size())
            {
                ++ind_odd;
            }
        }
        else
        {
            answer += num[ind_even++];
            while ((int)num[ind_even] % 2 != 0 && ind_even < num.size())
            {
                ++ind_even;
            }
        }
    }
    if (ind_even == num.size())
    {
        while (ind_odd < num.size())
        {
            answer += num[ind_odd++];
            while ((int)num[ind_odd] % 2 != 1 && ind_odd < num.size())
            {
                ++ind_odd;
            }
        }
    }
    else
    {
        while (ind_even < num.size())
        {
            answer += num[ind_even++];
            while ((int)num[ind_even] % 2 != 0 && ind_even < num.size())
            {
                ++ind_even;
            }
        }
    }
    return answer;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0 ; i < t ; i++)
    {
        string num;
        cin >> num;
        cout << solution(num) << endl;
    }
}