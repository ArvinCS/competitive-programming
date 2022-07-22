#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 1e5 + 5;

struct Fenwick {
	int tree[maxN];
	
	void reset(){
		fill(tree, tree+maxN, 0);
	}
	
	void update(int pos, int val){
		pos++;
		
		while(pos < maxN){
			tree[pos] += val;
			pos += pos&(-pos);
		}
	}
	
	int query(int pos){
		pos++;
		
		int ans = 0;
		while(pos > 0){
			ans += tree[pos];
			pos -= pos&(-pos);
		}
		return ans;
	}
} row, col;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	row.reset(); col.reset();
	
	int cntRow[n+1], cntCol[n+1];
	fill(cntRow, cntRow+n+1, 0);
	fill(cntCol, cntCol+n+1, 0);
	
	while(q--){
		int t;
		cin >> t;
		
		if(t == 1){
			int r, c;
			cin >> r >> c;
			
			if(cntRow[r] == 0) row.update(r, 1);
			if(cntCol[c] == 0) col.update(c, 1);
			
			cntRow[r]++; cntCol[c]++;
		} else if(t == 2){
			int r, c;
			cin >> r >> c;
			
			if(cntRow[r] == 1) row.update(r, -1);
			if(cntCol[c] == 1) col.update(c, -1);
			
			cntRow[r]--; cntCol[c]--;
		} else if(t == 3){
			int r1, c1, r2, c2;
			cin >> r1 >> c1 >> r2 >> c2;
			
			if(row.query(r2) - row.query(r1-1) == r2-r1+1){
				cout << "Yes\n";
				continue;
			}
			if(col.query(c2) - col.query(c1-1) == c2-c1+1){
				cout << "Yes\n";
				continue;
			}
			
			cout << "No\n";
		}
	}
	
    return 0;
}

