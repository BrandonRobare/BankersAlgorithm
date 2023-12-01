#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Function to check if the system is in a safe state
bool isSafeState(const vector<vector<int>>& allocation, const vector<vector<int>>& max, const vector<int>& available) {
    int numProcesses = allocation.size();
    int numResources = allocation[0].size();

    vector<int> work = available;
    vector<bool> finish(numProcesses, false);
    vector<int> safeSequence;

    int count = 0;
    while (count < numProcesses) {
        bool found = false;
        for (int i = 0; i < numProcesses; i++) {
            if (!finish[i]) {
                bool canAllocate = true;
                for (int j = 0; j < numResources; j++) {
                    if (max[i][j] - allocation[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    for (int j = 0; j < numResources; j++) {
                        work[j] += allocation[i][j];
                    }
                    safeSequence.push_back(i);
                    finish[i] = true;
                    found = true;
                    count++;
                }
            }
        }
        if (!found) {
            break;
        }
    }

    return count == numProcesses;
}

int main() {
    // Read input from a file
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cout << "Failed to open input file." << endl;
        return 1;
    }

    int numProcesses, numResources;
    inputFile >> numProcesses >> numResources;

    vector<vector<int>> allocation(numProcesses, vector<int>(numResources));
    vector<vector<int>> max(numProcesses, vector<int>(numResources));
    vector<int> available(numResources);

    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            inputFile >> allocation[i][j];
        }
    }

    for (int i = 0; i < numProcesses; i++) {
        for (int j = 0; j < numResources; j++) {
            inputFile >> max[i][j];
        }
    }

    for (int i = 0; i < numResources; i++) {
        inputFile >> available[i];
    }

    inputFile.close();

    // Check if the system is in a safe state
    vector<int> safeSequence;

    if (isSafeState(allocation, max, available)) {
        cout << "The system is in a safe state." << endl;
        cout << "Safe sequence: ";
        for (int i = 0; i < numProcesses; i++) {
            safeSequence.push_back(i); // Add the process index to the safeSequence vector
            cout << "P" << safeSequence[i];
            if (i != numProcesses - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    } else {
        cout << "The system is not in a safe state." << endl;
    }

    return 0;
}
