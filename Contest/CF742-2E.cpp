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

const int maxN = 2e5 + 5;

int n, a[maxN];
ll tree[4*maxN][4];
int leftPart = 0;
// 0 subarray not in longest.
// 1 prefix 2 suffix
// 3 full or not

ll f(int x){
	return x*1ll*(x+1)/2;
}

void calc(int v, int left, int right){
	int mid = (left+right) >> 1;
	
	if(tree[v*2+1][3] && tree[v*2+2][3]){
		if(a[mid] <= a[mid+1]){
			tree[v][0] = 0;
			tree[v][1] = right-left+1;
			tree[v][2] = right-left+1;
			tree[v][3] = true;
		} else {
			tree[v][0] = 0;
			tree[v][1] = mid-left+1;
			tree[v][2] = right-mid;
			tree[v][3] = false;
		}
	} else if(tree[v*2+1][3]){
		if(a[mid] <= a[mid+1]){
			tree[v][0] = tree[v*2+2][0];
			tree[v][1] = tree[v*2+1][2]+tree[v*2+2][1];
			tree[v][2] = tree[v*2+2][2];
			tree[v][3] = false;
		} else {
			tree[v][0] = tree[v*2+1][0]+tree[v*2+2][0]+f(tree[v*2+2][1]);
			tree[v][1] = tree[v*2+1][1];
			tree[v][2] = tree[v*2+2][2];
			tree[v][3] = false;
		}
	} else if(tree[v*2+2][3]){
		if(a[mid] <= a[mid+1]){
			tree[v][0] = tree[v*2+1][0];
			tree[v][1] = tree[v*2+1][1];
			tree[v][2] = tree[v*2+1][2]+tree[v*2+2][1];
			tree[v][3] = false;
		} else {
			tree[v][0] = tree[v*2+1][0]+tree[v*2+2][0]+f(tree[v*2+1][2]);
			tree[v][1] = tree[v*2+1][1];
			tree[v][2] = tree[v*2+2][2];
			tree[v][3] = false;
		}
	} else {
		if(a[mid] <= a[mid+1]){
			tree[v][0] = tree[v*2+1][0]+tree[v*2+2][0]+f(tree[v*2+1][2]+tree[v*2+2][1]);
			tree[v][1] = tree[v*2+1][1];
			tree[v][2] = tree[v*2+2][2];
			tree[v][3] = false;
		} else {
			tree[v][0] = tree[v*2+1][0]+tree[v*2+2][0]+f(tree[v*2+1][2])+f(tree[v*2+2][1]);
			tree[v][1] = tree[v*2+1][1];
			tree[v][2] = tree[v*2+2][2];
			tree[v][3] = false;
		}
	}
}

ll query(int v, int left, int right, int queryLeft, int queryRight){
	if(left > queryRight || right < queryLeft) return 0;
	
	if(queryLeft <= left && right <= queryRight){
		ll ans = 0;
		if(tree[v][3]){
			if(left > 0 && a[left-1] <= a[left]){
				leftPart = leftPart+(right-left+1);
			} else {
				ans += f(leftPart);
				leftPart = right-left+1;
			}
		} else {
			if(left > 0 && a[left-1] <= a[left]){
				ans += tree[v][0]+f(leftPart+tree[v][1]);
				leftPart = tree[v][2];
			} else {
				ans += tree[v][0]+f(leftPart)+f(tree[v][1]);
				leftPart = tree[v][2];
			}
		}
		return ans;
	}
	
	int mid = (left+right) >> 1;
	return query(v*2+1, left, mid, queryLeft, queryRight) + query(v*2+2, mid+1, right, queryLeft, queryRight);
}

void update(int v, int left, int right, int pos, int val){
	if(left == right){
		a[pos] = val;
		return;
	}
	
	int mid = (left+right) >> 1;
	if(pos <= mid){
		update(v*2+1, left, mid, pos, val);
	} else {
		update(v*2+2, mid+1, right, pos, val);
	}
	calc(v, left, right);
}

void build(int v, int left, int right){
	if(left == right){
		cin >> a[left];
		tree[v][1] = tree[v][2] = 1;
		tree[v][3] = true;
		return;
	}
	
	int mid = (left+right) >> 1;
	build(v*2+1, left, mid);
	build(v*2+2, mid+1, right);
	calc(v, left, right);
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	fill(tree[0], tree[4*maxN], 0);
	
	int q;
	cin >> n >> q;
	
	build(0, 0, n-1);
	
	for(int i=1;i<=q;i++){
		int t;
		cin >> t;
		
		if(t == 1){
			int pos, val;
			cin >> pos >> val;
			pos--;
			
			update(0, 0, n-1, pos, val);
		} else {
			int left, right;
			cin >> left >> right;
			
 			leftPart = 0;
			left--; right--;
			cout << query(0, 0, n-1, left, right)+f(leftPart) << "\n";
		}
	}
    return 0;
}

