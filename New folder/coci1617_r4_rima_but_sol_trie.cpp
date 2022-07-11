#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 5e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;



struct node{
	node* child[26];
	ll f,dp;
	ll cnt;
	node(){
		for(ll i = 0;i < 26;i++){
			child[i] = NULL;
		}
		cnt = 0;
		f = 0;
		dp = 0;
	}
};

node *root;
void build(string s){
	ll n = s.size();
	
	node *p = root;
	
	for(ll i = 0;i < n;i++){
		ll next = s[i] - 'a';
		
		if(p->child[next] == NULL){
			p->child[next] = new node();
		}
		p = p-> child[next];
	}
	
	p->f = 1;
	
}
ll res = 1;
void dfs(node *u){
	
	ll cnt = 0;
	ll mx1 = 0,mx2 = 0;
	for(ll i = 0;i < 26;i++){
		
		if(u -> child[i] == NULL)continue;

		dfs(u -> child[i]);
		cnt +=  u -> child[i] -> f;
		u -> dp = max(u -> dp,u -> child[i] -> dp);
		
		if(u -> child[i] -> dp >= mx1){
			mx2 = mx1;
			mx1 = u -> child[i] -> dp;
		}else if(u -> child[i] -> dp > mx2){
			mx2 = u -> child[i] -> dp;
		}
		
	}
	 
	if(! u -> f)u -> dp = 0;
	else u -> dp += 1 + max(0ll,cnt - 1);
	
	res = max(res,mx1 + mx2 + u -> f + max(0ll,cnt - 2));
	
	//cout<<mx1 + mx2 + u -> f + max(0ll,cnt - 2)<<"\n";
}

signed main(){
	ll n;
	cin>>n;
	
	root = new node();
	
	
	for(ll i = 1;i <= n;i++){
		string s;
		cin>>s;
		reverse(s.begin(),s.end());
		//cout<<s<<"\n";
		build(s);
	}
	
	dfs(root);
	
	
	cout<<res;
}