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

ll n;
ll a[MAX];
priority_queue<ll> q;

signed main(){
	cin>>n;
	
	ll sum = 0;
	for(ll i = 1,x;i <= n;i++){
		cin>>x;
		//q.push(x);
		if(q.size() && q.top() > x){
			cout<<q.top()<<' '<<x<<" "<<q.top() - x<<"\n";
			sum += q.top() - x;
			q.pop();
		}else{
			q.push(x);
		}
		//if(q.size())cout<<i<<" "<<q.top()<<"\n";
	}
	
	cout<<sum;
	return 0;
		
}
