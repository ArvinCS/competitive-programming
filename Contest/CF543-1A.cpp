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

const int maxN = 5e5 + 5;

int cnt[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int m, k, n, s;
	cin >> m >> k >> n >> s;
	
	int data[m];
	for(int x=0;x<m;x++){
		cin >> data[x];
	}
	
	int b[s];
	for(int x=0;x<s;x++){
		cin >> b[x];
	}
	
	fill(cnt, cnt+maxN, 0);
	
	for(int x=0;x<s;x++){
		cnt[b[x]]++;
	}
	
	vector<int> ans;
	for(int left=0;left<m;left++){
		int right = m - (n-1-(left/k)*k);
		int space = right-left+1-s;
		
		if(space < 0){
			continue;
		}
		
		cout << left << " " << right << "\n";
	}
	
	
	cout << ans.size() << "\n";
	for(int x=0;x<ans.size();x++){
		if(x > 0) cout << " ";
		cout << ans[x];
	}
	cout << "\n";
    return 0;
}

// Santai
// Pikirin dengan benar-benar

