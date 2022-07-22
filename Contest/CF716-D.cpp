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

const int maxN = 3e5 + 5;
const int maxL = log2(maxN);

int block;
int data[maxN], freq[maxN], cnt[maxN];
map<pair<int, int>, int> ans;

bool customSort(pair<int, int> a, pair<int, int> b){
	if((a.first/block) != (b.first/block)){
		return (a.first/block) < (b.first/block);
	}
	return a.second < b.second;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
	
	int n, q;
	cin >> n >> q;
	
	for(int x=0;x<n;x++){
		cin >> data[x];
	}
	
	pair<int, int> w[q];
	vector<pair<int, int>> v;
	for(int x=0;x<q;x++){
		cin >> w[x].first >> w[x].second;
		
		w[x].first--; w[x].second--;
		v.push_back({w[x].first, w[x].second});
	}
	
	block = sqrt(n);
	sort(v.begin(), v.end(), customSort);
	
	int curL = 0, curR = 0;
	fill(freq, freq+n+1, 0);
	fill(cnt, cnt+n+1, 0);
	
	cnt[0] = n;
	int curMX = 0;
	for(int x=0;x<q;x++){ // [curL, curR)
		int l = v[x].first, r = v[x].second;
		int length = r-l+1;
		
		while(curL > l){
			cnt[freq[data[curL-1]]]--;
			freq[data[curL-1]]++;
			cnt[freq[data[curL-1]]]++;
			
			curMX = max(curMX, freq[data[curL-1]]);
			curL--;
		}
		
		while(curR <= r){
			cnt[freq[data[curR]]]--;
			freq[data[curR]]++;
			cnt[freq[data[curR]]]++;
			
			curMX = max(curMX, freq[data[curR]]);
			curR++;
		}
		
		while(curL < l){
			cnt[freq[data[curL]]]--;
			freq[data[curL]]--;
			cnt[freq[data[curL]]]++;
			curL++;
			
			if(cnt[curMX] == 0) curMX--;
		}
		
		while(curR > r+1){
			cnt[freq[data[curR-1]]]--;
			freq[data[curR-1]]--;
			cnt[freq[data[curR-1]]]++;
			curR--;
			
			if(cnt[curMX] == 0) curMX--;
		}
		
		if(curMX <= (length+1)/2) ans[{l, r}] = 1;
		else ans[{l, r}] = 2*curMX - length;
	}
	
	for(int x=0;x<q;x++){
		cout << ans[w[x]] << "\n";
	}
    return 0;
}

// Santai
// Pikirin dengan benar-benar

