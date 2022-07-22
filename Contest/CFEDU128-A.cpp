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
		int l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		
		if(l1 > l2){
			swap(l1, l2);
			swap(r1, r2);
		}
		
		if(l2 <= r1){
			cout << l2 << "\n";
		} else {
			cout << l1 + l2 << "\n";
		}
	}
	
    return 0;
}

