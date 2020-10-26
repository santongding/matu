#include<iostream>

using namespace std;

int climbstairs(int n)

{
    int f0=1,f1=1;
    for(int i=2;i<=n;i++){
        int f2=f1+f0;
        f0=f1;
        f1=f2;
    }
    return f1;
}

int main()

{

int n;

cin >> n;

cout << climbstairs(n) << endl;

return 0;

}
