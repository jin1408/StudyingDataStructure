#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>


using namespace std;


int main(){
    cout << "This is meeting program" << endl;

    deque<string> man;
    deque<string> woman;
    int count =0;
    string name;
    string gender;
    string answer;

    while(true){
        if(count >100)
            return 0;

        cout<<"Name :";
        cin>>name;
        cout<<"Gender : ";
        cin>>gender;
        cout<<"Do you want to match immediately?";
        cin>>answer;
        if(gender == "m"){
            if(answer == "y")
                man.push_front(name);
            else
                man.push_back(name);

            if(woman.empty() == false){
                cout<<"Matching Success! "<<man.front()<<"  and  " <<woman.front()<<endl;
                cout<<endl;
                man.pop_front();
                woman.pop_front();
            }
            else{
                cout<<"Can not match! Please Wait" << endl;
                cout<<endl;
            }
        }
        else{
             if(answer == "y")
                woman.push_front(name);
            else
                woman.push_back(name);

            if(man.empty() == false){
                cout<<"Matching Success! "<<man.front()<<"  and  " <<woman.front()<<endl;
                cout<<endl;
                man.pop_front();
                woman.pop_front();
            }
            else{
                cout<<"Can not match! Please Wait" << endl;
                cout<<endl;
            }
        }
        count +=1;
    }

}
