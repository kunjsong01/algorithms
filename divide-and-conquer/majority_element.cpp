#include <algorithm>
#include <iostream>
#include <vector>
#include <map>

using std::vector;
using std::map;

int get_majority_element(vector<int> &a, int left, int right) {
    map<int, int> frequency;

    // initialise map
    for (auto i = 0; i < a.size(); ++i) {
        frequency[a[i]] = 0;
    }

    // count frequency, and store frequencies in the map
    for (auto i = 0; i < a.size(); ++i) {
        frequency[a[i]] += 1;
    }

    bool found_target = false;
    int target;
    // traverse map to find the target
    for (auto& i : frequency)
    {
        if (i.second > a.size()/2) 
        {
            target = i.first;
            found_target = true;
            break;
        }
    }

    if (found_target)
    {
        return 1;
    }

    /*
    // debug print
    std::cout << " === debug: ===" << std::endl;
    for (auto& i : frequency) {
        std::cout << i.first << " : " << i.second << std::endl;
    }
    std::cout << "found_target: " << found_target << std::endl;
    std::cout << "target: " << target << std::endl;


    // find target index in the original array, the first occurance
    if (found_target)
    {
        for (int i = 0; i < a.size(); ++i)
        {
            if (a.at(i) == target)
            {
                std::cout << "a.at(" << i << "): " << a.at(i) << std::endl;
                return i+1; 
            }
        }
    }
    else
    {
        return 0;
    }
    */

    return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
