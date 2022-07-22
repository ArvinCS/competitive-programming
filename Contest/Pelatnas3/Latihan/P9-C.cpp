#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ordered_set tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>

const int maxN = 1e5 + 5;

vector<int> adj[maxN];

struct Segmentsum {
    ll tree[4*maxN], lazy[4*maxN];

    void reset(){
        fill(tree, tree+4*maxN, 0);
        fill(lazy, lazy+4*maxN, 0);
    }

    void push(int v, int l, int r){
        tree[2*v+1] += l*lazy[v];
        lazy[2*v+1] += lazy[v];

        tree[2*v+2] += r*lazy[v];
        lazy[2*v+2] += lazy[v];

        lazy[v] = 0;
    }

    void update(int v, int curL, int curR, int l, int r, ll val){
        if(curL > curR || l > r) return;
        if(curL == l && curR == r){
            tree[v] += (curR-curL+1)*val;
            lazy[v] += val;
            return;
        }

        int curM = (curL+curR) >> 1;

        push(v, curM-curL+1, curR-curM);

        update(2*v+1, curL, curM, l, min(curM, r), val);
        update(2*v+2, curM+1, curR, max(l, curM+1), r, val);

        tree[v] = tree[2*v+1] + tree[2*v+2];
    }

    ll query(int v, int curL, int curR, int l, int r){
        if(curL > curR || l > r) return 0;
        if(curL == l && curR == r){
            return tree[v];
        }

        int curM = (curL+curR) >> 1;

        push(v, curM-curL+1, curR-curM);

        return query(2*v+1, curL, curM, l, min(curM, r)) + query(2*v+2, curM+1, curR, max(l, curM+1), r);
    }
} sum;

int inTime[maxN], outTime[maxN], t = 0;
set<pair<int, int>> st[maxN];
ordered_set s[maxN], e[maxN];

void dfs(int curNode, int prvNode){
    inTime[curNode] = t++;
    for(auto nxt : adj[curNode]){
        if(nxt != prvNode){
            dfs(nxt, curNode);
        }
    }
    outTime[curNode] = t-1;
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	// N update + N delete
    // Delete cost O(logN) for using set

    // update:
    // check children which have color C
    // delete use set and segment sum [intime, outttime] -1
    // update segment sum [intime, outtime] +1
    // query, segment sum q(intime, outtime)

    int n, q;
    cin >> n >> q;

    sum.reset();
    for(int x=0;x<n-1;x++){
        int a, b;
        cin >> a >> b;

        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0, 0);

    while(q--){
        int type;
        cin >> type;

        if(type == 1){ // update node
            int pos, c;
            cin >> pos >> c;

            pos--;
            
            auto it = st[c].lower_bound({inTime[pos], -1});

            vector<pair<int, int>> pending;
            while(it != st[c].end()){
                if((*it).first <= outTime[pos]){
                    pending.push_back(*it);
                    it++;
                } else {
                    break;
                }
            }

            for(auto p : pending){
                // cout << "Erased " << p.second << "\n";
                sum.update(0, 0, n-1, inTime[p.second], outTime[p.second], -1);
                st[c].erase(p);
                e[c].erase(e[c].find({outTime[p.second], p.second}));
                s[c].erase(s[c].find({inTime[p.second], p.second}));
            }

            
            int sz = s[c].size();
            int cnt = s[c].order_of_key({outTime[pos], n+1}) - e[c].order_of_key({outTime[pos]-1, n+1});

//            cout << pos << " " << c << " -> " << cnt << " " << sz << "\n";
            if(cnt != 0){
                continue;
            }

            // cout << "Added " << pos << "\n";
            sum.update(0, 0, n-1, inTime[pos], outTime[pos], 1);
            st[c].insert({inTime[pos], pos});
            s[c].insert({inTime[pos], pos});
            e[c].insert({outTime[pos], pos});
        } else if(type == 2){
            int pos;
            cin >> pos;

            pos--;
            cout << sum.query(0, 0, n-1, inTime[pos], outTime[pos]) << "\n";
        } else {
            assert(false);
        }
    }
	
    return 0;
}

