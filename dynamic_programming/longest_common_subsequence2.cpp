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

int lcs2(vector<int> &a, vector<int> &b)
{
    // size of two sequences
    int n = a.size();
    int m = b.size();

    // initialise a 2D array as DP table
    int** E = new int*[n+1]; // number of rows
    for (int i = 0; i <= n; ++i)
    {
        E[i] = new int[m+1]; // number of columns
    }

    // initialise 0-th row and column
    for (int j = 0; j <= m; ++j)
    {
        E[0][j] = 0;
    }
    for (int i = 0; i <= n; ++i)
    {
        E[i][0] = 0;
    }

    //print_dp_table(E, n, m);

    // populate DP table
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            int match = E[i-1][j-1] + 1;
            int mismatch = std::max(E[i-1][j], E[i][j-1]); 

            if (a.at(i-1) == b.at(j-1))
            {
                E[i][j] = match;
            }
            else
            {
                E[i][j] = mismatch;
            }
        }
    }

    //print_dp_table(E, n, m);

    int result = E[n][m];
    
    // delete dynamic 2D array
    for (int i = 0; i<=n; ++i)
    {
        delete[] E[i];
    }
    delete[] E;

    return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
