#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ll n;
	cin >> n;
	
	vector<ll> v;
	string ans;
	while(n > 0){
		ll left = 1, right = n, bound = 1;
		while(left <= right){
			ll mid = (left+right) >> 1;
			
			if(mid*(mid+1)/2 <= n){
				bound = max(bound, mid);
				left = mid+1;
			} else {
				right = mid-1;
			}
		}
		
		n -= bound*(bound+1)/2;
		for(ll y=0;y<bound;y++){
			for(int z=0;z<v.size();z++){
				v[z] *= 10;
				v[z] += 7;
				v[z] %= 7;
			}
			
			ans.push_back('7');
		}
		
		for(int y=1;y<10;y++){
			bool valid = true;
			for(int z=0;z<v.size();z++){
				if((v[z]*10+y) % 7 == 0){
					valid = false;
					break;
				}
			}
			
			if(valid){
				for(int z=0;z<v.size();z++){
					v[z] *= 10; 
					v[z] += y;
					v[z] %= 7;
				}
				
				ans.push_back(('0' + y));
				v.push_back(y);
				break;
			}
		}
	}
	
	cout << ans << "\n";
    return 0;
}

