#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
// 문자열을 입력받아 거꾸로 출력하는 
void reverse(string w, int len){
    if(len == -1){
        return ;
    }
    else{
        cout<<w.at(len);
        return reverse(w, len-1);
    }


}

int main()
{
    string word;
    cin>>word;
    int len = word.length();
    reverse(word, len-1);
	return 0;
}
