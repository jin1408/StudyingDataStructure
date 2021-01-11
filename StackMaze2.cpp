#include <iostream>
#include<fstream>
#include <cstdio>
#include <cstdlib>
#include<stack>
// stack과 이차원 동적 배열을 이용한 미로 탈출 프로그램

using namespace std;

class Location{
public:
    int row;
    int col;
    Location(int r=0, int c=0){
        row =r;
        col = c;
    }
    bool isNeighbor(Location &p){
        return ((row==p.row && (col ==p.col +1 || col ==p.col-1)) ||
                    (col==p.col && (row==p.row-1 || row==p.row+1)));
    }
    bool operator==(Location &p){return row==p.row && col==p.col;}
};

class Maze{
    int width;
    int height;
    int** map;
    stack<Location> locStack;
    Location Exit;
public:
    Maze(){init(0,0); }
    ~Maze(){reset(); }
    void init(int w, int h){
        map = new int*[h];
        for(int i=0; i<h; i++)
            map[i] = new int[w];

    }

    void reset(){
        for(int i=0; i<height; i++)
            delete[] map[i];
        delete[] map;
    }

    void load(char *fname){
        ifstream fin(fname, ios::in);
        fin>>width>>height;
        init(width,height);
        int temp;
        for(int i=0; i<height; i++){
            for(int j=0;j<width; j++){
                fin>>temp;
                map[i][j] = temp;
                if(map[i][j] ==5){
                    Location entry(j,i);
                    locStack.push(entry);
                }
                else if(map[i][j] == 9){
                    Exit.col = i;
                    Exit.row = j;
                }
            }
        }
        fin.close();
    }

    bool isValid(int r, int c){
    if(r<0 || c<0 || r>=20 || c>=10)
        return false;
    else
        return (map[c][r] == 1 || map[c][r] == 9);
    }

    void print(){
        cout<<"전체 미로의 크기 = "<<width<<" X " <<height<<endl;
        for(int i=0; i<height; i++){
            for(int j=0; j<width; j++){
                if(map[i][j] ==1)
                    cout<<"  ";
                else if(map[i][j] ==0)
                    cout<<"■";
                else if(map[i][j] ==7)
                    cout<<"□";
                else if(map[i][j] ==5)
                    cout<<"○";
                else if(map[i][j] ==9)
                    cout<<"★";
            }
            cout<<endl;
        }
        cout<<endl;
    }

    void searchExit(){
        while(locStack.empty() == false){
            Location here = locStack.top();
            locStack.pop();

            int r = here.row;
            int c = here.col;
            map[c][r] = 7;

           if (Exit.col==c && Exit.row==r)
                  return;
           else{
                  map[c][r] = 7;
                  if (isValid(r - 1, c))
                    locStack.push(Location(r - 1, c));
                  if (isValid(r + 1, c))
                    locStack.push(Location(r + 1, c));
                  if (isValid(r, c - 1))
                    locStack.push(Location(r, c-1));
                  if (isValid(r, c + 1))
                    locStack.push(Location(r, c + 1));
            }
        }
    }
};

int main()
{
    Maze maze;
    maze.load("C:\\Maze.txt");
    maze.print();
    maze.searchExit();
    maze.print();
    return 0;
}
