#include <iostream>
#include <stack>
#include <vector>
#include <string>
 
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
 
    int n;
    std::cin >> n;
 
    std::stack<int> hemoglobin;
    std::vector<long long> sumVec;
    sumVec.push_back(0);
 
    for (int i = 0; i < n; ++i) {
        std::string command;
        std::cin >> command;
 
        if (command[0] == '+') {
            int x = stoi(command.substr(1));
            hemoglobin.push(x);
            sumVec.push_back(sumVec.back() + x);
        }
        else if (command[0] == '-') {
            std::cout << hemoglobin.top() << "\n";
            hemoglobin.pop();
            sumVec.pop_back();
        }
        else if (command[0] == '?') {
            int k = stoi(command.substr(1));
            std::cout << sumVec.back() - sumVec[sumVec.size() - k - 1] << "\n";
        }
    }
 
    return 0;
}