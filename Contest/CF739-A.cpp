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

	vector<int> v;
	int cur = 1;
	while(v.size() < 1000){
		if(cur % 3 == 0 || cur % 10 == 3){
			cur++;
			continue;
		}
		
		v.push_back(cur++);
	}

	int t;
	cin >> t;
	
	while(t--){
		int k;
		cin >> k;
		
		cout << v[k-1] << "\n";
	}
    return 0;
}

