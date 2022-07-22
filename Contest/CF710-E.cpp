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

	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
		
		int a[n], b[n];
		fill(a, a+n, -1);
		fill(b, b+n, -1);
		
		set<int> st;
		for(int x=1;x<=n;x++){
			st.insert(x);
		}
		a[0] = data[0];
		
		st.erase(a[0]);
		for(int x=1;x<n;x++){
			if(data[x-1] == data[x]){
				a[x] = *st.lower_bound(0);
			} else {
				a[x] = data[x];
			}
			st.erase(a[x]);
		}
		
		for(int x=1;x<=n;x++){
			st.insert(x);
		}
		b[0] = data[0];
		
		st.erase(b[0]);
		for(int x=1;x<n;x++){
			if(data[x-1] == data[x]){
				auto it = st.lower_bound(data[x]);
				--it;
				b[x] = *it;
			} else {
				b[x] = data[x];
			}
			st.erase(b[x]);
		}
		
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << a[x];
		}
		cout << "\n";
		
		for(int x=0;x<n;x++){
			if(x > 0) cout << " ";
			cout << b[x];
		}
		cout << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

