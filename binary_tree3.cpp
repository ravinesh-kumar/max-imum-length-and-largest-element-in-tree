// print the Kth element of the tree
/*
                 1     0th index
                / \
               2  3    1st index
              /\  /\
             4 5 6 7  2nd index and so on.......!!!!!

             we are going to print kth element or for the first time
             2nd index
             output screen will be
             4,5,6,7

             impelentation is on line number :-111

             for maximum height go to line number 127
             for largest node go to line number 146

*/
#include <bits/stdc++.h>
using namespace std;
template <typename T> // we can use any datatype weather it is int,string,char etc etc...
class TreeNode
{
public:
    T data;                         // data lenge
    vector<TreeNode<T> *> children; // data ke jo child honge unke pointer

    TreeNode(T data) // constructor of tree
    {
        this->data = data;
    }
    // we use deconstructor to delete the node of the tree
    // and by loop it also delete the children of the particular node if they have children
    ~TreeNode() // deconstructor
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};
string tobePrinted;

TreeNode<int> *takeInputLevelWise()
{
    queue<TreeNode<int> *> pendingNode; // taken a queue

    cout << "enter the root data " << endl;

    int rootdata; // taken root data from user

    cin >> rootdata;

    TreeNode<int> *root = new TreeNode<int>(rootdata); // new queue me root data element insert

    pendingNode.push(root); // push the data

    while (pendingNode.size() != 0)
    { // loop run until the queue is empty

        TreeNode<int> *currentNode = pendingNode.front(); // front data store in current data

        pendingNode.pop(); // pop front data

        cout << "Enter the number of children " << currentNode->data << endl; // taken total number of child
        int n;
        cin >> n; // child le liya element me
        for (int i = 1; i <= n; i++)
        {
            // saare child insert kr diya
            int currentchilddata;

            cout << i << " th child data" << currentNode->data << endl;

            cin >> currentchilddata;

            TreeNode<int> *childNode = new TreeNode<int>(currentchilddata);

            currentNode->children.push_back(childNode); // children me childnode ko dal do

            pendingNode.push(childNode); // childnode ko queue me dal do taki woo aage process kr sake
        }
    }
    return root;
}

void dataTreePrint(TreeNode<int> *root)
{
    // string tobeprinted;
    // string tobePrinted;
    queue<TreeNode<int> *> pendingNode; // queue
    pendingNode.push(root);
    while (pendingNode.size() != 0)
    {
        TreeNode<int> *currentNode = pendingNode.front();
        pendingNode.pop();
        tobePrinted = to_string(currentNode->data) + " :";

        for (int i = 0; i < currentNode->children.size(); i++)
        {
            tobePrinted += to_string(currentNode->children[i]->data) + " ,";
            pendingNode.push(currentNode->children[i]);
        }

        if (tobePrinted[tobePrinted.length() - 1] == ',')
        {
            tobePrinted = tobePrinted.substr(0, tobePrinted.length() - 1); // it start from 0th index and end in length-1
        }
        cout << tobePrinted << endl;
    }
}
// print the Kth index as explain above
int printAtK(TreeNode<int> *root, int k)
{

    if (k == 0)
    {
        cout << root->data << endl;

        return 0;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        printAtK(root->children[i], k - 1);
    }
}
// calculate the maximum height of the tree
int height(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int maxchildheight = 0; // let max child height is zero
    for (auto child : root->children)
    {
        int currentChildHeight = height(child);
        if (currentChildHeight > maxchildheight)
        {
            maxchildheight = currentChildHeight;
        }
    }
    return 1 + maxchildheight;
}

// print the largest node
TreeNode<int> *getLargestNode(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    TreeNode<int> *maxLargestNode = root; // initially humne bol diya hai root jo hai bada hia
    for (auto child : root->children)
    {
        TreeNode<int> *maxcurrentLargestNode = getLargestNode(child);
        if (maxLargestNode->data < maxcurrentLargestNode->data)
        {
            maxLargestNode = maxcurrentLargestNode;
        }
        
    }
    return maxLargestNode;
}

int main()
{
    TreeNode<int> *root = takeInputLevelWise();
    dataTreePrint(root);
    cout << "......................................................" << endl;
    cout << "                                                      " << endl;
    cout << "                                                      " << endl;
    cout << "                                                      " << endl;
    cout << "for unknown the height was calculate from 0th or \n the root is calculated as 0th position" << endl;
    cout << "                                                      " << endl;
    cout << "                                                      " << endl;
    cout << "......................................................" << endl;
    cout << "enter the k-1 position to print";
    int k;
    cin >> k;
    printAtK(root, k);
    cout << "the maximum height of the tree is " << height(root) << endl;
    // cout << height(root);
    cout << "the largest node in the tree is" << getLargestNode(root)->data << endl;
    // cout << getLargestNode(root)->data << endl;
}
// 1 2 2 3 2 4 5 2 6 7 0 0 0 0
