#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 4e5 + 5;
const long long mod = 666013;
const long long INF = 1e9;

using namespace std;

ll n;
ll pref[MAX];
ll a[MAX];
ll pear[MAX];
signed main(){
	cin>>n;
	pref[0] = 0;
	for(ll i = 1;i <= n;i++){
		cin>>a[i];
		pref[i] = pref[i - 1] + a[i];
		pear[pref[i]] = i;
	}
	ll cnt = 0;
	ll sum = 0;
	for(ll i = n;i >= 1;i--){
		sum += a[i];
		
		ll last = i;
		
		//if(pref[i - 1] - sum >= 0 && pear[pref[i - 1] - sum])cnt++;
		//cout<<sum<<",";
		//cout<<i<<":";
		if(i != 1)
		cnt++;
		while(last - 1 >= 0 && pref[last - 1] - sum >= 0 && pear[pref[last - 1] - sum]){
			cnt++;
			//cout<<last<<" ";
			last = pear[pref[last - 1] - sum] + 1;
			//cout<<last<<" ";
		}
		//cout<<"\n";
		//cout<<sum<<" "<<pref[i - 1] - sum<<"\n";
	}
	cout<<cnt;
}