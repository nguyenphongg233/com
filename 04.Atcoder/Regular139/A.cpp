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

ll n,t[MAX],a[MAX];

ll binary(string n){
	ll sum = 0;
	reverse(n.begin(),n.end());
	ll pow2 = 1;
	for(ll i = 0;i < n.size();i++){
		if(n[i] == '1')sum += pow2;
		pow2*=2;
	}
	return sum;
}

signed main(){
    
    
    cin>>n;
    
    string last = "";
    for(ll i = 1;i <= n;i++)cin>>t[i];
    
    for(ll i = 1;i <= n;i++){
    	string new2 = "";
    	reverse(last.begin(),last.end());
    	
    	for(ll j = 1;j <= t[i];j++)new2 += "0";
    	bool find0 = 0;
    	
    	string new1 = new2;
    	for(ll j = t[i];j < last.size();j++){
    		if(!find0 && last[j] == '0'){
    			new2 = "1" + new2;
    			find0 = 1;
    		}else new2 = last[j] + new2;
    	}
    	
    	if(!find0){
    		new1 = "1";
    		for(ll j = 1;j <= max(t[i],last.size());j++)new1 += "0";
    		last = new1;
    	}else{
    		last = reverse(new2.begin(),new2.end());
    	}
    	
    }
    
    cout<<binary(last);
    
    
    
    
    
    
    
    
}