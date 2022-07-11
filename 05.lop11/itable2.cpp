#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 5e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;

ll q,t,n;
ll row[MAX][MAX];
ll col[MAX][MAX];

signed main(){
	
	
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>t;
	
	
	memset(row,0,sizeof row);
	memset(col,0,sizeof col);
	for(ll i = 1,k,rc,x,y;i <= t;i++){
		cin>>k>>rc>>x>>y;
		ll z = y - x + 1;
		ll gtr = (z >> 1) + (z % 2);
		
		if(k & 1){

			if(!(z % 2)){
				row[rc][x]++;
				row[rc][y + 2]++;
				row[rc][x + gtr]--;
				row[rc][x + gtr + 1]--;
				
			}else{
				row[rc][x]++;
				row[rc][x + gtr] -= 2;
				row[rc][y + 2] ++;
			}
		}else{

			if(!(z % 2)){
				col[x][rc] += 1;
				col[y + 2][rc] += 1;
				col[x + gtr][rc] -= 1;
				col[x + gtr + 1][rc] -= 1;
				
			}else{
				col[x][rc] += 1;
				col[x + gtr][rc] -= 2;
				col[y + 2][rc] ++;
			}
		}
	}
	
	for(ll i = 1;i <= n;i++){
		ll p = 0;
		for(ll j = 1;j <= n;j++){
			p += row[i][j];
			row[i][j] = row[i][j - 1] + p;
		}
	}
	
	
	for(ll j = 1;j <= n;j++){
		ll p = 0;
		for(ll i = 1;i <= n;i++){
			p += col[i][j];
			col[i][j] = col[i - 1][j] + p;
		}
	}
	
	/*for(ll i =1;i <= n;i++){
		for(ll j = 1;j <= n;j++){
			cout<<row[i][j]<<" ";
		}
		cout<<'\n';
	}*/
	
	
	
	cin>>q;
	while(q--){
		ll x,y;
		cin>>x>>y;
		cout<<col[x][y]+ row[x][y]<<"\n";
	}
	
}