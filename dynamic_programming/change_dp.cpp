#include <iostream>
#include <vector>

int get_change(int m)
{
    // init a vector containing all demoninations
    std::vector<int> denoms {1, 3, 4};
    // init a vector containing extremely large number with size m 
    std::vector<int> min_num_coins;
    for (size_t i = 0; i <= m; ++i)
    {
        min_num_coins.push_back(10000);
    }

    // dynamic programming: 
    //  - work from 0 to m
    //  - try denomination 1, 3 and 4 for each amount
    for (size_t i = 0; i <= m; ++i)
    {
        //std::cout << "Calculating optimal solution for m = " << i << std::endl;
        // zero case
        if (i == 0)
        {
            min_num_coins.at(i) = 0;
            continue;
        }

        // non-zero case
        //  - try each coin and getting min(min_num_coin(coin-1)+1, min_num_coin(coin-3)+1, min_num_coin(coin-4)+1)
        for (size_t j = 0; j < 3; ++j)
        {
            int coin = denoms.at(j); // coin to be tested in this iteration
            //std::cout << "   - Testing coin [" << coin << "]: ";
            if (i >= coin)
            {
                int num_coins = min_num_coins.at(i - coin) + 1; // +1 because we are using this coin
                //std::cout << " num_coins: " << num_coins;
                if (num_coins < min_num_coins.at(i))
                {
                    min_num_coins.at(i) = num_coins;
                }
            }
            //std::cout << std::endl;
        }
        //std::cout << std::endl;
    }

    /*
    // debug
    std::cout << "min_num_coins: " << " "; 
    for (auto n : min_num_coins)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    */

    return min_num_coins.at(m);
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
