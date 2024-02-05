#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;

    // Euclidean distance between two points
    double distance(const Point& other) const {
        int dx = x - other.x;
        int dy = y - other.y;
        return sqrt(dx * dx + dy * dy);
    }
};

// Function to calculate the total distance of a given route
double calculateTotalDistance(const vector<Point>& cities, const vector<int>& route) {
    double totalDistance = 0.0;
    int numCities = route.size();

    for (int i = 0; i < numCities - 1; ++i) {
        int city1 = route[i];
        int city2 = route[i + 1];
        totalDistance += cities[city1].distance(cities[city2]);
    }

    // Return to the starting city
    totalDistance += cities[route.back()].distance(cities[route.front()]);

    return totalDistance;
}

// Nearest Neighbor Algorithm to solve TSP
vector<int> nearestNeighbor(const vector<Point>& cities) {
    int numCities = cities.size();
    vector<int> route(numCities);

    // Initialize the route with the order of cities (0, 1, 2, ..., n-1)
    for (int i = 0; i < numCities; ++i) {
        route[i] = i;
    }

    // Start from the first city
    int currentCity = 0;

    // Mark each city as not visited
    vector<bool> visited(numCities, false);
    visited[currentCity] = true;

    for (int i = 1; i < numCities; ++i) {
        // Find the nearest unvisited city
        int nearestCity = -1;
        double minDistance = numeric_limits<double>::infinity();

        for (int j = 0; j < numCities; ++j) {
            if (!visited[j] && j != currentCity) {
                double distance = cities[currentCity].distance(cities[j]);
                if (distance < minDistance) {
                    minDistance = distance;
                    nearestCity = j;
                }
            }
        }

        // Move to the nearest unvisited city
        currentCity = nearestCity;
        visited[currentCity] = true;
        route[i] = currentCity;
    }

    return route;
}

int main() {
    // Example usage
    vector<Point> cities = {{0, 0}, {1, 2}, {2, 4}, {3, 1}};
    vector<int> route = nearestNeighbor(cities);

    // Output the order of cities in the optimized route
    cout << "Optimized Route: ";
    for (int city : route) {
        cout << city << " ";
    }

    // Output the total distance of the optimized route
    double totalDistance = calculateTotalDistance(cities, route);
    cout << "\nTotal Distance: " << totalDistance << endl;

    return 0;
}
