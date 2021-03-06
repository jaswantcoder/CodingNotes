//Divisible Subarrays - Page 48
//https://hack.codingblocks.com/practice/p/66/266
//https://www.youtube.com/watch?v=QQQpOa3aXew
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000000
#define MAX 1000005
typedef long long ll;
typedef unsigned long long ull;

ll a[MAX] {}, prefixSum[MAX] {};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        ll sum = 0;
        prefixSum[0] = 1;
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            sum += a[i];
            sum %= n;
            sum = (sum + n) % n;    //Negative numbers mod is (-2 + n) % n
            prefixSum[sum]++;
        }
        ll ans = 0;
        for (int i = 0; i < n; ++i)
        {
            ll no = prefixSum[i];
            ans += ((no) * (no-1))/2;
        }
        cout << ans << endl;
    }
    return 0;
}