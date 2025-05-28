#include <iostream>

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int v, Node *l = nullptr, Node *r = nullptr)
    {
        val = v;
        left = l;
        right = r;
    };
};

Node *createNode(int num)
{
    Node *newnode = new Node(num);

    return newnode;
}

Node *insert(Node *root, int value)
{
    if (root == nullptr)
    {
        return createNode(value);
    }
    if (value > root->val)
    {
        root->right = insert(root->right, value);
    }
    else
    {
        root->left = insert(root->left, value);
    }
    return root;
}
void inorder(Node *root)
{
    if (root != nullptr)
    {

        inorder(root->left);
        std::cout << root->val << " ";
        inorder(root->right);
    }
    return;
}
void preorder(Node *root)
{
    if (root != nullptr)
    {

        std::cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }
    return;
}

int main()
{
    int j = 8, data;
    Node *head = nullptr;
    for (int i = 0; i < j; i++)
    {
        std::cout << "Enter a value : ";
        std::cin >> data;
        head = insert(head, data);
    }

    inorder(head);

    return 0;
}