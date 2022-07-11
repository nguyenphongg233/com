#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll t,x,n;
ll a[MAX];


signed main(){
	
	cin>>t;
	
	while(t--){
		cin>>n>>x;
		
		memset(a,0,sizeof a);
		
		bool c1 = 1,c2 = 1;
		
		for(ll i = 1;i <= n;i++){
			cin>>a[i];
			
			if(a[i] == 1) c1 = 0;
			if(a[i] >= x) c2 = 0;
			
		}
		
		ll sum = 0;
		
		for(ll i = 1;i < n;i++)sum += abs(a[i] - a[i+1]);
		
		ll minl = min(abs(a[1] - 1),abs(a[n] - 1));
		ll minr = min(abs(a[1] - x),abs(a[n] - x));
		
		for(ll i = 1;i < n;i++){
			minl = min(minl,abs(1 - a[i]) + abs(1 - a[i+1]) - abs(a[i] - a[i + 1]));
			minr = min(minr,abs(x - a[i]) + abs(x - a[i+1]) - abs(a[i] - a[i + 1]));
		}
		
		//cout<<sum + minl + minr<<"\n";
		cout<<sum + (c1 ? minl : 0) + (c2 ? minr : 0)<<"\n";
	}
	
}