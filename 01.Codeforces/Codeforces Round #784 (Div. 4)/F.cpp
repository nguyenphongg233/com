#include<bits/stdc++.h>
 
#define int long long
#define X first
#define Y second
 
#define vi vector<ll>
#define ii pair<ll,ll>
 
const long long MAX = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;
 
using namespace std;
 
 
int n, a[MAX];

signed main() {
   
    
	int t;
	cin>>t; while(t--) {
		cin>>n;
		for (int i=1; i<=n; i++) {
			cin>>a[i];
		}
		int fn = 0;
		int l = a[1], r = a[n];
		int i=1, j=n;
		while (i!=j){
			if (l == r){
				fn = max(fn, i+n-j+1);
				i++;
				l += a[i];
				continue;
			}
			else if (l>r){
				j--;
				r += a[j];
				continue;
			}
			else if(r>l){
				i++;
				l += a[i];
			}
		}
		cout<<fn<<'\n';
	}

	return 0;
}