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
		
		vector<int> odd, even;
		for(int x=0;x<n;x++){
			int tmp;
			cin >> tmp;
			
			if(tmp&1) odd.push_back(tmp);
			else even.push_back(tmp);
		}
		
		for(int x=0;x<odd.size();x++){
			if(x > 0) cout << " ";
			cout << odd[x];
		}
		for(int x=0;x<even.size();x++){
			if((x == 0 && odd.size() > 0) || x > 0) cout << " ";
			cout << even[x];
		}
		cout << "\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

