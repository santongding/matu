#include<iostream>
#include<map>
#include<string>
using namespace std;
class User{
public:
    map<string,string>mp;
    User(char *s,char *ss){
        mp[string(s)]=string(ss);
    }
    void AddUser(char *s,char *ss){
        mp[string(s)]=string(ss);
    }
    int login(char *s,char *ss){
        if(mp[string(s)]==string(ss))return 0;
        else return -1;
    }
};

int main(){
	char name[10],name1[10],pass[10],pass1[10];
	cin>>name>>pass>>name1>>pass1;
	User user("LiWei","liwei101");
	user.AddUser(name,pass);
	if (user.login(name1,pass1) >=0)
	{
		cout<<"Success Login!"<<endl;
	}
	else{
		cout<<"Login failed!"<<endl;
	}
	  return 0;
}
