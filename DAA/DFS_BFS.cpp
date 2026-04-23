#include <iostream>
using namespace std;

class node 
{
    int vertex;
    node *next;
    friend class graph;
};

class graph 
{
    node* head[20];
    int adj[20][20]; 
    int n;

public:
    graph() 
    { 
        for(int i = 0; i < 20; i++) {
            head[i] = NULL;
            for(int j = 0; j < 20; j++) adj[i][j] = 0; 
        }
    }
    void create();
    void DFS(int start);
    void BFS(int start);
};

void graph::create()
{
    cout << "Enter no. of friends: ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        head[i] = new node;
        head[i]->vertex = i;
        head[i]->next = NULL;

        node* temp = head[i];
        char choice;

        cout << "\nEntering friends for person " << i << endl;
        do 
        {
            int v;
            cout << "Enter friend ID: ";
            cin >> v;

            if(v == i) 
            {
                cout << "Self loops are not allowed!" << endl;
            } else 
            {
                node* curr = new node; 
                curr->vertex = v;
                curr->next = NULL;
                
                temp->next = curr;    
                temp = curr;

               
                adj[i][v] = 1; 
                adj[v][i] = 1; 
            }

            cout << "Add another friend for " << i << "? (y/n): ";
            cin >> choice;
        } while (choice == 'y' || choice == 'Y');
    }
}

void graph::DFS(int start)
{
    int visited[20] = {0}; 
    int stack[20];
    int top = -1;

    stack[++top] = start;
    visited[start] = 1;

    cout << "DFS Traversal: ";
    do
    {
        int v = stack[top--];
        cout << v << " ";
        node* temp = head[v]->next; 
        while (temp != NULL)
        {
            int w = temp->vertex;
            if (visited[w] == 0)
            {
                stack[++top] = w;
                visited[w] = 1;
            }
            temp = temp->next;
        }
    } while (top != -1);
    cout << endl;
}

void graph::BFS(int start)
{
    int visited[20] = {0}; 
    int q[100];
    int front = 0, rear = 0;
    
    visited[start] = 1;
    q[rear++] = start;

    cout << "BFS Traversal: ";
    while(front < rear)
    {
        int v = q[front++];
        cout << v << " ";

        for(int i = 0; i < n; i++)
        {
            if(adj[v][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                q[rear++] = i;
            }
        }
    }
    cout << endl;
}

int main() 
{
    graph g1;
    g1.create();
    int start;
    cout << "\nEnter the starting vertex: ";    
    cin >> start;
    g1.DFS(start);
    g1.BFS(start);
    return 0;
}