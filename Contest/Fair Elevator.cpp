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

const int emp = -1;
int c[505];

short n;

bool valid(short left, short right, short val){
	if(left >= right || left < 1 || left > 2*n || right < 1 || right > 2*n) return false;
	
	for(short x=left;x<=right;x++){
		if(c[x] != emp && c[x] != val) return false;
	}	
	return true;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n;
	
	fill(c, c+505, emp);
	
	vector<pair<short, short>> segs;
	for(short x=0;x<n;x++){
		int a, b;
		cin >> a >> b;
		if(a != -1 && b != -1){
			if(a >= b || a > 2*n || a < 1 || b > 2*n || b < 1){
				cout << "No\n";
				return 0;
			}
			int valC = b-a-1;
			for(short y=a;y<=b;y++){
				if(c[y] != emp && c[y] != valC){
					cout << "No\n";
					return 0;
				}
				c[y] = valC;
			}
		} else {
			segs.push_back({a,b});
		}
	}
	
	short size = segs.size();
	if(size == n){
		cout << "Yes\n";
		return 0;
	}
	
	for(short x=0;x<size;x++){
		int left = segs[x].first, right = segs[x].second;
		if(left == -1 && right == -1) continue;
		// only one of them -1
		if(left != -1){ // left
			if(c[left] != emp){
				if(c[left] < 0){
					cout << "No\n";
					return 0;
				}
				if(valid(left, c[left]+left+1, c[left])){
					for(int x=left+1;x<=c[left]+left+1;x++){
						c[x] = c[left];
					}
				} else {
					cout << "No\n";
					return 0;
				}
			} else {
//				bool goLeft = left > 1 && (c[left-1] == emp || valid(left, c[left-1]+left+1, c[left-1]));
				bool goRight = left < 2*n && (c[left+1] == emp || valid(left, c[left+1]+left+1, c[left+1]));
				
				if(goRight){
					if(c[left+1] == emp){
						c[left] = c[left+1] = 0;
					} else {
						for(int x=left;x<=c[left+1]+left+1;x++){
							c[x] = c[left+1];
						}
					}
				} else {
					cout << "No\n";
					return 0;
				}
			}
		} else { // right
			if(c[right] != emp){
				if(c[right] >= right){
					cout << "No\n";
					return 0;
				}
				if(valid(right-c[right]-1, right, c[right])){
					for(int x=right-c[right]-1;x<right;x++){
						c[x] = c[right];
					}
				} else {
					cout << "No\n";
					return 0;
				}
			} else {
				bool goLeft = right > 1 && (c[right-1] == emp || valid(right-c[right-1]-1, right, c[right-1]));
//				bool goRight = right < 2*n && (c[right+1] == emp || valid(right-c[right+1]-1, right, c[right+1]));
				
				if(goLeft){
					if(c[right-1] == emp){
						c[right] = c[right-1] = 0;
					} else {
						for(int x=right-c[right-1]-1;x<=right;x++){
							c[x] = c[right-1];
						}
					}
				} else {
					cout << "No\n";
					return 0;
				}
			}
		}
	}
	
	cout << "Yes\n";
    return 0;
}

