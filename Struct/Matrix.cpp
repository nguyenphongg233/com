#include<bits/stdc++.h>

#define ll long long
#define ld long double

#define X first
#define Y second

#define faster() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ce(x) cerr << #x << " = " << x << endl
#define len(x) x.size();

#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<pair<ll, ll>>
#define matrix vector<vi>

const double pi = 1.00 * acos(-1.00);
const long long  MAX = 100005;
const long long  INF = 1e18;
const long long mod = 1e9 + 7;

const int dx[] = {0,0,-1,1};
const int dy[] = {1,-1,0,0};

//  code là cái gì ?

using namespace std;

const int N = 10;

struct Matrix {
    ll a[N][N];
    ll row,col;
    Matrix(){
       row = 0,col = 0;
       memset(a,0,sizeof a);
    }
    Matrix(ll n,ll m){
        row = n,col = m;
        memset(a,0,sizeof a);
    }
    Matrix operator * (const Matrix &x) const{
        Matrix res(row,x.col);
        for(ll i = 0;i<row;i++){
            for(ll j = 0;j<x.col;j++){
                res.a[i][j] = 0;
                for(ll z = 0;z < x.col;z++){
                    res.a[i][j] += a[i][z]*x.a[z][j];
                }
            }
        }
    }
    // x.size() = a.size()
    Matrix operator + (const Matrix &x) const{
        Matrix res(row,col);
        for(ll i = 0;i<row;i++){
            for(ll j = 0;j<col;j++){
                res.a[i][j] = a[i][j] + x.a[i][j];
            }
        }
    }
};


Matrix power(Matrix &a,ll b){
	if(b == 1)return a;
	Matrix s = power(a,b / 2);
	
	s = s * s;
	
	if(b & 1)s = s * a;
	
	return s;
}

signed main(){
	
}
