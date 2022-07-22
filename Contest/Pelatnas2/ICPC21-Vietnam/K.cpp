#include <bits/stdc++.h>
#include <chrono>
#include <random>

using namespace std;

#define ll long long

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct Node {
	int prior, size;
	ll pos;
	
	Node *l, *r;
	Node() : pos(0), size(1), val(1), l(NULL), r(NULL){
		prior = chrono::steady_clock::now().time_since_epoch().count();
	}
};

void split(Node t, Node &l, Node &r, int x, ll add = 0){
		
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	
	
	return 0;
}
