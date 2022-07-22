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
		
		int prefix[n];
		prefix[0] = data[0];
		
		for(int x=1;x<n;x++){
			prefix[x] = max(prefix[x-1], data[x]);
		}
		
//		vector<int> ans;
		stack<int> st[n+1];
		
		int s = 0;
		for(int x=n-1;x>=0;x--){
			if(data[x] == prefix[x]){
				st[s++].push(data[x]);
			} else {
				st[s].push(data[x]);
			}
		}
		
		bool spc = false;
		for(int x=0;x<=s;x++){
			while(!st[x].empty()){
				if(spc) cout << " ";
				cout << st[x].top();
				st[x].pop();
				spc = true;
			}
		}
		cout << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

