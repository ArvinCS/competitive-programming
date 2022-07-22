#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e6;

bool prime[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	
	fill(prime, prime+maxN, true);
	for(int x=2;x*x<maxN;x++){
		if(prime[x]){
			for(int y=2*x;y<maxN;y+=x){
				if(prime[y]) prime[y] = false;
			}
		}
	}
	
	string mode;
	int l;
	cin >> mode >> l;
	
	int t;
	cin >> t;
	while(t--){
		vector<int> v;
		for(int x=1e4;x<1e5;x++){
			if(prime[x]) v.push_back(x);
		}
		
		int placed[5];
		fill(placed, placed+5, -1);
		
		auto digit = [&](int val, int d) -> int {
			int cur = val;
			for(int x=0;x<d;x++){
				cur /= 10;
			}
			return cur%10;
		};
		
		pair<int, int> best[10];
		for(int x=0;x<10;x++) best[x] = {0, 0};
		for(auto val : v){
			int cnt[10];
			fill(cnt, cnt+10, 0);
			
			for(int y=0;y<5;y++){
				cnt[digit(val, 4-y)]++;
			}
			
			for(int y=0;y<10;y++){
				best[y] = max(best[y], {cnt[y], val});
			}
		}
		
		bool block[5][10];
		fill(block[0], block[5], false);
		
		int mn[10], mx[10], exact[10];
		fill(mn, mn+10, 0);
		fill(mx, mx+10, 6);
		fill(exact, exact+10, -1);
		
		bool found = false;
		int cur = l;
		set<int> st;
		
		while(cur > 0){
			set<int> exist;
			vector<int> w;
			for(int x=0;x<v.size();x++){
				bool ok = true;
				for(int y=0;y<5;y++){
					if(placed[y] != -1 && placed[y] != digit(v[x], 4-y)){
						ok = false;
						break;
					}
				}
				
				for(int y=0;y<5;y++){
					if(block[y][digit(v[x], 4-y)]){
						ok = false;
						break;
					}
				}
				
				int cnt[10];
				fill(cnt, cnt+10, 0);
				
				for(int y=0;y<5;y++){
					cnt[digit(v[x], 4-y)]++;
				}
				for(int y=0;y<10;y++){
					if(mx[y] < cnt[y] || mn[y] > cnt[y] || (exact[y] != -1 && exact[y] != cnt[y])){
						ok = false;
						break;
					}
				}
				
				if(ok){
					exist.insert(v[x]);
					w.push_back(v[x]);
				}
			}
			
			assert(!w.empty());
			
			shuffle(w.begin(), w.end(), rng);
			
			int idx = rng() % w.size();
			int val = w[idx];
			
			vector<int> z;
			for(int x=0;x<10;x++){
				if(exist.count(best[x].second) && !st.count(best[x].second)){
					z.push_back(best[x].second);
				}
			}
			
			if(cur >= l-2 && !z.empty()){
				idx = rng() % z.size();
				val = z[idx];
			} else {
				while(st.count(w[idx])){
					idx = rng() % w.size();
					val = w[idx];
				}
			}
			
			cout << val << endl;
			st.insert(val);
			cur--;
			
			string res;
			cin >> res;
			
			if(res == "+++++"){
				found = true;
				break;
			}
			if(res == "!!!!!"){
				break;
			}
			
			int cnt[10];
			fill(cnt, cnt+10, 0);
			for(int y=0;y<5;y++){
				if(res[y] == '+'){
					placed[y] = digit(val, 4-y);
					cnt[placed[y]]++;
				} else if(res[y] == '?'){
					cnt[digit(val, 4-y)]++;
					block[y][digit(val, 4-y)] |= true;
				}
			}
			
			int cnt2 = 0;
			for(int y=0;y<5;y++){
				if(res[y] == '-'){
					cnt2++;
					block[y][digit(val, 4-y)] |= true;
					
					exact[digit(val, 4-y)] = cnt[digit(val, 4-y)];
					mx[digit(val, 4-y)] = min(mx[digit(val, 4-y)], cnt[digit(val, 4-y)]);
				}
			}
			
			int cnt3 = 0;
			for(int y=0;y<10;y++){
				cnt3 += max(cnt[y], exact[y]);
			}
			
			for(int y=0;y<10;y++){
				mx[y] = min(mx[y], cnt[y]+min(cnt2, max(0, 5-cnt3)));
			}
			for(int y=0;y<10;y++){
				mn[y] = max(mn[y], cnt[y]);
			}
			
//			for(int y=0;y<10;y++){
//				cout << mn[y] << "," << mx[y] << "," << exact[y] << " ";
//			}cout << endl;
//			for(int y=0;y<5;y++){
//				cout << placed[y] << " ";
//			}cout << endl;
//			for(int y=0;y<5;y++){
//				for(int z=0;z<10;z++){
//					if(block[y][z]) cout << "1";
//					else cout << "0";
//				}
//				cout << " ";
//			}
//			cout << endl;
//			for(auto val : w){
//				cout << "== " << val << endl;
//			}
			v = w;
			w.clear();
		}
		assert(found);
//		assert(found && cur >= 0);
	}
    return 0;
}

