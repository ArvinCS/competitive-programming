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

	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		ll data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
		
		if(n == 2 && data[0] == data[1]){
			cout << "0\n";
			continue;
		}
		
		bool unli = true;
		for(int x=1;x<n;x++){
			if(data[x]-data[x-1] != data[1] - data[0]){
				unli = false;
				break;
			}
		}
		
		if(unli){
			cout << "0\n";
			continue;
		}
		
		bool possible = true;
		ll diff = -1;
		for(int x=1;x<n;x++){
			if(data[x-1] <= data[x]){
				diff = data[x]-data[x-1];
				break;
			}
		}
		
		ll m = -1;
		for(int x=1;x<n;x++){
			if(data[x-1] > data[x] && m == -1){
				m = (data[x-1]+diff)-data[x];
				break;
			}
		}
		
		if(m > 0){
			if(data[0]%m != data[0]){
				possible = false;
			}
			for(int x=1;x<n;x++){
				if((data[x-1]+diff)%m != data[x]){
					possible = false;
					break;
				}
			}
			bool dup = true;
			for(int x=1;x<n;x++){
				if((data[x-1]+diff)%(m+1) != data[x]){
					dup = false;
					break;
				}
			}
			if(dup) m = -1;
		} else {
			for(int x=1;x<n;x++){
				if(data[x-1]+diff != data[x]){
					possible = false;
					break;
				}
			}
		}
		
		if(diff < 0 || (m > 0 && diff >= m)){
			possible = false;
		}
		
		if(possible){
			if(m == -1) cout << "0\n";
			else cout << m << " " << diff << "\n";
		} else {
			cout << "-1\n";
		}
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

