#include<bits/stdc++.h>
 
#define ll long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 1e2 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 165;
 
using namespace std;

ll n,k;
ll dp[MAX][2][2];
bool d[MAX];

// f(i,<= n,>= 0) = cnt

signed main(){
	while(cin>>n>>k){
		memset(d,0,sizeof d);
		d[0] = 1;
		for(ll i = 1;i * k + 1 < MAX;i++){
			d[i * k + 1] = 1;
		}
		
		string s = "";
		
		while(n > 0){
			s = char(n % 2 + '0') + s;
			n /= 2;
		}
		
		cout<<s<<"\n";
		
		dp[s.size() - 1][1][1] = d[s.size() - 1];
		dp[s.size() - 1][0][0] = d[s.size() - 1];
		
		for(ll i = s.size() - 1;i > 0;i--){
			for(ll lower = 0;lower < 2;lower++){
				for(ll pos = 0;pos < 2;pos++){
					for(ll digit = 0;digit < 2;digit++){
						if(!lower && digit >= s[i - 1] - '0')continue;
						
						bool pos2 = pos || digit == 1;
						
						bool lower2 = lower || digit < s[i - 1] - '0';
						
						if(d[i])dp[i][lower][pos]++;
						dp[i - 1][lower2][pos2] += dp[i][lower][pos];
							
					}
				}
			}
		}
		
		cout<<dp[0][1][1]<<"\n";
	}
}


