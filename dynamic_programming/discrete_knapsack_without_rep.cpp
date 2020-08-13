#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

void print_dp_table(int** E, int row, int column)
{
    std::cout << " === E ===" << std::endl;
    for (int i = 0; i <= row; ++i)
    {
        std::cout << "E[" << i << "]: ";
        for (int j = 0; j <= column; ++j)
        {
            std::cout << E[i][j] << " "; 
        }
        std::cout << std::endl;
    }
}

int optimal_weight(int W, const vector<int> &w)
{
    int size_w = w.size();

    // initialise a 2D array as DP table
    int** E = new int*[size_w+1]; // number of rows : size_w+1
    for (int i = 0; i <= size_w; ++i)
    {
        E[i] = new int[W+1]; // number of columns : W+1
    }

    // each E[][] is a subproblem 
    // initialise 0-th row and column
    for (int j = 0; j <= W; ++j)
    {
        E[0][j] = 0; 
    }
    for (int i = 0; i <= size_w; ++i)
    {
        E[i][0] = 0; 
    }

    //print_dp_table(E, size_w, W);

    // populate DP table
    for (int i = 1; i <= size_w; ++i)
    {
        for (int j = 1; j <= W; ++j)
        {
            int current_test_weight = w.at(i-1);

            if ( current_test_weight <= j)
            {
                int not_chosen = E[i-1][j]; // current test weight is not chosen
                int chosen = E[i-1][j-current_test_weight] + current_test_weight; // current test weight is chosen
                E[i][j] = std::max(chosen, not_chosen);
            }
            else
            {
                int not_chosen = E[i-1][j];
                E[i][j] = not_chosen; 
            }
        }
    }

    //print_dp_table(E, size_w, W);

    int result = E[size_w][W];

    // delete dynamic 2D array
    for (int i = 0; i<=size_w; ++i)
    {
        delete[] E[i];
    }
    delete[] E;

    return result;
}

int main()
{
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
