#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e5 + 5;

struct SegTree {
	int tree[2*maxN][3][3];
	int n;
	
	void reset(int n){
		this->n = n;
		fill(*tree[0], *tree[2*maxN], 0);	
	}	
	
	void merge(int (&v)[3][3], int (&l)[3][3], int (&r)[3][3]){
		for(int x=0;x<3;x++){
			for(int y=x;y<3;y++){
				v[x][y] = 1e9;
				for(int z=x;z<=y;z++){
					v[x][y] = min(v[x][y], l[x][z] + r[z][y]);
				}
			}
		}
	}
	
	void build(string s){
		for(int x=0;x<n;x++){
			for(int l=0;l<3;l++){
				for(int r=l;r<3;r++){
					tree[n+x][l][r] = (l == r && (s[x] - 'a') == l);
				}
			}
		}
		
		for(int x=n-1;x>0;x--){
			merge(tree[x], tree[x<<1], tree[x<<1|1]);
		}
	}
	
	void update(int pos, int c){
		pos += n;
		
		for(int l=0;l<3;l++){
			for(int r=l;r<3;r++){
				tree[pos][l][r] = (l == r && c == l);
			}
		}
		
		for(int x=pos;x>1;x>>=1){
			merge(tree[x>>1], tree[x&(~1)], tree[x|1]);
		}
	}
	
	int query(int left, int right){
		int leftAns[3][3], rightAns[3][3];
		fill(leftAns[0], leftAns[3], 0);
		fill(rightAns[0], rightAns[3], 0);
		
		for(left += n, right += n; left < right; left >>= 1, right >>= 1){
			if(left&1){
				int new_leftAns[3][3];
				fill(new_leftAns[0], new_leftAns[3], 0);
				
				merge(new_leftAns, leftAns, tree[left]);
				swap(new_leftAns, leftAns);
				left++;
			}
			if(right&1){
				right--;
				
				int new_rightAns[3][3];
				fill(new_rightAns[0], new_rightAns[3], 0);
				
				merge(new_rightAns, tree[right], rightAns);
				swap(new_rightAns, rightAns);
			}
		}
		
		int ans[3][3];
		fill(ans[0], ans[3], 0);
		
		merge(ans, leftAns, rightAns);
		return ans[0][2];
	}
};

SegTree tree;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, q;
	cin >> n >> q;
	
	string s;
	cin >> s;
	
	tree.reset(n);
	tree.build(s);
	
	while(q--){
		int pos;
		char ch;
		cin >> pos >> ch;
		
		pos--;
		s[pos] = ch;
		tree.update(pos, (ch - 'a'));
		cout << tree.query(0, n) << "\n";
	}
    return 0;
}

