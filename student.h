/// @ This file  contain all the  function that  is  accessible for a Student......  @ ///


/// This is the function which we used for showing @Student @Profile
void details(char a[15]){
    system("CLS");
    window();
    print_heading(78," My  Profile ");
    SetColor(45);int p=45,isFound=0;
    fp=fopen("record.txt","rb+");
    while(fread(&stu,sizeof(stu),1,fp)==1)
    {
        if(strcmp(stu.ID,a)==0)
        {
            isFound=1;
            break;
        }
    }
    if(isFound==1){
        gotoxy(5+p,10);printf("\xB2 ID            : %s",stu.ID);
        gotoxy(5+p,12);printf("\xB2 Name          : %s.",stu.name);
        gotoxy(5+p,14);printf("\xB2 Department    : %s.",stu.Dep);
        gotoxy(5+p,16);printf("\xB2 Intake        : %d.",stu.Intake);
        gotoxy(5+p,18);printf("\xB2 Section       : %d.",stu.sec);
        gotoxy(5+p,20);printf("\xB2 Blood group   : \"%s\"",stu.bgrp);
        gotoxy(5+p,22);printf("\xB2 Nationality   : %s.",stu.nat);
        gotoxy(5+p,24);printf("\xB2 Phone No      : %s",stu.phone_no);
    }
    fclose(fp);
    SetColor(1);
    gotoxy(65,27);printf("\xdb\xb2 Press 0 to go back");
    while(1)
    {
        int choice=_getch()-'0';
        int c=5;
        if(choice==0){ c=1;}
        switch(c)
        {
        case 1:
            Student_option(a);
            break;
        default:
            break;
        }
    }
}

/// This function is used for change the password of student.....
void stu_pass(char a[15])
{
    system("CLS");
    window();
    int ifFound=0;
    print_heading(74," Password Changing ");
    start:
    fp=fopen("student.txt","rb+");
    SetColor(45);
    gotoxy(65,13);printf("\xdb\xdb\xb2 Enter current password:");
    fflush(stdin);c='0';
    memset(&p1[0],0,sizeof(p1));
    memset(&P[0],0,sizeof(P));i=0;
    while(c!=13)
    {
        c=_getch();
        if(c!=13&&c!=8)
        {
            putch('*');
            P[i]=c;
            i++;
        }
    }
    P[i]='\0';
    while(fread(&st,sizeof(st),1,fp)==1){
            if(strcmp(P,st.stp)==0&&strcmp(a,st.sti)==0){
                ifFound=1;
                break;
            }
    }

        if(ifFound==1){
            memset(&p1[0],0,sizeof(p1));
            memset(&P[0],0,sizeof(P));
            fflush(stdin);c='0';i=0;
            gotoxy(65,15);printf("\xdb\xdb\xb2 Enter new password: ");
            while(c!=13)
            {
               c=_getch();
               if(c!=13&&c!=8)
               {
                   putch('*');
                   P[i]=c;
                   i++;
               }
            }
            P[i]='\0';
            vul:
            SetColor(45);
            memset(&p1[0],0,sizeof(p1));
            fflush(stdin);c='0';i=0;
            gotoxy(65,17);printf("\xdb\xdb\xb2 Confirm Password: ");
            while(c!=13)
            {
               c=_getch();
               if(c!=13&&c!=8)
               {
                   putch('*');
                   p1[i]=c;
                   i++;
               }
            }
            p1[i]='\0';
            if(strcmp(P,p1)==0){
                SetColor(2);
                strcpy(st.sti,a);
                strcpy(st.stp,P);
                gotoxy(65,19);printf("\xdb\xdb\xb2 Password Successfully Changed---->>>");
                gotoxy(65,20);printf("\xdb\xdb\xb2 Press Any key to continue--->>>");
                fseek(fp, -sizeof(st), SEEK_CUR);
                fwrite(&st,sizeof(st), 1,fp);
                fclose(fp);
                _getch();
                Student_option(a);
            }
            else
            {
                SetColor(4);
                gotoxy(60,19);printf("\xdb\xdb\xb2 \aWarning! Password Doesn't match .Try Again--->>");
                _getch();
                fflush(stdin);
                clearLine(19);
                clearLine(17);
                goto vul;
            }
        }
        else
        {
            SetColor(4);
            gotoxy(57,19);printf("\xdb\xdb\xb2 \aWarning! Previous Password Doesn't match .Try Again--->>");
            _getch();
            fflush(stdin);
            fclose(fp);
            clearLine(19);
            clearLine(13);
            goto start;
        }

}

