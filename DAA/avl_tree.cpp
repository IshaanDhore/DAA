#include<iostream>
#include<algorithm>
using namespace std;

class avl_node
{
    public:
    string word,meaning;
    avl_node *left,*right;
    int height;
    public:
    friend class avlTree;
};

class avlTree
{
    public:
    avl_node *root;
    public:
    int height(avl_node *);
    int diff(avl_node *);
    avl_node *rr_rotation(avl_node *);
    avl_node *ll_rotation(avl_node *);
    avl_node *lr_rotation(avl_node *);
    avl_node *rl_rotation(avl_node *);
    avl_node* balance(avl_node *);
    avl_node* insert();
    avl_node* insert(avl_node *,avl_node *);
    void display(avl_node *,int);
    void inorder(avl_node *);
    void preorder(avl_node *); 
    void postorder(avl_node *);
    avlTree()
    {
        root=NULL;
    }
};

int avlTree::height(avl_node *temp)
{
    if (temp == NULL)
            return 0;
    return temp->height;
}

int avlTree::diff(avl_node *temp)
{
    int l_height = height(temp->left);
    int r_height = height(temp->right);
    int b_factor = l_height - r_height;
    return b_factor;
}

avl_node *avlTree::rr_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    parent->height = max(height(parent->left), height(parent->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;
    return temp;
}

avl_node *avlTree::ll_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    parent->height = max(height(parent->left), height(parent->right)) + 1;
    temp->height = max(height(temp->left), height(temp->right)) + 1;
    return temp;
}

avl_node *avlTree::lr_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->left;
    parent->left = rr_rotation(temp);
    return ll_rotation(parent);
}

avl_node *avlTree::rl_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->right;
    parent->right = ll_rotation(temp);
    return rr_rotation(parent);
}

avl_node *avlTree::balance(avl_node *temp)
{
    int bal_factor = diff(temp);
    if (bal_factor > 1)
    {
        if (diff(temp->left) > 0)
            temp = ll_rotation(temp);
        else
            temp = lr_rotation(temp);
    }
    else if (bal_factor < -1)
    {
        if (diff(temp->right) > 0)
            temp = rl_rotation(temp);
        else
            temp = rr_rotation(temp);
    }
    return temp;
}

avl_node* avlTree::insert(avl_node *root, avl_node *ptr)
{
    if (root == NULL)
    {
        root = ptr;
        return root;
    }
    if (ptr->word < root->word)
    {
        root->left = insert(root->left, ptr);
        root = balance(root);
    }
    else if (ptr->word > root->word)
    {
        root->right = insert(root->right, ptr);
        root = balance(root);
    }
    return root;
}

avl_node* avlTree::insert()
{
    avl_node *ptr;
    ptr = new avl_node;
    cout<<"Enter Word: ";
    cin>>ptr->word;
    cout<<"Enter Meaning: ";
    cin>>ptr->meaning;
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->height = 1;
    if (root == NULL)
    {
        root = ptr;
    }
    else
    {
        root = insert(root, ptr);
    }
    return root;
}

void avlTree::inorder(avl_node *tree)
{
    if (tree == NULL)
        return;
    inorder(tree->left);
    cout<<tree->word<<" : "<<tree->meaning<<endl;
    inorder(tree->right);
}

void avlTree::preorder(avl_node *tree)
{
    if (tree == NULL)
        return;
    cout<<tree->word<<" : "<<tree->meaning<<endl;
    preorder(tree->left);
    preorder(tree->right);
}

void avlTree::postorder(avl_node *tree)
{
    if (tree == NULL)
        return;
    postorder(tree->left);
    postorder(tree->right);
    cout<<tree->word<<" : "<<tree->meaning<<endl;
}

void avlTree::display(avl_node *tree, int level)
{
    int i;
    if (tree == NULL)
        return;
    display(tree->right, level + 1);
    cout<<endl;
    for (i = 0; i < level; i++)
        cout<<"        ";
    cout<<tree->word;
    display(tree->left, level + 1);
}

int main()
{
    avlTree avl;
    int choice;
    while(1)
    {
        cout<<"\n1.Insert Element\n2.Display Inorder\n3.Display Preorder\n4.Display Postorder\n5.Display Tree\n6.Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                avl.insert();
                break;
            case 2:
                cout<<"Inorder Traversal:"<<endl;
                avl.inorder(avl.root);
                break;
            case 3:
                cout<<"Preorder Traversal:"<<endl;
                avl.preorder(avl.root);
                break;
            case 4:
                cout<<"Postorder Traversal:"<<endl;
                avl.postorder(avl.root);
                break;
            case 5:
                cout<<"Tree Structure:"<<endl;
                avl.display(avl.root, 1);
                cout<<endl;
                break;
            case 6:
                return 0;
            default:
                cout<<"Invalid Choice"<<endl;
        }
    }
    return 0;
}
