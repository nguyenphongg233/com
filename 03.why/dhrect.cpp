#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 3e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 165;

using namespace std;

ll t,n;
ll a[MAX];

bool cmp(ll x,ll y){
	return x > y;
}


signed main(){
	cin>>t;
	
	while(t--){
		cin>>n;
		
		memset(a,0,sizeof a);
		for(ll i = 1;i <= n;i++)cin>>a[i];
		sort(a + 1,a + 1 + n,cmp);
		
		ll b1 = -1,b2 = -1;
		
		for(ll i = 2;i <= n;i++){
			if(a[i] == a[i-1] && b1 == -1){
				b1 = i;
			}else if(a[i] == a[i-1] && b1 != -1 && b2 == -1 &&  i - 1  != b1){
				b2 = i;
				break;
			}
		}
		
		if(b1 == -1 || b2 == -1)cout<<-1<<"\n";
		else cout<<a[b1] * a[b2]<<"\n";
		
	}
}