#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 1e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

ll n,t,su[MAX];

signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	
	for(ll i = 1;i < MAX;i++){
		
		for(ll j = 1;j * j <= i;j++){
			
			 if(i % j != 0)continue;
		
		     if(j * j == i)su[i] += j;
		     else su[i] += (j + i / j);
		
		
		}
		
	}
	
	
	
	
	
	cin>>t;
	
	
	
	
	while(t--){
		cin>>n;
		
		
		if(n > 1e5){
			ll sum = 0;
			for(ll i = 1;i * i <= n;i++){
				
				if(n % i != 0)continue;
				
				if(i * i == n){
					
					sum += i;
					
				}else{
					
					sum += i;
					sum += (n / i);
	
				}
				
			}
			
			cout<<sum<<"\n";
		}else{
			cout<<su[n]<<'\n';
		}
		
	}
}