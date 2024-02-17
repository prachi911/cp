#include <iostream>
using namespace std;
struct Node {
 int data;
 struct Node* left;
 struct Node* right;
};
Node* newNode(int d)
{
 Node* root = new Node;
 root->data = d;
 root->left = NULL;
 root->right = NULL;
 return root;
}
Node* insert(Node* root, int data)
{
 Node* newnode = newNode(data);
 Node* x = root;
 Node* y = NULL;
 while (x != NULL) {
 y = x;
 if (data < x -> data)
1
 
x = 
x->left
;
 else
 
x = 
x->right
;
 }
 if (
y == NULL
)
 
y = newnode
;
 else if (data < 
y->data
)
 
y->left = newnode
;
 else
 
y->right = newnode
;
 return
y
;
}
void Inorder
(Node
* root
)
{
 if (root == NULL
)
 return
;
 else {
 Inorder
(root->left);
 cout << root->data << " "
;
 Inorder
(root->right);
 } }
void preorder
(Node
* root
)
{
 if (root == NULL
)
 return
;
 else {
 cout << root->data << " "
;
 preorder
(root->left);
 preorder
(root->right);
 } }
void postorder
(Node
* root
)
{
 if (root == NULL
)
 return
;
 else {
 postorder
(root->left);
 postorder
(root->right);
 cout << root->data << " "
;
 } }
int main() {
2
 
 Node* root = NULL;
 int i;
 int j;
 cout<<"\nenter the node:\n";
 cin>>j;
 root=insert(root,j);
 while(true){
 cout<<"\nenter the node:\n";
 cin>>i;
 if(i != -1)
 {
 insert(root,i);
 }
 else{
 break;
 }
 }
 int choice;
 cout<<"\n1. inorder of the binary tree:\n";
 cout<<"2. preorder of the binary tree:\n";
 cout<<"3. postorder of the binary tree:\n";
 
 while(true)
 {
 cout<<"\nEnter the choice:\n";
 cin>>choice;
 switch(choice)
 {
 case 1:{
 cout <<"\ninorder for the tree:\n";
 Inorder(root);
 break;
 }
 case 2 :{
 cout <<"\npreorder for the tree:\n";
 preorder(root);
 break;
 }
 case 3: {
 cout <<"\npostorder for the tree:\n";
 postorder(root);
 break;
 }
 case 4:
 {
 exit (0);
3
 }
 }
 }
 return 0;
}
