#include <iostream>
using namespace std;

int solution(int arr1[], int n, int arr2[], int m)
{
    int answer = 0;
    int i = -1;
    int j = -1;
    while ((i < n - 1) && (j < m - 1))
    {
        ++i;
        ++j;
        long long sum = arr1[i] - arr2[j];
        while (sum != 0)
        {
            if (sum < 0)
            {
                ++i;
                sum += arr1[i];
            }
            else if (sum > 0)
            {
                ++j;
                sum -= arr2[j];
            }
            if (i == n | j == m)
            {
                return -1;
            }
        }
        answer++;
    }
    if (i != n - 1 || j != m - 1)
    {
        return -1;
    }
    return answer;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int arr1[300000];
    int arr2[300000];
    int n, m;
    cin >> n;
    for (int i = 0 ; i < n ; i++)
    {
        cin >> arr1[i];
    }
    cin >> m;
    for (int j = 0 ; j < m ; j++)
    {
        cin >> arr2[j];
    }
    cout << solution(arr1, n, arr2, m);
}
/*
5
11 2 3 5 7
4
11 7 3 7
*/