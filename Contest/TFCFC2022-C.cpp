#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;
const int logN = 30;

int pw[logN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	pw[0] = 1;
	for(int x=1;x<logN;x++){
		pw[x] = 2 * pw[x-1];
	}
	
	int n;
	cin >> n;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	int cnt[30];
	fill(cnt, cnt+30, 0);
	
	auto check = [&cnt](int length) -> bool {
		for(int x=0;x<30;x++){
			if(cnt[x] == length){
				return false;
			}
		}
		return true;
	};
	
	int pos = -1;
	for(int x=0;x<n;x++){
		if(pos < x){
			pos = x;
			fill(cnt, cnt+30, 0);
			for(int y=0;y<30;y++){
				if(a[x]&pw[y]){
					cnt[y]++;
				}
			}
		}
		
		while(pos < n && !check(pos-x+1)){
			pos++;
			for(int y=0;y<30;y++){
				if(a[pos]&pw[y]){
					cnt[y]++;
				}
			}
		}
		
		if(x > 0) cout << " ";
		if(pos == n){
			cout << "-1";
		} else {
			cout << pos+1;
		}
		
		for(int y=0;y<30;y++){
			if(a[x]&pw[y]){
				cnt[y]--;
			}
		}
	}cout << "\n";
	
    return 0;
}

