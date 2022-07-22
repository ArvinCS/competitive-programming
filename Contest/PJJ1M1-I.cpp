#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxA = 1e6 + 5;
const int maxQ = 2e5 + 5;

int n, sz;
pair<int, int> p[maxQ];
int freq[maxA];

bool customSort(int a, int b){
	if(p[a].first/sz == p[b].first/sz){
		if(p[a].first/sz % 2 == 0) return p[a].second < p[b].second;
		else return p[a].second > p[b].second;
	}
	return p[a].first/sz < p[b].first/sz;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n;
	sz = sqrt(n)+1;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	
	int q;
	cin >> q;
	
	vector<int> v;
	for(int x=0;x<q;x++){
		cin >> p[x].first >> p[x].second;
		p[x].first--; p[x].second--;
		
		v.push_back(x);
	}
	
	sort(v.begin(), v.end(), customSort);
	fill(freq, freq+maxA, 0);
	
	int ans[q], cnt = 0;
	int curL = 0, curR = 0;
	for(int x=0;x<q;x++){ // [L, R)
		int idx = v[x];
		
		while(curL < p[idx].first){
			freq[a[curL]]--;
			if(freq[a[curL]] == 0){
				cnt--;
			}
			
			curL++;
		}
		while(curR > p[idx].second+1){
			curR--;
			freq[a[curR]]--;
			
			if(freq[a[curR]] == 0){
				cnt--;
			}
		}
		
		while(curL > p[idx].first){
			curL--;
			if(freq[a[curL]] == 0){
				cnt++;
			}
			
			freq[a[curL]]++;	
		}
		while(curR <= p[idx].second){
			if(freq[a[curR]] == 0){
				cnt++;
			}
			
			freq[a[curR]]++;
			curR++;
		}
		
		ans[idx] = cnt;
	}
	
	for(int x=0;x<q;x++){
		cout << ans[x] << "\n";
	}
    return 0;
}

