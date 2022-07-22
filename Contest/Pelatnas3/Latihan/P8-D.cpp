#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n], b[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	for(int x=0;x<n;x++){
		cin >> b[x];
	}
	
	assert(n <= 2);
	
	if(n == 1){
		if(a[0] != b[0]){
			cout << "NO\n";
		} else {
			cout << "YES\n";
			cout << "0\n";
		}
	} else if(n == 2){
		if(a[0] == b[0] && a[1] == b[1]){
			cout << "YES\n";
			cout << "0 0\n";
		} else if(a[0] > b[0] && a[1] < b[1]){
			int nxt = a[0]*a[1] - b[0]*b[1];
			if(nxt*(b[0]-a[0]) < 0){
				cout << "NO\n";
				continue;
			}
			
			int lcm = (nxt*(b[0]-a[0]))/__gcd(abs(nxt), abs(b[0]-a[0]));
			int l = lcm/abs(nxt), r = lcm/abs(b[0]-a[0]);
			
			cout << l << " " << r
		}
	}
    return 0;
}

