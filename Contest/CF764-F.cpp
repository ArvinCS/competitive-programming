#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int left = 1, right = n-1;
	int prv = 0, last = 0;
	int sum = 0, mn = 1e9;
	while(left <= right){
		int mid = (left+right) >> 1;
		
		cout << "+ " << (prv+mid) << endl;
		sum += prv+mid;
		
		int res;
		cin >> res;
		
		if(res-last >= 1){
			right = mid-1;
			prv = n-mid;
			mn = min(mn, mid);
		} else {
			left = mid+1;
			prv = -mid;
		}
		
		last = res;
	}
	
	cout << "! " << n-mn+sum << endl;
    return 0;
}

