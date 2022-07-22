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

int ask(int l, int r){
	cout << "? " << l << " " << r << endl;
	int ans;
	cin >> ans;
	
	return ans;
}

void ans(int x){
	cout << "! " << x << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n, t;
	cin >> n >> t;
	
	int m;
	cin >> m;
	
	int left = 1, right = n;
	int cnt = 0;
	while(left <= right){
		if(left == right){
			ans(left);
			break;
		}
		
		int mid = (left+right) >> 1;
		
		int a = ask(left, mid);
		if(cnt+(mid-left+1-a) < m){
			cnt += (mid-left+1-a);
			left = mid+1;
		} else {
			right = mid;
		}
	}
	
    return 0;
}

// Santai
// Pikirin dengan benar-benar

