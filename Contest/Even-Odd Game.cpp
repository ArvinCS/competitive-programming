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
		for(int x=0;x<n;x++) cin >> data[x];
		
		sort(data, data+n);
		
		vector<int> odd, even;
		for(int x=0;x<n;x++){
			if(data[x]&1) odd.push_back(data[x]);
			else even.push_back(data[x]);
		}
		
		ull a = 0, b = 0;
		bool alice = true;
		while(odd.size() != 0 || even.size() != 0){
			if(alice){
				if(even.size() == 0 || (odd.size() > 0 && odd.back() > even.back())){
					odd.pop_back();
				} else {
					a += even.back();
					even.pop_back();
				}
			} else {
				if(odd.size() == 0 || (even.size() > 0 && even.back() > odd.back())){
					even.pop_back();
				} else {
					b += odd.back();
					odd.pop_back();
				}
			}
			alice = !alice;
		}
		
		if(a > b){
			cout << "Alice\n";
		} else if(a == b){
			cout << "Tie\n";
		} else {
			cout << "Bob\n";
		}
//		ull total[2], odd, even;
//		total[0] = total[1] = even = odd = 0;
//		
//		for(int x=0;x<n;x++){
//			if(data[x]&1){
//				odd++;
//				total[1] += data[x];
//			} else {
//				even++;
//				total[0] += data[x];
//			}
//		}
//
//		if(odd > even+1){
//			if(data[0] % 2 == 0){
//				cout << "Bob\n";
//			} else {
//				cout << "Alice\n";
//			}
//		} else if(odd == even+1){
//			if(total[1] >= total[0]){
//				cout << "Tie\n";
//			} else {
//				cout << "Alice\n";
//			}
//		} else if(odd == even){
//			if(total[1] >= total[0]){
//				cout << "Bob\n";
//			} else {
//				cout << "Alice\n";
//			}
//		} else {
//			cout << "Alice\n";
//		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

