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
	
	int n;
	cin >> n;
	
//	if(n == 3){
//		cout << "6 10 15\n";
//		return 0;
//	}
	
	ll ans[n];
	
	set<int> st;
	for(int x=1;x*6<=10000;x++) st.insert(x*6);
	for(int x=1;x*10<=10000;x++) st.insert(x*10);
	for(int x=1;x*15<=10000;x++) st.insert(x*15);
	
	auto it = st.begin();
	for(int x=0;x<n;x++){
		ans[x] = (*it);
		it++;
	}
	
	for(int x=0;x<n;x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

