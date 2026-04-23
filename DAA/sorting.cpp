//write a program to perform merge and quick sort and find its time complexity
//accept mobile no. user info 4 fields-uid/username/mobile no./bill amount
//display data in descending order along with uid using recursive merge sort
//display no. of passes and comparison for different 

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class userinfo
{
    public:
    int userid;
    string username;
    int mobile;
    int bill;
    static int passes;
    static int comparisons;
    void get();
    void display();
    void merge_sort(userinfo ui[20],int low,int high);
    void merge(userinfo ui[20],int low,int mid,int high);
    void quick_sort(userinfo ui [20],int p,int r);
    int partition(userinfo ui[20],int p,int r);
};

int userinfo::passes = 0;
int userinfo::comparisons = 0;

void userinfo::get()
{
    cout<<"Enter userid: ";
    cin>>userid;
    cout<<"Enter Username: ";
    cin>>username;
    cout<<"Enter Bill no.: ";
    cin>>bill;
}

void userinfo::display()
{
    cout<<"\nUserID: "<<userid;
    cout<<"\nUsername: "<<username;
    cout<<"\nBill no.: "<<bill;
}


void userinfo::merge(userinfo ui[20],int low,int mid,int high)
{
    userinfo temp[10];
    int i = low, j = mid + 1, k = low;

    while (i <= mid && j <= high)
    {
        comparisons++;
        if (ui[i].username > ui[j].username)
            temp[k++] = ui[i++];
        else
            temp[k++] = ui[j++];
    }

    while (i <= mid)
        temp[k++] = ui[i++];

    while (j <= high)
        temp[k++] = ui[j++];

    for (int i = low; i <= high; i++)
        ui[i] = temp[i];
}


void userinfo::merge_sort(userinfo ui[20],int low,int high)
{
    if(low < high)
    {
        passes++;
       int mid = (low + high)/2;

        merge_sort(ui,low,mid);
        merge_sort(ui,mid + 1,high);
        merge(ui,low,mid,high);
    }
}

void userinfo::quick_sort(userinfo ui[20],int p,int r)
{
    int q;
    if(p<r)
    {
        q = partition(ui,p,r);
        quick_sort(ui,p,q-1);
        quick_sort(ui,q+1,r);
    }
}

int userinfo::partition(userinfo ui[20],int p,int r)
{
    string x = ui[r].username;
    int i = p-1;
    for(int j=p;j<=r-1;j++)
    {
        comparisons++;
        if(ui[j].username >= x)
        {
             i++;
            class userinfo temp = ui[i];
            ui[i] = ui[j];
            ui[j] = temp; 
        }
        
    }
    class userinfo temp2 = ui[i+1];
            ui[i+1] = ui[r];
            ui[r] = temp2;
            return i+1;
}

int main()
{
    int n,choice,low,high,f;
    userinfo u[10];
    cout<<"Enter number of users: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        u[i].get();
    }
    cout<<"\n--- Original List ---";
    for(int i=0;i<n;i++)
    {
        u[i].display();
    }
    
    userinfo u1;
    string target;
    cout<<"\n1. Merge Sort(Descending)";
    cout<<"\n2. Quick Sort(Descending)";
    cout<<"\nEnter your choice: ";
    cin>>choice;
    
    // string target;
    switch(choice)
    {

        case 1: u1.merge_sort(u,0,n-1);
                for(int i=0;i<n;i++)
                {
                     u[i].display();
                }
                cout << "\nPasses: " << userinfo::passes;
                cout << "\nComparisons: " << userinfo::comparisons;
                break;

        case 2: u1.quick_sort(u,0,n-1);
                for(int i=0;i<n;i++)
                {   
                    u[i].display();
                }
                //cout << "\nPasses: " << userinfo::passes;
                cout << "\nComparisons: " << userinfo::comparisons;
                break;
            
        default: cout<<"No Operation";
                 break;
    }
    
    return 0;
}