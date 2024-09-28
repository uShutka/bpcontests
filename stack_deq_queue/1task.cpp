#include <iostream>
#include <stack> 


int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int q, k;
    
    std::cin >> q;

    std::stack<std::pair<int, int>> n;

    for (int i = 0; i < q; ++i) {
        std::cin >> k;

        if (k == 1) {
            std::cin >> k;

            if (!n.empty()) {
                if (k < n.top().second) n.push(std::make_pair(k, k));
                else n.push(std::make_pair(k, n.top().second));
            }
            else {
                n.push(std::make_pair(k, k));
            }
        }
        else if (k == 2) {
            n.pop();
        }
        else if (k == 3) {
            std::cout << n.top().second << "\n";
        }
    }
}

