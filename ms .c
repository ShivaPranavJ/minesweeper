#include<stdio.h>
#include<graphics.h>
#include<conio.h>

int i, j,cnt=0, m, n, sc=0, x=150,y=150;
int bomb [41[4] =(0), disp[4][4]=(0), score[4][4]={0};
char *ch;

void reinitiate()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm, "C:\\turbo3\\bgi");
    setbkcolor(BLUE);
}

void displaybomb()
{
    x=150,y=300;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
           printf (ch, "%d", bomb[i][j]);
           setfillstyle (SOLID_FILL, GREEN);
           rectangle(x,y,x+30,y+30);
           floodfill(x+1,y+1,WHITE);
           if (bomb[i][j]!=0)
           setcolor(RED);
           outtextxy(x+10,y+10,ch);
           setcolor (WHITE);
           x+=30;
        }
    }
    x=150; y+=30;
}

void placebomb ()
{
    bomb[0][3]=1;
    bomb[1][1]=1;
    bomb[3][2]=1;
    bomb[2][0]=1;
}
void placescore()
{
    score[0][0]=1; score[1][0]=1; score[2][3]=1;
    score[0][1]=4; score[0][2]=1; score[1] [3]=2;
    score[2][1]=4; score[3][0]=4; score[3][1]=3;
    score[1][2]=2; score[2][2]=1; score[3][3]=1;
}

void dispmat()
{
    x=150,y=100;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            sprintf (ch, "%d",disp[i][j]);
            setfillstyle (SOLID FILL, GREEN);
            rectangle(x,y,x+30,y+30);
            floodfill(x+1,y+1, WHITE);
            if(disp[i][j]!=0)
            setcolor(RED);
            outtextxy(x+15,y+15,ch);
            setcolor(WHITE);
            x+=30;
        }
        x=150;
        y+=30;
    }
}

void checkuser()
{
    printf("%\n Welcome to Minesweeper Game");
    printf("%\n Enter the cordinates : ");
    scanf ("%d %d",&m,&n);
    if (bomb[m][n]==1)
    {
        settextstyle(1,0,1);
        outtextxy(10,250, "You pressed a mine!!! GAME OVER " );
        outtextxy(10,270, "Mine Sweeper Layout" );
        displaybomb();
    }
    else
    {
        cnt++;
        sc=sc+score[m][n];
        disp[m][n]=score[m][n];
        cleardevice();
        reinitiate();
        dispmat();
        printf ("Now, Your score is: %d",sc);
    if(cnt<12)
        checkuser();
    else
        outtextxy(x+4,y+4,"\n Congratulations you have won");
}
}

void main()
{
    int errorcode;
    reinitiate();
    errorcode=graphresult();
    if (errorcode==grOk)
    {
        placebomb();
        placescore();
        dispmat();
        checkuser();
    }
    getch();
}
