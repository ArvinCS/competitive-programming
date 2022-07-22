#include <bits/stdc++.h>
#define int long long
using pii=std::pair<int,int>;
using namespace std;

const int maxn = 1e5 + 5;

// answer is of the form (b|c)*(a|c)*(a|b)*, node stores min deletions for starting in part i and ending in part j
int n, q, x, st[4 * maxn][3][3];
char val;
string s;

void init(int v, char x)
{
    int curval = x - 'a';
    for(int l = 0; l < 3; l++)
        for(int r = l; r < 3; r++)
            st[v][l][r] = (l == r && curval == l);
}

void combine(int v)
{
    for(int l = 0; l < 3; l++)
        for(int r = l; r < 3; r++)
        {
            st[v][l][r] = 2e9;
            for(int split = l; split <= r; split++)
                st[v][l][r] = min(st[v][l][r], st[2 * v][l][split] + st[2 * v + 1][split][r]);
        }
}

// https://cp-algorithms.com/data_structures/segment_tree.html
void build(int v, int tl, int tr) {
    if (tl == tr) {
        init(v, s[tl]);
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        combine(v);
    }
}

void update(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        init(v, s[tl]);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos);
        else
            update(v*2+1, tm+1, tr, pos);
        combine(v);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q >> s;
    build(1, 0, n - 1);
    for(int i = 0; i < q; i++)
    {
        cin >> x >> val;
        x--;
        s[x] = val;
        update(1, 0, n - 1, x);
        cout << s << " " << st[1][0][2] << "\n";
    }
    return 0;
}
