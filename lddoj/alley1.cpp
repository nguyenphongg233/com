#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define I first
#define II second
#define int long long
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a / gcd(a, b) * b
using namespace std;

const int MAXn = 100005;
const int MOD = 20152015;
const long long oo = 1e18;

int T, N;
char a[505][5];

int getbit(int x, int i) {
    return (x >> i) & 1;
}
int dp[505][1 << 5];

bool check1(int row, int mac) {
    for (int i = 0; i < 5; i++)
        if (getbit(mac, i) && a[row][i] == 'x') return false;
    return true;
}

bool check2(int row, int x, int y) {
    for (int i = 0; i < 4; i++){
        /*if (a[row + 1][i] != 'x' && a[row + 1][i + 1] != 'x' &&
            getbit(x, i) == getbit(y, i) && 
            getbit(x, i + 1) == getbit(y, i + 1) && 
            getbit(x, i) == getbit(x, i + 1))
            
            
            
            return false;*/
            
        
        if(a[row + 1][i] == 'x' && getbit(y,i) == 0)continue;
        if(a[row + 1][i + 1] == 'x' && getbit(y,i + 1) == 0)continue;
        if(a[row][i] == 'x' && getbit(x,i) == 0)continue;
        if(a[row][i + 1] == 'x' && getbit(x,i + 1) == 0)continue;
            
        if( getbit(x, i) == getbit(y, i) && 
            getbit(x, i + 1) == getbit(y, i + 1) && 
            getbit(x, i) == getbit(x, i + 1))return false;
    }
    return true;
}

int DP(int pos, int mask) {
    if (pos == N) return 1;
    
    if (dp[pos][mask] != -1) return dp[pos][mask];
    
    dp[pos][mask] = 0;
    for (int mask1 = 0; mask1 < 32; mask1++)
        if (check1(pos + 1, mask1) && check2(pos, mask, mask1))
            dp[pos][mask] = (dp[pos][mask] + DP(pos + 1, mask1)) % MOD;
    
    return dp[pos][mask];
}

signed main(void) {
    speed;
    
    cin >> N;
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < 5; j++) cin >> a[i][j];
    memset(dp, -1, sizeof dp);
    int res = 0;
    for (int i = 0; i < 32; i++) if (check1(1, i)) res = (res + DP(1, i)) % MOD;
    cout << res;
    
    return 0;
}
