#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll n;
ll a[MAX];

priority_queue<ii,vii,greater<ii>>q;
bool use[MAX];
signed main(){
	cin>>n;
	for(ll i = 1;i <= n;i++)cin>>a[i],q.push({a[i],i});
	
	ll sum = 0;
	memset(use,0,sizeof use);
	for(ll i = 1;i <= n;i++){
		//cout<<"#i = "<<i<<":\n";
		while(q.size() && q.top().Y < i && q.top().X != a[i])q.pop();
		//cout<<q.top().Y<<" "<<i<<"\n";

		if(q.size() && !use[i] && !use[q.top().Y] && q.top().Y > i){
			//cout<<"yep\n";
			//cout<<q.top().X<<" "<<a[i]<<"\n";
			//cout<<"end\n";
			use[i] = 1;
			use[q.top().Y] = 1;
			sum += a[i] - q.top().X;
			q.pop();
		}
		
		//while(q.size() && q.top().Y < i && q.top().X != a[i])q.pop();
		/*vii aw;
		while(q.size())aw.push_back(q.top()),q.pop();
		for(auto v : aw)cout<<v.X<<" "<<v.Y<<"\n",q.push(v);*/
	}
	
	cout<<sum;
	
}