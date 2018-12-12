#include<stdio.h>
#include<stdlib.h>

#define _MAX_X 5
#define _MAX_Y 4

/*绘制迷宫的函数*/
int draw();

int arr[_MAX_X][_MAX_Y]={0};    //迷宫图
int endx=3,endy=2;              //目的地
int startx=0,starty=0;          //起点
int stop[][2]={{0,2},{2,2},{
            3,1},{4,3}};        //障碍物
int num=1;
int min=-1;
int next_step[][2]={{0,1},{1,0},{0,-1},{-1,0}};   //上下左右四个方向的移动方向

void dfs(int x,int y,int step)
{
    int nextx=0,nexty=0;        //下一步的坐标
    int i=0,j=0;
    arr[0][0]=-1;       //标记原点为障碍，防止深度搜索时回溯

    if(x > _MAX_X || y > _MAX_Y || x < 0 || y < 0){
        return ;
    }

    //DFS第一步，边界条件判断
    if(x == endx && y == endy){    //进入if意味着DFS已经找到终点
        if(step < min || min <= 0){
            min = step;
        }
        //还原起点和终点的标记状态，以使它们能正确绘制
        arr[0][0]=-3;      
        arr[endx][endy]=-2;
        draw();     
        num=0;      
        return;
    }

    //DFS第二步，尝试所有可用的搜索办法
    for(i=0;i < sizeof(next_step)/sizeof(int)/2;++i)
    {
        //计算下一步的坐标并且判断是否越出了迷宫的边界
        nextx = x + next_step[i][0];
        nexty = y + next_step[i][1];
        if(nextx >= _MAX_X || nexty >= _MAX_Y || nextx < 0 || nexty < 0){
            continue;
        }

        //判断该点是否已经在路径中(即是否已经走过了，不能再往回走)或是否为障碍物
        if((arr[nextx][nexty] != -1) && (arr[nextx][nexty] <= 0)){
            arr[nextx][nexty]=num++;     //该点可走，走过该点并标记它为‘走过了’
            dfs(nextx,nexty,step+1);     //进入下一级深度继续搜索
            arr[nextx][nexty]=0;         //从上一行的dfs返回，将它还原为未走状态
        }
    }
    return;
}

int main(int argc,char *argv[])
{
    int i=0,j=0;
    int step=0;        //记录最短路径的步数

    //为障碍物、起点终点等对应的数组元素赋值
    for(i=0;i < sizeof(stop)/sizeof(int)/2;++i){
        arr[stop[i][0]][stop[i][1]] = -1;            //障碍物
    }
    arr[endx][endy]=-2;                              //目的地
    arr[startx][starty]=-3;                         //出发点

    draw();
    dfs(startx,starty,step);

    return 0;
}

int draw()
{
    int i,j;

    //打印迷宫图
    putchar('\n');
    for(i=0;i<_MAX_X;++i){
        for(j=0;j<_MAX_Y;++j)
        {
            switch(arr[i][j]){
                case 0:
                    printf("_");
                    break;
                case -1:
                    printf("X");
                    break;
                case -2:
                    printf("O");
                    break;
                case -3:
                    printf("S");
                    break;
                default:
                    printf("%d",arr[i][j]);
                    break;
            }
            printf("|");
        }
        printf("\n");
    }
    putchar('\n');
	return 0;
}
