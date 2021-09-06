//Luogu 3372
#include<iostream>
#include<cstdio>
using namespace std;

const int MAXN=100000;

int n, q;
long long add[4*MAXN+10], s[4*MAXN+10];

void up(int p)
{
    s[p]=s[2*p]+s[2*p+1];
    return;
}

void down(int p, int l, int r)
{
    if (add[p]) {
        add[2*p]+=add[p];
        add[2*p+1]+=add[p];
        int m=(l+r)/2;
        s[2*p]+=(m-l+1)*add[p];
        s[2*p+1]+=(r-m)*add[p];
        add[p]=0;
    }
    return;
}

void build(int p, int l, int r)
{
    add[p]=0;
    if (l==r) {
        scanf("%d",&s[p]);
        return;
    }

    int m=(l+r)/2;
    build(2*p, l, m);
    build(2*p+1, m+1, r);
    up(p);
    return;
}

void update(int p, int l, int r, int x, int y, int v)
{
    if (x<=l && r<=y) {
        add[p]+=v;
        s[p]+=(r-l+1)*v;
        return;
    }

    down(p, l, r);
    int m=(l+r)/2;
    if (x<=m) update(2*p, l, m, x, y, v);
    if (m<y) update(2*p+1, m+1, r, x, y, v);
    up(p);
    return;
}

long long query(int p, int l, int r, int x, int y)
{
    if (x<=l && r<=y) {
        return s[p];
    }

    down(p, l, r);
    int m=(l+r)/2;
    long long ret=0;
    if (x<=m) ret+=query(2*p, l, m, x, y);
    if (m<y) ret+=query(2*p+1, m+1, r, x, y);
    return ret;
}

int main()
{
    cin >> n >> q;
    build(1,1,n);
	update(1,1,n,3,5,1);
	for(int i=1;i<=n*2;i++){
		cout<<s[i]<<" ";
	}
	cout<<endl;
	
  /*  for (int i=1; i<=q; i++) {
        int tmp, a, b, x;
        scanf("%d",&tmp);
        if (tmp==1) {
            scanf("%d%d%d",&a,&b,&x);
            update(1, 1, n, a, b, x);
        }
            else {
                scanf("%d%d",&a,&b);
                cout << query(1, 1, n, a, b) << endl;
            }
    }*/
    return 0;
}
