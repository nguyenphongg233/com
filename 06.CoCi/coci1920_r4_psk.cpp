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

ll n;
ii a[MAX];
ll sum = 0;
bool cmp(ii i,ii j){
	return i.X > j.X;
}
ll d[MAX];
signed main(){
	cin>>n;
	
	for(ll i = 1,x;i <= n;i++){
		cin>>x>>a[i].X;
		a[i].Y = i;
		sum += x;
	}
	
	sort(a + 1,a + 1 + n,cmp);
	
	ll sum2 = 0;
	
	ll ans = 0;
	for(ll i = 1;i <= n;i++){
		sum2 += a[i].X;
		
		if(sum2 >= sum){
			ans = n - i;
			d[a[i].Y] = a[i].X - sum2 + sum;
			break;
		}else{
			d[a[i].Y] = a[i].X;
		}
		
		
	
	}
	
	cout<<ans<<"\n";
	
	for(ll i = 1;i <= n;i++)cout<<d[i]<<" ";
	
}