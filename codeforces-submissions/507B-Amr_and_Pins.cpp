#include <bits/stdc++.h>
using namespace std;

int main() {
  long long r, x, y, xx, yy;
  cin >> r >> x >> y >> xx >> yy;
  long long dist = (x - xx) * (x - xx) + (y - yy) * (y - yy);
  long long step = 4 * r * r;
  long long res = (dist + step - 1) / step;
  long long ans = sqrt(1.0 * res);
  while (ans * ans < res) ans++;
  while (ans > 0 && (ans - 1) * (ans - 1) >= res) ans--;
  cout << ans << endl;
  return 0;
}