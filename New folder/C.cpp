#include<bits/stdc++.h>

#define ll int
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 1e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
const long long N = 205;
using namespace std;


bool dd[30][MAX];
string s[MAX];
vi vty[N];
ll n;

signed main(){


    cin >> n;
	for(ll i = 1;i<=n;i++){
		cin >> s[i];
		
		char x = s[i][0] - 'a';
		ll y = s[i].size();
		dd[x][y] = 1;
	}
	
	for(char x = 'a'; x <= 'z'; x++){
		//cout<<x<<"";
		
		for(ll i=1;i < MAX;i++){
			
			ll io = x - 'a';
			//cout<<io<<"";
			if(!dd[io][i]){
				
				vty[io].push_back(i);
				
			}
			
			
			//cout<<io<<"";
		}
		
		
	}
	
	for(ll i = 1;i<=n;i++){
		char x = s[i][0] - 'a';
		
		ll tt = lower_bound(vty[x].begin(),vty[x].end(),s[i].size()) - vty[x].begin();
		
		
		
		//cout<<x<<"\n";
		cout << vty[x][tt] - s[i].size() << endl;
		
	}
	return 0;
	
}