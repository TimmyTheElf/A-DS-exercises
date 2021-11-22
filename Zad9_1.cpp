#include <iostream>
#include <bits/stdc++.h>

using namespace std;
struct BSTNode
{
 BSTNode * up, * left, * right;
 int key;
};
void insertBST ( BSTNode * & root, int k )
{
  BSTNode * w, * p;

  w = new BSTNode;

  w->left = w->right = NULL;
  w->key = k;

  p = root;

  if( !p )
    root = w;
  else
    while( true )
      if( k < p->key )
      {
        if( !p->left )
        {
          p->left = w;
          break;
        }
        else p = p->left;
      }
      else
      {
        if( !p->right )
        {
          p->right = w;
          break;
        }
        else p = p->right;
      }

  w->up  = p;

}
void Release ( BSTNode * v )
{
  if( v )
  {
    Release ( v->left );
    Release ( v->right );
    delete v;
  }
}
void printPreorder(struct BSTNode* node)
{
    if (node == NULL)
        return;
    cout << node->key<< " ";
    printPreorder(node->left);
    printPreorder(node->right);
}
void printPostorder(struct BSTNode* node)
{
    if (node == NULL)
        return;
        printPostorder(node->left);
    printPostorder(node->right);
    cout << node->key << " ";
}
void printLevelorder(struct BSTNode *node)
{
    if (node == NULL)  return;
    queue<BSTNode *> q;
    q.push(node);
    while (q.empty() == false)
    {
        BSTNode *node = q.front();
        cout << node->key << " ";
        q.pop();
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }
}



int main()
{   int tests, n;
    short int k;
    cin>>tests;
    for(int i =0;i<tests;i++){
            cin>>n;
        BSTNode * root =NULL;
        for(int j=0;j<n;j++){
            cin>>k;
            insertBST ( root, k );
        }
        cout<<"Test nr "<<i+1<<endl;
        cout<<"Preorder:   ";
        printPreorder(root);
        cout<<endl<<"Postorder:  ";
        printPostorder(root);
        cout<<endl<<"Levelorder: ";
        printLevelorder(root);
        cout<<endl;

        Release ( root );
    }

    return 0;
}
