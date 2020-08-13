#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int numRefills = 0;
    int currentRefill = 0; // starting point
    int n = stops.size();
    //std::cout << "stops size: " << stops.size() << std::endl;
    stops.push_back(dist);

    /*
    std::cout << "stops size: " << stops.size() << std::endl;
    for (auto& i : stops)
    {
        std::cout << "stop: " << i << std::endl;
    }
    */

    while (currentRefill <= n) 
    {
        if (currentRefill == n)
            break;
        //std::cout << "currentRefill in the beginning of while: " << currentRefill << std::endl;
        int lastRefill = currentRefill;
        while (currentRefill <= n &&
               stops.at(currentRefill+1) - stops.at(lastRefill) <= tank)
        {
            currentRefill += 1;
            //std::cout << "currentRefill in the middle of while: " << currentRefill << std::endl;
            if (currentRefill == n)
                break;
        }
        if (currentRefill == lastRefill)
        {
            return -1;
        }
        if (currentRefill <= n)
        {
            if (currentRefill != n)
                numRefills += 1;
        }
        //std::cout << numRefills << std::endl;
    }

    return numRefills;
}


int main() {
    int d = 0;
    cin >> d; // distination
    int m = 0; 
    cin >> m; // full tank travel distance 
    int n = 0;
    cin >> n; // number of stops

    vector<int> stops(n+1);
    stops.at(0) = 0;
    for (size_t i = 1; i < n+1; ++i)
        cin >> stops.at(i);


    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
