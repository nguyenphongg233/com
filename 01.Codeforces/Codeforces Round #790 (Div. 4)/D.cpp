#include<bits/stdc++.h>

#define ll int
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 3e2 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll a[MAX][MAX];


signed main(){
	ll t;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		ll row[MAX][MAX],col[MAX][MAX];
		for(ll i = 1;i <= n;i++){
			for(ll j = 1;j <= m;j++){
				cin>>a[i][j];
			}
		}
		for(ll i = 1;i <= n;i++){
			ll x = i;
			ll y = 1;
			ll sum = a[i][1];
			while(1){
				//cout<<x<<" "<<y<<"\n";
				x--;
				y++;
				if(x < 1 || x > n || y < 1 || y > m)break;
				sum += a[x][y];
			}
			//cout<<"end";
			x = i;
			y = 1;
			row[x][y] = sum;
			while(1){
				x--;
				y++;
				if(x < 1 || x > n || y < 1 || y > m)break;
				row[x][y] = sum;
			}
		}
		
		
		for(ll j = 1;j <= m;j++){
			ll x = n;
			ll y = j;
			ll sum = a[x][y];
			while(1){
				x--;
				y++;
				if(x < 1 || x > n || y < 1 || y > m)break;
				sum += a[x][y];
			}
			x = n;
			y = j;
			row[x][y] = sum;
			while(1){
				x--;
				y++;
				if(x < 1 || x > n || y < 1 || y > m)break;
				row[x][y] = sum;
			}
		}
		
		ll res = 0;
		
		for(ll i = 1;i <= n;i++){
			ll x = i;
			ll y = 1;
			ll sum = a[x][y];
			
			while(1){
				x++;
				y++;
				if(x < 1 || x > n || y < 1 || y > m)break;
				sum += a[x][y];
				
			}
		    x = i,y = 1;
		    res = max(res,row[x][y] + sum - a[x][y]);
		    col[x][y] = sum;
			while(1){
				
				x++;
				y++;
				if(x < 1 || x > n || y < 1 || y > m)break;
				col[x][y] = sum;
				res = max(res,row[x][y] + sum - a[x][y]);
				
			}
		}
		
		for(ll j = 1;j <= m;j++){
			ll x = 1;
			ll y = j;
			ll sum = a[x][y];
			while(1){
				x++;
				y++;
				if(x < 1 || x > n || y < 1 || y > m)break;
				sum += a[x][y];
				
			}
			
			x = 1,y = j;
			col[x][y] = sum;
			res = max(res,row[x][y] + sum - a[x][y]);
			while(1){
				x++;
				y++;
				if(x < 1 || x > n || y < 1 || y > m)break;
				col[x][y] = sum;
				//res = max(res,row[x][y] + sum - a[x][y]);
				
			}
		}
		
		for(ll i = 1;i <= n;i++){
			for(ll j = 1;j <= m;j++){
				//cout<<col[i][j]<<" ";
				res = max(res,row[i][j] + col[i][j] - a[i][j]);
			}
			//cout<<"\n";
		}
		
		cout<<res<<"\n";
		
	}
}