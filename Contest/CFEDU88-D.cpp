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

const int maxN = 1e5 + 5;
const int logN = log2(maxN);

int table[logN+1][maxN];
int prefix[logN+1][maxN], suffix[logN+1][maxN];
int sum[maxN];

int query(int left, int right){
	int lg = log2(right-left+1);
	int length = (1 << lg);
	
	return max(table[lg][left], table[lg][right-length+1]);
}

int queryPrefix(int left, int right){
	if(left > right) return 0;
	
	int lg = log2(right-left+1);
	int length = (1 << lg);
	
	return max(0, max(prefix[lg][left], sum[left+length-1] - (left-1 >= 0 ? sum[left-1] : 0) + queryPrefix(left+length, right)));
}

int querySuffix(int left, int right){
	if(left > right) return 0;
	
	int lg = log2(right-left+1);
	int length = (1 << lg);
	
	return max(0, max(suffix[lg][right], sum[right] - (right-length >= 0 ? sum[right-length] : 0) + querySuffix(left, right-length)));
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);

	int n;
	cin >> n;
	
	int a[n];
	for(int x=0;x<n;x++){
		cin >> a[x];
		suffix[0][x] = prefix[0][x] = table[0][x] = a[x];
	}
	
	// Observations:
	// The optimal strategy for Bob is remove biggest element in Alice's segment.
	// So, we loop each element in array that bob will remove if it's appear in Alice's segment.
	// To make bob remove this element, we must make sure to expand the segment from element position and make sure the biggest element still same.
	// (if biggest element become bigger than to-be-deleted element, it's not optimal).
	// We can use dp and binlift to expand it.
	// It's more complicated than intended solution, but it works for Ai <= 1e9 :) 
	// Time: O(NlogN)
	
	for(int x=0;x<n;x++){
		sum[x] = a[x] + (x-1 >= 0 ? sum[x-1] : 0);
	}
	
	for(int x=1;x<=logN;x++){
		int length = (1 << x);
		for(int y=0;y+length<=n;y++){
			table[x][y] = max(table[x-1][y], table[x-1][y+length/2]);
		}
	}
	
	for(int x=1;x<=logN;x++){
		int length = (1 << x);
		for(int y=0;y+length<=n;y++){
			prefix[x][y] = max(prefix[x-1][y], sum[y+length/2-1] - (y-1 >= 0 ? sum[y-1] : 0) + prefix[x-1][y+length/2]);
		}
	}
	
	for(int x=1;x<=logN;x++){
		int length = (1 << x);
		for(int y=n-1;y-length+1>=0;y--){
			suffix[x][y] = max(suffix[x-1][y], sum[y] - sum[y-length/2] + suffix[x-1][y-length/2]);
		}
	}
	
	int ans = -inf_int;
	for(int x=0;x<n;x++){
		int left = 0, right = x, boundLeft = x, boundRight = x;
		while(left <= right){
			int mid = (left+right) >> 1;
			
			if(query(mid, x) <= a[x]){
				boundLeft = min(boundLeft, mid);
				right = mid-1;
			} else {
				left = mid+1;
			}
		}
		
		left = x; right = n-1;
		while(left <= right){
			int mid = (left+right) >> 1;
			
			if(query(x, mid) <= a[x]){
				boundRight = max(boundRight, mid);
				left = mid+1;
			} else {
				right = mid-1;
			}
		}
						
		ans = max(ans, querySuffix(boundLeft, x-1)+queryPrefix(x+1, boundRight));
	}
	cout << ans << "\n";
    return 0;
}

