#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 3e3 + 5;
const int maxK = 3e5 + 5;

pair<int, int> p[maxK];
int d[maxK];
int cnt[maxN][maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	for(int x=0;x<k;x++){
		cin >> p[x].first >> p[x].second >> d[x];
		p[x].first--; p[x].second--;
	}
	
	fill(cnt[0], cnt[n], 0);
	
	for(int x=0;x<k;x++){
		for(int y=0;y<=min(d[x], m-1);y++){
			int rem = d[x]-y;
			
			if(p[x].second-y >= 0){
				cnt[max(0, p[x].first-rem)][p[x].second-y]++;
				if(p[x].first+rem+1 < n){
					cnt[p[x].first+rem+1][p[x].second-y]--;
				}
			}
			if(y > 0 && p[x].second+y < m){
				cnt[max(0, p[x].first-rem)][p[x].second+y]++;
				if(p[x].first+rem+1 < n){
					cnt[p[x].first+rem+1][p[x].second+y]--;
				}
			}
		}
	}
	
	for(int y=0;y<m;y++){
		int sum = 0;
		for(int x=0;x<n;x++){
			sum += cnt[x][y];
			cnt[x][y] = sum;
		}
	}
	
	int q;
	cin >> q;
	
	for(int x=0;x<q;x++){
		int a, b;
		cin >> a >> b;
		
		a--; b--;
		cout << cnt[a][b] << "\n";
	}
    return 0;
}

