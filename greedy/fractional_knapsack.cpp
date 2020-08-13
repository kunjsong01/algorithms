#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
    double value = 0.0;

    if (weights.size() == 0)
        return 0;

    // write your code here
    // sort veights and values based on v/w
    vector<double> weights_sorted;
    vector<double> values_sorted;
    std::map<double, int> price_index; // price vs. vector index, map sorts items using key NOT value!

    for (int i = 0; i < values.size(); ++i)
    {
        double price = ((double)values.at(i)/(double)weights.at(i));
        price_index[price] = i;
    }

    //for (auto& t : price_index)
    //    std::cout << "price_index[" << t.first << "] = " << t.second << std::endl;

    for (auto rit = price_index.rbegin(); rit != price_index.rend(); ++rit)
    {
        //std::cout << "This is rit->second=" << rit->second << ", rit->first=" << rit->first << std::endl;
        if (capacity == 0)
        {
            break;
        }
        
        int i = rit->second; // vector index
        int a = std::min(weights.at(i), capacity);
        value += a * (rit->first); // update value
        weights[i] = weights.at(i) - a; // update weights
        capacity -= a; // update capacity
    }

    return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
