#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	cin >> n;
	
	int p[n], q[n];
	for(int x=0;x<n;x++){
		cin >> p[x];
		p[x]--;
	}
	for(int x=0;x<n;x++){
		cin >> q[x];
		q[x]--;
	}
	
	int l[n], r[n];
	for(int x=0;x<n;x++){
		l[x] = r[x] = -1;
	}
	
	int pos[n];
	for(int x=0;x<n;x++){
		pos[q[x]] = x;
	}
	
	auto solve = [&l, &r, &pos, &p, &n](auto self, int idx, int left, int right) -> int {
		int cnt = 0;
		int m = pos[p[idx]];
		
		if(idx+1 < n && pos[p[idx+1]] >= left && pos[p[idx+1]] < m){
			l[p[idx]] = p[idx+1];
			cnt += self(self, idx+1, left, m-1);
		}
		
		if(idx+cnt+1 < n && pos[p[idx+cnt+1]] > m && pos[p[idx+cnt+1]] <= right){
			r[p[idx]] = p[idx+cnt+1];
			cnt += self(self, idx+cnt+1, m+1, right);
		}
		return cnt+1;
	};
	
	if(p[0] != 0){
		cout << "-1\n";
		return 0;
	}
	
	solve(solve, 0, 0, n-1);
	
	vector<int> pre, in;
	auto check = [&l, &r, &pre, &in](auto self, int curNode) -> void {
		pre.push_back(curNode);
		if(l[curNode] != -1){
			self(self, l[curNode]);
		}
		in.push_back(curNode);
		if(r[curNode] != -1){
			self(self, r[curNode]);
		}
	};
	
	check(check, 0);
	
	bool ok = true;
	for(int x=0;x<n;x++){
		if((pre.size() <= x || pre[x] != p[x]) || (in.size() <= x || in[x] != q[x])){
			ok = false;
			break;
		}
	}
	
	if(!ok){
		cout << "-1\n";
		return 0;
	}
	
	for(int x=0;x<n;x++){
		cout << l[x]+1 << " " << r[x]+1 << "\n";
	}
    return 0;
}

