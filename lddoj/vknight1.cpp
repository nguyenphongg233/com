#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 2e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 20;

using namespace std;

ll n;
ll k[MAX];
ll dp[MAX][(1 << 3)];
ll cnt[MAX][(1 << 3)];


signed main(){
	cin>>n;
	
	
	memset(k,0,sizeof k);
	memset(dp,0,sizeof dp);
	memset(cnt,0,sizeof cnt);
	
	for(ll i = 0,x;i < n;i++){
		cin>>x;
		if(x == 0)x = 4;
		else x--;
		
		k[i] = x;
		
	}
	
	// calc col 0 
	
	for(ll mask = 0;mask < (1 << 3);mask++){
		
		bool can = 0;
		
		for(ll id = 0;id < 3;id++){
			if(mask >> id & 1 && k[0] == id)can = 1;
		}
		
		if(can)continue;
		
		ll x = __builtin_popcount(mask);
		
		dp[0][mask] = x;
		cnt[0][mask] = 1;
		// ????????????? dm
		
	}
	
	//calc col 1
	
	for(ll mask = 0;mask < (1 << 3);mask++){
		
		bool can = 0;
		
		ll x = __builtin_popcount(mask);
		
		for(ll id = 0;id < 3;id++){
			if(mask >> id & 1 && k[1] == id)can = 1;
		}
		
		if(can)continue;
		
		for(ll premask = 0;premask < (1 << 3);premask++){
			bool can1 = 0;
			
			for(ll idp = 0;idp < 3;idp++){
				if(premask >> idp & 1 && k[0] == idp)can1 = 1;
			}
			
			if(can1)continue;
			
			/*   
			   *..
			   ..*
			   
			   ..*
			   *..		
			*/
			
			if(premask & 1 && mask >> 2 & 1)continue;
			if(mask & 1 && premask >> 2 & 1)continue;
			
			
			if(dp[1][mask] < dp[0][premask] + x){
				dp[1][mask] = dp[0][premask] + x;
				cnt[1][mask] = cnt[0][premask];
			}else if(dp[1][mask] == dp[0][premask] + x){
				cnt[1][mask] += cnt[0][premask];
			}	
		}
		
	}
	
	
	
	// calc col >= 2
	
	
	for(ll i = 2;i < n;i++){
		for(ll mask = 0;mask < 1 << 3;mask++){
			
			ll x = __builtin_popcount(mask);
			
			bool can = 0;
			
			
			string s = "";
			for(ll id = 0;id < 3;id++){
				if(mask >> id & 1 && id == k[i])can = 1;
				if(mask >> id & 1)s += "1" ;
			    else s += "0" ;
			}
			
			
			if(can)continue;
			
			
			// mask hang (i - 1)
			for(ll mask1 = 0;mask1 < 1 << 3;mask1++){
				ll x_ = __builtin_popcount(mask1);
				
				bool can1 = 0;
				
				string s1 = "";
				for(ll id1 = 0;id1 < 3;id1 ++){
					
					if(mask1 >> id1 & 1 && id1 == k[i - 1])can1 = 1;
					if(mask1 >> id1 & 1)s1 += "1" ;
			        else s1 += "0" ;
				}
				
				if(can1)continue;
				
				
				
				// mask hang (i - 2)
				
				
				for(ll mask2 = 0;mask2 < 1 << 3;mask2++){
					
					bool can2 = 0;
					
					string s2 = "";
					
					for(ll id2 = 0;id2 < 3;id2++){
						if(mask2 >> id2 & 1 && id2 == k[i - 2])can2 = 1;
						if(mask2 >> id2 & 1)s2 += "1" ;
			            else s2 += "0" ;
					}
					
					if(can2)continue;
					
					if(mask2 & 1 && (mask1 >> 2 & 1 || mask >> 1 & 1))continue;
					
					/*
					    *..
					    ..*
					    .*.
					
					*/
					
					
					if(mask2 >> 1 & 1 && (mask & 1 || mask >> 2 & 1))continue;
					
					/*
					    .*.
					    ...
					    *.*
					
					*/
					
					
					if(mask2 >> 2 & 1 && (mask1 & 1 || mask >> 1 & 1))continue;
					
					/*
					    ..*
					    *..
					    .*.
					
					
					*/
					
					if(mask1 & 1 && (mask2 >> 2 & 1 || mask >> 2 & 1))continue;
					
					/*
					   ..*
					   *..
					   ..*
					  
					  
					  
					*/
					
					
					if(mask1 >> 2 & 1 && (mask2 & 1 || mask & 1))continue;
					
					/*
					   
					   *..
					   ..*
					   *..
					  
					  
					*/
					
					if(mask & 1 && (mask2 >> 1 & 1 || mask1 >> 2 & 1))continue;
					
					/*
					  
					  .*.
					  ..*
					  *..
					  
					
					*/
					
					
					if(mask >> 1 & 1 && (mask2 & 1 || mask2 >> 2 & 1))continue;
					
					
					/*
					  
					  *.*
					  ...
					  .*.
					  
					  
					
					*/
					if(mask >> 2 & 1 && (mask1 & 1 || mask2 >> 1 & 1))continue;
					
					
					/*
					  .*.
					  *..
					  ..*
					
					*/
					
					
					if(dp[i][mask] < dp[i - 1][mask1] + x){
						dp[i][mask] = dp[i - 1][mask1] + x;
						cnt[i][mask] = cnt[i - 1][mask1];
					}else if(dp[i][mask] == dp[i - 1][mask1] + x){
						cnt[i][mask] += cnt[i - 1][mask1];
					}	
					
					
					/*if(dp[i][mask] < dp[i - 2][mask2] + x + x_){
						dp[i][mask] = dp[i - 2][mask2] + x + x_;
						cnt[i][mask] = cnt[i - 2][mask2];
					}else if(dp[i][mask] == dp[i - 2][mask2] + x + x_){
						cnt[i][mask] += cnt[i - 2][mask2];
					}*/
					
					//cout<<s2<<"\n"<<s1<<"\n"<<s<<"\n\n";
					
					
				}
				
				
				
				
				
				
			}
			
			
			
		}
	}
	
	ll M = -1,L = 0;
	
	for(ll mask = 0;mask < (1 << 3);mask++){
		
		bool can = 0;
		
		string s = "";
		for(ll id = 0;id < 3;id++){
			if(mask >> id & 1 && k[n - 1] == id)can = 1;
			if(mask >> id & 1)s += "1" ;
			else s += "0";
		}
		
		if(can)continue;
		
		//cout<<dp[n - 1][mask]<<"\n";
		
		
		if(M < dp[n - 1][mask]){
			M = dp[n - 1][mask];
			L = cnt[n - 1][mask];
		}else if(M == dp[n - 1][mask]){
			L += cnt[n - 1][mask];
		}
		
		//cout<<mask<<" "<<s<<" "<<dp[n - 1][mask]<<" "<<cnt[n - 1][mask]<<"\n";
		
	}
	
	
	
	/*for(ll i = 0;i < n;i++){
		for(ll mask = 0;mask < (1 << 3);mask++){
		
		   bool can = 0;
		
		   string s = "";
		   for(ll id = 0;id < 3;id++){
			   if(mask >> id & 1 && k[i] == id)can = 1;
			   if(mask >> id & 1)s += "1" ;
			   else s += "0" ;
		   }
		
		   if(can)continue;
		
		

		   cout<<" "<<s<<" "<<dp[i][mask]<<" "<<cnt[i][mask]<<"\n";
		
	    }
	    cout<<"#END\n";
	}*/
	
	
	
	
	
	
	cout<<M<<" "<<L;
	
	
	
	
	
	
	
	
	
	
	
}