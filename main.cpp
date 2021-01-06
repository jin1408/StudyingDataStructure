#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>

// �⺻ Queue�� �̿��� meeting program

using namespace std;

int main()
{
    cout << "This is meeting program" << endl;
    queue<string> man;
    queue<string> woman;
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
            if(woman.empty() == false){
                cout<<"Matching Success! "<<man.front()<<"  and  " <<woman.front()<<endl;
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
            if(man.empty() == false){
                cout<<"Matching Success! "<<man.front()<<"  and  " <<woman.front()<<endl;
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
