#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m;
    cin >> n >> m;
	
    int a[n], s[n], p[n];
    for(int x=0;x<n;x++){
        cin >> a[x] >> s[x] >> p[x];
    }

    int b[m], t[m], q[m];
    for(int x=0;x<m;x++){
        cin >> b[x] >> t[x] >> q[x];
    }

    ll prefixA[n+1], prefixB[m+1];
    prefixA[0] = 0; prefixB[0] = 0;

    for(int x=0;x<n;x++){
        prefixA[x+1] = prefixA[x];
        prefixA[x+1] += a[x];
    }
    for(int x=0;x<m;x++){
        prefixB[x+1] = prefixB[x];
        prefixB[x+1] += b[x];
    }

    int ans = 0;
    int l = 0, r = 0;
    while(l < n && r < m){
        ll sum = prefixA[l] + prefixB[r];
        if(sum+a[l])
    }

    cout << ans << "\n";
    return 0;
}

