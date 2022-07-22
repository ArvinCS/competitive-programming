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
	
	int n, q;
	cin >> n >> q;
	
	set<int> st;
	st.insert(0);
	st.insert(n);
	
	for(int i=1;i<=q;i++){
		int c, m;
		cin >> c >> m;
		
		if(c == 1){
			st.insert(m);
		} else {
			auto it = st.lower_bound(m+1);
			auto it2 = st.lower_bound(m);
			it2--;
			
			cout << *it - *it2 << "\n";
		}
	}
	
    return 0;
}

