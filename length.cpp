#include<iostream>
#include<stdio.h>
#include<map>
#include<vector>
using namespace std;
vector<string> split(string s)
{
    vector<string> ans;
    string temp="";
    bool flag=false;
    int L=s.size();
    for(int i=0;i<L;i++)
    {
        if(s[i]!=' ')
        {
            if(flag==true){
                temp+=s[i];
            }else{
                temp+=s[i];
                flag=true;
            }
        }else{
            if(flag==true)
            {
                flag=false;
                ans.push_back(temp);
                temp="";
            }else{
                continue;
            }
        }
    }
    if(flag==true)
    {
         ans.push_back(temp);
    }
    return ans;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cout<<"acmhujiafeng@gmail.com"<<endl<<endl;
    string str;
    map<string,double> transMap;
    int i,j;
    while(getline(cin,str))
    {
        if(str.find("=")!=-1)
        {
            string temp="";
            for(i=2;str[i]!=' ';i++)
            temp+=str[i];
            while(!isdigit(str[i])) i++;
            string num="";
            for(j=i;str[j]!=' ';j++)
            num+=str[j];
            transMap[temp]=atof(num.c_str());
            string temp1=temp+"s";
            transMap[temp1]=atof(num.c_str());
            string temp2=temp+"es";
            transMap[temp2]=atof(num.c_str());m
            if(temp=="foot")
            transMap["feet"]=atof(num.c_str());
        }
        else if(str.size()>2)
        {
            double sum=0;
            vector<string> p=split(str);
            int n=p.size();
            int flag=1;
            for(i=0;i<n;i++)
            {
                if(p[i]=="+") {flag=1;continue;}
                if(p[i]=="-") {flag=-1;continue;}
                sum+= flag * atof(p[i].c_str())*transMap[p[i+1]];
                i++;
            }
            printf("%.2lf m\n",sum);

        }

    }
}
