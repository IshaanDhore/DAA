#include <iostream>
#include <algorithm>
using namespace std;

class userinfo
{
    public:
    int userid;
    string username;
    void get();
    void display();
    void lsearch(userinfo ui[20],int size,string target);
    void bin_search(userinfo ui[20],int low,int high,string key);
    void sort_users(userinfo ui[20],int size);
};

void userinfo::get()
{
    cout<<"Enter userid: ";
    cin>>userid;
    cout<<"Enter Username: ";
    cin>>username;
}

void userinfo::display()
{
    cout<<"\nUserID: "<<userid;
    cout<<"\nUsername: "<<username;
}

void userinfo::lsearch(userinfo ui[20],int size,string target)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(ui[i].username==target)
        {
            cout<<"Student is found at postion "<<i+1;
            cout<<"\nUserID: "<<ui[i].userid;
            break;
        }
    }
    if(i==size)
    {
        cout<<"Unsuccessful";
    }
}

void userinfo::sort_users(userinfo ui[20],int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(ui[j].username > ui[j+1].username)
            {
                userinfo temp = ui[j];
                ui[j] = ui[j+1];
                ui[j+1] = temp;
            }
        }
    }
    cout<<"\nUsers sorted alphabetically by username.";
}

void userinfo::bin_search(userinfo ui[20],int low,int high,string key)
{
    int flag=0;
    while(low <= high)
    {
        int mid = (high + low) / 2;
        
        if(ui[mid].username == key)
        {
            cout<<"Student is found at position "<<mid+1;
            cout<<"\nUserID: "<<ui[mid].userid;
            flag=1;
            break;
            //return;
        }
        else if(key < ui[mid].username)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if(flag=0)
    cout<<"Unsuccessful";
}

int main()
{
    int n, choice;
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
    u1.sort_users(u, n);
    
    cout<<"\n--- Sorted List ---";
    for(int i=0;i<n;i++)
    {
        u[i].display();
    }
    
    cout<<"\nChoose search method:";
    cout<<"\n1. Linear Search";
    cout<<"\n2. Binary Search";
    cout<<"\nEnter your choice (1/2): ";
    cin>>choice;
    
    string target;
    cout<<"\nEnter Username to search: ";
    cin>>target;
    
    switch(choice)
    {
        case 1: u1.lsearch(u, n, target);
        break;

        case 2: u1.bin_search(u, 0, n-1, target);
        break;

        default: cout<<"exit";
    }
    return 0;
}