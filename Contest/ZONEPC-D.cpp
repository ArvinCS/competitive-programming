#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	string s;
	cin >> s;
	
	bool normal = true;
	deque<char> dq;
	for(int x=0;x<s.length();x++){
		if(s[x] == 'R'){
			normal = !normal;
		} else {
			if(normal){
				dq.push_back(s[x]);
			} else {
				dq.push_front(s[x]);
			}
		}
	}
	
	string t;
	if(normal){
		for(int x=0;x<dq.size();x++){
			t += dq[x];
		}
	} else {
		for(int x=dq.size();x>=1;x--){
			t += dq[x-1];
		}
	}
	
	int n = t.length(), prv = 0;
	int parrent[n+1];
	for(int x=0;x<n;x++){
		parrent[x] = x-1;
	}
	
	for(int x=1;x<n;x++){
		if(t[x] == t[prv]){
			t[x] = t[prv] = '.';
			
			prv = parrent[prv];
			parrent[x+1] = prv;
		} else {
			prv = x;
		}
	}
	
	for(int x=0;x<n;x++){
		if(t[x] != '.') cout << t[x];
	}
	cout << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

