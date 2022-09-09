#include<iostream>
using namespace std;

const int N =100;    //城市个数
const int INF =1e7;
int map[N][N];    //地图对应的带权链接矩阵
int dist[N];      //记录源点u到某顶点的最短路径长度
int p[N];         //记录源点到某顶点的最短路径上的该顶点的前一个顶点
int n=5,m=11;        //n城市的个数，m城市间路线的条数
bool flag[N];        //true说明顶点i已经加入到集合s

void Dijkstra(int n);

int main()
{
    int u,v,w,st;
    system("color 0d");
    cout<<"请输入城市间的路线及距离："<<endl;
    for(int i=1;i<n;i++){//初始化图的邻接矩阵
        for(int j=1;j<n;j++){
            map[i][j]=INF;//初始化邻接矩阵为无穷大
        }
    }
    while(m--){
        cin>>u>>v>>w;
        map[u][v]=min(map[u][v],w);//邻接矩阵储存，保留最小的距离
    }
    cout<<"请输入起始位置"<<endl;
        cin>>st;
        Dijkstra(st);
        return 0;
}

void Dijkstra(int u){
    for(int i=1;i<=n;i++){
        dist[i]=map[u][i];//初始化点u到其他各个顶点的最短路径长度
        flag[i]=false;
        if(dist[i]==INF){
            p[i]=-1;//源点u到顶点的路径长度为无穷大，说明顶点i与源点u不相邻
        }
        else{
            p[i]=u;
        }
    }
    dist[u]=0;
    flag[u]=true;//初始时，集合s中只有一个元素：源点u
    for(int i=1;i<=n;i++){
        int temp=INF,t=u;
        for(int j=1;j<=n;j++){  //在集合V-S中寻找距离远点u最近的顶点t
            if(!flag[j]&&dist[j<temp]){
                t=j;
                temp=dist[j];
            }
            if(t==u){   //找不到t，跳出循环
                return ;
            }
            flag[t]=true;  //将t加入集合V
            for(int j=1;j<=n;j++){
                if(!flag[j]&&map[t][j]<INF){
                    dist[j]=dist[t]+map[t][j];
                    p[j]=t;
                }
            }
        }
    }
}


