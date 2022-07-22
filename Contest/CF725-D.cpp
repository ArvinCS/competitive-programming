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
		int a, b, k;
		cin >> a >> b >> k;
				
		if(k == 1){
			if(a == b){
				cout << "NO\n";
				continue;
			}
			if(a % b == 0 || b % a == 0){
				cout << "YES\n";
				continue;
			}
			
			cout << "NO\n";
			continue;
		}
		if(k > 60){
			cout << "NO\n";
			continue;
		}
		
		int cnt1 = 0, cnt2 = 0;
		while(a%2 == 0){
			cnt1++;
			a /= 2;
		}
		for(int x=3;x*x<=a;x+=2){
			if(a == 1) break;
			
			while(a%x == 0){
				cnt1++;
				a /= x;
			}
		}
		
		if(a > 1) cnt1++;

		while(b%2 == 0){
			cnt2++;
			b /= 2;
		}
		for(int x=3;x*x<=b;x+=2){
			if(b == 1) break;
			
			while(b%x == 0){
				cnt2++;
				b /= x;
			}
		}
		
		if(b > 1) cnt2++;
		
//		cout << cnt1 << " " << cnt2 << "\n";
		if(cnt1+cnt2 >= k){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}



