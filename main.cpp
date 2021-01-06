#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#define Max_size 8


using namespace std;

class CircularQueue{
protected:
    int front;
    int rear;
    string data[Max_size];
public:
    CircularQueue(){front = rear = 0;}
    bool isEmpty() {return front==rear;}
    bool isFull() {return (rear+1)%Max_size == front;}
    void push(string a){
        if(isFull()){
            cout<<"Full Error!";
        }
        else{
            rear = (rear+1)%Max_size;
            data[rear] = a;
        }
    }
    string pop(){
        if(isEmpty()){
            cout<<"Empty Error!";
        }
        else{
            front = (front+1)%Max_size;
            return data[front];
        }
    }
    string peek(){
        if(isEmpty()){
            cout<<"Empty Error!";
        }
        else{
            return data[(front+1)%Max_size];
        }
    }

};


int main(){
    cout << "This is meeting program" << endl;

    CircularQueue man;
    CircularQueue woman;
    int count =0;
    string name;
    string gender;

    while(true){
        if(count >100)
            return 0;

        cout<<"Name :";
        cin>>name;
        cout<<"Gender : ";
        cin>>gender;
        if(gender == "m"){
            man.push(name);
            if(woman.isEmpty() == false){
                cout<<"Matching Success! "<<man.peek()<<"  and  " <<woman.peek()<<endl;
                cout<<endl;
                man.pop();
                woman.pop();
            }
            else{
                cout<<"Can not match! Please Wait" << endl;
                cout<<endl;
            }
        }
        else{
            woman.push(name);
            if(man.isEmpty() == false){
                cout<<"Matching Success! "<<man.peek()<<"  and  " <<woman.peek()<<endl;
                cout<<endl;
                man.pop();
                woman.pop();
            }
            else{
                cout<<"Can not match! Please Wait" << endl;
                cout<<endl;
            }
        }
        count +=1;
    }

}
