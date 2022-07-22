#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int m, n;
    cin >> m >> n;

    auto ask = [&](int val) -> int{
        cout << val << endl;

        int res;
        cin >> res;

        return res;
    };

    int p[n];
    for(int x=0;x<n;x++){
        int res = ask(m);

        if(res == 0){
            return 0;
        }
        
        p[x] = (res <= 0);
    }

    int idx = 0;
    int left = 1, right = m-1;
    while(left <= right){
        int mid = (left+right) >> 1;

        int res = ask(mid) * (p[idx] ? 1 : -1);
        idx++;
        idx %= n;

        if(res == 0){
            return 0;
        }
        if(res == -1){
            right = mid-1;
        } else {
            left = mid+1;
        }
    }
    return 0;
}

