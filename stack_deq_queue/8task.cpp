#include <iostream>
#include <deque>
 
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
 
    int N;
    std::cin >> N;
 
    std::deque<int> front_half, back_half;
 
    for (int i = 0; i < N; ++i) {
        char command;
        std::cin >> command;
 
        if (command == '+') {
            int goblin;
            std::cin >> goblin;
            back_half.push_back(goblin);
        }
        else if (command == '*') {
            int goblin;
            std::cin >> goblin;
            back_half.push_front(goblin);
        }
        else if (command == '-') {
            std::cout << front_half.front() << "\n";
            front_half.pop_front();
        }
 
        if (front_half.size() < back_half.size()) {
            front_half.push_back(back_half.front());
            back_half.pop_front();
        }
    }
 
    return 0;
}