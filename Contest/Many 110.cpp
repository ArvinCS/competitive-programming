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
	
	ll n;
	cin >> n;
	
	short data[n];
	for(int x=0;x<n;x++){
		char tmp;
		cin >> tmp;
		
		data[x] = (tmp-'0');
	}
	
	ll cnt = 1;
	bool first = true;
	bool one = data[0];
	for(int x=1;x<n;x++){
		if(data[x] == 1){
			if(one){
				cnt++;
				if(cnt >= 3){
					cout << "0\n";
					return 0;
				}
			} else {
				if(cnt > 1 && !first){
					cout << "0\n";
					return 0;
				}
				first = false;
				cnt = 1;
			}
			one = true;
		} else {
			if(one){
				if(cnt < 2 && !first){
					cout << "0\n";
					return 0;
				}
				cnt = 1;
				first = false;
			} else {
				cnt++;
				if(cnt > 1){
					cout << "0\n";
					return 0;
				}
			}
			one = false;
		}
	}
	
	ll ans = 3*1e10;
	
	int index = 0;
	while(index < 10){
		bool valid = true;
//		cout << index << " : ";
		for(ll x=0;x<min(n, 3ll);x++){
//			cout << ((index+x+1)%3 != 0) << "(" << data[x] << ") ";
			if(((index+x+1)%3 != 0) != data[x]){
				valid = false;
				break;
			}
		}
//		cout << "\n";
		
		if(valid){
//			cout << valid << " - " << index << "\n";
			break;
		}
		index++;
	}

	if(n == 1 && data[0] == 1){
		cout << 2*ans/3 << "\n";
		return 0;
	}
	
	ll length = ans-index+1;
	cout << index << "\n";
	cout << max(length-((n+2)/3-1)*3, 0ll)/3 << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

