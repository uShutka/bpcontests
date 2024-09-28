#include <iostream>
#include <deque>
 
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
 
    int n;
    std::cin >> n;
 
    std::deque<int> q;
    std::deque<int> min_q;
 
    for (int i = 0; i < n; ++i) {
        std::string command;
        std::cin >> command;
 
        if (command == "PUSH") {
            int x;
            std::cin >> x;
            q.push_back(x);
 
            while (!min_q.empty() && min_q.back() > x) {
                min_q.pop_back();
            }
            min_q.push_back(x);
        }
        else if (command == "POP") {
            if (!q.empty()) {
                if (q.front() == min_q.front()) {
                    min_q.pop_front();
                }
                q.pop_front();
            }
        }
 
        if (q.empty()) {
            std::cout << "-1" << "\n";
        }
        else {
            std::cout << min_q.front() << "\n";
        }
    }
 
    return 0;
}