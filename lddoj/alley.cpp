#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 5e2 + 5;
const long long mod = 20152015;
const long long INF = 1e9;

using namespace std;

char a[MAX][5];
ll n;
ll dp[MAX][(1 << 5)];

signed main(){
	cin>>n;
	for(ll i = 0;i < n;i++){
		for(ll j = 0;j < 5;j++){
			cin>>a[i][j];
		}
	}
	
	
	for(ll mask = 0;mask < (1 << 5);mask++){
		
		bool can = 0;
		for(ll idm = 0;idm < 5;idm++){
			if((mask >> idm & 1 ) && a[0][idm] == 'x')can = 1;
		}
		dp[0][mask] = 1 - can;
	}
	
	ll sum = 0;
	
	for(ll i = 1;i < n;i++){
		
		for(ll mask = 0;mask < (1 << 5);mask++){
				
				bool could = 0;
				
				for(ll idm = 0;idm < 5;idm++){
					if((mask >> idm & 1) && a[i][idm] == 'x')could = 1;
				}
				
				if(could)continue;
		
		
		        for(ll premask = 0;premask < (1 << 5);premask++){
			        bool can = 0;
			
			        for(ll idpm = 0;idpm < 5;idpm++){
				        if((premask >> idpm & 1) && a[i - 1][idpm] == 'x')can = 1;
			        }
			
			
			        if(can)continue;
				
				    bool ciu = 0;
				
				    for(ll id = 0;id < 4;id++){
					    bool xi = premask >> id & 1;
					    bool xi_ = mask >> id & 1;
					
					    bool yi = premask >> (id + 1) & 1;
					    bool yi_ = mask >> (id + 1) & 1;
					    
					    
					    if((a[i - 1][id] == 'x' && xi == 0)|| (a[i - 1][id + 1] == 'x' && yi == 0))continue;
					    if((a[i][id] == 'x' && xi_ == 0)|| (a[i][id + 1] == 'x' && yi_ == 0))continue;
					
					    if(xi == xi_ && xi == yi && yi_ == yi)ciu = 1;
					
					
				     }
				
				     if(ciu)continue;
				
				
				     dp[i][mask] += dp[i - 1][premask];
				     dp[i][mask] %= mod;
				

				
			    }  
			
		}
	}
	
	
	for(ll mask = 0;mask < (1 << 5);mask++){
		bool could = 0;
				
		for(ll idm = 0;idm < 5;idm++){
			if((mask >> idm & 1) && a[n - 1][idm] == 'x')could = 1;
		}
				
		if(could)continue;
		sum += dp[n - 1][mask];
		sum %= mod;
	}
	
	
	cout<<sum % mod;
	
	
}
