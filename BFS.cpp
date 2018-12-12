#include<stdio.h>
#include<stdlib.h>

#define _MAX_X 5                        //�Թ��Ĵ�С
#define _MAX_Y 4

int arr[_MAX_X][_MAX_Y]={0};            //�Թ���ά����
int endx=3,endy=2;                      //Ŀ�ĵ�
int startx=0,starty=0;                  //���
int stop[][2]={{0,2},{2,2},{3,1},{4,3}};            //�ϰ���
int next_step[][2]={{0,1},{1,0},{0,-1},{-1,0}};     //���������ĸ�����(����仯)

struct point{       //�Թ���ÿһ����
    int x;
    int y;
    int step;       //��ǰ�Ĳ�����ÿһ����չ����1
    int pre;        //��һ���㣬���������ڵĵõ����Թ���·��
};
int head,tail;      //���еĶ�ͷ�Ͷ�β

//ʹ��������ģ����У��ö��д洢�������ʱ������ÿһ����
struct point queue[_MAX_X * _MAX_Y]={0};   

/*�����Թ����ն�*/
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
                    printf("_");//�����ߵĵط�
                    break;
                case -1:
                    printf("X");//�ϰ���
                    break;
                case -2:
                    printf("O");//�յ�
                    break;
                case -3:
                    printf("S");//���
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

//BFS
void bfs()
{
    int i=0;
    int nextx=0,nexty=0;     //��һ���������

    //����Ƿ��ҵ�Ŀ��(���˱���ҵ�Ŀ�����⣬������������while��for����Ƕ�׵�ѭ��)
    int flag = 0;            

    //���е�ͷβ
    head = 0;
    tail = 0;

    //��������
    queue[tail].x = startx;
    queue[tail].y = starty;
    queue[tail].pre = 0;
    queue[tail].step = 1;
    ++tail;                 //�Ƶ���һ���հ�λ��

    while(head < tail)      //�����л����ڵ�û����ɹ������
    {
        for(i=0;i < sizeof(arr)/sizeof(int)/2;++i)
        {
            nextx = queue[head].x + next_step[i][0];
            nexty = queue[head].y + next_step[i][1];

            //�ж���Щ���ǲ������Թ���
            if(nextx < 0 || nexty < 0 || nextx >= _MAX_X || nexty >= _MAX_Y){
                continue;
            }

            //�ж���Щ���Ƿ������(�����ϰ���û���߹�)
            if(arr[nextx][nexty] == 0){
                /*���������Ϊ�Ѿ��߹��ˣ�Ȼ������������;׼���ڵ�ǰ���з�������ɺ�(��forѭ������)������չ(ȥ��һ��εĵ�,������һ��while)*/
                arr[nextx][nexty] = queue[head].step;       //���
                queue[tail].x = nextx;
                queue[tail].y = nexty;
                queue[tail].step = queue[head].step+1;
                queue[tail].pre = head;
                ++tail;             //�ƶ�tail

                //�������������������̿��ӻ���û��ʵ���㷨����
                draw();
                system("pause");
            }

            if(nextx == endx && nexty == endy){
                flag = 1;
                break;
            }
        }/*End for()*/

        if(flag != 0)
            break;
        else
            ++head;         
            //ִ��else�������õ�����з�����������������++head������һ��ȵ�����
    }/*End while()*/
}

int main(int argc,char **argv)
{
    int i=0,j=0;

    //Ϊ�ϰ������յ�ȶ�Ӧ������Ԫ�ظ�ֵ
    for(i=0;i < sizeof(stop)/sizeof(int)/2;++i){
        arr[stop[i][0]][stop[i][1]] = -1;            //�ϰ���
    }
    arr[endx][endy]=-2;                              //Ŀ�ĵ�
    arr[startx][starty]=-3;                         //������

    draw();
    bfs();

    return 0;
}
