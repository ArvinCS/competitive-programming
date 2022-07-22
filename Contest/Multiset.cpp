#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

ui n;
vector<int> tree(1000005, 0);

int query(int index){
	int ans = 0;
	while(index > 0){
		ans += tree[index];
		index -= index & (-index);
	}
	return ans;
}

void update(int index, int val){
	while(index <= n){
		tree[index] += val;
		index += index & (-index);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	ui q;
	cin >> n >> q;
	
//	fill(tree, tree+n+1, 0);
	
	int tmp, element = n;
	for(ui x=0;x<n;x++){
		cin >> tmp;
		update(tmp, 1);
	}
	
//	for(ui x=1;x<=n;x++){
//		cout << tree[x] << " ";
//	}
//	cout << "\n";
	
	int l, r;
	for(ui x=0;x<q;x++){
		cin >> tmp;
		if(tmp < 0){
			l = 1, r = n;
			tmp *= -1;
			while(l < r){
				int mid = l + (r-l)/2;
				if(query(mid) >= tmp){
					r = mid;
				} else {
					l = mid + 1;
				}
			}
			update(l, -1);
			element--;
		} else {
			update(tmp, 1);
			element++;
		}
	}
	
	if(element > 0){
		for(int x=1;x<=n;x++){
			if(query(x) > 0){
				cout << x << "\n";
				break;
			}
		}
	} else {
		cout << "0\n";
	}
    return 0;
}

