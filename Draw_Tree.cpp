#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
// 3행의 줄을 가진 같은모양을 순환하여 출력하는 함수(미완성...)


int Left = 0;;
int Right = 40;
int shape[40];

void display(int* s,int left, int right){
    for(int i=left; i<right; i++){
        if(s[i])
            cout<<"X";
        else
            cout<<"-";
    }
    cout<<endl;
}

void draw_tree(int row, int left, int right){
    int center = right/2;
    for(int i=Left; i<Right; i++)
        shape[i]=0;

    if(row==0){
        return ;
    }
    else{
        for(int i=0; i<4-row; i++){
            shape[center] = 1;
            shape[center+Right/2] = 1;
            center = (center*2)+center;
        }
        display(shape, Left, Right);
        draw_tree(row-1,left,right/2);

    }
}

int main()
{
    int row;

    cout<<"How many rows?"<<endl;
    cin>>row;
    draw_tree(row, Left, Right);
	return 0;
}
