#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 5e4 + 5;
const long long mod = 20152015;
const long long INF = 1e9;

using namespace std;

ll n,a[MAX],pref[MAX];
ll rmq[MAX][20][2];

signed main(){
	
	cin>>n;
	for(ll i = 1;i <= n;i++){
		
	    cin>>pref[i];
	    if(i == 0)continue;
	    pref[i] += pref[i - 1];
	    cout<<pref[i]<<" ";
	}
	
	for(ll i = 1;i <= n;i++)rmq[i][0][0] = rmq[i][0][1] = i;
	cout<<"\n";
	

	
	for(ll k = 1; (1 << k) <= n;k++){
		for(ll i = 1;i + (1 << k) - 1 <= n;i++){
			
			if(pref[rmq[i][k - 1][0]] > pref[rmq[i + (1 << (k - 1))][k - 1][0]]){
				rmq[i][k][0] = rmq[i + (1 << (k - 1))][k - 1][0];
			}else{
				rmq[i][k][0] = rmq[i][k - 1][0];
			}
			
			if(pref[rmq[i][k - 1][1]] < pref[rmq[i + (1 << (k - 1))][k - 1][1]]){
				rmq[i][k][1] = rmq[i + (1 << (k - 1))][k - 1][1];
			}else{
				rmq[i][k][1] = rmq[i][k - 1][1];
			}
			
			
			
			
		}
	}
	
	
	
	ll t;
	cin>>t;
	while(t--){
		ll l,r;
		cin>>l>>r;

		
		ll k = log2(r - l + 1);
		
		ll x,y;
		
		
		
		if(pref[rmq[l][k][1]] > pref[rmq[r - (1 << k) + 1][k][1]]){
			y = rmq[l][k][1];
		}else y = rmq[r - (1 << k) + 1][k][1];
		
		k = log2(y - l + 1);
		
		if(pref[rmq[l][k][0]] > pref[rmq[y - (1 << k) + 1][k][0]]){
			x = pref[rmq[y - (1 << k) + 1][k][0]];
		}else x = rmq[l][k][0];
		
		
		
		
		cout<<x<<" "<<y<<" ";
		//cout<<y<<"\n";
		cout<<max({pref[y] - pref[x - 1],pref[r] - pref[x],pref[r] - pref[x - 1],pref[y + 1] - pref[x],pref[r] - pref[y + 1]})<<"\n";
		
	}
	
}