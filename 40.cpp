

#include<iostream>
using namespace std;
void * reversememcpy ( void * destination, const void * source, int num ){
    if(destination==NULL||source==NULL||num<0){
        cout<<"error";
    }else{
    char *p=(char *)destination,*s=(char *)source;
    if((p>=s&&s+num>=p)||(p<=s&&p+num>=s)){
        cout<<"error";

    }else{
    for(int i=0;i<num;i++){
        p[i]=s[num-i-1];
    }
    }
    }
    return destination;
}
