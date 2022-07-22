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

	int n, m;
	cin >> n >> m;
	
	bool bit[20];
	fill(bit, bit+20, false);
	
	for(int x=0;x<=19;x++){
		if(m&(1<<x)){
			bit[x] = true;
		}
	}
	
	vector<int> ans;
	set<int> st;
	st.insert(0);
	for(int x=1;x<pow(2,n);x++){
		if(st.count(x^m)) continue;
		st.insert(x);
	}
	
	for(auto it=st.begin();it != st.end();it++){
		ans.push_back(*it);
	}
	
	cout << ans.size()-1 << "\n";
	for(int x=1;x<ans.size();x++){
		if(x > 1) cout << " ";
		int num = ans[x]^ans[x-1];
		cout << num;
	}
	cout << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

