#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

short check(int x, int n, int data[]){
	if(x > 0 && x < n-1){
		if(data[x-1] < data[x] && data[x] > data[x+1]) return 1;
		else if(data[x-1] > data[x] && data[x] < data[x+1]) return -1;
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int data[n];
		for(int x=0;x<n;x++){
			cin >> data[x];
		}
		
		ll intimidation = 0;
		for(int x=0;x<n;x++){
			intimidation += (check(x, n, data) != 0);
		}
		
//		cout << "before: " << intimidation << "\n";
		ll best = intimidation;
		for(int x=0;x<n;x++){
			ll tmp1 = intimidation, tmp2 = intimidation, prev = data[x];
			short center = check(x, n, data), left = check(x-1, n, data), right = check(x+1, n, data);
			if(x > 0){
				data[x] = data[x-1];
				short cur = check(x, n, data), curLeft = check(x-1, n, data), curRight = check(x+1, n, data);
				if(center != 0 && cur == 0){
					tmp1--;
				} else if(center == 0 && cur != 0){
					tmp1++;
				}
				if(left != 0 && curLeft == 0){
					tmp1--;
				} else if(left == 0 && curLeft != 0){
					tmp1++;
				}
				if(right != 0 && curRight == 0){
					tmp1--;
				} else if(right == 0 && curRight != 0){
					tmp1++;
				}
			}
			if(x < n-1){
				data[x] = data[x+1];
				short cur = check(x, n, data), curLeft = check(x-1, n, data), curRight = check(x+1, n, data);
				if(center != 0 && cur == 0){
					tmp2--;
				} else if(center == 0 && cur != 0){
					tmp2++;
				}
				if(left != 0 && curLeft == 0){
					tmp2--;
				} else if(left == 0 && curLeft != 0){
					tmp2++;
				}
				if(right != 0 && curRight == 0){
					tmp2--;
				} else if(right == 0 && curRight != 0){
					tmp2++;
				}
			}
			
			data[x] = prev;
			best = min(min(tmp1, tmp2), best);
		}
		
		cout << best << "\n";
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

