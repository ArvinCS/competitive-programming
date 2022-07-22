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
		
		int odd = 0, even = 0;
		for(int x=0;x<n;x++){
			int val;
			cin >> val;
			
			if(val&1) odd++;
			else even++;
		}
		
		cout << min(odd, even) << "\n";
	}
	
    return 0;
}

