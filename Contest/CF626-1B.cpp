#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	int b[n];
	
	int ans = 0;
	for(int y=0;y<29;y++){
		int bit = (1 << y);
		int nxt = (1 << (y+1));
		int one = 0;
		
		for(int x=0;x<n;x++){
			b[x] = a[x]%nxt;
		}
		
		sort(b, b+n);
		
		auto search = [&](int val, int sz) -> int {
			int ans = sz+1;
			int left = 0, right = sz;
			while(left <= right){
				int mid = (left+right) >> 1;
				
				if(b[mid] >= val){
					ans = mid;
					right = mid-1;
				} else {
					left = mid+1;
				}
			}
			return ans;
		};
		
		for(int x=0;x<n;x++){
			if(b[x]&bit){
				one += search((b[x]^(nxt-1))+1, x-1);//st.order_of_key((b[x]^(nxt-1))+1);
				one += x - search(((b[x]^(nxt-1))|bit)+1, x-1);//st.size() - st.order_of_key(((b[x]^(nxt-1))|bit)+1);
			} else {
				one += x - search((b[x]^(bit-1))+1, x-1);//st.size() - st.order_of_key((b[x]^(bit-1))+1);
			}
		}
		
		if(one&1){
			ans |= bit;
		}
	}
	
	cout << ans << "\n";
    return 0;
}

