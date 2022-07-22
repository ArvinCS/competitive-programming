#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int q = 0;
	auto ask = [&](int l, int r) -> bool {
		q++;
		cout << "? " << l << " " << r << endl;
		
		bool res;
		cin >> res;
		
		return res;
	};
	
	int ans = 1;
	int l = -1;
	for(int x=1;x<n;x++){
		if(l >= 0){
			if(ask(l+1, x+1)){
				ans = max(ans, x-l+1);
				l--;
			} else {
				l = -1;
			}
		}
		if(l < 0){
			if(x >= 2 && ask((x-2)+1, x+1)){
				l = x-2;
				ans = max(ans, x-l+1);
				l--;
			} else if(x >= 1 && ask((x-1)+1, x+1)){
				l = x-1;
				ans = max(ans, x-l+1);
				l--;
			}
		}
	}
	
	assert(q <= 200000);
	
	cout << "! " << ans << endl;
    return 0;
}

