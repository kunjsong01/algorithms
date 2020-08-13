#include <iostream>
#include <vector>
#include <cstdlib>
#include <utility>
#include <assert.h>

using std::vector;
using std::swap;
using std::pair;

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

pair<int, int> partition3(vector<int> &a, int l, int r) 
{
    pair<int, int> tmp;
    int x = a[l];
    int ml = l; // m1
    int mr = l; // m2

    for (int i = l+1; i <= r; ++i)
    {
        if (a[i] == x) // == x
        {
            mr++;
            swap(a[i], a[mr]);
        }
        else if (a[i] < x) // < x
        {
            // two cases:
            //  - length between ml and mr is 0, i.e. this segment has no equal elements and ml and mr are pointing to the same elemnt in the vector
            //  - length between ml and mr is not 0, i.e. this segment has equal elements and ml and mr are point to different elments in the vector
            if (ml < mr)
            {
                // first swap
                mr++;               // now a[mr] > x
                swap(a[i], a[mr]);  // now a[mr] < x
                // second swap
                swap(a[ml], a[mr]); // now a[ml] < x, a[mr] == x
                // increment left boundary
                ml++;               // now a[ml] == x
            }
            else if (ml == mr)
            {
                // first swap 
                mr++;              // now a[mr] > x
                swap(a[i], a[mr]); // now a[mr] < x 
                // second swap
                swap(a[ml], a[mr]);// now a[mr] == x
                // increment left boundary
                ml++;              // now a[ml] == x 
            }
            else
            {
                assert(!"ml > mr, it's impossible!");
            }
        }
        else // > x
        {
            // do nothing
        }
    }

    assert(ml <= mr);
    tmp.first = ml;
    tmp.second = mr;
    return tmp; 
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  //int m = partition2(a, l, r);
  pair<int, int> m = partition3(a, l, r);

  randomized_quick_sort(a, l, m.first - 1);
  randomized_quick_sort(a, m.second + 1, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
  std::cout << std::endl;
}
