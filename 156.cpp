#include <iostream>
#include<cstring>
using namespace std;
class String{
protected:
	char *mystr;
	int len;
public:
	String(const char *p){
		len = strlen(p);
		mystr = new char[len+1];
		strcpy(mystr,p);
	}
	~String(){
		if (mystr !=NULL)
		{
			delete []mystr;
			mystr = NULL;
			len = 0;
		}
	}
	void showStr(){cout <<mystr;}
	char * GetStr(){return mystr;}
	virtual bool IsSubString(const char *str){
		int i,j;
		for (i =0;i<len;i++)
		{
			int k = i;
			for (j =0;str[j] !='\0';j++,k++)
			{
				if (str[j]!= mystr[k]) break;
			}
			if(str[j] =='\0') return true;
		}
		return false;
	}
};

class EditString:public String{
public:
	EditString(const char *p):String(p){}
	int IsSubString(int start, const char *str);
	void EditChar(char s, char d);
	void EditSub(char * subs,char *subd);

	void DeleteChar(char ch);
	void DeleteSub(char * sub);

};
//#include<CString.h>
int EditString::IsSubString(int start,const char *str){
    int slen=strlen(str);
    for(int i=start;i<len-slen+1;i++){
        for(int j=0;j<slen;j++){
            if(mystr[i+j]!=str[j])break;
            if(j==slen-1)return i;
        }

    }
    return -1;
}
void EditString::EditChar(char s, char d){
    for(int i=0;i<len;i++){
        if(mystr[i]==s)mystr[i]=d;
    }
}
void EditString::EditSub(char * subs,char *subd){
    int bg;
    while((bg=IsSubString(0,subs))!=-1){
     //   cout<<bg<<endl;
        int nlen=len+strlen(subd)-strlen(subs);
        char *nstr=new char[nlen+1];
        memset(nstr,0,sizeof(char)*(nlen+1));
        memcpy(nstr,mystr,sizeof(char)*bg);
    //    cout<<nstr<<endl;
        strcpy(nstr+bg,subd);
        strcpy(nstr+bg+strlen(subd),mystr+bg+strlen(subs));
        delete[]mystr;
        mystr=nstr;
     //   exit(0);
    }
 //   cout<<bg<<endl;
}
void EditString::DeleteChar(char ch){
    char s[2];
    s[0]=ch;
    s[1]=0;
    EditSub(s,"");
}
void EditString::DeleteSub(char * sub){
    EditSub(sub,"");
}
int main(){
   // EditString es("testtesttest");
  //  cout<<es.IsSubString(3,"test");
  //  EditString es("testtesttest");
   EditString es("testtesttest");
    es.EditSub("test","str");//"strstrstr"
    es.showStr();
}
