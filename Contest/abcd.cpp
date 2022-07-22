    #include <bits/stdc++.h>
    #define LOG2(n) (31 - __builtin_clz(n))
    #define pii pair<int, int>
    using namespace std;
     
    long long N, S;
    int A[25], sum;
    int byk;
     
    long long sumdig(long long now) {
      long long res = 0;
      while(now > 0) {
        res += now % 10;
        now /= 10;
      }
      return res;
    }
     
    int main() {
      ios_base::sync_with_stdio(0);
      int tc;
      cin >> tc;
      while(tc--) {
        cin >> N >> S;
        long long i = 1, now = N, skg;
        while(sumdig(now) > S) {
          skg = now / i % 10;
          if(skg != 0) {
            now += (10 - skg) * i;
          }
          i *= 10;
        }
        cout << now - N << "\n";
      }
    }
