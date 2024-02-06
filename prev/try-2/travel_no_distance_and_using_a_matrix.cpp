#include <bits/stdc++.h>
#include <climits> 
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;
typedef pair<int, short> is;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef vector<vector<short>> vss;
typedef vector<long> vl;

const int INF = 1e9;
const double PI = acos(-1.0);
const double EPS = 1e-9;

#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()

template<typename T>
void print_vector(const vector<T>& v) {
    for (const auto& elem : v) {
        cout << elem << " ";
    }
    cout << endl;
}

template<typename T>
void print_matrix(const vector<vector<T>>& mat) {
    for (const auto& row : mat) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

template<typename T>
void read_vector(vector<T>& v, int n) {
    v.resize(n);
    for (auto& elem : v) {
        cin >> elem;
    }
}

stringstream output;
void add_to_out(const string& str) {
    output << str;
}

// vehicle type
// 1 - bus
// 2 - plane

void travel(vss & towns, int current_index, int planes_limit, int searched_index, int used_cars, int used_planes, int distance, int & max_distance, bool & been_to_the_end_flag) {

    // Check if the current index is equal to the searched one. If it's true - then check the distances. 
    // If the distance to here is less, then set the new distance. Return to end the recursion.
    if (current_index == searched_index) {
        been_to_the_end_flag = true;
        if (distance < max_distance) {
            max_distance = distance;
        }
        return;
    }

    // No need to go deeper, we have currently found a better path
    if (distance > max_distance) {
        return;
    }

    // We are not on the end node
    if (towns[current_index - 1].size() == 0) { return; } // No children left, leave the recursion

    // Iterate trough the children of the current index
    for (size_t index = 0; index < towns[current_index - 1].size(); index++) {

        // we are iterating over all of the indeces
        if (towns[current_index - 1][index] == 0) { continue; }

        if (towns[current_index - 1][index] == 2 && (used_planes + 1) > planes_limit) {
            // We exceeded planes usage: Invalid path
            return;
        } 

        // Cars and planes relaxation step
        if (towns[current_index - 1][index] == 1) {
            travel(towns, index, planes_limit, searched_index, used_cars + 1, used_planes, distance + 1, max_distance, been_to_the_end_flag);
        } else if (towns[current_index - 1][index] == 2) {
            travel(towns, index, planes_limit, searched_index, used_cars, used_planes + 1, distance + 1, max_distance, been_to_the_end_flag);
        }
    }
}

/* May the source be with you */
int main(void) {

    int number_of_cities;
    int number_of_vehicles;
    int max_ammount_of_planes;

    // > [A]:[(B, type),(C, type)]
    vss towns; 
    int max_distance = INT_MAX;

    cin >> number_of_cities >> number_of_vehicles >> max_ammount_of_planes;

    int first_index = 1;
    int last_index = number_of_cities;

    // don't laugh at this :d
    bool been_to_the_end_flag = false;

    // fill in the towns
    for (size_t x = 0; x < number_of_cities; x++) {
        vector<short> inner;
        for (size_t y = 0; y < number_of_cities; y++)
            inner.push_back(0);
            towns.push_back(inner);
    }

    // Read the distances
    for (size_t index = 0; index < number_of_vehicles; index++) {
        short type;
        int townA;
        int townB;

        cin >> townA >> townB >> type;

        towns[townA - 1][townB - 1] = type;
    }

    // Iterate trough the children
    travel(towns, first_index, max_ammount_of_planes, last_index, 0, 0, 0, max_distance, been_to_the_end_flag);
    
    if (been_to_the_end_flag)
        output << max_distance << endl;
    else
        output << -1 << endl;

    cout << output.str();

    return 0;
}

// ok, we are still exceeding the memo somehow :d
/*
town a
[0][0][0][0][0]
[1][0][1][0][0]
[0][0][0][1][2] town b
[0][0][0][0][2]
[0][0][0][0][0]
*/

// waay too slow.