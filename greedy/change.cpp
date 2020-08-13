#include <iostream>
#include <vector>

int get_change(int m) {
    //write your code here
    if (m == 0)
    {
        return 0;
    }

    int num_coin = 0;
    std::vector<int> coin_value {10, 5, 1}; // sorted coin values
    int n = 0;
    while (n < coin_value.size() && m != 0)
    {
        int selected_value = coin_value.at(n); // selected value 
        int remainder = m % selected_value;
        if (remainder == 0) 
        {
            num_coin += m / selected_value; 
            break;
        }
        else
        {
            if (m >= selected_value)
            {
                num_coin += m / selected_value; 
                m = remainder; // reduce to subproblem 
            }
        }
        
        //std::cout << "This is n= " << n << ", m=" << m << std::endl;
        ++n; // update coint value
    }

    return num_coin;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
