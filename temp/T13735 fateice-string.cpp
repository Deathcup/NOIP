#include<bits/stdc++.h>
using namespace std;
string a,b;
int T,i,j,lena,lenb,k,p,o,u;
int main(){
	cin>>T;
	while(T--){
		cin>>a>>b;
		bool cc=1;
		lena=a.length()-1;
		lenb=b.length()-1;
		i=0;j=0;
		while(1){
			if(a[i]!=b[j]){
				if(a[i]!='*'){
					cc=0;break;
				}
				else{
					k=i;
					while(a[k]=='*'&&k>=1) k--;
					if(k==-1){
						p=i;
						while(a[p]=='*'&&p<=lena) p++;
						if(p>lena){
							cc=0;break;
						}
						else if(a[p]==b[j]){
							i=p;j++;
							continue;
						}
					}
					else{
						p=i;
						while(a[p]=='*'&&p<=lena) p++;
						if(p>lena){
							if(a[k]!=b[j]){
								cc=0;break;
							}
							else{
								bool flag=1;
								while(j<=lenb){
									if(b[j]!=a[k]){
										flag=0;break;
									}
									j++;
								}
								if(flag==1) break;
								else {
									cc=0;break;
								}
							}
						}
						else{
							if(a[k]==a[p]&&a[p]==b[j]){
								o=1;
								while(a[p+1]==a[k]) o++;
								u=1;
								while(b[j+u]==a[k]) u++;
								if(o-1>u){
									cc=0;break;
								}
								else{
									i=o;j=u;
									continue;
								}	
							}
							if(a[k]!=b[j]&&a[p]==b[j]){
								o=1;
								while(a[p+1]==a[k]) o++;
								u=1;
								while(b[j+u]==a[k]) u++;
								if(o-1!=u){
									cc=0;break;
								} 
							}
							if(a[k]!=b[j]&&a[p]!=b[j]){
								cc=0;
								break;
							}
						}
					}
				}
			}
			else{
				i++;j++;
				continue;
			}
		}
	if(cc==0) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;		
	}
	

}
