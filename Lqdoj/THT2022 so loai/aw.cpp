#include <bits/stdc++.h>
#define pii pair<int, int>
#define mp make_pair
#define F first
#define S second
#define maxc 1000000007
#define N 1000005
#define PB push_back

using namespace std;

int n, k, spe[N], sz[N], dd[N], best[N], ans = maxc, markB[N], dem = 1;
vector<pii> a[N];

void nhap()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i < n; i++)
    {
        int u, v, w; scanf("%d %d %d", &u, &v, &w); u++; v++;
        a[u].PB(mp(v, w));
        a[v].PB(mp(u, w));
    }
}

void dfsCentroid(int u)
{
    spe[u] = 0; sz[u] = 1;
    dd[u] = 1;
    for (auto z : a[u])
    {
        int v = z.F;
        if (dd[v]) continue;
        dfsCentroid(v);
        if (sz[v] > sz[spe[u]]) spe[u] = v;
        sz[u] += sz[v];
    }
    dd[u] = 0;
    
    
    //cout<<u<<" "<<sz[u]<<"\n";
}
int centroid(int u)
{
    int siz = sz[u]/2;
    while (sz[spe[u]] > siz)
        u = spe[u];
    return u;
}
void reset(int x)
{
    if (markB[x] != dem)
        markB[x] = dem, best[x] = maxc;
}
void DFS1(int u, int h, int dis)
{
    if (k <= dis)
    {
        if (dis == k)
            ans = min(ans, h);
        return;
    }
    reset(k - dis);
    ans = min(ans, h + best[k - dis]);
    dd[u] = 1;
    for (auto z : a[u])
    {
        int v = z.F;
        int w = z.S;
        if (dd[v]) continue;
        DFS1(v, h+1, dis + w);
    }
    dd[u] = 0;
}
void DFS2(int u, int h, int dis)
{
    if (k <= dis) return;
    reset(dis);
    best[dis] = min(best[dis], h);
    dd[u] = 1;
    for (auto z : a[u])
    {
        int v = z.F;
        int w = z.S;
        if (dd[v]) continue;
        DFS2(v, h+1, dis+w);
    }
    dd[u] = 0;
}
void solve(int u)
{
    dfsCentroid(u);
    for(int i = 1;i <= n;i++)cout<<i<<" "<<sz[i]<<'\n';
    u = centroid(u);
    dd[u] = 1;
    dem++;
    for (auto z : a[u])
    {
        int v = z.F;
        int w = z.S;
        if (dd[v]) continue;
        DFS1(v, 1, w);
        DFS2(v, 1, w);
    }
    for (auto z : a[u])
    {
        int v = z.F;
        if (!dd[v])
            solve(v);
    }
}
int main()
{
    //freopen("INP.TXT", "r", stdin);
    nhap();
    solve(1);
    //for(int i = 1;i <= n;i++)cout<<i<<" "<<sz[i]<<'\n';
    if (ans == maxc) ans = -1;
    printf("%d", ans);
}
