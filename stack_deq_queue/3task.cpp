#include <iostream>
#include <queue>
 
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
 
    int q;
    std::cin >> q;
 
    std::queue<long long> qQueue;
    long long shift = 0;
 
    for (int i = 0; i < q; i++) {
        std::string command;
        std::cin >> command;
 
        if (command == "PUSH") {
            long long x;
            std::cin >> x;
            qQueue.push(x - shift);
        }
        else if (command == "POP") {
            if (qQueue.empty()) {
                std::cout << -1 << "\n";
            }
            else {
                std::cout << qQueue.front() + shift << "\n";
                qQueue.pop();
            }
        }
        else if (command == "INC") {
            long long x;
            std::cin >> x;
            shift += x;
        }
    }
 
    return 0;
}
