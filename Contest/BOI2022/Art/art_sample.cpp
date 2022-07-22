#include "art.h"
#include <bits/stdc++.h>

using namespace std;

#define ll long long

//
// --- Sample implementation for the task art ---
//
// To compile this program with the sample grader, place:
//     art.h art_sample.cpp sample_grader.cpp
// in a single folder, then open the terminal in this directory (right-click onto an empty spot in the directory,
// left click on "Open in terminal") and enter e.g.:
//     g++ -std=c++17 art_sample.cpp sample_grader.cpp
// in this folder. This will create a file a.out in the current directory which you can execute from the terminal
// as ./a.out
// See task statement or sample_grader.cpp for the input specification
//

void solve(int n) {
	vector<int> ans(n, -1);
	
	int cnt[n+1];
	fill(cnt, cnt+n+1, -1);
	
	for(int x=1;x<=n;x++){
		vector<int> v;
		for(int y=0;y<n;y++){
			v.push_back((x+y-1) % n + 1);
		}
		
		cnt[(x+n-1)%n + 1] = publish(v);
	}
	
	for(int x=1;x<=n;x++){
		int r = (n-1-(cnt[x] - cnt[(x%n) + 1]))/2;
		ans[n-1-r] = x;
	}
	answer(ans);
}