/// This function is for student to @Viewing their @Result
void view_result(char a[15])
{
    system("CLS");
    window2();
    print_heading(76," Result  Sheet ");
    for(i=10;i<17;i++)
    {
        gotoxy(23,i);printf("%c",186);
        gotoxy(143,i);printf("%c",186);
    }
    for(i = 23; i <=120+23; i++){
            if(i==23){
                gotoxy(i,10+7);
                printf("%c",204);
            }
            else if(i==143){
                gotoxy(i,10+7);
                printf("%c",185);
            }
            else{
        gotoxy(i,10+7);
        printf("%c",205);///for middle horizontal line....
            }
    }
    for(i=42;i<135;i+=17){
        gotoxy(i,10+7);
        printf("%c",203);
    }
    gotoxy(23,11+7);printf("%c",186);
    gotoxy(23,12+7);printf("%c",186);
    gotoxy(143,11+7);printf("%c",186);
    gotoxy(143,12+7);printf("%c",186);
    for(i=42;i<135;i+=17){
        gotoxy(i,11+7);
        printf("%c",186);
    }
    for(i = 23; i <=120+23; i++){
            if(i==23){
                gotoxy(i,12+7);
                printf("%c",204);
            }
            else if(i==143){
                gotoxy(i,12+7);
                printf("%c",185);
            }
            else{
        gotoxy(i,12+7);
        printf("%c",205);///for middle horizontal line....
            }
    }
    for(i=42;i<135;i+=17){
        gotoxy(i,12+7);
        printf("%c",206);///plus line...
    }
    ft=fopen("record.txt","rb+");
    while(fread(&stu,sizeof(stu),1,ft)==1){
        if(strcmp(a,stu.ID)==0)
        {
            SetColor(0);
            gotoxy(42,11); printf("Name : %s",stu.name);
            gotoxy(99,11);printf("ID : %s",stu.ID);
            gotoxy(45,14);printf("Department : %s",stu.Dep);
            gotoxy(75,14);printf("Intake : %d",stu.Intake);
            gotoxy(100,14);printf("Section : %d",stu.sec);
            break;
        }
    }
    fclose(ft);
    SetColor(45);
    gotoxy(29,11+7);printf("SUBJECTS");
    gotoxy(47,11+7);printf("MID EXAM");
    gotoxy(63,11+7);printf("FINAL EXAM");
    gotoxy(80,11+7);printf("ATTENDANCE");
    gotoxy(94,11+7);printf("CT & ASSIGNMENTS");
    gotoxy(116,11+7);printf("TOTAL");
    gotoxy(133,11+7);printf("GRADE");
    int ka=21,me=20;float sum=0.00,sub=0.00;
    fp=fopen("marks.txt","rb+");
    while(fread(&mr,sizeof(mr),1,fp)==1){
        if(strcmp(a,mr.id)==0){
                SetColor(45);
            gotoxy(29,me);printf("%s",mr.sub);
            gotoxy(48,me);printf("%0.2f",mr.mid_marks);
            gotoxy(66,me);printf("%0.2f",mr.final_marks);
            gotoxy(85,me);printf("%0.0f",mr.attend);
            gotoxy(100,me);printf("%0.2f",mr.assignment);
            gotoxy(117,me);printf("%0.2f",mr.total);
            sum+=mr.gpa;
            gotoxy(135,me);printf("%s",mr.grade);sub+=1.00;
        SetColor(1);
        for(i = 23; i <=120+23; i++){
            if(i==23){gotoxy(i,ka);printf("%c",204);}
            else if(i==143){gotoxy(i,ka);printf("%c",185);}
            else{gotoxy(i,ka);printf("%c",205);}
        }
        for(i=42;i<135;i+=17){
            gotoxy(i,ka-1);
            printf("%c",186);
            gotoxy(i,ka);
            printf("%c",206);///plus line...
        }
        gotoxy(23,ka-1);printf("%c",186);
        gotoxy(143,ka-1);printf("%c",186);
        ka+=2;
        me+=2;
    }
}
    fclose(fp);
    if(sub==0){
        SetColor(45);gotoxy(67,ka+1);printf("\xdb\xb2 The result isn't published yet!");
    SetColor(1);
    gotoxy(71,ka+5);printf("\xdb\xb2 Press 0 to continue--->>>");
    }
    else{
    SetColor(45);gotoxy(77,ka+1);printf("\xdb\xdb\xb2  SGPA: %0.2f",sum/sub);
    SetColor(1);
    gotoxy(71,ka+5);printf("\xdb\xb2 Press 0 to continue--->>>");}
    ka-=2;
        for(i = 23; i <=120+23; i++){
            if(i==23){gotoxy(i,ka);printf("%c",204);}
            else if(i==143){gotoxy(i,ka);printf("%c",185);}
            else{gotoxy(i,ka);printf("%c",205);}
        }
        for(i=42;i<135;i+=17){
        gotoxy(i,ka);
        printf("%c",202);
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
                Student_option(a);
                break;
            default:
                break;
        }
    }
}
