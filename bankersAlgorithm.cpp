// Banker's Algorithm
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // P0, P1, P2, P3, P4
    int n, m, i, j, k;
    n = 5; // Number of processes
    m = 3; // Number of resources
    int alloc[5][3]; // Allocation Matrix
    int max[5][3]; // MAX Matrix
    int avail[3]; // Available Resources

    // Read input from file
    ifstream inputFile("input.txt");
    if (inputFile.is_open()) {
        // Read allocation matrix
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                inputFile >> alloc[i][j];
            }
        }

        // Read max matrix
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                inputFile >> max[i][j];
            }
        }

        // Read available resources
        for (j = 0; j < m; j++) {
            inputFile >> avail[j];
        }

        inputFile.close();
    } else {
        cout << "Unable to open input file." << endl;
        return 1;
    }

    int f[n], ans[n], ind = 0;
    for (k = 0; k < n; k++) {
        f[k] = 0;
    }
    int need[n][m];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];
    }
    int y = 0;
    for (k = 0; k < 5; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {

                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    f[i] = 1;
                }
            }
        }
    }

    int flag = 1;

    // To check if sequence is safe or not
    for (int i = 0; i < n; i++) {
        if (f[i] == 0) {
            flag = 0;
            cout << "The given sequence is not safe";
            break;
        }
    }

    if (flag == 1) {
        cout << "Following is the SAFE Sequence" << endl;
        for (i = 0; i < n - 1; i++)
            cout << " P" << ans[i] << " ->";
        cout << " P" << ans[n - 1] << endl;
    }

}
