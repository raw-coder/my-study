#include <vector>

using namespace std;


int main() {
  vector<int> v;

  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  return 0;
}