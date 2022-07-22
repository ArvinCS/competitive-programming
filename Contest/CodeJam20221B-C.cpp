#include <bits/stdc++.h>

using namespace std;

#define ll long long

int ask(int n){
	for(int x=0;x<n;x++){
		cout << "1";
	}
	for(int x=0;x<8-n;x++){
		cout << "0";
	}
	cout << endl;
	
	int res;
	cin >> res;
	
	return res;
}

int askWithVal(int n){
	for(int x=0;x<8;x++){
		if(n&(1 << x)) cout << "1";
		else cout << "0";
	}
	cout << endl;
	
	int res;
	cin >> res;
	
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	
	int t;
	cin >> t;
	
	while(t--){
		int cnt = ask(8);
		
		while(cnt > 0){
			int val = 0;
			while(__builtin_popcount(val) == (cnt+(rng()%(8-cnt+1)))){
				val = (rng() % (1 << 8));
			}
			
			cnt = askWithVal(val);
			if(cnt == 8) cnt = ask(cnt);
			assert(cnt >= 0);
		}
	}
	
    return 0;
}

