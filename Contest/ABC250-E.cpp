#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int a[n], b[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
	}
	for(int x=0;x<n;x++){
		cin >> b[x];
	}
	
	vector<int> v;
	for(int x=0;x<n;x++){
		v.push_back(a[x]);
		v.push_back(b[x]);
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	for(int x=0;x<n;x++){
		a[x] = lower_bound(v.begin(), v.end(), a[x]) - v.begin();
		b[x] = lower_bound(v.begin(), v.end(), b[x]) - v.begin();
	}
	
	int q;
	cin >> q;
	
	array<int, 3> p[q];
	for(int x=0;x<q;x++){
		cin >> p[x][0] >> p[x][1];
		p[x][0]--; p[x][1]--; p[x][2] = x;
	}
	
	int sz = sqrt(n)+1;
	
	sort(p, p+q, [&](array<int, 3> a, array<int, 3> b) {
		if(a[0]/sz == b[0]/sz){
			if((a[0]/sz)&1) return a[1] > b[1];
			return a[1] < b[1];
		}	
		return a[0] < b[0];
	});
	
	int cnt[v.size()][2];
	fill(cnt[0], cnt[v.size()], 0);
	
	int eq = v.size();
	
	auto add = [&](int val, int idx) -> void {
		if(cnt[val][idx] > 0 && cnt[val][idx^1] > 0){
			eq--;
		}
		if(cnt[val][idx] == 0 && cnt[val][idx^1] == 0){
			eq--;
		}	
		cnt[val][idx]++;
		if(cnt[val][idx] > 0 && cnt[val][idx^1] > 0){
			eq++;
		}
		if(cnt[val][idx] == 0 && cnt[val][idx^1] == 0){
			eq++;
		}
	};
	
	auto remove = [&](int val, int idx) -> void {
		if(cnt[val][idx] > 0 && cnt[val][idx^1] > 0){
			eq--;
		}
		if(cnt[val][idx] == 0 && cnt[val][idx^1] == 0){
			eq--;
		}
		cnt[val][idx]--;
		if(cnt[val][idx] > 0 && cnt[val][idx^1] > 0){
			eq++;
		}
		if(cnt[val][idx] == 0 && cnt[val][idx^1] == 0){
			eq++;
		}
	};
	
	bool ans[q];
	
	int curL = 0, curR = 0;
	for(int i=0;i<q;i++){ // [L, R)
		int l = p[i][0], r = p[i][1];
		
		while(curL > l){
			curL--;
			add(a[curL], 0);
			add(b[curL], 1);
		}
		while(curR <= r){
			add(a[curR], 0);
			add(b[curR], 1);
			curR++;
		}
		
		while(curL < l){
			remove(a[curL], 0);
			remove(b[curL], 1);
			curL++;
		}
		while(curR > r+1){
			curR--;
			remove(a[curR], 0);
			remove(b[curR], 1);
		}
		
		if(eq == v.size()) ans[p[i][2]] = true;
		else ans[p[i][2]] = false;
		
		cout << p[i][2] << ":\n";
		cout << p[i][0] << " " << p[i][1] << "\n";
		for(int x=0;x<v.size();x++){
			cout << v[x] << " -> " << cnt[x][0] << " " << cnt[x][1] << "\n";
		}
	}
	
	for(int x=0;x<q;x++){
		cout << (ans[x] ? "Yes" : "No") << "\n";	
	}
    return 0;
}

