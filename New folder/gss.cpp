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

int n,a[MAX];
int q;
int x,y;
int pref[MAX];

struct Node{
	
	int l,r,mid;
	int cl,cr;
};

Node st[MAX << 2];

void buildtree(int id,int l,int r){
	
	if(l == r){
		
		st[id] = {a[l],a[l],a[l],l,l};
		return;
	}
	
	int m = l + r >> 1;
	buildtree(id << 1,l,m);
	buildtree(id << 1 | 1,m + 1,r);
	
	
	int suml = pref[st[id << 1].cr] - pref[st[id << 1].cl - 1];
	int sumr = pref[st[id << 1 | 1].cr] - pref[st[id << 1 | 1].cl - 1];
	st[id].l = max({st[id << 1].l,suml + st[id << 1 | 1].l,suml + sumr});
	st[id].r = max({st[id << 1 | 1].r,sumr + st[id << 1].r,suml + sumr});
	st[id].mid = max({st[id << 1].mid,st[id << 1 | 1].mid,suml + sumr,st[id << 1].r + st[id << 1| 1].l});
	st[id].cl = l;
	st[id].cr = r;
	
}

Node get(int id,int l,int r,int u,int v){
	
	if(u > r || v < l)return {-INF,-INF,-INF,-1,-1};
	
	
	if(u <= l && r <= v)return st[id];
	
	int m = l + r >> 1;
	
	Node left = get(id << 1,l,m,u,v);
	Node right = get(id << 1 | 1,m + 1,r,u,v);
	
	int le = 0,ri = 0,mi = 0;
	int suml = pref[left.cr] - pref[left.cl - 1];
	int sumr = pref[right.cr] - pref[right.cl - 1];
	
	
	
	le = max({left.l,suml + right.l,suml + sumr});
	ri = max({right.r,sumr + left.r,suml + sumr});
	mi = max({right.mid,left.mid,left.r + right.l,suml + sumr});
	
	
	if(right.cl == -1)return left;
	else if(left.cl == -1)return right;
	
	return {le,ri,mi,l,r};
		
	
	
	
	
	
}

void solve(int x,int y){
	Node ans = get(1,1,n,x,y);
	
	int rt = max({ans.l,ans.r,ans.mid});
	if(x == y)cout<<a[x]<<"\n";
	else 
	cout<<rt<<"\n";
}

signed main(){
	cin>>n;
	for(int i = 1;i <= n;i++){
	    cin >> a[i];
	    pref[i] = pref[i - 1] + a[i];
	}
	
	buildtree(1,1,n);
	cin>>q;
	while(q--){
		cin>>x>>y;
		solve(x,y);
	}
}