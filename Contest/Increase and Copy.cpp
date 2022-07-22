#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		if(n == 1) cout << "0\n";
		else {
			int best = inf_int, element = 1;
			while(element < n){
				int first = element-1;
				int step = first+(n/element);
				if(step > best) break;
				best = min(best, first+((n+element-1)/element)-1);
//				cout << element << " | " << best << "\n";
				element++;
			}
			cout << best << "\n";
		}
	}
	
    return 0;
}

