#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    
    int cnt = 0;
    for(int x=0;x<n;x++){
    	bool ok = true;
		int lst = -2;
		for(int y=0;y<=log2(n);y++){
			if(x&(1 << y)){
				if(y-lst <= 1){
					if(x == 5) cout << y << " " << lst << "\n";
					ok = false;
					break;
				}
				lst = y;
			}
		}
		
		if(ok){
			cnt++;
			for(int y=0;y<=log2(n);y++){
				if(x&(1<<y)) cout << 1;
				else cout << 0;
			}
			cout << "\n";
//			cout << x << "\n";
		}
	}
	
	cout << " -> " << cnt << "\n";
    return 0;
}

