#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int cnt[n];
	fill(cnt, cnt+n, 0);
	
	for(int x=0;x<4*n-1;x++){
		int val;
		cin >> val;
		
		cnt[val-1]++;
	}
	
	for(int x=0;x<n;x++){
		if(cnt[x] != 4){
			cout << x+1 << "\n";
			break;
		}
	}
    return 0;
}

