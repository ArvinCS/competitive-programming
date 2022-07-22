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
		
		ull sum = 0;
		int data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
			sum += data[x];
		}
		
		sort(data, data+n, greater<int>());
		if(n == 1){
			cout << "T\n";
		} else {
			int cnt = 0;
			for(int x=0;x<n;x++){
				if(data[x] > sum/2){
					cnt++;
				}
			}
			
			if(cnt > 0){
				cout << "T\n";
			} else {
				if(sum % 2 == 0){
					cout << "HL\n";
				} else {
					cout << "T\n";
				}
			}
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

