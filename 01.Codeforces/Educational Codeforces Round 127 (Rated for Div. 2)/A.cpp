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


signed main(){
    
    ll t;
    
    cin>>t;
    
    while(t--){
    	string s;
    	cin>>s;
    	
    	ll n = s.size();
    	
    	s = " " + s;
    	
    	ll xa = 0,xb = 0;
    	bool can = 0;
    	
    	
    	
    	for(ll i = 1;i <= n;i++){
    		if(s[i] == 'a'){
    			if(xb > 0){
    				if(xb >= 2)xb = 0;
    				else {
    					can = 1;
    					break;
    				}
    			}
    			
    			xa++;
    			
    			
    		}else{
    			if(xa > 0){
    				if(xa >= 2)xa = 0;
    				else{
    					can = 1;
    					break;
    				}
    			}
    			xb++;
    		}
    	}
    	
    	
    	if(xa > 0){
    		if(xa < 2)can = 1;
    	}
    	
    	if(xb > 0){
    		if(xb < 2)can = 1;
    	}
    	
    	if(n == 1)can = 1;
    	
    	
    	cout<<((can) ? "NO" : "YES")<<"\n";
    }
    
    
    
}