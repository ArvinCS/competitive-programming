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
		
		int sum = 0;
		for(int x=0;x<n;x++){
			int val;
			cin >> val;
			
			sum += val;
		}
		
		cout << (sum+n-1)/n - sum/n << "\n";
	}
	
    return 0;
}

