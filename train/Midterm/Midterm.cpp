#include <iostream>
#include <utility>
#include <algorithm>
#include <set>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <queue>
#include <time.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

int minPlatforms(map<int, pair<int, int>> trains) { // function to find how many active thru the whole day

    int min = 0; // for the current min thru loops
    int minnest = 0; // for highest given min thru loops

    for (int i = 0; i < 2400; i++) { // repeat till end of day
        for (int j = 1; j < 169; j++) {
            if (i == trains[j].first) { // add if a train arrives
                min++;
            }
            if (i == trains[j].second) { // subtract if a train leaves
                min--;
                trains.erase(j); // train erase since we don't need it after it leaves (although the loop still checks im sorry)
            }
            if (min > minnest) {
                minnest = min; // update biggest min
            }
        }
    }
    
    return minnest; // return biggest min
}

int findTimeFunc(map<int, pair<int, int>> trains, int timeFirst) { // function to find how many active at x time

    int min = 0; // for the current min thru loops
    int minnest = 0; // for highest given min thru loops

    for (int i = 0; i < timeFirst; i++) { // repeat till the time given
        for (int j = 1; j < 169; j++) {
            if (i == trains[j].first) { // add if a train arrives
                min++;
            }
            if (i == trains[j].second) { // subtract if a train leaves
                min--;
                trains.erase(j); // train erase since we don't need it after it leaves (although the loop still checks im sorry)
            }
            if (min > minnest) {
                minnest = min; // update biggest min
            }
        }
    }

    return minnest; // return biggest min

}

int main()
{
    auto start = high_resolution_clock::now(); // start time counting

    srand(time(NULL)); // sample

    vector<int> in; // vector of arrival
    vector<int> stay; // vector of duration


    for (int u = 1; u < 171; u++) {
        in.push_back(1 + rand() % 2400); // randomize arrival time
    }

    sort(in.begin(), in.end()); // sort arrival times

    for (int u = 1; u < 171; u++) {
        stay.push_back(rand() % 7 + 1); // randomize time stayed in before departure
    }

    map<int, pair<int, int>> trains; // map to combine info

    for (int u = 1; u < 171; u++) {
        trains.insert({ u, {} }); // creating 170 map elements
    }

    for (int j = 1; j < 171; j++) {
        trains[j].first = in[j-1]; // inserting arrival times
        trains[j].second = in[j-1] + stay[j - 1]; // inserting departure times
    }

    cout << "Trains\n" << endl; // printing info till line 101

    for (int i = 0; i < 170; i++) {
        cout << "Train " << i+1 << "\nArrival: " << trains[i + 1].first << "\n" << "Time of Departure: " << trains[i + 1].second << " minutes\n" << endl;
    }
    
    int min = minPlatforms(trains); // put the min aka the max platforms into an int

    cout << "Today there will be " << min << " active." << endl;

    int findTimeFirst; // int for how many will be active at x time

    cout << "Insert time to see how many platforms will be active:" << endl;
    cout << "Time: ";
    cin >> findTimeFirst;
    cout << "\n" << findTimeFunc(trains, findTimeFirst) << " out of " << min << " will be active." << endl; // print how mouch out of max will be active at the given time

    auto stop = high_resolution_clock::now(); // everything below is time running

    auto duration = duration_cast<seconds>(stop - start);

    cout << "\nProgram took: " << duration.count() << " seconds." << endl;

    return 0;

}