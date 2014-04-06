/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <iostream>
using namespace std;
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x){
		val=x;
		left=NULL;
		right=NULL;
	}
};
class Solution {
public:
    void flatten(TreeNode *root) {
        if(root!=NULL){ 
            TreeNode *right=NULL;
            if(root->right!=NULL){right=root->right;root->right=NULL;}
            if(root->left!=NULL) {flatten(root->left);TreeNode *left=(root->left);(root->right)=left;(root->left)=NULL;}
            TreeNode *p1=root;
            while((p1->right)!=NULL) p1=p1->right;
            if(right!=NULL) {flatten(right);(p1->right)=right;(p1->left)=NULL;}
        }
        
    }
};
int main(){
	Solution calculate;
	TreeNode *a=new TreeNode(0);
	calculate.flatten(a);
	return 0;
}