#include <iostream>
#include <algorithm>

using namespace std;

void displayTable(int** B, int n, int W) {
    cout << "\n--- Dynamic Programming Table ---\n";
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            cout << B[i][w] << "\t";
        }
        cout << endl;
    }
}

void findItems(int** B, int weights[], int values[], int n, int W) 
{
    cout << "\n--- Items Selected (Backtracking) ---\n";
    int res = B[n][W]; 
    int w = W;         
    
    for (int i = n; i > 0 && res > 0; i--) 
    {
    
        if (res != B[i - 1][w]) 
        {
            cout << "Picked Item " << i<<endl;
                //  << " [Value: " << values[i - 1] 
                //  << ", Weight: " << weights[i - 1] << "]\n";
            
            res -= values[i - 1];
            w -= weights[i - 1];
        }
    }
}

void solveKnapsack(int n, int W, int weights[], int values[], int** B) 
{
    for (int i = 0; i <= n; i++) 
    {
        for (int w = 0; w <= W; w++) 
        {
            if (i == 0 || w == 0) 
            {
                B[i][w] = 0;
            } else if (weights[i - 1] <= w) 
            {
                B[i][w] = max(values[i - 1] + B[i - 1][w - weights[i - 1]], B[i - 1][w]);
            } else 
            {
                B[i][w] = B[i - 1][w];
            }
        }
    }
}

int main() 
    {
    int n, W;
    

    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter max knapsack capacity: ";
    cin >> W;

    int* values = new int[n];
    int* weights = new int[n];

    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " - Enter Value and Weight: ";
        cin >> values[i] >> weights[i];
    }

    int** B = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
        B[i] = new int[W + 1];
    }


    solveKnapsack(n, W, weights, values, B);
    displayTable(B, n, W);
    
    cout << "\nTotal Maximum Value: " << B[n][W] << endl;
    
    findItems(B, weights, values, n, W);

    return 0;
}   