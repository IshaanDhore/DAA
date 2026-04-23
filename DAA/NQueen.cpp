#include <iostream>
#include <cmath>
using namespace std;

int x[100];
int solutionCount = 0;

// Check if safe
bool Place(int k, int i) 
{
    for (int j = 1; j <= k - 1; j++) 
    {
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return false;
    }
    return true;
}

// Print solution
void printSolution(int n) 
{
    solutionCount++;

    cout << "Solution " << solutionCount << ":\n";

    // Written form
    cout << "Positions: ";
    for (int i = 1; i <= n; i++) 
    {
        cout << x[i] << " ";
    }
    cout << endl;

    // Matrix form
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= n; j++) 
        {
            if (x[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

// N-Queen function
void NQueen(int k, int n) 
{
    for (int i = 1; i <= n; i++) 
    {
        if (Place(k, i)) 
        {
            x[k] = i;
            if (k == n) 
            {
                printSolution(n);
            } else 
            {
                NQueen(k + 1, n);
            }
        }
    }
}

int main() 
{
    int n;
    cout << "Enter number of queens: ";
    cin >> n;

    NQueen(1, n);

    return 0;
}
