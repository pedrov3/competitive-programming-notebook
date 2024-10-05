#include <bits/stdc++.h>
using namespace std;

mt19937 rnd;
int gen(int a, int b) {
  uniform_int_distribution<int> dist(a, b);
  return dist(rnd);
}

signed main(signed argc, char *argv[]) {
  cin.tie(0)->sync_with_stdio(0);
  if (argc < 2) {
    cout << "uso errado\n";
    exit(1);
  }
  rnd = mt19937(atoi(argv[1]));
 
  int n = gen(1, 5);
  cout << n << "\n";
  for (int i=0; i < n; i++){
    int a = gen(-10, 10);
    int b = gen(-10, 10);
    cout << a << " " << b << "\n";
  }
  
}
