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
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		sort(a, a+n);
		
		bool found = false;
		int last = 0;
		for(int x=0;x<n;x++){
			if(a[last] != a[x]){
				if(x-last >= 3){
					found = true;
					cout << a[last] << "\n";
					break;
				}
				last = x;
			}
		}
		
		if(!found && n-last >= 3){
			cout << a[last] << "\n";
			found = true;
		}
		if(found) continue;
		cout << "-1\n";
	}
	
    return 0;
}

