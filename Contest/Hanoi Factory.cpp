#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define ui unsigned int
#define us unsigned short
#define inf_int 1e9
#define inf_ll 1e18

const int mxTree = 200005;
ui n;
vector<ll> tree(mxTree, 0);

struct Ring {
	ui inner, outer;
	ll height;	
};

bool customSort(Ring a, Ring b){
	if(a.outer == b.outer) return a.inner > b.inner;
	return a.outer > b.outer;
}

ll query(int index){
	ll ans = 0;
	while(index > 0){
		ans = max(ans, tree[index]);
		index -= index & (-index);
	}
	return ans;
}

void update(int index, ll val){
	while(index <= mxTree){
		tree[index] = max(tree[index], val);
		index += index & (-index);
	}	
}

int main(){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	cin >> n;
	
	set<ui> s;
	Ring data[n];
	for(ui x=0;x<n;x++){
		cin >> data[x].inner >> data[x].outer >> data[x].height;
		s.insert(data[x].inner);
		s.insert(data[x].outer);
	}
	
	ui index = 1;
	unordered_map<ui, ui> mp;
	set<ui>::iterator it;
	for(it = s.begin();it != s.end();it++){
		mp[*it] = index++; 
	}
	
	for(ui x=0;x<n;x++){
		data[x].inner = mp[data[x].inner];
		data[x].outer = mp[data[x].outer];
	}
	
	sort(data, data+n, customSort);
	
	ll ans = 0, table[n+1];
	table[0] = 0;
	for(ui x=0;x<n;x++){
		ll currentHeight = query(data[x].outer-1);
//		cout << "current height: " << currentHeight << "\n";
		table[x+1] = currentHeight + data[x].height;
		ans = max(ans, table[x+1]);
		update(data[x].inner, table[x+1]);
	}
	
	// kita sorting dari outer radius terbesar
	// setiap iterasi kita simpan max height ke tree dengan index inner radius
	// kenapa kita lakukan itu, soalnya di iterasi selanjutnya akan dianggap bisa dilanjutkan dengan ring saat itu karena inner radiusnya
	// yang lebih kecil dari outer radius ring saat itu
	// sehingga bisa kita dapatkan height maksimal
	
//	for(ui x=1;x<=n;x++){
//		cout << table[x] << " ";
//	}
//	cout << "\n";
	cout << ans << "\n";
	
    return 0;
}

