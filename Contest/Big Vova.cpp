#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ui t;
	cin >> t;
	
	while(t--){
		ui n;
		cin >> n;
		
		int data[n];
		for(ui x=0;x<n;x++) cin >> data[x];
		
		sort(data, data+n, greater<int>());	
		
		int pgcd = data[0];
		for(int x=0;x<n-1;x++){
			int j = x+1, best = 0, bestIndex = x+1;
			for(;j<n;j++){
				int tmp = gcd(pgcd, data[j]);
				if(tmp > best){
					best = tmp;
					bestIndex = j;
				}
			}
			swap(data[bestIndex], data[x+1]);
			pgcd = best;
		}
		
		cout << data[0];
		for(int x=1;x<n;x++){
			cout << " " << data[x];
		}
		cout << "\n";
	}
	
    return 0;
}

