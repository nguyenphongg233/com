#include<bits/stdc++.h>

#define ll long long
#define X first
#define Y second

#define vi vector<ll>
#define ii pair<ll,ll>

const long long MAX = 2e5 + 5;
const long long mod = 1e9 + 7;
const long long INF = 1e9;

using namespace std;

string s;

signed main() {
	
	cin>>s;
	if (s.find("+") == -1 && s.find("-") == -1) {
		s = s + char('9' + 1);
		for (ll i=0; i<s.size(); i++) {
			if (s[i] < s[i+1]) {
				s.erase(i, 1);
				break;
			}
		}
		s.erase(s.size()-1, 1);
		cout<<s;
	}
	else {
		ll fn = -1e18;
		ll sum = 0;
		s = '+' + s;
		for (ll i=0; i<s.size(); i++) {
			if (s[i] == '+') {
				string tmp = "";
				while (i < s.size()) {
					i++;
					if (s[i] == '+' || s[i] == '-') {
						i--;
						break;
					}
					tmp = tmp + s[i];
				}
				ll tmp1 = stoll(tmp);
				sum = sum + tmp1;
			
			}
			else if (s[i] == '-') {
				string tmp = "";
				while (i < s.size()) {
					i++;
					if (s[i] == '+' || s[i] == '-') {
						i--;
						break;
					}
					tmp = tmp + s[i];
				}
				ll tmp1 = stoll(tmp);
				sum = sum - tmp1;
			
			}
		}
	
		for (ll i=0; i<s.size(); i++) {
			ll ok = 0;
			if (s[i] == '+' || s[i] == '-') {
				string s2 = "";
				string s1 = "";
				ll pos;
				for (ll j=i-1;j>=0;j--) {
					if (s[j] == '+' || s[j] == '-') {
						j++;
						pos = j;
						break;
					}
					s1 = s1 + s[j];
				}
				reverse(s1.begin(), s1.end());
				for (ll j=i+1;j<s.size();j++) {
					if (s[j] == '+' || s[j] == '-') {
						j--;
						break;
					}
					s2 = s2 + s[j];
				}
				if (s1 == "" || s2 == "") continue;
				string okela = s1+s2;
				ll t = stoll(okela);
				ll t1 = stoll(s1);
				ll t2 = stoll(s2);
				pos--;
				if (s[i] == '+') ok = ok - t2;
				else ok = ok + t2;
				if (s[pos] == '-') ok = ok + t1;
				else ok = ok - t1;
				if (s[pos] == '-') {
					ok = ok - t;
				}
				else ok = ok + t;
				
				pos--;
				fn = max(fn, sum + ok);
			}
		}
		for (ll i=1; i<s.size(); i++) {
			ll ok = 0;
			string s1 = "";
			string s2 = "";
			if (s[i] != '+' && s[i] != '-') {
				ll l, r;
				for (ll j=i-1; j>=0; j--) {
					if (s[j] == '+' || s[j] == '-') {
						j++;
						l = j;
						break;
					}
					s1 = s1 + s[j];
				}
				reverse(s1.begin(), s1.end());
				for (ll j=i+1; j<s.size(); j++) {
					if (s[j] == '+' || s[j] == '-') {
						j--;
						r = j;
						break;
					}
					s1 = s1 + s[j];
					r = j;
				}
				if (s1 == "") s1 = "0";
				if (s2 == "") s2 = "0";
				for (ll j=l; j<=r; j++) {
					s2 = s2 + s[j];
 				}
 			
 				ll t1 = stoll(s1);
 				ll t2 = stoll(s2);
 		
 				if (s[l-1] == '-') fn = max(fn, sum + t2 - t1);
 				else fn = max(fn, sum + t1 - t2);
			}
		}
		cout<<fn;
	}
	return 0;
}