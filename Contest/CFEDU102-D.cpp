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

struct SegTree {
	vector<vector<int>> tree; // mn mx sum
	
	int n;
	void resize(int m){
		n = m;
		tree = vector<vector<int>>(2*n+5, vector<int>(3, 0));
	}
	
	void build(string s){
		int n = s.length();
		for(int x=0;x<s.length();x++){
			int val = (s[x] == '+' ? 1 : -1);
			
			tree[n+x][0] = min(0, val);
			tree[n+x][1] = max(0, val);
			tree[n+x][2] = val;
		}
		
		for(int x=n-1;x>0;x--){
			tree[x][0] = min(tree[x<<1][0], tree[x<<1][2]+tree[x<<1|1][0]);
			tree[x][1] = max(tree[x<<1][1], tree[x<<1][2]+tree[x<<1|1][1]);
			tree[x][2] = tree[x<<1][2]+tree[x<<1|1][2];
		}
	}
	
	vector<int> query(int left, int right){
		int leftSeg[3], rightSeg[3];
		for(int x=0;x<3;x++) leftSeg[x] = rightSeg[x] = 0;
		for(left += n, right += n; left < right; left >>= 1, right >>= 1){
			if(left&1){
				leftSeg[0] = min(leftSeg[0], leftSeg[2]+tree[left][0]);
				leftSeg[1] = max(leftSeg[1], leftSeg[2]+tree[left][1]);
				leftSeg[2] = leftSeg[2]+tree[left][2];
				left++;
			}
			if(right&1){
				right--;
				rightSeg[0] = min(tree[right][0], tree[right][2]+rightSeg[0]);
				rightSeg[1] = max(tree[right][1], tree[right][2]+rightSeg[1]);
				rightSeg[2] = tree[right][2]+rightSeg[2];
			}
		}
		
		leftSeg[0] = min(leftSeg[0], leftSeg[2]+rightSeg[0]);
		leftSeg[1] = max(leftSeg[1], leftSeg[2]+rightSeg[1]);
		leftSeg[2] = leftSeg[2]+rightSeg[2];
		
		return {leftSeg[0], leftSeg[1], leftSeg[2]};
	}
};

SegTree seg;

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int t;
	cin >> t;
	
	while(t--){
		int n, m;
		cin >> n >> m;
		
		string s;
		cin >> s;
		
		seg.resize(n);
		seg.build(s);
		
		for(int x=0;x<m;x++){
			int left, right;
			cin >> left >> right;
			
			left--; right--;
			
			vector<int> l = seg.query(0, left);
			vector<int> r = seg.query(right+1, n);
			
			l[0] = min(l[0], l[2]+r[0]);
			l[1] = max(l[1], l[2]+r[1]);
			l[2] = l[2]+r[2];
			
			cout << l[1]-l[0]+1 << "\n";
		}
	}

    return 0;
}

