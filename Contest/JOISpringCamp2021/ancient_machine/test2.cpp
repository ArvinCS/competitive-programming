#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
//    cout << 101 << "\n";
//    cout << "X";
//    for(int x=0;x<100;x++){
//    	if(x%2 == 0){
//    		cout << " Y";
//		} else {
//			cout << " Z";
//		}
//	}cout << "\n";
    int n;
    cin >> n;
    
    ll sum = 2;
    ll table[n+1];
    table[0] = 1;
    table[1] = 1;
    for(int x=2;x<=n;x++){
    	table[x] = 0;
		for(int y=0;y<=x-2;y++){
    		table[x] += table[y];
		}
		
		sum += table[x];
		cout << x << " -> " << sum << " " << log2(sum-1)+1 << "\n";
	}
    return 0;
}

