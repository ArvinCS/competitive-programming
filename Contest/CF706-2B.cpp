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
		int n, k;
		cin >> n >> k;
		
		int data[n];
		set<int> st;
		for(int x=0;x<n;x++){
			cin >> data[x];
			st.insert(data[x]);
		}
		
		sort(data, data+n);
		
		int a = -1, b = data[n-1];
		for(int x=0;x<n;x++){
			if(a+1 == data[x]){
				a++;
			} else {
				break;
			}
		}
		a++;
		
		if(a > b){
			cout << n+k << "\n";
			continue;
		}
		
		int ans = n;
		for(int x=0;x<k;x++){
			int res = (a+b+1)/2;
			if(res == a){
				ans++;
				st.insert(a);
				while(st.count(a)) a++;
			} else {
				if(!st.count(res)) ans++;
				break;
			}
		}
		
		cout << ans << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

