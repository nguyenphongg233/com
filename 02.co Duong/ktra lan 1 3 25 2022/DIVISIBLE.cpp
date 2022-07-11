#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 1e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 165;
 
using namespace std;

ll snt[MAX];
ll sn[MAX];

signed main(){
	
	if(ifstream("divisible.inp")){
		freopen("divisible.inp","r",stdin);
		freopen("divisible.out","w",stdout);
	}
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	memset(snt,0,sizeof snt);
	
	for(ll i = 2;i * i < MAX;i++){
		if(!snt[i]){
			for(ll j = i * i;j < MAX;j += i)snt[j] = min(snt[j],i);
		}
	}
	
	for(ll i = 1;i < MAX;i++){
		if(!snt[i])snt[i] = i;
	}
	
	//for(ll i = 1;i < MAX;i++)cout<<i<<" "<<snt[i]<<"\n";
	
	/*ll x;
	
	cin>>x;
	
	while(x != 1){
		cout<<x<<" ";
		cout<<snt[x]<<"\n";
		x/=snt[x];
	}*/
	
	
	ll t;
	cin>>t;
	
	while(t--){
		memset(sn,0,sizeof sn);
		
		ll n,m;
		cin>>n>>m;
		bool app0 = 0;
		for(ll i = 1,x;i <= n;i++){
			cin>>x;
			
			if(x == 0)app0 = 1;
			while(x > 1){
				//cout<<x<<"\n";
				sn[snt[x]]++;
				//cout<<snt[x]<<" ";
				x /= snt[x];
			}
		}
		bool app22 = 0;
		for(ll i = 1,x;i <= m;i++){
			cin>>x;
			
			if(x == 0)app22 = 1;
			
			while(x > 1){
				sn[snt[x]]--;
				x /= snt[x];
			}
		}
		bool ck = 0;
		
		for(ll i = 1;i < MAX;i++){
			if(sn[i] < 0){
			   ck = 1;
			   break;
			}
		}
		if(app22)cout<<"NO\n";
		else if(app0)cout<<"YES\n";
		
		else cout<<(ck ? "NO" : "YES")<<"\n";
	}
	
	
	
}
