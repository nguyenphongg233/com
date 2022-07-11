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
    
    
    string s;
    ll a[MAX];
    ll n;
    
    cin>>n>>s;
    
    ll sum = 0;
    for(ll i = 'a';i <= 'z';i++)cin>>a[i - 'a' + 1],sum += a[i - 'a' + 1];
    
    if(sum != n)return cout<<-1,0;
    
    for(ll i = 0;i < s.size();i++)if(s[i] != '?'){
    	a[s[i] - 'a' + 1]--;
    	if(a[s[i] - 'a' + 1] < 0)return cout<<-1,0;
    }
    
    for(ll i = 0;i <s.size();i++){
    	
    	if(s[i] != '?')cout<<s[i];
    	else{
    		
    	   char d;
    	
    	   for(ll j = 'a';j <= 'z';j++){
    	   	   if(a[j - 'a' + 1] > 0){
    	   	   	   d = j;
    	   	   	   a[j - 'a' + 1]--;
    	   	   	   break;
    	   	   }
    	   }
    	   
    	   cout<<char(d);
    	}
    }
    
    
    
}