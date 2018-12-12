#include<stdio.h>
#include<stdlib.h>

#define _MAX_X 5
#define _MAX_Y 4

/*�����Թ��ĺ���*/
int draw();

int arr[_MAX_X][_MAX_Y]={0};    //�Թ�ͼ
int endx=3,endy=2;              //Ŀ�ĵ�
int startx=0,starty=0;          //���
int stop[][2]={{0,2},{2,2},{
            3,1},{4,3}};        //�ϰ���
int num=1;
int min=-1;
int next_step[][2]={{0,1},{1,0},{0,-1},{-1,0}};   //���������ĸ�������ƶ�����

void dfs(int x,int y,int step)
{
    int nextx=0,nexty=0;        //��һ��������
    int i=0,j=0;
    arr[0][0]=-1;       //���ԭ��Ϊ�ϰ�����ֹ�������ʱ����

    if(x > _MAX_X || y > _MAX_Y || x < 0 || y < 0){
        return ;
    }

    //DFS��һ�����߽������ж�
    if(x == endx && y == endy){    //����if��ζ��DFS�Ѿ��ҵ��յ�
        if(step < min || min <= 0){
            min = step;
        }
        //��ԭ�����յ�ı��״̬����ʹ��������ȷ����
        arr[0][0]=-3;      
        arr[endx][endy]=-2;
        draw();     
        num=0;      
        return;
    }

    //DFS�ڶ������������п��õ������취
    for(i=0;i < sizeof(next_step)/sizeof(int)/2;++i)
    {
        //������һ�������겢���ж��Ƿ�Խ�����Թ��ı߽�
        nextx = x + next_step[i][0];
        nexty = y + next_step[i][1];
        if(nextx >= _MAX_X || nexty >= _MAX_Y || nextx < 0 || nexty < 0){
            continue;
        }

        //�жϸõ��Ƿ��Ѿ���·����(���Ƿ��Ѿ��߹��ˣ�������������)���Ƿ�Ϊ�ϰ���
        if((arr[nextx][nexty] != -1) && (arr[nextx][nexty] <= 0)){
            arr[nextx][nexty]=num++;     //�õ���ߣ��߹��õ㲢�����Ϊ���߹��ˡ�
            dfs(nextx,nexty,step+1);     //������һ����ȼ�������
            arr[nextx][nexty]=0;         //����һ�е�dfs���أ�������ԭΪδ��״̬
        }
    }
    return;
}

int main(int argc,char *argv[])
{
    int i=0,j=0;
    int step=0;        //��¼���·���Ĳ���

    //Ϊ�ϰ������յ�ȶ�Ӧ������Ԫ�ظ�ֵ
    for(i=0;i < sizeof(stop)/sizeof(int)/2;++i){
        arr[stop[i][0]][stop[i][1]] = -1;            //�ϰ���
    }
    arr[endx][endy]=-2;                              //Ŀ�ĵ�
    arr[startx][starty]=-3;                         //������

    draw();
    dfs(startx,starty,step);

    return 0;
}

int draw()
{
    int i,j;

    //��ӡ�Թ�ͼ
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
