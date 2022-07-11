#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 2e3 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 50;

using namespace std;


ll n,m;

signed main(){
	cin>>n>>m;
	
	for(ll i = 1;i <= n;i++){
		if(i == 1)cout<<1<<" "<<m<<"\n";
		else {
			cout<<m + i - 1<<" ";
			
			if( ! (i & 1)){
				if(i <= n / 2){
					
				}
			}
		}
	}
}