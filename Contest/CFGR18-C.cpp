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
		int n;
		cin >> n;
		
		string a, b;
		cin >> a >> b;
		
		string inv_a = a;
		bool valid = false;
		for(int x=0;x<n;x++){
			if(inv_a[x] == '0'){
				inv_a[x] = '1';
			} else {
				valid = true;
				inv_a[x] = '0';
			}
		}
		
		if(!valid){
			if(a == b){
				cout << "0\n";
			} else {
				cout << "-1\n";
			}
			continue;
		}
		
		bool zero = false;
		int ans = 1e9;
		int cnt1 = 0, cnt2 = 0;
		for(int x=0;x<n;x++){
			if(a[x] != b[x]){
				if(a[x] == '0'){
					cnt1++;
				} else {
					cnt2++;
				}
			}
		}
		
		if(cnt1+cnt2 == 0){
			ans = min(ans, 0);
		} else {
			if(cnt1 <= cnt2){
				int mx = max(2*cnt1, cnt2);
				ans = min(ans, mx+(mx&1));
			}
		}

		cnt1 = 0, cnt2 = 0, zero = false;
		for(int x=0;x<n;x++){
			if(inv_a[x] != b[x]){
				if(inv_a[x] == '0'){
					cnt1++;
				} else {
					cnt2++;
				}
			}	
		}
		
		if(cnt1+cnt2 > 0 && cnt2 <= cnt1){
			int mx = max(cnt1, 2*cnt2);
			ans = min(ans, mx+(!(mx&1)));
		}
		
		cout << (ans != 1e9 ? ans : -1) << "\n";
	}
	
    return 0;
}

