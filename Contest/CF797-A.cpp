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
		
		for(int a=3;a<=n;a++){
			int rem = n-a;
			int b = 2, c = 1;
			rem -= b;
			rem -= c;
			
			if(rem < 0){
				continue;
			}
			
			int mn = max(0, min(rem, a-b-1));
			rem -= mn;
			b += mn;
			
			mn = max(0, min(rem, b-c-1));
			rem -= mn;
			c += mn;
			if(rem == 0){
				cout << b << " " << a << " " << c << "\n";
				break;
			}
		}
	}
	
    return 0;
}

