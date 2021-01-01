/// We define this header file only for see the total result of the institute.........



/// this function is only accessible by Admin.........
void result_of_bubt()
{
    system("CLS");
    window2();
    print_heading(73," Total Result  Sheet ");

    for(i = 23; i <=120+23; i++){
            if(i==23){
                gotoxy(i,10);
                printf("%c",204);
            }
            else if(i==143){
                gotoxy(i,10);
                printf("%c",185);
            }
            else{
        gotoxy(i,10);
        printf("%c",205);///for middle horizontal line....
            }
    }
    for(i=37;i<135;i+=15){
        if(i==132)
            i--;
        gotoxy(i,10);
        printf("%c",203);
        if(i==97)
            i+=5;
    }
    gotoxy(23,11);printf("%c",186);
    gotoxy(23,12);printf("%c",186);
    gotoxy(143,11);printf("%c",186);
    gotoxy(143,12);printf("%c",186);
    for(i=37;i<135;i+=15){
        if(i==132)
            i--;
        gotoxy(i,11);
        printf("%c",186);
        if(i==97)
            i+=5;
    }
    for(i = 23; i <=120+23; i++){
            if(i==23){
                gotoxy(i,12);
                printf("%c",204);
            }
            else if(i==143){
                gotoxy(i,12);
                printf("%c",185);
            }
            else{
        gotoxy(i,12);
        printf("%c",205);///for middle horizontal line....
            }
    }
    for(i=37;i<135;i+=15){
        if(i==132)
            i--;
        gotoxy(i,12);
        printf("%c",206);///plus line...
        if(i==97)
            i+=5;
    }
    SetColor(45);
    int x=11;
    gotoxy(27,x);printf("   ID   ");
    gotoxy(41,x);printf("SUBJECT");
    gotoxy(55,x);printf("MID EXAM");
    gotoxy(70,x);printf("FINAL EXAM");
    gotoxy(85,x);printf("ATTENDANCE");
    gotoxy(99,x);printf("CT & ASSIGNMENTS");
    gotoxy(122,x);printf("TOTAL");
    gotoxy(135,x);printf("GRADE");
    int ka=14,me=13;int sub=0;

    ft=fopen("record teacher.txt","rb+");
    char S[15];
    while(fread(&th,sizeof(th),1,ft)==1){
            fp=fopen("marks.txt","rb+");
            memset(&S[0],0,sizeof(S));
            strcpy(S,th.sub);
        while(fread(&mr,sizeof(mr),1,fp)==1){
            if(strcmp(S,mr.sub)==0){
                SetColor(45);
                gotoxy(25,me);printf("%s",mr.id);
                gotoxy(42,me);printf("%s",mr.sub);
                gotoxy(58,me);printf("%0.2f",mr.mid_marks);
                gotoxy(73,me);printf("%0.2f",mr.final_marks);
                gotoxy(89,me);printf("%0.0f",mr.attend);
                gotoxy(105,me);printf("%0.2f",mr.assignment);
                gotoxy(122,me);printf("%0.2f",mr.total);
                char a[5];memset(&a[0],0,sizeof(a));
                strcpy(a,mr.grade);
                int no=0;no=strlen(a);
                if(no==1){
                    gotoxy(137,me);printf("%s",mr.grade);
                }
                else if(no==2){
                    gotoxy(136,me);printf("%s",mr.grade);
                }
                    sub++;
            SetColor(1);
            for(i = 23; i <=120+23; i++){
                if(i==23){gotoxy(i,ka);printf("%c",204);}
                else if(i==143){gotoxy(i,ka);printf("%c",185);}
                else{gotoxy(i,ka);printf("%c",205);}
            }
            for(i=37;i<135;i+=15){
                if(i==132)
                i--;
                gotoxy(i,ka-1);
                printf("%c",186);
                gotoxy(i,ka);
                printf("%c",206);///plus line...
                if(i==97)
                i+=5;
            }
            gotoxy(23,ka-1);printf("%c",186);
            gotoxy(143,ka-1);printf("%c",186);
            ka+=2;
            me+=2;
        }
    }
        fclose(fp);
}
        fclose(ft);
        if(sub==0){
            SetColor(45);gotoxy(67,ka+1);printf("\xdb\xb2 No result is Published yet!");
        SetColor(1);
        gotoxy(71,ka+5);printf("\xdb\xb2 Press 0 to continue--->>>");
        }
        else{
        SetColor(1);
        gotoxy(71,ka+5);printf("\xdb\xb2 Press 0 to continue--->>>");}
        ka-=2;
            for(i = 23; i <=120+23; i++){
                if(i==23){gotoxy(i,ka);printf("%c",204);}
                else if(i==143){gotoxy(i,ka);printf("%c",185);}
                else{gotoxy(i,ka);printf("%c",205);}
            }
            for(i=37;i<135;i+=15){
                if(i==132)
                i--;
            gotoxy(i,ka);
            printf("%c",202);
            if(i==97)
                i+=5;
        }
        ka++;
        for(i=ka;i<ka+10;i++){
            gotoxy(23,i);
            printf("%c",186);
            gotoxy(143,i);
            printf("%c",186);
        }
        ka=i;
        for(i=23;i<144;i++){
            if(i==23){gotoxy(i,ka);printf("%c",200);}
            else if(i==143){gotoxy(i,ka);printf("%c",188);}
            else {gotoxy(i,ka);printf("%c",205);}
        }
        SetColor(0);gotoxy(104,ka-1);t();
    while(1)
    {
        switch(_getch())
        {
        case '0':
            main_window();
            break;
        default:
            break;
        }
    }
}
