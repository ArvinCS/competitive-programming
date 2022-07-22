#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18
#define mod 1000000007
#define smod 998244353

const int maxN = 1e5 + 5;

int prefix[2][maxN][3], cnt[maxN][3][3], n;
string a, b;

int transform(char c){
	if(c == 'A') return 0;
	else if(c == 'T') return 1;
	else return 2;
}

void init(string c, string d){
	a = c;
	b = d;
	n = a.length();
	
	for(int x=0;x<n;x++){
		for(int y=0;y<3;y++){
			prefix[0][x][y] = (x > 0 ? prefix[0][x-1][y] : 0);
			prefix[1][x][y] = (x > 0 ? prefix[1][x-1][y] : 0);
		}
		
		prefix[0][x][transform(a[x])]++;
		prefix[1][x][transform(b[x])]++;
	}
	
	for(int x=0;x<n;x++){
		for(int y=0;y<3;y++){
			for(int z=0;z<3;z++){
				cnt[x][y][z] = (x > 0 ? cnt[x-1][y][z] : 0);
			}
		}
		
		if(a[x] != b[x]){
			cnt[x][transform(a[x])][transform(b[x])]++;
		}
	}
}

int get_distance(int l, int r){
	bool valid = true;
	for(int x=0;x<3;x++){
		if(prefix[0][r][x] - (l > 0 ? prefix[0][l-1][x] : 0) != prefix[1][r][x] - (l > 0 ? prefix[1][l-1][x] : 0)){
			valid = false;
			break;
		}
	}
	
	if(!valid) return -1;
	
	int ans = 0, ans2 = 0;
	for(int x=0;x<3;x++){
		for(int y=x+1;y<3;y++){	
			int left = cnt[r][x][y] - (l > 0 ? cnt[l-1][x][y] : 0);
			int right = cnt[r][y][x] - (l > 0 ? cnt[l-1][y][x] : 0);
			int mn = min(left, right);		
			
			ans += mn*2;
			ans2 += left-mn + right-mn;
		}
	}
	
	return ans/2 + ans2 - ans2/3;
}

//int main(){
//	string a, b;
//	cin >> a >> b;
//	
//	init(a, b);
//	
//	int q;
//	cin >> q;
//	
//	while(q--){
//		int l, r;
//		cin >> l >> r;
//		
//		cout << get_distance(l, r) << "\n";
//	}
//	
//	return 0;
//}
