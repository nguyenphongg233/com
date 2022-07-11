#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 5e4 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll n,m,k;
ll a[MAX],b[MAX];
ll dd[MAX];


priority_queue<ll> q;

signed main(){
	cin>>n>>m>>k;
	for(ll i = 1;i <= n;i++)cin>>a[i];
	for(ll i = 1;i <= m;i++)cin>>b[i];

	
	sort(b + 1,b + 1 + m);
	sort(a + 1,a + 1 + n);
	
	for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= m;j++){
			if(q.size() >= k && q.top() <= a[i] + b[j])break;
			if(q.size() >= k && q.top() > a[i] + b[j])q.pop();
			q.push(a[i] + b[j]);
		}
	}
	
	vi wer;
	
	while(!q.empty())wer.push_back(q.top()),q.pop();
	
	sort(wer.begin(),wer.end());
	for(auto v : wer)cout<<v<<"\n";
	
}
