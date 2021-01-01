/// We just use this header file for fun.............



void image()
{
    char msg[]="TEAM_PEGASUS";
    initwindow(13690,710,msg);
    readimagefile("a.jpg",0,0,1360,710);
    settextstyle(1,HORIZ_DIR,6);
    char m[]="TEAM_PEGASUS";
    setcolor(BLUE);
    setbkcolor(WHITE);
    outtextxy(360,450,m);
    settextstyle(1,HORIZ_DIR,5);
    char n[]="Md. Asfakur Rahat";
    outtextxy(410,500,n);
    char namu[]="Mahjabin Namira Mazumder";
    outtextxy(285,540,namu);
    char r[]="Nazmur Raihan";
    outtextxy(450,580,r);
    delay(1000);
    closegraph();
}

void Exit()
{
    char msg[]="TEAM_PEGASUS";
    initwindow(1360,710,msg);
    readimagefile("d.jpg",0,0,1360,710);
    delay(2000);
    closegraph();
    system("CLS");
    exit(0);
}
