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

ll data[maxN];

int solve(vector<int> v, int bit){
	if(bit < 0) return 0;
	
	vector<int> zero, one;
	
	int tmp = (1 << bit);
	for(auto e : v){
		if(e&tmp) one.push_back(e);
		else zero.push_back(e);
	}
	
	if(zero.size() == 0) return solve(one, bit-1);
	if(one.size() == 0) return solve(zero, bit-1);
	
	return min(solve(zero, bit-1), solve(one, bit-1)) + tmp;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	vector<int> v;
	for(int x=0;x<n;x++){
		cin >> data[x];
		v.push_back(data[x]);
	}
	
	cout << solve(v, 30) << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar
