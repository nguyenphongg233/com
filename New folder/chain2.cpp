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

struct node{
	node *child[26];
	ll f,dp;
	
	node(){
		for(ll i = 0;i < 26;i++)child[i] = NULL;
		f = 0;
		dp = 0;
	}
	
	
};

node *root;

void build(string s){
	
	node *p = root;
	
	for(ll i = 0;i < s.size();i++){
		ll x = s[i] - 'a';
		
		if(p -> child[x] == NULL)p -> child[x] = new node();
		p = p -> child[x];
		
	}
	
	p -> f = 1;
}
ll res = 0;
void dfs(node *u){
	
	u -> dp = 0;
	ll mx = 0;
	for(ll i = 0;i < 26;i++){
		if(u -> child[i] == NULL)continue;
		dfs(u -> child[i]);
		
		mx = max(mx,u -> child[i] -> dp);
		
	}
	
	
	u -> dp = mx + u -> f;
	
	res = max(res,u -> dp);
	
	//cout<<u -> dp<<"\n";
}


ll n;

signed main(){
	cin>>n;
	
	root = new node();
	
	for(ll i = 1;i <= n;i++){
		string s;
		cin>>s;
		
		build(s);
	}
	
	dfs(root);
    cout<<res;
}