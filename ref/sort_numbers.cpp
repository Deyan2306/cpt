#include <iostream>
#include <vector>
#include <algorithm>

std::string getNumbersAsString(std::vector<int> numbers) {
    std::stringstream out;
    out << numbers[0];
    for (int i = 1; i < numbers.size(); i++) {
        out << " " << numbers[i];
    }
    return out.str();
}

std::vector<int> solution(std::vector<int> nums) {
    std::sort(nums.begin(), nums.end()); 
    return nums;
}

int main() {
    int n;
    std::cout << "Array Length: ";
    std::cin >> n;

    std::vector<int> numbers;
    std::cout << "Array elements [space separated]: ";
    for (int index = 0; index < n; index++) {
        int num; std::cin >> num; 
        numbers.push_back(num);
    }
    
    std::cout << "[+] Started sorting the numbers" << std::endl;
    std::vector<int> sol = solution(numbers);

    std::cout << getNumbersAsString(numbers) << std::endl;

    return 0;
}
