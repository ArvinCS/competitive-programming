#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int maxN = 5e6 + 5;

int lst[maxN];

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n;
	scanf("%d", &n);
	
	int a[n];
	for(int x=0;x<n;x++){
		scanf("%d", &a[x]);
	}
	
	fill(lst, lst+maxN, -1);
	
	int nxt[n];
	fill(nxt, nxt+n, 1e9);
	
	for(int x=0;x<n;x++){
		if(lst[a[x]] != -1){
			nxt[lst[a[x]]] = x;
		}
		lst[a[x]] = x;
	}
	for(int x=n-2;x>=0;x--){
		nxt[x] = min(nxt[x+1], nxt[x]);
	}
	
	int q;
	scanf("%d", &q);
	
	while(q--){
		int l, r;
		scanf("%d %d", &l, &r);
		
		l--; r--;
		cout << (nxt[l] <= r ? "Yes\n" : "No\n");
	}
    return 0;
}

