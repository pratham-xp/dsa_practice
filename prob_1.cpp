/* Print right-side nodes for each left root node  */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void printRightSide(TreeNode* root) {
    if(root == NULL) return;
    TreeNode* temp = root;
    while(temp) {
        cout << temp->val << " ";
        temp = temp->right;
    }
    cout << endl;
    printRightSide(root->left);
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7};
    struct TreeNode* root = new TreeNode(arr[0]);
    root->left = new TreeNode(arr[1]);
    root->right = new TreeNode(arr[2]);
    root->left->left = new TreeNode(arr[3]);
    root->left->right = new TreeNode(arr[4]);
    root->right->left = new TreeNode(arr[5]);
    root->right->right = new TreeNode(arr[6]);
    printRightSide(root);
    return 0;
}