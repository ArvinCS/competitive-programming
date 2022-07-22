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

int arr[4], sum = 0;

bool solve(int idx, int cnt){
	if(idx == 4){
		if(cnt == (sum-cnt)) return true;
		else return false;
	}	
	
	return solve(idx+1, cnt) || solve(idx+1, cnt+arr[idx]);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	for(int x=0;x<4;x++) cin >> arr[x];
	for(int x=0;x<4;x++) sum += arr[x];
	
	if(solve(0,0)){
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}

    return 0;
}

// Santai
// Pikirin dengan benar-benar

