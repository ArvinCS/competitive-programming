#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	char data[n];
	for(int x=0;x<n;x++) cin >> data[x];
	
	int table[n+1][n+1];
	fill(table[0], table[n+1], 0);
	
	table[0][n] = 1;
	for(int x=0;x<n;x++){ // length
		for(int l=0;l<n-x;l++){ // range lft
			for(int r=l;r<l+(n-x);r++){ // range rght
				int tmp = table[l][r] * 25;
				for(char c='A';c<='Z';c++){
					if(data[r] == c) r--;
					else if(data[l] == c) l++;
					table[l][r] += tmp;
				}
			}
		}
	}
	
    return 0;
}

