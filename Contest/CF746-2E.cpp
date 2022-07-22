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

const int maxN = 1e7 + 5;
const int logN = log2(maxN)+1;

int a[maxN], b[maxN];
int l[maxN][2];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	for(int x=0;x<n;x++){
		cin >> a[x];
		b[x] = a[x];
	}
	
	fill(l[0], l[maxN], 1e9);
	
	int bit = 0;
	int ans = 0;
	for(int i=0;i<21;i++){
		int val = (1 << i);
		bit |= val;
		
		for(int x=0;x<n;x++){
			b[x] |= bit;
			b[x] ^= bit;	
		}
		
		int leftBound = 0;
		int cur = 0;
		queue<int> q;
		for(int x=0;x<n;x++){
			if(l[cur][x%2] == 1e9){
				l[cur][x%2] = x;
				q.push(cur);
			}
			
			cur ^= b[x];
			if(!(a[x]&val)){
				leftBound = x+1;
				
				while(!q.empty()){
					l[q.front()][0] = l[q.front()][1] = 1e9;
					q.pop();
				}
				continue;
			}
			
			ans = max(ans, x-l[cur][(x+1)%2]+1);
		}
		
		while(!q.empty()){
			l[q.front()][0] = l[q.front()][1] = 1e9;
			q.pop();
		}
	}
	
	cout << ans << "\n";
    return 0;
}

