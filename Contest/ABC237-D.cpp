#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	int ans[2*n+3];
	int left = n+1, right = n+1;
	ans[left] = n;
	for(int x=n-1;x>=0;x--){
		if(s[x] == 'L'){
			ans[++right] = x;
		} else {
			ans[--left] = x;
		}
	}
	
	for(int x=left;x<=right;x++){
		if(x > left) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

