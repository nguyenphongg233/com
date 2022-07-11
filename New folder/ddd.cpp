
#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define I first
#define II second
#define int long long
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / gcd(a, b) * b
using namespace std;
#define howlong cerr << "Time elapsed: " << fixed << setprecision(9) << (double)clock() / CLOCKS_PER_SEC << "s.";

const int MAXn = 100005;
const int MOD = 1e9 + 7;
const long long oo = 1e18;

int m, n;
int a[55], b[55];
int hmm[55][55];
int cnta[55], cntb[55];

signed main(void) {
    speed;
    if (ifstream("problem.INP")) {
    	freopen("problem.INP", "r", stdin);
    	freopen("problem.OUT", "w", stdout);
    }
    
    bool thinkcat = false;
    while (cin >> m >> n) {
    	if (!m && !n) break;
    	if (thinkcat) cout << '\n';
    	fill_n(cnta, 55, 0);
    	fill_n(cntb, 55, 0);
    	memset(hmm, 0, sizeof hmm);
    	for (int i = 1; i <= m; i++) cin >> a[i];
    	for (int j = 1; j <= n; j++) cin >> b[j];
    	for (int i = 1; i <= m; i++)
    		if (a[i] == n) {
    			for (int j = 1; j <= n; j++) {
    				hmm[i][j] = 1;
    				cnta[i]++;
    				cntb[j]++;
    			}
    		}
    	for (int j = 1; j <= n; j++)
    		if (b[j] == m) {
    			for (int i = 1; i <= m; i++) {
    				if (!hmm[i][j]) {
    					cnta[i]++;
    					cntb[j]++;
    				}
    				hmm[i][j] = 1;
    			}
    		}
    	for (int i = 1; i <= m; i++) {
    		for (int j = n; j >= 1; j--) {
    			if (cnta[i] < a[i]) {
    				if (cntb[j] < b[j]) {
    					if (!hmm[i][j]) {
	    					cnta[i]++;
	    					cntb[j]++;
	    				}
	    				hmm[i][j] = 1;
    				} else continue;
    			} else continue;
    		}
    	}
    	
    	bool ok = true;
    	for (int i = 1; i <= m; i++) if (cnta[i] != a[i]) {
    		ok = false;
    		break;
    	}
    	for (int j = 1; j <= n; j++) if (cntb[j] != b[j]) {
    		ok = false;
    		break;
    	}
    	if (ok) {
    		for (int i = 1; i <= m; i++)
    			for (int j = 1; j <= n; j++) cout << hmm[i][j];
    	} else cout << -1;
    	thinkcat = true;
    }
    
    
    return 0;
}