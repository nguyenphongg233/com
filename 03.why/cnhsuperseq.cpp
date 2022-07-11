#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 20 + 5;
const long long mod = 666013;
const long long INF = 1e9;

using namespace std;

struct Matrix{
    ll a[101][101];
    ll row,col;
    Matrix(){
        row = 0,col = 0;
        memset(a,0,sizeof a);
    }
    Matrix(ll n,ll m){
        row = n,col = m;
        memset(a,0,sizeof(a));
    }
    Matrix operator * (const Matrix & x) const{
        Matrix res(row,x.col);
        for (int i = 0; i <= row; ++i) {
            for (int j = 0; j <= x.col; ++j) {
                res.a[i][j] = 0;
                for (int k = 0; k <= col; ++k) {
                    res.a[i][j] += a[i][k]*x.a[k][j] ;
                    res.a[i][j] %= mod;
                }
            }
        }
        return res;
    }
};;

Matrix power(Matrix a,ll b){
    if(b == 1)return a;
    Matrix s = power(a,b/2);
    return (b & 1 ? s * s * a : s * s);
}

ll n,h,k;

signed main(){
	cin>>n>>h>>k;
	
	Matrix t(h,h);
	
	for(ll i = 0;i <= h;i++){
		for(ll j = 0;j <= h;j++){
			if(abs(i - j) <= k)t.a[i][j] = 1;
			else t.a[i][j] = 0;
		}
	}

	t = power(t,n - 1);
	
	cout<<(t.a[h][0])%mod;
	
}
