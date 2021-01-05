#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

const int MAZE_SIZE = 6;
char map[MAZE_SIZE][MAZE_SIZE] = {
    {'1','1','1','1','1','1'},
    {'e','0','1','0','0','1'},
    {'1','0','0','0','1','1'},
    {'1','0','1','0','1','1'},
    {'1','0','1','0','0','x'},
    {'1','1','1','1','1','1'},
};

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

bool isValid(int r, int c){
    if(r<0 || c<0 || r>=MAZE_SIZE || c>=MAZE_SIZE)
        return false;
    else
        return map[r][c] == '0' || map[r][c] == 'x';
}

int main()
{
    deque<Location> locQueue;
    Location entry(1,0);
    locQueue.push_front(entry);

    while(locQueue.empty() == false){
        Location here = locQueue.front();
        locQueue.pop_front();

        int r = here.row;
        int c = here.col;
        cout << "(" << r <<"," <<c<<")"<<endl;
        if(map[r][c] == 'x'){
            cout<< "Escape Success";
            return 0;
        }
        else{
            map[r][c] = '.';
            if(isValid(r-1,c)) locQueue.push_front(Location(r-1,c));
            if(isValid(r+1,c)) locQueue.push_front(Location(r+1,c));
            if(isValid(r,c+1)) locQueue.push_front(Location(r,c+1));
            if(isValid(r,c-1)) locQueue.push_front(Location(r,c-1));
        }
    }
    cout <<"Escape Failed";
}
