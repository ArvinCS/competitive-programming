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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, k;
	cin >> n >> k;
	
	if(k == 1){
		int a[10];
		fill(a, a+10, false);
		
		cout << "? 10" << endl;
		for(int sz=512;sz>=1;sz>>=1){
			cout << (n/sz)/2 * sz;
			for(int x=1;x<=n/sz;x++){
				if(x%2 == 0) continue;
				for(int y=(x-1)*sz+1;y<=x*sz;y++){
					cout << " " << y;
				}
			}
			cout << endl;
		}
		for(int i=0;i<10;i++){
			string res;
			cin >> res;
			
			a[i] = (res == "YA");
		}
		
		pair<int, int> ans = {1, n};
		for(int i=0;i<10;i++){
			if(a[i]){
				ans.second = (ans.first+ans.second) >> 1;
			} else {
				ans.first = (ans.first+ans.second) >> 1;
				ans.first++;
			}
		}
		
		cout << "! " << ans.first << endl;
	} else {
		bool a[10][2], b[10];
		fill(a[0], a[10], false);
		fill(b, b+10, false);
		
		cout << "? 10" << endl;
		
		// first case (512 -> 32)
		for(int sz=512;sz>32;sz>>=1){
			for(int i=0;i<2;i++){
				cout << sz;
				for(int x=1;x<=n/sz;x++){
					if(x%2 != i) continue;
					
					for(int y=(x-1)*sz+1;y<=x*sz;y++){
						cout << " " << y;
					}
				}
				cout << endl;
			}
		}
		
		for(int i=0;i<5;i++){
			for(int j=0;j<2;j++){
				string res;
				cin >> res;
				
				a[i][j] = (res == "YA");
			}
		}
		
		// second case (32 -> 1)
		for(int sz=32;sz>=1;sz>>=1){
			for(int i=0;i<2;i++){
				cout << sz;
				for(int x=1;x<=n/sz;x++){
					if(x%2 != i) continue;
					
					for(int y=(x-1)*sz+1;y<=x*sz;y++){
						cout << " " << y;
					}
				}
				cout << endl;
			}
		}
		
		for(int i=5;i<10;i++){
			for(int j=0;j<2;j++){
				string res;
				cin >> res;
				
				a[i][j] = (res == "YA");
			}
		}
		
		// find answer
		vector<int> ans;
		queue<pair<int, int>> q;
		
		while(!q.empty()){
			pair<int, int> p = q.front();
			q.pop();
			
			int left = p.first, right = p.second;
			int sz = right-left+1;
			int i = 9-log2(sz);
			if(sz == 1){
				ans.push_back(left);
				continue;
			}
			
			
		}
		
		cout << "!";
		for(auto e : ans){
			cout << " " << e;
		}
		cout << endl;
	}
    return 0;
}

