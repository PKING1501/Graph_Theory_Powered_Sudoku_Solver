#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

struct Medicine {
    int days;
    int removes;
    int sideEffects;
};

int solve(int n, int m, int initialSymptoms, vector<Medicine>& medicines) {
    int targetState = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    unordered_map<int, int> minDays;

    pq.push({0, initialSymptoms});
    minDays[initialSymptoms] = 0;

    while (!pq.empty()) {
        int currentDays = pq.top().first;
        int currentState = pq.top().second;
        pq.pop();

        if (currentState == targetState) {
            return currentDays;
        }

        for (const auto& medicine : medicines) {
            int nextState = currentState;
            nextState &= ~medicine.removes;
            nextState |= medicine.sideEffects;

            int nextDays = currentDays + medicine.days;
            if (minDays.find(nextState) == minDays.end() || nextDays < minDays[nextState]) {
                minDays[nextState] = nextDays;
                pq.push({nextDays, nextState});
            }
        }
    }

    return -1;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        string symptoms;
        cin >> symptoms;

        int initialSymptoms = 0;
        for (int i = 0; i < n; ++i) {
            if (symptoms[i] == '1') {
                initialSymptoms |= (1 << i);
            }
        }

        vector<Medicine> medicines(m);
        for (int i = 0; i < m; ++i) {
            cin >> medicines[i].days;

            string removes, sideEffects;
            cin >> removes >> sideEffects;

            medicines[i].removes = 0;
            for (int j = 0; j < n; ++j) {
                if (removes[j] == '1') {
                    medicines[i].removes |= (1 << j);
                }
            }

            medicines[i].sideEffects = 0;
            for (int j = 0; j < n; ++j) {
                if (sideEffects[j] == '1') {
                    medicines[i].sideEffects |= (1 << j);
                }
            }
        }

        int result = solve(n, m, initialSymptoms, medicines);
        cout << result << endl;
    }

    return 0;
}
