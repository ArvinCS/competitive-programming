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

int tree[maxN];

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

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n, q;
	cin >> n >> q;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		a[x] = (x+1) - a[x];
	}
	
	int leftBound[q];
	vector<int> v[n+1];
	for(int i=0;i<q;i++){
		int left, right;
		cin >> left >> right;
		
		left++;
		right = n-right;
		
		leftBound[i] = left;
		v[right].push_back(i);
	}
	
	fill(tree, tree+maxN, 0);
	
	int ans[q], sum = 0, lg = log2(n)+1;
	
	for(int right=1;right<=n;right++){
		if(a[right-1] >= 0){
			int left = 0, r = right;
			
			while(left <= r){
				ll mid = (left+r) >> 1;
				
				if(sum-query(mid) >= a[right-1]){
					left = mid+1;
				} else {
					r = mid-1;
				}
			}
			
			sum++;
			update(left, 1);
		}
		
		for(auto idx : v[right]){
			ans[idx] = sum - query(leftBound[idx]);
		}
	}
	
	for(int x=0;x<q;x++){
		cout << ans[x] << "\n";
	}
    return 0;
}

