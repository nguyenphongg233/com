#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 50 + 5;
const long long mod = 20152015;
const long long INF = 1e9;

using namespace std;

ll n,m;
ll a[MAX],b[MAX];
ll pdt[MAX][MAX];
ll cnta[MAX],cntb[MAX];

signed main(){
	while(cin>>m>>n){
		if(n == 0 && m == 0)return 0;
		
    	memset(a,0,sizeof a);
    	memset(b,0,sizeof b);
    	memset(cnta,0,sizeof cnta);
    	memset(cntb,0,sizeof cntb);
    	memset(pdt,0,sizeof pdt);
    	
    	for (ll i = 1; i <= m; i++) cin >> a[i];
    	for (ll j = 1; j <= n; j++) cin >> b[j];
    	
    	for (ll i = 1; i <= m; i++){
    		if (a[i] == n) {
    			for (ll j = 1; j <= n; j++) {
    				pdt[i][j] = 1;
    				cnta[i]++;
    				cntb[j]++;
    			}
    		}
    	}
    		
    	for (ll j = 1; j <= n; j++){
    		if (b[j] == m) {
    			for (ll i = 1; i <= m; i++) {
    				if (!pdt[i][j]) {
    					cnta[i]++;
    					cntb[j]++;
    				}
    				pdt[i][j] = 1;
    			}
    		}
    	}
    	for (ll i = 1; i <= m; i++) {
    		for (ll j = n; j >= 1; j--) {
    			if (cnta[i] < a[i] && cntb[j] < b[j] && !pdt[i][j]) {
    				
    				    cnta[i]++;
	    				cntb[j]++;
	    				pdt[i][j] = 1;
    				
    			}
    		}
    	}
    	
    	bool ok = true;
    	for (ll i = 1; i <= m; i++)if(cnta[i] != a[i])ok = false;
    	for (ll j = 1; j <= n; j++)if(cntb[j] != b[j])ok = false;
    	
    	if(!ok)cout<<"-1";
    	else {
    		for (ll i = 1; i <= m; i++){
    			for(ll j = 1; j <= n; j++){
    			    cout << pdt[i][j];
    			}
    		}
    	}
    	
    	cout<<"\n";
		
	}
}