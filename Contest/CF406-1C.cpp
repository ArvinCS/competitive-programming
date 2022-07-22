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
const int maxB = 400;

int freq[maxB][maxN];
int comp[maxB], a[maxN], ans[maxN], color[maxN];
int l[maxB], r[maxB];

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
	}
	
	int sz = sqrt(n)+1;
	fill(comp, comp+maxB, 0);
	
	for(int i=1;i<=sz;i++){
		int cnt = 0;
		int comp = 0;
		
		fill(color, color+n+1, -1);
		for(int x=0;x<n;x++){
			if(color[a[x]] != comp){
				cnt++;
			}
			color[a[x]] = comp;
			
			if(cnt > i){
				comp++;
				cnt = 1;
				color[a[x]] = comp;
			}
		}
		if(cnt > 0){
			comp++;
		}
		
		ans[i] = comp;
	}
	
	fill(l, l+maxB, 0);
	fill(r, r+maxB, 0);
	fill(freq[0], freq[maxB], 0);
	
	for(int i=sz+1;i<=n;i++){
		for(int x=0;x<n;x++){
			if(x > 0){
				while(l[x] < r[x-1]){
					freq[x][a[l[x]]]--;
					
					if(freq[x][a[l[x]]] == 0){
						comp[x]--;
					}
					
					l[x]++;
				}
			}
			
			while(comp[x] <= i && r[x] < n){
				if(freq[x][a[r[x]]] == 0){
					if(comp[x] == i){
						break;
					}
					
					comp[x]++;
				}
				
				freq[x][a[r[x]]]++;
				r[x]++;	
			}
			
			ans[i] = x+1;
			if(r[x] >= n) break;
		}
	}
	
	for(int x=1;x<=n;x++){
		if(x > 1) cout << " ";
		cout << ans[x];
	}
	cout << "\n";

    return 0;
}

