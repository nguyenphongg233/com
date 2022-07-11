#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>
#define vii vector<ii>

const long long MAX = 1e6 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e18;

using namespace std;


signed main(){
	char a,b;
	
	cin>>a>>b;
	
	if(a == b)cout<<'D';
	else if(a == 'S' && b == 'R')cout<<'B';
	else if(a == 'R' && b == 'P')cout<<'B';
	else if(a == 'P' && b == 'S')cout<<'B';
	else cout<<'A';
}
