#include <iostream>
#include <queue>
 
 
int timeToMinutes(int hours, int minutes) {
    return hours * 60 + minutes;
}
 
std::pair<int, int> minutesToTime(int totalMinutes) {
    return { totalMinutes / 60, totalMinutes % 60 };
}
 
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
 
    int N;
    std::cin >> N;
 
    std::queue<int> queueTimes;
    int currentEndTime = 0; 
 
    for (int i = 0; i < N; ++i) {
        int hours, minutes, patience;
        std::cin >> hours >> minutes >> patience;
 
        int arrivalTime = timeToMinutes(hours, minutes);
 
        while (!queueTimes.empty() && queueTimes.front() <= arrivalTime) {
            queueTimes.pop();
        }
 
        if ((int)queueTimes.size() > patience) {
            std::cout << hours << " " << minutes << "\n";
        }
        else {
            if (queueTimes.empty()) {
                currentEndTime = arrivalTime + 20;
            }
            else {
                currentEndTime += 20;
            }
            queueTimes.push(currentEndTime);
 
            std::pair<int, int> leaveTime = minutesToTime(currentEndTime);
            std::cout << leaveTime.first << " " << leaveTime.second << "\n";
        }
    }
 
    return 0;
}