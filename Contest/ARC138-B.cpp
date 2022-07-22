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
	
	bool possible = true;
	int cur = 0;
	int l = 0, r = n-1;
	while(l <= r){
		bool change = false;
		while(l <= r && (a[r]^cur) == 0){
			r--;
			change = true;
		}
		if(l <= r && (a[l]^cur) == 0){
			l++;
			cur++;
			cur %= 2;
			change = true;
		}
		
		if(!change){
			possible = false;
			break;
		}
	}
	
	cout << (possible ? "Yes" : "No") << "\n";
    return 0;
}

