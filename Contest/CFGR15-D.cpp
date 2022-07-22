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
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		bool possible = false;
		for(int i=0;i<n;i++){
			vector<int> v;
			set<int> st;
			
			v.push_back(0);
			st.insert(0);
			v.push_back(a[i]);
			st.insert(a[i]);
			
			for(int x=0;x<n;x++){
				if(x == i) continue;
				
				bool found = false;
				for(int y=0;y<v.size();y++){
					for(int z=0;z<v.size();z++){
						if(v[y]-v[z] == a[x] || v[z]-v[y] == a[x]){
							found = true;
							break;
						}
					}
					if(found) break;
				}
				
				if(!found){
					v.push_back()
				}
			}
		}
		
		if(possible) cout << "YES\n";
		else cout << "NO\n";
	}

    return 0;
}

