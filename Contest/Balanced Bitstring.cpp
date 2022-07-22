#include <iostream>
#include <vector>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

const short mxP = 19;
const int mxN = 524288;

ll tree[2*mxN];

void update(int size, int index, ll value){
	index += size;
	tree[index] = value;
	
	while(index > 1){
		index/=2;
		tree[index] = tree[2*index] + tree[2*index+1];
	}
}

int getResult(int size, ui left, ui right){
	left += size;
	right += size;
	
	ll ans = 0;
//	for(ui x=1;x<size;x++) cout << tree[x] << " ";
//	cout << "\n";
	while(left < right){
//		cout << "curr: " << left << " " << right;
		if(left % 2 == 1){
			ans += tree[left];
			left++;
		}
		if(right % 2 == 1){
			right--;
			ans += tree[right];
		}
//		cout << " -> " << ans << "\n";
		left /= 2;
		right /= 2;
	}
//	cout << "ans: " << ans << "\n";
	return ans;
}

bool brute(ui i, ui t, ui n, ui k, vector<int> marks){
	if(i >= marks.size()){
		for(ui x=0;x<=n-k;x++){
//			cout << x << "-" << x+k-1 << "\n";
			if(getResult(t, x, x+k) != 0) return false;
		}
		return true;
	}
	
	bool ans = brute(i+1, t, n, k, marks);
	if(!ans){
		us tmp = tree[t + marks[i]];
		update(t, marks[i], -1);
		ans = brute(i+1, t, n, k, marks);
		update(t, marks[i], tmp);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	us t;
	cin >> t;
	
	while(t--){
		ui n, k;
		cin >> n >> k;
		
		string bit;
		cin >> bit;
		
		int sizeTree = 2;
		while(sizeTree < n){
			sizeTree *= sizeTree;
		}
		
		vector<int> markIndex;
		for(int x=0;x<sizeTree;x++){
			short val = x >= n ? 0 : (bit[x] == '0' ? -1 : 1);
			if(x < n && bit[x] == '?') markIndex.push_back(x);
			tree[sizeTree+x] = val;
		}
		
//		for(ui x=0;x<n;x++) cout << tree[sizeTree+x] << " ";
//		cout << "\n";
		
		for(int x=sizeTree-1;x>0;x--){
			tree[x] = tree[2*x] + tree[2*x+1];
		}
		
//		for(ui x=1;x<sizeTree;x++) cout << tree[x] << " ";
//		cout << "\n";
		
//		cout << "marks: " << markIndex.size() << "\n";
		if(brute(0, sizeTree, n, k, markIndex)){
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	
    return 0;
}

