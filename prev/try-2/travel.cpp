#include <bits/stdc++.h>
#include <climits> 
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
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

void travel(unordered_map<int, vector<ii>>& towns, vector<int>& distances, int current_index, int planes_limit, int searched_index, int used_cars, int used_planes, int distance) {

    // Check if the current index is equal to the searched one. If it's true - then check the distances. 
    // If the distance to here is less, then set the new distance. Return to end the recursion.
    if (current_index == searched_index) {
        if (distance < distances[searched_index - 1]) {
            distances[searched_index - 1] = distance;
        }
        return;
    }

    // No need to go deeper, we have currently found a better path
    if (distance > distances[searched_index - 1]) {
        return;
    }

    // We are not on the end node
    if (towns[current_index].size() == 0) { return; } // No children left, leave the recursion

    // Iterate trough the children of the current index
    for (size_t index = 0; index < towns[current_index].size(); index++) {

        if (towns[current_index][index].second == 2 && (used_planes + 1) > planes_limit) {
            // We exceeded planes usage: Invalid path
            return;
        } 

        if (distance < distances[current_index - 1]) {
            distances[current_index - 1] = distance;
        }

        // Cars and planes relaxation step
        if (towns[current_index][index].second == 1) {
            travel(towns, distances, towns[current_index][index].first, planes_limit, searched_index, used_cars + 1, used_planes, distance + 1);
        } else if (towns[current_index][index].second == 2) {
            travel(towns, distances, towns[current_index][index].first, planes_limit, searched_index, used_cars, used_planes + 1, distance + 1);
        }
        
    }
}

/* May the source be with you */
int main(void) {

    int number_of_cities;
    int number_of_vehicles;
    int max_ammount_of_planes;

    // > [A]:[(B, type),(C, type)]
    unordered_map<int, vector<ii>> towns;   
    vector<int> distances;

    cin >> number_of_cities >> number_of_vehicles >> max_ammount_of_planes;

    int first_index = 1;
    int last_index = number_of_cities;

    // Fill in the distances
    for (size_t index = 0; index < number_of_cities; index++)
        distances.push_back(INT_MAX);

    // Read the distances
    for (size_t index = 0; index < number_of_vehicles; index++) {
        int type;
        int townA;
        int townB;

        cin >> townA >> townB >> type;

        towns[townA].push_back(pair<int, int>(townB, type));
    }

    // set the distance to the first town to 0
    distances[first_index - 1] = 0;

    // Iterate trough the children
    travel(towns, distances, first_index, max_ammount_of_planes, last_index, 0, 0, 0);
    
    // The distance to the last node should be at distances[last_index]
    if (distances[last_index - 1] == INT_MAX) {
        output << -1 << endl;
    } else {
        output << distances[last_index - 1];
    }

    cout << output.str();
    return 0;
}

// Do we need the distances array?
