#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
   Node *left;
   bool lthread;
   Node *right;
   bool rthread;
   int data;

   Node(int x)
   {
       data=x;
       left=NULL;
       right=NULL;
       lthread=true;
       rthread=true;
   }

};

class Threaded
{
  public:
  Node *root;
  Threaded()
  {
      root=NULL;
  }

  void Insert(int x)
  {
      Node *curr = root;
      Node *par=root;

      while(curr != NULL )
      {
      par=curr;
      if(x<curr->data)
      {
          if(curr->lthread == false) // if curr has lchild 
          {
            curr=curr->left;
          }
          else
          {
            break;
          }
      }
      else
      {
          if(curr->rthread == false) // if curr has rchild
          {
          curr=curr->right;
          }
          else
          {
              break;
          }
      }

     }

  Node *temp = new Node(x);
   if(par == NULL)
   {
       root =temp;
       return;
   }
   else 
   {

       if(par->data > x) // insert node on left of tree;
       { 
          temp->left=par->left;
          temp->right=par;
          par->lthread=false;
          par->left=temp;
       }
       else // insert node on right of tree
       {
          temp->right=par->right;
          temp->left=par;
          par->rthread=false;
          par->right=temp;
       }

   }
  }

  void Inorder()
  {
     if(root == NULL)
     {
         cout<<"Tree is null \n";
         return;
     }

     Node *curr= root;

     while(curr->left != NULL)
     {
         curr=curr->left;
     }

     while(curr != NULL )
     {
       cout<<curr->data<<" ";
       curr=curr->right;

     }


  }
  
  void Preorder(Node *rt)
  {

    if(rt!= NULL)
    {
       while(rt != NULL)
       {
        cout<<rt->data<<" ";
       if(rt->lthread == false)
       {
        rt=rt->left;
       }
       else if(rt->rthread == false)
       {
        rt=rt->right;
       }
       else
       {
           while(rt != NULL && rt->rthread == true)
           {
              rt=rt->right;
           }
          
          if(rt != NULL)
          {
            rt=rt->right;
          }
     
       }
       }

    }

  }



void RecInorder(Node *rt);
void RecPreorder(Node *rt);
void RecPostorder(Node *rt);
 
};

void Threaded::RecInorder(Node *rt)
{
   if(rt != NULL)
   {
   if(rt->lthread == false)
   {
    RecInorder(rt->left);
   }
   cout<<rt->data<<" ";
   if(rt->rthread == false)
   {
    RecInorder(rt->right);
   }

   }
}

void Threaded::RecPreorder(Node *rt)
{
    if(rt != NULL)
    {
       cout<<rt->data<<" ";

       if(rt->lthread == false)
       {
        RecPreorder(rt->left);
       }

       if(rt->rthread == false)
       {
        RecPreorder(rt->right);
       }

    }

}

void RecPostorder(Node *rt)
{
  if(rt != NULL)
  {
      if(rt->lthread == false)
      {
        RecPostorder(rt->left);
      }

      if(rt->rthread == false)
      {
        RecPostorder(rt->right);
      }

      cout<<rt->data<<" ";

  }

}


int main()
{
  Threaded t1;
  t1.Insert(12);
  t1.Insert(6);
  t1.Insert(14);
  t1.Insert(8);
  cout<<"Inorder :- ";
  t1.RecInorder(t1.root);
  cout<<"\n";
  cout<<"Preorder :- ";
  t1.Preorder(t1.root);
  cout<<"\n";

  //***** Output *******//

  /*
  key :- 12,6,14,8
  Inorder :- 6 8 12 14
  Preorder :- 12 6 8 14

  */

return 0;
}