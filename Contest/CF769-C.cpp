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
		
		int ans = b-a;
		for(int x=a;x<=b;x++){
			if((b&x) == x){
				ans = min(ans, x-a+1);
				break;
			}
		}
		for(int x=b;x<=2*b;x++){
			if((x&a) == a){
				ans = min(ans, x-b+1);
				break;
			}
		}
		cout << ans << "\n";
	}
	
    return 0;
}

