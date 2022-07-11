#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 2e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 105;

using namespace std;



ll dp[N][1 << 3][1 << 3], cnt[N][1 << 3][1 << 3];
 
ll a[N], n;
 
bool out(ll a, ll b){
    if (    ((a & 1 << 0) && (b & 1 << 2)) ||
            ((a & 1 << 2) && (b & 1 << 0))) return 0;
    return 1;
}
 
bool in(ll a, ll b){
    if (((a & 1 << 1) && ( (b & 1 << 0) || (b & 1 << 2))) ||
            ((b & 1 << 1) && ( (a & 1 << 0) || (a & 1 << 2))) ) return 0;
    return 1;
}
 
signed main(){
  
    cin >> n;
    for (ll i=1, j;i<=n;i++){
        cin >> j;
        if (j) a[i] = 1 << (j - 1);
    }
 
    ll M = 0;
    cnt[0][0][0] = 1;
    for (ll i=1;i<=n;i++)
        for (ll mask = 0; mask < 8; mask ++)
            if (!(mask & a[i])){
 
                ll cnt_bits = __builtin_popcount(mask);
                for (ll mask_1 = 0; mask_1 < 1 << 3; mask_1 ++)
                if (!(mask_1 & a[i-1]) && out(mask_1, mask))
                {
                    for (ll mask_2 = 0; mask_2 < 1 << 3; mask_2++)
                        if (out(mask_1, mask_2) && in(mask, mask_2)){
                            if (dp[i][mask][mask_1] < dp[i-1][mask_1][mask_2] + cnt_bits)
                                cnt[i][mask][mask_1] = cnt[i-1][mask_1][mask_2];
                            else 
                                if (dp[i][mask][mask_1] == dp[i-1][mask_1][mask_2] + cnt_bits)
                                    cnt[i][mask][mask_1] += cnt[i-1][mask_1][mask_2];
 
                            dp[i][mask][mask_1] = max(dp[i-1][mask_1][mask_2] + cnt_bits, dp[i][mask][mask_1]);
                        }
 
                    M = max(M, dp[i][mask][mask_1]);
                }
            }
    ll L = 0;
    for (ll i=n;i<=n;i++){
        for (ll j=0; j< 8; j++)
            if ((a[i] & j) == 0)
            for (ll t= 0;t<8;t++)
                if (dp[i][j][t] == M)
                    L += cnt[i][j][t];
    }
    cout << M << ' ' << L;
 

}