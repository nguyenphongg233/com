#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define pii pair<int,int>
#define taskname "onepiece"
#define faster ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

const int oo = 1e5+5;
const int mod = 1000007;

int n,k;
int f[oo][102][2];

int cal(int i, int sk, bool ok)
{
	if(i > n)
	{
		if(sk >= k || ok) return 1;
		else return 0; 
	}
	if(f[i][sk][ok] != -1) return f[i][sk][ok];
	
	int res = 0;
	if(ok)
	{
		res += cal(i+1, sk+1, 1);
		res += cal(i+1,    0, 1);
	}
	else
	{
		int tk = sk+1;
		
		if(tk <= k){
		res += cal(i+1, tk, (tk >= k) ? 1 : 0);
		res += cal(i+1, 0, 0);
		}
		else 
	}
	res %= mod;
	return f[i][sk][ok] = res;	
}

int32_t main()
{
	if(ifstream(taskname".inp"))
	{
		freopen(taskname".inp", "r", stdin);
		freopen(taskname".out", "w", stdout);
	}
	faster
	
	cin >> n >> k;
	memset(f,-1,sizeof(f));
	cout << cal(1,0,0);
//	for(int i = 1; i <= n; i++)
//	{
//		for(int sk = 0; sk <= n; sk++)
//		{
//			for(int ok = 0; ok <= 1; ok++) cout << i <<" "<< sk <<" "<< ok << ":" <<" "<< f[i][sk][ok] << '\n';
////			cout << endl;
//		}
//	}

	return 0;
}
