#include <iostream>
#include <stdio.h>
using namespace std;
int i=0,s=0;
int f(int n){
    if(i<n){
        i++;
        s=s+i;
        f(s);

    }

    return s;
}

int main(){
    cout<<f(5);

    return 0;
    }