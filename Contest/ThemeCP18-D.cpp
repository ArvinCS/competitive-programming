#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int t;
    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;

        bool subset[k][n];
        fill(subset[0], subset[k], false);

        for(int x=0;x<k;x++){
            int c;
            cin >> c;

            for(int y=0;y<c;y++){
                int val;
                cin >> val;

                val--;
                subset[x][val] = true;
            }
        }

        int mx = 0;
        {
            cout << "? " << n;
            for(int x=0;x<n;x++){
                cout << " " << x+1;
            }
            cout << endl;

            cin >> mx;
        }

        int pos = k-1;
        int left = 0, right = k-1;
        while(left <= right){
            int mid = (left+right) >> 1;

            vector<int> v;
            for(int x=left;x<=mid;x++){
                for(int y=0;y<n;y++){
                    if(subset[x][y]){
                        v.push_back(y);
                    }
                }
            }

            cout << "? " << v.size();
            for(int x=0;x<v.size();x++){
                cout << " " << v[x]+1;
            }
            cout << endl;

            int res;
            cin >> res;

            if(res == mx){
                pos = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }

        int mx2 = -1;

        {
            vector<int> v;
            for(int y=0;y<n;y++){
                if(!subset[pos][y]){
                    v.push_back(y);
                }
            }

            cout << "? " << v.size();
            for(int x=0;x<v.size();x++){
                cout << " " << v[x]+1;
            }
            cout << endl;

            cin >> mx2;
        }

        cout << "!";
        for(int x=0;x<k;x++){
            if(x == pos){
                cout << " " << mx2;
            } else {
                cout << " " << mx;
            }
        }
        cout << endl;

        string res;
        cin >> res;

        assert(res == "Correct");
    }
	
    return 0;
}

