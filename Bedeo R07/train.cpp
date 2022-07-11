#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 1e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 20;
 
using namespace std;

ll n,l;
ll x[MAX],t[MAX];

signed main(){
	cin>>n>>l;
	
	ll cnt = 0;
	
	for(ll i = 1;i <= n;i++)cin>>x[i];
	for(ll i = 1;i <= n;i++)cin>>t[i];
	
	ll id = 0;
	bool ok = 0;
	
	// 0 : xuoi
	// 1 : nguoc
	
	for(ll i = 1;i <= n;i++){
		if(ok){
			
			if(id < x[i])cnt++,id = x[i],ok = 0;
			
			if(id >= x[i]){
				if(x[i] * 2 >= t[i]){
					id = x[i];
					cnt++;
					ok = 0;
				}else{
					ll time = t[i] - x[i];
					// dung o 0 
					
					ll round = time / l;
					ll rt = time % l;
					
					
					if(round & 1){
						// di nguov
						
						if(rt <= l - x[i])cnt += round,ok = 1,id = x[i];
						else cnt += round + 1,ok = 0,id = x[i];
						
						
					}else{
						// di xuoi 
						
						if(rt <= x[i])cnt += round,ok = 0,id = x[i];
						else cnt += round + 1,ok = 1,id = x[i];
						
					}
					
				}
			}
		}else{
			if(id > x[i])cnt++,id = x[i],ok = 0;
			
			if(id <= x[i]){
				if((l - x[i]) * 2 >= t[i]){
					id = x[i];
					cnt++;
					ok = 0;
				}else{
					ll time = t[i] - x[i];
					// dung o 0 
					
					ll round = time / l;
					ll rt = time % l;
					
					
					if(round & 1){
						// di nguov
						
						if(rt <= l - x[i])cnt += round,ok = 0,id = x[i];
						else cnt += round + 1,ok = 1,id = x[i];
						
						
					}else{
						// di xuoi 
						
						if(rt <= x[i])cnt += round,ok = 1,id = x[i];
						else cnt += round + 1,ok = 0,id = x[i];
						
					}
					
				}
			}
		}
	}
	
	
	
	//ll sum = l * cnt;
	
	if(id != 0 && id != l)cnt+= 1 - ok + 1;
	cout<<l * cnt;
	
}