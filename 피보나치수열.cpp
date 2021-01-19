#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
//피보나치 수열 출력 및 호출 빈도를 계산한 프로그램 

int fib(int *count, int n){
    count[n]++;
    if(n<2){return n; }
    else{
        return (fib(count, n-1)+fib(count, n-2));
    }

}

int main()
{
    int num;
    cin>> num;
    int *count = new int[num+1];
    for(int i=0; i<num+1; i++)
        count[i] =0;
    fib(count, num);
    for(int i=0; i<num+1; i++)
        printf("Fibo(%d) = %d¹ø\n",i,count[i]);

	return 0;
}
