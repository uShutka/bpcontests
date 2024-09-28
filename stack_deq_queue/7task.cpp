#include <iostream>
#include <stack>
#include <vector>
 
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
 
    int N;
    std::cin >> N;
 
    std::vector<int> prices(N);
    std::vector<int> result(N);
 
    for (int i = 0; i < N; ++i) {
        std::cin >> prices[i];
    }
 
    std::stack<int> s;
 
    for (int i = N - 1; i >= 0; --i) {
        while (!s.empty() && prices[s.top()] >= prices[i]) {
            s.pop();
        }
 
        if (!s.empty()) {
            result[i] = s.top();
        }
        else {
            result[i] = -1;
        }
 
        s.push(i);
    }
 
    for (int i = 0; i < N; ++i) {
        std::cout << result[i] << " ";
    }
 
    return 0;
}