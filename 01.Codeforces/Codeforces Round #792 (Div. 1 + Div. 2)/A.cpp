#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 1e5 + 5;
const long long mod = 666013;
const long long INF = 1e9;

using namespace std;

signed main(){
	ll t;
	cin>>t;
	
	while(t--){
		string s;
		cin>>s;
		
		if(s.size() == 1)cout<<s[0]<<"\n";
		if(s.size() == 2)cout<<s[1]<<"\n";
		else{
			ll smallest = 9;
			
			for(ll i = 0;i < s.size();i++)if(smallest > s[i] - '0')smallest = s[i] - '0';
		    cout<<smallest<<"\n";
		}
	}
}