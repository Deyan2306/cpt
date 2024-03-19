#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

void debug(const std::string& info, const std::string& point) {
    cout << "[+] " << info << point << endl;
}

std::string find_routes(const std::vector<std::pair<std::string, std::string>>& routes) {
    
    std::unordered_set<std::string> all_points;
    std::unordered_map<std::string, std::queue<std::string>> destination_points;
    
    for (const auto & route : routes) {
        const std::string & current_point = route.first;
        const std::string & next_point = route.second;

        all_points.insert(current_point);
        all_points.insert(next_point);

        std::cout << "[+] Added currrent point (" << current_point << ") and next point (" << next_point << ")" << std::endl; 

        destination_points[current_point].push(next_point); 
    }

    std::string starting_point;

    std::cout << "[+] Searching for starting point" << std::endl; 
    for (const auto & point : all_points) {
        std::cout << "[+] Checking condition for next point: " << point << std::endl; 
        bool found = false;
        for (const auto & route : routes) {
            if (route.second == point) {
                found = true;
                break;
            }
        }
        if (!found) {
            std::cout << "[-] Starting point was not found!" << std::endl; 
            starting_point = point;
            break;
        }
    }

    if (starting_point.empty()) {
        return "Starting point not found!";
    }

    // traverse
    std::cout << "[+] Starting the traversal for the out" << std::endl; 
    std::stringstream out; out << starting_point;
    std::string current = starting_point;

    while (!destination_points[current].empty()) {
        std::cout << "[+] Moved to next point: " << current << std::endl; 
        std::string next = destination_points[current].front();
        out << ", " << next;
        destination_points[current].pop();
        current = next;
    }

    return out.str();
}

int main() {

    std::vector<std::pair<std::string, std::string>> routes;

    routes.push_back(std::make_pair("Chicago", "Winnipeg"));
    routes.push_back(std::make_pair("Halifax", "Montreal"));
    routes.push_back(std::make_pair("Montreal", "Toronto"));
    routes.push_back(std::make_pair("Toronto", "Chicago"));
    routes.push_back(std::make_pair("Winnipeg", "Seattle"));

    std::string result = find_routes(routes);
    cout << "--- --- --- ---\nRoute: " << result << endl; 
    return 0;
}
