#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;

class BinaryNode{
protected:
    int data;
    BinaryNode* left;
    BinaryNode* right;

public:
    BinaryNode(int val=0, BinaryNode* l=NULL, BinaryNode* r=NULL)
        :data(val), left(l), right(r) {}
    void setData(int val){data = val;}
    void setLeft(BinaryNode* l){left = l;}
    void setRight(BinaryNode* r){right = r;}
    int getData(){return data;}
    BinaryNode* getLeft(){return left;}
    BinaryNode* getRight(){return right;}
    bool isLeaf(){return left==NULL && right==NULL;}
};

class BinaryTree{
    BinaryNode* root;
public:
    BinaryTree():root(NULL){}
    void setRoot(BinaryNode* node){root = node;}
    BinaryNode* getRoot(){return root;}
    bool isEmpty(){return root=NULL;}

    void inorder(BinaryNode *node)
        {
               if (node != NULL)
               {
                       if (node->getLeft() != NULL)
                              inorder(node->getLeft());
                       cout << "[" << (char)node->getData() << "] ";
                       if (node->getRight() != NULL)
                              inorder(node->getRight());
               }
        }
    void preorder(BinaryNode *node)
    {
           if (node != NULL)
           {
                   cout << "[" << (char)node->getData() << "] ";
                   if (node->getLeft() != NULL)
                          preorder(node->getLeft());
                   if (node->getRight() != NULL)
                          preorder(node->getRight());
           }
    }
    void postorder(BinaryNode *node)
    {
           if (node != NULL)
           {
                   if (node->getLeft() != NULL)
                          postorder(node->getLeft());
                   if (node->getRight() != NULL)
                          postorder(node->getRight());
                   cout << "[" << (char)node->getData() << "] ";
           }
    }
    int getCount(BinaryNode *node)
    {
           if (node == NULL)
                return 0;
           return 1 + getCount(node->getLeft()) + getCount(node->getRight());
    }
    int getHeight(BinaryNode *node)
    {
           if (node == NULL)
                   return 0;
           int hLeft = getHeight(node->getLeft());
           int hRight = getHeight(node->getRight());
           return (hLeft > hRight) ? hLeft + 1 : hRight + 1;
    }
    int getLeafCount(BinaryNode *node)
    {
           if (node == NULL)
                   return 0;
           if (node->isLeaf())
                   return 1;
           else
                   return getLeafCount(node->getLeft()) + getLeafCount(node->getRight());
    }

    bool isFull(){
        queue<BinaryNode*> q;
        root = getRoot();
        q.push(root);
        while(!q.empty()){
            BinaryNode* n = q.front();
            if(n->getLeft() != NULL && n->getRight() != NULL){
                q.push(n->getLeft());
                q.push(n->getRight());
                q.pop();
            }
            else{
                if(n->getLeft() == NULL && n->getRight() != NULL)
                    return false;
                else{
                    if(n->getLeft() !=NULL){
                        q.push(n->getLeft());
                        q.pop();
                        break;
                    }
                    else{
                        break;
                    }
                }
            }
        }

        while(!q.empty()){
            BinaryNode* temp= q.front();
            if(temp->isLeaf())
                q.pop();
            else
                return false;
        }
        return true;
    }

    int levelCount(BinaryNode* node, BinaryNode* node2, int lev =1){
        if(node == NULL)
            return 0;

        if(node == node2)
            return lev;
        if(node->getLeft() == NULL && node->getRight() == NULL)
            return 0;

        int left = levelCount(node->getLeft(), node2, lev+1);
        int right = levelCount(node->getRight(), node2, lev+1);

        if(!left)
            return right;
        else
            return left;
    }

    int level(BinaryNode* node){
        return levelCount(root,node);
    }

    int pathLength(){
        int sum=0;
        queue<BinaryNode*> q;
        root = getRoot();
        q.push(root);
        while(!q.empty()){
            BinaryNode* n = q.front();
            sum+= levelCount(root,n,0);
            if(n->getLeft() !=NULL){
                q.push(n->getLeft());
            }
            if(n->getRight() !=NULL){
                q.push(n->getRight());

            }
            q.pop();
        }
        return sum;
    }

    bool reverseShape(BinaryNode* node){
        if(node == NULL)
            return false;
        else{
            reverseShape(node->getLeft());
            reverseShape(node->getRight());
            BinaryNode* temp = node->getLeft();
            node->setLeft(node->getRight());
            node->setRight(temp);
        }
        return true;
    }

    bool reverse(){
        return reverseShape(root);
    }
};


int main()
{
   BinaryTree tree;
   BinaryNode *d = new BinaryNode('D', NULL, NULL);
   BinaryNode *c = new BinaryNode('C', NULL, NULL);
   BinaryNode *b = new BinaryNode('B', c, d);
   BinaryNode *f = new BinaryNode('F', NULL, NULL);
   BinaryNode *g = new BinaryNode('G', NULL, NULL);
   BinaryNode *e = new BinaryNode('E', NULL, f);

   BinaryNode *a = new BinaryNode('A', b, e);
   tree.setRoot(a);
   if(tree.isFull())
    cout<<"���� ����Ʈ��"<<endl;
   else{
    cout<<"���� ����Ʈ�� �ƴ�"<<endl;
   }

	cout<<"C�� ���� : "<<tree.level(c)<<endl;
	cout<<"Path �� �� : "<<tree.pathLength()<<endl;
	tree.inorder(a);
	if(tree.reverse())
        cout<<"Tree ������ ����"<<endl;
    else
        cout<<"Tree ������ ����"<<endl;
    tree.inorder(a);
	return 0;

}
