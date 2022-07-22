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
		
		set<int> st;
		vector<int> v;
		for(int x=0;x<n;x++){
			int tmp;
			cin >> tmp;
			
			v.push_back(tmp);
			st.insert(tmp);
		}
		
		bool run = true;
		while(run){
			run = false;
			
			if(v.size() > 300) break;
			for(int x=0;x<v.size();x++){
				if(v.size() > 300) break;
				for(int y=x+1;y<v.size();y++){
					if(v.size() > 300) break;
					
					int dif = abs(v[x]-v[y]);
					if(!st.count(dif)){
						st.insert(dif);
						v.push_back(dif);
						run = true;
					}
				}
			}
		}
		
		if(v.size() > 300){
			cout << "NO\n";
			continue;
		}
		
		cout << "YES\n";
		cout << v.size() << "\n";
		for(int x=0;x<v.size();x++){
			if(x > 0) cout << " ";
			cout << v[x];
		}
		cout << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

