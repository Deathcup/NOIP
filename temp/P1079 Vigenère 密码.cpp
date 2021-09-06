#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char k[1010],s[1010];
char ans[1010];
int len1,len2;
int main()
{
    cin>>k>>s;
    len1=strlen(k);
    len2=strlen(s);
    if(len1<len2)
        for(int i=len1;i<len2;i++)    k[i]=k[i-len1];
    for(int i=0,j;i<len2;i++)
    {
        if(k[i]>='A'&&k[i]<='Z')    j=k[i]-'A';
        if(k[i]>='a'&&k[i]<='z')    j=k[i]-'a';
        ans[i]=s[i]-j;
        if(s[i]>='A'&&s[i]<='Z')
            if(ans[i]<'A')    ans[i]+=26;
        if(s[i]>='a'&&s[i]<='z')
            if(ans[i]<'a')    ans[i]+=26;
    }
    for(int i=0;i<len2;i++)    cout<<ans[i];
    cout<<endl;
    return 0;
}
