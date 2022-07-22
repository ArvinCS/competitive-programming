#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	map<int, pair<int, int>> mp;
    int p[6] = {4, 8, 15, 16, 23, 42};
    for(int x=0;x<6;x++){
        for(int y=x+1;y<6;y++){
            assert(!mp.count(p[x]*p[y]));
            mp[p[x]*p[y]] = {p[x], p[y]};
        }
    }
	
    auto ask = [&](int i, int j) -> int {
        cout << "? " << i << " " << j << endl;

        int val;
        cin >> val;

        return val;
    };

    int a = ask(1, 2), b = ask(2, 3);

    int ans[6];
    if(mp[a].first == mp[b].first){
        ans[1] = mp[a].first;
    } else if(mp[a].second == mp[b].first){
        ans[1] = mp[a].second;
    } else if(mp[a].first == mp[b].second){
        ans[1] = mp[a].first;
    } else {
        ans[1] = mp[a].second;
    }

    ans[0] = a/ans[1];
    ans[2] = b/ans[1];
    for(int x=3;x<5;x++){
        int val = ask(x, x+1);
        ans[x] = val/ans[x-1];
    }

    for(int x=0;x<6;x++){
        bool ok = true;
        for(int y=0;y<5;y++){
            if(ans[y] == p[x]){
                ok = false;
                break;
            }
        }
        
        if(ok){
            ans[5] = p[x];
            break;
        }
    }

    cout << "!";
    for(int x=0;x<6;x++){
        cout << " " << ans[x];
    }
    cout << endl;
    return 0;
}

