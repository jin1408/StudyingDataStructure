#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
//c++을 사용한 단순 연결 리스트 구현
// +연결 리스트의 모든 데이터 값을 출력하는 프로그램(Sum함수)
// +연결 리스트의 특정 데이터 값의 개수를 찾는 프로그램(Search함수)
// +연결 리스트의 모든 노드의 순서를 뒤집는 프로그램(Reverse함수)
// +연결 리스트와 다른 연결 리스트를 병합하는 프로그램(Merge함수)

class Node{
    Node* link;
    int data;
public:
    Node(int val=0): data(val), link(NULL){}
    Node* getLink() {return link;}
    int getData(){return data;}

    void setLink(Node* next){link = next;}
    void display(){printf(" <%2d>",data);}
    bool hasData(int val){return data == val;}

    void insertNext(Node *n){
        if(n!=NULL){
            n->link = link;
            link = n;
        }
    }

    Node* removeNext(){
        Node* removed = link;
        if(removed != NULL)
            link = removed->link;
        return removed;
    }
};

class LinkedList{
    Node org;
    int sum;
public:
    LinkedList(): org(0) {sum=0; }
    ~LinkedList(){ clear();}
    void clear(){
        while(!isEmpty())
            delete remove(0);
    }
    Node* getHead(){
        return org.getLink();
    }
    bool isEmpty(){return getHead() == NULL;}

    Node* getEntry(int pos){
        Node* n = &org;
        for(int i=-1; i<pos; i++, n=n->getLink())
            if(n == NULL)
                break;
        return n;
    }

    void insert(int pos, Node *n){
        Node* prev = getEntry(pos-1);
        if(prev != NULL)
            prev->insertNext(n);
    }

    Node* remove(int pos){
        Node* prev = getEntry(pos-1);
        return prev->removeNext();
    }

    Node* find(int val){
        for(Node *p = getHead(); p!= NULL; p=p->getLink())
            if(p->hasData(val)) return p;
        return NULL;
    }

    void replace(int pos, Node *n){
        Node* prev = getEntry(pos-1);
        if(prev != NULL){
            delete prev->removeNext();
            prev->insertNext(n);
        }
    }

    int size(){
        int count = 0;
        for(Node *p = getHead(); p!=NULL; p=p->getLink())
            count++;
        return count;
    }

    void display(){
        printf("전체 항목수 = %2d : ", size());
        for(Node* p=getHead(); p!=NULL; p=p->getLink())
            p->display();
        cout<<endl;

    }

    void Sum(){
        int temp;
        for(Node* p=getHead(); p!=NULL; p=p->getLink()){
            temp = p->getData();
            sum+=temp;
        }
        cout<<"Sum : " <<sum<<endl;
    }
    void Search(int k){
        int temp;
        int count=0;
        for(Node* p=getHead(); p!=NULL; p=p->getLink()){
            if(k == p->getData())
                count++;
        }
        cout<<"리스트 내의 'k' 개수 : "<<count<<endl;
    }
    void Reverse(){
        int count=0;
        for(int i=0; i<size(); i++){
            Node *p = remove(size()-1);
            insert(count++,p);
        }
    }

    void Merge(LinkedList *that){
        while(!(that->isEmpty())){
            Node *p = that->remove(0);
            insert(size(),p);
        }
    }

};



int main()
{
    LinkedList list;
    LinkedList list2;
    list.insert(0, new Node(10));
    list.insert(0, new Node(20));
    list.insert(1, new Node(30));
    list.insert(2, new Node(50));
    list2.insert(0, new Node(100));
    list2.insert(0, new Node(101));
    list2.insert(1, new Node(212));
    list2.insert(2, new Node(413));
    list.Reverse();
    list.display();
    list.Merge(&list2);
    list.display();

	return 0;
}
