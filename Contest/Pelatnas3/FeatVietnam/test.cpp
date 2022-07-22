#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int m;
	cin >> m;
	
	int mn = 1e9;
	for(int a=30;a>=1;a--){
		int val1 = 100/a, val2 = 100/a + 1;
		int cnt2 = 100%a;
		int cnt1 = a-cnt2;
		
		ll val = 1;
		for(int x=0;x<cnt1;x++){
			val *= val1;
		}
		for(int x=0;x<cnt2;x++){
			val *= val2;
		}
		
		cout << val << "\n";
	}
	return 0;	
}
