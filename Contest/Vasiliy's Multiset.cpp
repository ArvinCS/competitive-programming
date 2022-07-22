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
	
	multiset<int> s;
	s.insert(0);
	
	int q;
	cin >> q;
	
	while(q--){
		int x;
		char c;
		cin >> c >> x;
		
		if(c == '+'){
			s.insert(x);
		} else if(c == '-'){
			s.erase(s.find(x));
		} else {
			int ans = 0;
			for(int i=31;i>=0;i--){
				ans |= (1 << i) & ~x;
				
				auto it = s.lower_bound(ans);
				if(it == s.end() || (*it >> i) != (ans >> i)){
					ans ^= (1 << i);
				}
			}
			cout << (ans^x) << "\n";
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

