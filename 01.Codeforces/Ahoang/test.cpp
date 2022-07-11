#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second
#define int long long

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

int findX(int A, int B)
{
    int j = 0, x = 0;
 
    // While either A or B is non-zero
    while (A || B) {
 
        // Position at which both A and B
        // have a set bit
        if ((A & 1) && (B & 1)) {
 
            // Inserting a set bit in x
            x += (1 << j);
        }
 
        // Right shifting both numbers to
        // traverse all the bits
        A >>= 1;
        B >>= 1;
        j += 1;
    }
    return x;
}

signed main(){
	ll n,m;

	cin>>n>>m;
	ll x = findX(n,m);
	cout<<x<<"\n";
	x = n & m;
	cout<<x<<"\n";
	cout<<(n ^ x  + m ^ x)<<"\n";
	cout<<(n ^ m)<<"\n";
}