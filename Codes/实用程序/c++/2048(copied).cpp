#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>
using namespace std;
int a[6][6],score;
void print()
{
    printf("score:%d\n",score);
    for(int i=1;i<=4;i++)
    {
        printf("++======++======++======++======++\n");
        printf("||      ||      ||      ||      ||\n");
        for(int j=1;j<=4;j++)
        {
            if(a[i][j]>0)
            {
                printf("||%6d",a[i][j]);
            }
            else if(a[i][j]<0)
            {
                printf("||    x%d",-a[i][j]);
            }
            else
            {
                printf("||      ");
            }
        }
        printf("||\n");
        printf("||      ||      ||      ||      ||\n");
    }
    printf("++======++======++======++======++\n");
    return;
}
void fun()
{
    srand((unsigned)time(NULL));
    int x=rand()%4+1,y=rand()%4+1,z=rand()%10000+1;
    while(a[x][y]!=0)
    {
        x=rand()%4+1;
        y=rand()%4+1;
    }
    if(z<=6000)
    {
        a[x][y]=2;
    }
    else if(z<=7500)
    {
        a[x][y]=4;
    }
    else if(z<=9000)
    {
        a[x][y]=-1;
    }
    else
    {
        a[x][y]=-2;
    }
    return;
}
bool win()
{
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            if(a[i][j]==65536)
            {
                return true;
            }
        }
    }
    return false;
}
bool lose()
{
    for(int i=1;i<=4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            if(a[i][j]==0)
            {
                return false;
            }
        }
    }
    int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};
    for(int i=0;i<4;i++)
    {
        for(int j=1;j<=4;j++)
        {
            for(int k=1;k<=4;k++)
            {
                if(a[j][k]==a[j+dx[i]][k+dy[i]]&&a[j][k]!=-4||a[j][k]*a[j+dx[i]][k+dy[i]]<0)
                {
                    return false;
                }
            }
        }
    }
    return true;
}
void game()
{
    fun();
    fun();
    print();
    while(1)
    {
        char ch=getch();
        if(ch=='w')
        {
            bool book=0;
            for(int i=1;i<=4;i++)
            {
                int x=0;
                for(int j=1;j<=4;j++)
                {
                    if(a[j][i]!=0)
                    {
                        if(x==0)
                        {
                            x=j;
                        }
                        else
                        {
                            if(a[x][i]==a[j][i]&&a[x][i]!=-4)
                            {
                                a[x][i]*=2;
                                a[j][i]=0;
                                score+=a[x][i];
                                j=x+1;
                                x=0;
                                book=1;
                            }
                            if(a[x][i]*a[j][i]<0&&x+1==j&&a[x][i]*-a[j][i]<=65536)
                            {
                                bool flag=1;
                                for(int k=1;k<=x;k++)
                                {
                                    if(a[k][i]==0)
                                    {
                                        flag=0;
                                    }
                                }
                                if(flag==1)
                                {
                                    a[x][i]*=-a[j][i];
                                    a[j][i]=0;
                                    score+=a[x][i];
                                    j=x+1;
                                    x=0;
                                    book=1;
                                }
                            }
                            x=j;
                        }
                    }
                }
                for(int j=2;j<=4;j++)
                {
                    if(a[j][i]!=0)
                    {
                        for(int k=j-1;k>=1;k--)
                        {
                            if(a[k][i]!=0)
                            {
                                break;
                            }
                            a[k][i]=a[k+1][i];
                            a[k+1][i]=0;
                            book=1;
                        }
                    }
                }
            }
            if(book==1)
            {
                fun();
            }
        }
        if(ch=='s')
        {
            bool book=0;
            for(int i=1;i<=4;i++)
            {
                int x=0;
                for(int j=4;j>=1;j--)
                {
                    if(a[j][i]!=0)
                    {
                        if(x==0)
                        {
                            x=j;
                        }
                        else
                        {
                            if(a[x][i]==a[j][i]&&a[x][i]!=-4)
                            {
                                a[x][i]*=2;
                                a[j][i]=0;
                                score+=a[x][i];
                                j=x-1;
                                x=0;
                                book=1;
                            }
                            if(a[x][i]*a[j][i]<0&&x-1==j&&a[x][i]*-a[j][i]<=65536)
                            {
                                bool flag=1;
                                for(int k=x;k<=4;k++)
                                {
                                    if(a[k][i]==0)
                                    {
                                        flag=0;
                                    }
                                }
                                if(flag==1)
                                {
                                    a[x][i]*=-a[j][i];
                                    a[j][i]=0;
                                    score+=a[x][i];
                                    j=x-1;
                                    x=0;
                                    book=1;
                                }
                            }
                            x=j;
                        }
                    }
                }
                for(int j=3;j>=1;j--)
                {
                    if(a[j][i]!=0)
                    {
                        for(int k=j+1;k<=4;k++)
                        {
                            if(a[k][i]!=0)
                            {
                                break;
                            }
                            a[k][i]=a[k-1][i];
                            a[k-1][i]=0;
                            book=1;
                        }
                    }
                }
            }
            if(book==1)
            {
                fun();
            }
        }
        if(ch=='a')
        {
            bool book=0;
            for(int i=1;i<=4;i++)
            {
                int x=0;
                for(int j=1;j<=4;j++)
                {
                    if(a[i][j]!=0)
                    {
                        if(x==0)
                        {
                            x=j;
                        }
                        else
                        {
                            if(a[i][x]==a[i][j]&&a[i][x]!=-4)
                            {
                                a[i][x]*=2;
                                a[i][j]=0;
                                score+=a[i][x];
                                j=x+1;
                                x=0;
                                book=1;
                            }
                            if(a[i][x]*a[i][j]<0&&x+1==j&&a[i][x]*-a[i][j]<=65536)
                            {
                                bool flag=1;
                                for(int k=1;k<=x;k++)
                                {
                                    if(a[i][k]==0)
                                    {
                                        flag=0;
                                    }
                                }
                                if(flag==1)
                                {
                                    a[i][x]*=-a[i][j];
                                    a[i][j]=0;
                                    score+=a[i][x];
                                    j=x+1;
                                    x=0;
                                    book=1;
                                }
                            }
                            x=j;
                        }
                    }
                }
                for(int j=2;j<=4;j++)
                {
                    if(a[i][j]!=0)
                    {
                        for(int k=j-1;k>=1;k--)
                        {
                            if(a[i][k]!=0)
                            {
                                break;
                            }
                            a[i][k]=a[i][k+1];
                            a[i][k+1]=0;
                            book=1;
                        }
                    }
                }
            }
            if(book==1)
            {
                fun();
            }
        }
        if(ch=='d')
        {
            bool book=0;
            for(int i=1;i<=4;i++)
            {
                int x=0;
                for(int j=4;j>=1;j--)
                {
                    if(a[i][j]!=0)
                    {
                        if(x==0)
                        {
                            x=j;
                        }
                        else
                        {
                            if(a[i][x]==a[i][j]&&a[i][x]!=-4)
                            {
                                a[i][x]*=2;
                                a[i][j]=0;
                                score+=a[i][x];
                                j=x-1;
                                x=0;
                                book=1;
                            }
                            if(a[i][x]*a[i][j]<0&&x-1==j&&a[i][x]*-a[i][j]<=65536)
                            {
                                bool flag=1;
                                for(int k=x;k<=4;k++)
                                {
                                    if(a[i][k]==0)
                                    {
                                        flag=0;
                                    }
                                }
                                if(flag==1)
                                {
                                    a[i][x]*=-a[i][j];
                                    a[i][j]=0;
                                    score+=a[i][x];
                                    j=x-1;
                                    x=0;
                                    book=1;
                                }
                            }
                            x=j;
                        }
                    }
                }
                for(int j=3;j>=1;j--)
                {
                    if(a[i][j]!=0)
                    {
                        for(int k=j+1;k<=4;k++)
                        {
                            if(a[i][k]!=0)
                            {
                                break;
                            }
                            a[i][k]=a[i][k-1];
                            a[i][k-1]=0;
                            book=1;
                        }
                    }
                }
            }
            if(book==1)
            {
                fun();
            }
        }
        if(win())
        {
            printf("win!\n");
            system("pause");
            system("cls");
            return;
        }
        if(lose())
        {
            system("cls");
            print();
            printf("lose!\n");
            system("pause");
            system("cls");
            return;
        }
        system("cls");
        print();
    }
    return;
}
int main()
{
    SetConsoleTitle("2048");
    ShowWindow(GetForegroundWindow(),SW_MAXIMIZE);
    printf("\n\n");
    printf("2048\n\n");
    printf("作者：席芳隆\n\n");
    system("pause");
    system("cls");
    while(1)
    {
        int cho;
        game();
        printf("还想再玩一局吗？（想输入1，不想输入0）：\n\n");
        scanf("%d",&cho);
        while(cho!=1&&cho!=0)
        {
            system("cls");
            printf("\n\n");
            printf("数据超出限定，请重新输入（想输入1，不想输入0）：\n\n");
            scanf("%d",&cho);
        }
        if(cho==0)
        {
            break;
        }
        system("cls");
    }
    return 0;
}
