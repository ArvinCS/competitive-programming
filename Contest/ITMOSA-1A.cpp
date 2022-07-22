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

const int maxN = 1e5 + 5;
pair<string, int> v[maxN];

bool customSort(pair<string, int> &a, pair<string, int> &b){
	return a.first < b.first;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	string s;
	cin >> s;
	
	s.push_back('$');
	
	int n = s.length();
	int lg = ceil(log2(n));
	int pw = pow(2, lg);
	
	for(int x=0;x<pow(2, lg);x++){
		s.push_back(s[x%n]);
	}
	
	string prv;
	for(int x=n-1;x>=0;x--){
		v[x] = {s.substr(x, pw), x};
	}
	
	sort(v, v+n, customSort);
	
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << v[x].second;
	}
	cout << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

