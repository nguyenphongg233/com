#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 165;
 
using namespace std;


ll n;
ll a[MAX];
ll cnt[MAX];
ll dist[MAX];
ll t[MAX];
 
signed main(){
	
	if(ifstream("test.inp")){
		freopen("test.inp","r",stdin);
		freopen("test.out","w",stdout);
	}
	
    cin >> n;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        a[n+i] = a[i];
        dist[n+i] = n+i-a[i];
    }
    for(ll i = 1; i <= n; i++){
        if(dist[n+i]<=i)continue;
        else{
            t[i+1]++;
            t[dist[n+i]+1]--;
        }
    }
    ll sum = 0;
    for(ll i = 1; i <= 2*n; i++){
        sum += t[i];
        cnt[i] = sum;
    }
    for(ll i = 1; i <= n;i++){
        cnt[i] += cnt[n+i];
    }
    ll res = 0;
    ll ans = 0;
    for(ll i = 1; i <= n; i++){
        if(res < cnt[i]){
            ans = i;
            res = cnt[i];
 
        }
    }
    cout << ans;
}