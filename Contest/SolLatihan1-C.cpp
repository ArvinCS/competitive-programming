#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n, m, rb, cb, rd, cd;
		cin >> n >> m >> rb >> cb >> rd >> cd;
		
		// kita incar nilai minimum dari step row atau column.
		
		int ans = 1e9;
		if(rd < rb){ // jika robot perlu memantul terlebih dahulu, karena robot harus ke bawah baru bisa naik lagi.
			int step = (n-rb)+(n-rd);
			
			if(ans > step){
				ans = step;
			}
		} else {
			int step = rd-rb;
			
			if(ans > step){
				ans = step;
			}
		}
		
		if(cd < cb){ // jika robot perlu memantul terlebih dahulu, karena robot harus ke kanan baru bisa ke kiri lagi.
			int step = (m-cb)+(m-cd);
			
			if(ans > step){
				ans = step;
			}
		} else {
			int step = cd-cb;
			
			if(ans > step){
				ans = step;
			}
		}
		
		cout << ans << "\n";
	}
	
    return 0;
}

