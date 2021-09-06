//        Mayan游戏
//一个模拟程度大于搜索的搜索题……
//大体模拟过程：移动--下降--消除--repeat--到达规定步数判断是否消除完 
//具体剪枝方案luogu上的其他题解都说的比较清楚了。
//不过根据本代码注释也许可以更好理解一些
//***************注意***************
//此代码中行、列指的为输入样例中的行、列，不是指图片中的行、列。 
#include<iostream>
#include<cstring> 
#include<cstdlib>
using namespace std;
int tot;
int a[10][10],b[10][10],num[100],n,ans[10][4];
bool judge()//判断是否全部消除完，只需看最左边一列是否全为0即可。 
{
    for (int i=1;i<=5;++i)
        if (a[i][1]!=0)
            return false;
    return true;
}
void down()//让悬浮的方块下落 
{
    for (int i=1;i<=5;++i)
        for (int j=1;j<=7;++j)
        {
            int x=i,y=j;
            while (a[x][y]!=0&&a[x][y-1]==0&&y-1>=1)
            //如果此方块还悬空就不停降，直到下面有方块或者降到底为止 
            {
                swap(a[x][y],a[x][y-1]);
                --y;
            }
        }
}
void remove()//消除过程 
{
    int i,j;
    down();//因为在dfs中的remove前面移动了方块，所以可能有方块悬空，必须先让所有块下落 
    bool f=false;
    //f是判断此次移动有没有方块消除。
    //如果有的话全部消除完后就要再判断一遍图里有没有新的可以消除的方块，如果有继续remove 
    memset(b,0,sizeof(b));
    for (i=1;i<=5;++i)
        for (j=1;j<=7;++j)
            b[i][j]=a[i][j];//先给a数组存档，不然后面乱换的话就无法回溯到本来的a数组了 
    for (i=1;i<=5;++i)
        for (j=1;j<=7;++j)
        {        
            if (b[i][j]==0)    break;//如果该点为0那么它以及它右边的点都为0，没必要换 
            if (b[i][j]==b[i+1][j]&&b[i+1][j]==b[i-1][j])
            {
                f=true;
                a[i][j]=a[i+1][j]=a[i-1][j]=0; 
            }
            if (b[i][j]==b[i][j+1]&&b[i][j+1]==b[i][j-1])
            {
                f=true;
                a[i][j]=a[i][j+1]=a[i][j-1]=0;
            }    
        }
        //具体解释一下消除部分
        //因为b数组在消除过程中不发生改变，所以我们只要参照b数组
        //看哪个以格子为中心，该格子左右或者上下和该格子相同（可消除），把a中要消的数字变为0即可。
        //若一次消除的格子为连续四个也不影响。具体为什么就不多做解释了，可以想一想 
    if (f)//发生过消除 
    {
        down();//所有方块下落。
        remove();//再消一遍，看能不能继续消除。 
    }
}
void dfs(int step)
{
    int i,j,c[10][10];
    if (step==n+1)//如果步数用完了 
    {
    	tot++;
        if (judge())//如果全部消除掉 
        {
            for (i=1;i<=n;++i)
                cout<<ans[i][1]-1<<' '<<ans[i][2]-1<<' '<<ans[i][3]<<endl;
            cout<<tot<<endl;
			exit(0);//输出结果然后退出整个程序。 
        }
    }
    else
    for (i=1;i<=5;++i)
        for (j=1;j<=7;++j)
        {
            if (a[i][j]==0)    break;//解释同第五十二行 
            for (int k=1;k<=5;++k)for (int l=1;l<=7;++l)c[k][l]=a[k][l];
            //给a数组存档 
            if (!(a[i][j]==a[i+1][j]||i+1>5))
            //1、如果右边的块等于该块那么没有换的必要 
            //2、移动方块操作不能越界 
            {
                swap(a[i][j],a[i+1][j]);
                remove();
                ans[step][1]=i;
                ans[step][2]=j;
                ans[step][3]=1;
                dfs(step+1); 
                for (int k=1;k<=5;++k)for (int l=1;l<=7;++l)a[k][l]=c[k][l];
            }
            //该块向右移
            if(!(a[i-1][j]!=0||i-1<1))
            //1、如果左边的块不为空那么就不换（解释看下面）
            //2、移动方块操作不能越界 
            {
                swap(a[i][j],a[i-1][j]);
                remove();
                ans[step][1]=i;
                ans[step][2]=j;
                ans[step][3]=-1;
                dfs(step+1);
                for (int k=1;k<=5;++k)for (int l=1;l<=7;++l)a[k][l]=c[k][l];
            }
            //该块向左移（只有左边为空时才移动，不然的话该操作等价于左边的块向右移动，重复浪费时间） 
        }
}
int main()
{
    cin>>n;
    for (int i=1;i<=5;++i)
    {
        int nu=0;
        int x;
        cin>>x;
        while (x!=0)
        {
            ++num[x];
            a[i][++nu]=x;
            cin>>x;
        }
    }
    for(int i=1;i<=5;i++){
    	for(int j=1;j<=7;j++){
    		cout<<a[i][j]<<" ";
    	}
    	cout<<endl;
    }
    //此处为读入，不解释 
    dfs(1);//开始搜索 
   cout<<-1;//如果搜索过程中没有“找到结果输出后exit”这一步，就代表无解 
}
