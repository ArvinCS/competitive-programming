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
		int a, b;
		cin >> a >> b;
		
		int mn = min(a, b);
		a -= mn;
		b -= mn;
		for(int x=0;x<mn;x++){
			if(a > 0){
				cout << "01";
			} else {
				cout << "10";
			}
		}
		for(int x=0;x<a;x++){
			cout << 0;
		}
		for(int x=0;x<b;x++){
			cout << 1;
		}
		cout << "\n";
	}
	
    return 0;
}

