#include<bits/stdc++.h>

#define ll long long
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>

const double pi = 1.00 * acos(-1.00);
const long long  MAX = 1005;
const long long  INF = 1e9;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

// 🥇 🐘

using namespace std;

signed main(){
    faster();
    string a;
    getline(cin,a);
    cout<<a.size()<<" ";
    string b = a;
    string a1 = a;
    reverse(b.begin(),b.end());
    ll m = b.size();
    ll n = a.size();
    a = " " + a;
    b = " " + b;
    ll dp[MAX][MAX];
    for(ll i = 1;i<=n;i++){
        for(ll j = 1;j<=m;j++){
            if(a[i] == b[j])dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    }
    ll ans = dp[n][m];
    string s = "";
    for(auto c : a1)s += "_",s+=c;
    s+="_";
    ll n1 = s.size();
    vi f(n1);
	ll r = 0, c = 0;
    for(ll i = 0;i<n1;i++){
		f[i] = 0;
		while (s[i - f[i] - 1] == s[i + f[i] + 1])f[i]++;
		//if (i + f[i] > r)r = i + f[i], c = i;
	}
	sort(f.rbegin(), f.rend());
	cout << f[0]<<"\n"<<ans;
    return 0;
}