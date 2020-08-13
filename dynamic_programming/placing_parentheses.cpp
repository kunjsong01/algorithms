#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <algorithm>
#include <utility>

using std::vector;
using std::string;
using std::max;
using std::min;
using namespace std;

pair<long long, long long> MinAndMax(int i, int j, long long** m, long long** M, vector<char>& op);

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

void print_dp_table(long long** E, int row, int column, const string &msg)
{
    std::cout << msg << std::endl;
    for (int i = 0; i < row; ++i)
    {
        std::cout << "E[" << i << "]: ";
        for (int j = 0; j < column; ++j)
        {
            std::cout << E[i][j] << " "; 
        }
        std::cout << std::endl;
    }
}

void print_op(vector<char>& op)
{
    cout << "===== op vector ======" << endl;
    for (auto i : op)
    {
        cout << i << ", ";
    }
    cout << endl;
}

void print_d(vector<long long>& d)
{
    cout << "===== d vector ======" << endl;
    for (auto i : d)
    {
        cout << i << ", ";
    }
    cout << endl;
}

long long get_maximum_value(const string &exp)
{
    // split digits and operators
    vector<char> op;
    vector<long long> d;
    for (int i = 0; i < exp.length(); ++i)
    {
        if (i%2 != 0)
        {
            op.push_back(exp[i]);
        }
        else
        {
            char c = exp[i];
            d.push_back(atoll(&c));
        }
    }
    //print_op(op);
    //print_d(d);

    // initialise 2D arrays for DP tables - m and M for min and max respectively 
    int n = d.size(); 
    long long** m = new long long*[n];
    long long** M = new long long*[n];
    for (int i = 0; i < n; ++i)
    {
        m[i] = new long long[n];
        M[i] = new long long[n];
    }
    for (int i = 0; i < n; ++i)
    {
        m[i][i] = d.at(i);
        M[i][i] = d.at(i);
    }

    // populate m and M
    for (int s = 0; s <=n-2; ++s)
    {
        for (int i = 0; i <= ((n-2)-s); ++i)
        {
            int j = (i + 1) + s;
            pair<long long, long long> tmp = MinAndMax(i, j, m, M, op);
            m[i][j] = tmp.first;
            M[i][j] = tmp.second;
        }
    }
    //print_dp_table(m, n, n, "=== m ===");
    //print_dp_table(M, n, n, "=== M ===");

    return M[0][n-1];
}

pair<long long, long long> MinAndMax(int i, int j, long long** m, long long** M, vector<char>& op)
{
    long long min_ = numeric_limits<long long>::max();
    long long max_ = 0 - numeric_limits<long long>::max();

    for (int k = i; k <= j-1; ++k)
    {
        long long a = eval(M[i][k], M[k+1][j], op.at(k)); 
        long long b = eval(M[i][k], m[k+1][j], op.at(k)); 
        long long c = eval(m[i][k], M[k+1][j], op.at(k)); 
        long long d = eval(m[i][k], m[k+1][j], op.at(k)); 
        min_ = min({min_, a, b, c, d}); 
        max_ = max({max_, a, b, c, d});
    }
    pair<long long, long long> result;
    result.first = min_;
    result.second = max_;
    return result; 
}

int main() {
  string s;
  std::cin >> s;
  //s = "5-8+7*4-8+9"; for test
  //s = "1+5"; for test
  std::cout << get_maximum_value(s) << '\n';
}
