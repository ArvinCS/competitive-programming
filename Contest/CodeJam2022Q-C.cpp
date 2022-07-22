#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int mx = 1e6;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	for(int i=1;i<=t;i++){
		int n;
		cin >> n;
		
		int a[n];
		for(int x=0;x<n;x++){
			cin >> a[x];
		}
		
		sort(a, a+n);
		
		cout << "Case #" << i << ": ";
		int cnt = 1;
		for(int x=0;x<n;x++){
			if(cnt <= a[x]){
				cnt++;
			}
		}
		cout << cnt-1 << "\n";
	}
	
    return 0;
}

