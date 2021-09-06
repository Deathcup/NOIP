 #include<cstdio>
 #include<vector>
 #include<cstring>
 using namespace std;
 #define N 2001
 vector<int>G[N<<2];
 typedef vector<int>::iterator ITER;
 int mat[N<<2];
 bool vis[N<<2];
 int n,x,y;
 bool dfs(int U)
 {
     for(ITER it=G[U].begin();it!=G[U].end();it++)
       if(!vis[*it])
         {
           vis[*it]=1;
           if(mat[*it]==-1||dfs(mat[*it]))
             {
               mat[*it]=U;
               return 1;
             }
         }
       return 0;
 }
 int max_match()
 {
     memset(mat,-1,sizeof(mat)); int res=0;
     for(int i=1;i<=(n<<1);i++)
       {
         memset(vis,0,sizeof(vis));
         if(dfs(i)) res++;
       }
     return res;
 }
 int main()
 {
     scanf("%d",&n);
     for(int i=1;i<=(n<<1);i++)
       {
         scanf("%d%d",&x,&y);
         G[i+(n<<1)].push_back(x);
         G[i+(n<<1)].push_back(x+n);
         G[i+(n<<1)].push_back(y);
         G[i+(n<<1)].push_back(y+n);
         G[x].push_back(i+(n<<1));
         G[x+n].push_back(i+(n<<1));
         G[y].push_back(i+(n<<1));
         G[y+n].push_back(i+(n<<1));
       }
     printf("%d\n",max_match());
     for(;;);
     return 0;
 }
