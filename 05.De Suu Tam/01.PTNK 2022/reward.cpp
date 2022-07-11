#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

map<ii,ll> mp;
ll n;
ii str;
ll x,y;
string s;

ll point(ll x,ll y){
	
	if(x  + y <= n/2 + 4){	
	
	    //cout<<"u";
		ll q = x + y - 2;
		ll sum = q * (q + 1) / 2;
		
		
		// so luong duong cheo trc no : 
		
		
		q++;
		
		if(q & 1)return sum + y;
		else return sum + (q - y + 1);
		
		
		
	}else{
		
		//cout<<"d";
		x = n - x + 1;
		y = n - y + 1;
		
		ll q = x + y - 2;
		ll sum = q * (q + 1) / 2;
		
		q++;
		
		if((q & 1))return n * n - sum - y + 1;
		else return n * n - sum - (q - y + 1) + 1;
	}
	
	
	
}

ll dx[] = {0,0,-1,1};
ll dy[] = {1,-1,0,0};
signed main(){
	
	cin>>n>>str.X>>str.Y;
	
	string s;
	cin>>s;
	
	ll sum = 0;
	sum += point(str.X,str.Y);
	mp[str]++;
	
	ll a[MAX];
	for(ll i = 0;i < s.size();i++){
		if(s[i] == 'E')a[i] = 0;
		else if(s[i] == 'W')a[i] = 1;
		else if(s[i] == 'N')a[i] = 2;
		else a[i] = 3;	
	}
	
	/*for(ll i = 1;i <= n;i++){
		for(ll j = 1;j <= n;j++){
			cout<<point(i,j)<<" ";
		}
		cout<<"\n";
	}*/
	
	for(ll i = 0;i < s.size();i++){
		str.X += dx[a[i]];
		str.Y += dy[a[i]];
		
		
		
		if(!mp[str])sum += point(str.X,str.Y),mp[str]++;
	}
	
	cout<<sum;
	
	
}