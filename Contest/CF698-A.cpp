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
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
		
		vector<int> colors;
		int cnt = 0;
		colors.push_back(data[0]);
		for(int x=1;x<n;x++){
			while(cnt < colors.size()){
				if(colors[cnt] < data[x]){
					colors[cnt] = data[x];
					cnt = 0;
					break;
				} else {
					cnt++;
				}
			}
			if(cnt == colors.size()){
				colors.push_back(data[x]);
				cnt = 0;
			}
		}
		
		cout << colors.size() << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

