#include <bits/stdc++.h>

using namespace std;

#define ll long long

int ask(int i, int j, int k){
	cout << "? " << i << " " << j << " " << k << endl;
	
	int res;
	cin >> res;
	
	assert(res >= 0);
	
	return res;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		int start = ask(1,2,3);
		int c = 3;
		int prv = start;
		for(int x=4;x<=n;x++){
			int askA = ask(1, 2, x);
			
			if(prv < askA){
				prv = askA;
				c = x;
			}
		}
		
		int b = 2;
		int start2 = prv;
		prv = start2;
		for(int x=3;x<=n;x++){
			if(x == c) continue;
			
			int askB = ask(1, c, x);
			if(prv < askB){
				prv = askB;
				b = x;
			}
		}
		
		for(int x=1;x<=n;x++){
			if(x == 1 || x == b || x == c) continue;
			
			int askA = ask(1,b,x), askB = ask(1,c,x), askC = ask(b,c,x);
			
			if(askA >= max(askB, askC)){
				cout << "! " << 1 << " " << b << endl;
			} else if(askB >= max(askA, askC)){
				cout << "! " << 1 << " " << c << endl;
			} else if(askC >= max(askA, askB)){
				cout << "! " << b << " " << c << endl;
			}
			break;
		}
	}
	
    return 0;
}

