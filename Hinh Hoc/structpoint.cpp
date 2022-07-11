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


struct point{
	
	ll x,y;
	
};

point buildvector(point a,point b){
	
	ll x_ = b.x - a.x;
	ll y_ = b.y - a.y;
	
	ll x_1 = abs(x_);
	ll y_1 = abs(y_);
	
	ll rt = __gcd(x_1,y_1);
	
	
	return {x_ / rt,y_ / rt};
}

bool checkline(point a,point b,point c){
	
	
	point x1 = buildvector(b,c);
	point x2 = buildvector(a,c);
	
	
	
	
	if(x1.x < 0)x1.x *= -1,x1.y *= -1;
	if(x2.x < 0)x2.x *= -1,x2.y *= -1;
	
	cout<<x1.x<<" "<<x1.y<<"\n";
	cout<<x2.x<<" "<<x2.y<<"\n";
	cout<<"\n";
	if(x1.x != x2.x || x1.y != x2.y)return false;
	
	return true;
}

ll n;
point a[MAX];
signed main(){
	cin>>n;
	
	for(ll i = 1;i <= n;i++){
		cin>>a[i].x>>a[i].y;
	}
	
	for(ll i = 3;i <= n;i++){
		point c[] = {a[i],a[i - 1],a[i - 2]};
		ll x[] = {0,1,2};
		bool ok = 0;
		do{
			//cout<<x[0]<<" "<<x[1]<<" "<<x[2]<<"\n";
			if(checkline(c[x[0]],c[x[1]],c[x[2]])){
				ok = 1;
				break;
			}
		}while(next_permutation(x,x + 3));
		
		
		if(!ok)return cout<<"No",0;
		
	}
	
	cout<<"Yes";
	
}