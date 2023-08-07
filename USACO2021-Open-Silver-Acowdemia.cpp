#include<bits/stdc++.h>
using namespace std;

bool cmp(long long a, long long b)
{
    return a > b;
}

bool check(vector<long long>& sub, long long h, long long k, long long l)
{
    long long cnt = 0;
    long long sub_cnt = k * l;
    for (long long i = 0 ; i < h ; i++)
    {
        if (sub[i] >= h)
        {
            ++cnt;
            continue;
        }
        else
        {
            if ((k >= (h - sub[i])) && ((h - sub[i]) <= sub_cnt))
            {
                sub_cnt = sub_cnt - (h - sub[i]);
                ++cnt;
            }
            else
            {
                break;
            }
        }
    }
    return (cnt >= h);
}

int main()
{
    long long n, k, l;  
    cin >> n >> k >> l;
    vector<long long> sub;
    for (long long i = 0 ; i < n ; i++)
    {
        long long temp;
        cin >> temp;
        sub.push_back(temp);
    }
    sort(sub.begin(), sub.end(), cmp);
    long long lo, hi;
    lo = 1;
    hi = sub.size();
    while(lo < hi)
    {
        long long mid = lo + (hi - lo + 1) / 2;
        if (check(sub, mid, k, l))
        {
            lo = mid;
        }
        else
        {
            hi = mid - 1;
        }
    }
    cout << lo;
}
