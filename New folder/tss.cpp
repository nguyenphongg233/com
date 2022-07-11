#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define I first
#define II second
#define int long long
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / gcd(a, b) * b
using namespace std;

const int MAXn = 10005;
const int MOD = 1e9 + 7;
const long long oo = 1e18;

int n, hmm[MAXn], f[MAXn];
vector<int> adj[MAXn];
int c[31][MAXn];
void DFS(int v, int anc) {
    if (v != 1 && adj[v].size() < 2) {
        hmm[v] = 1;
        f[v] = 1;
    } else {
        for (int u: adj[v])
            if (u != anc) {
                DFS(u, v);
                f[v] += f[u];
                c[hmm[u]][v] = true;
            }
        for (int k = 1; k <= 30; k++) if (!c[k][v]) {
            hmm[v] = k;
            f[v] += k;
            break;
        }
    }
}

signed main(void) {
    speed;
    
    cin >> n;
    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    DFS(1, -1);
    cout << f[1] << '\n';
    for (int i = 1; i <= n; i++) cout << hmm[i] << '\n';
    
    return 0;
}
/*
    Glory to Informatics :>
    Never gonna give Informatics up!
*/