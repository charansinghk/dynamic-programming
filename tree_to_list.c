#include<stdio.h>
#include<stdlib.h>

struct node {
   int val;
   struct node *right;
   struct node *left;
};

typedef struct node* NODE;

NODE newNode(int x) {
   NODE t = (NODE)malloc(sizeof(struct node));
   t->right = NULL;
   t->left = NULL;
   t->val = x;
   return t;
}

void inorder(NODE root) {

   if (root != NULL) {
      inorder(root->left);
      printf("%d    ",root->val);
      inorder(root->right);
   }
}

NODE convert_to_list(NODE root) {

   if (root == NULL) {
      return NULL;
   }
   if (root->left != NULL) {
      // convert left subtree first
      NODE t = convert_to_list(root->left);
      // find the inorder predecessor 'root'
      while(t->right!=NULL)
         t = t->right;
      t->right=root;
      root->left=t;
   }
   if (root->right != NULL) {
      // convert right subtree
      NODE t = convert_to_list(root->right);
      while(t->left != NULL)
         t = t->left;
      t->left = root;
      root->right = t;
   }
   return root;
}

NODE convert(NODE root)
{
    // Base case
    if (root == NULL)
        return root;
 
    root = convert_to_list(root);
 
    // We need pointer to the leftmost node which is
    // head of the constructed DLL, so move to the leftmost node
    while (root->left != NULL)
        root = root->left;
 
    return (root);
}

int main() {

   NODE root = newNode(10);
   NODE t1 = newNode(12);
   NODE t2 = newNode(15);
   root->left = t1;
   root->right = t2;
   
   NODE t3 = newNode(25);
   NODE t4 = newNode(30);
   t1->left = t3;
   t1->right = t4;

   NODE t5 = newNode(36);
   t2->left = t5;
   inorder(root);
   printf("\n\n");
   root = convert(root);
   NODE t =root;
   while(t != NULL) {
      printf("%d    ",t->val);
      t=t->right;
   }
   printf("\n\n");
   return 0;
}
