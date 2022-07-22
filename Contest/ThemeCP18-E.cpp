#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
    int n, k;
    cin >> n >> k;

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int pos = -1, val;
    while(true){
        int cur = rng()%n + 1;
        cout << "? " << cur << endl;
        
        cin >> val;

        if(val < k){
            while(val < k){
                cur++;
                if(cur > n) cur -= n;

                cout << "? " << cur << endl;
                
                cin >> val;
            }

            cout << "! " << cur << endl;
            return 0;
        }
    }
    return 0;
}