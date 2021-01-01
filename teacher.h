/// @ We will use  this file  for teachers activities in  this project @ ///

/// For See the profile of the @Teacher


void tch_details(char a[15])
{
    system("CLS");
    window();
    print_heading(78," My  Profile ");
    fp=fopen("record teacher.txt","rb+");
    SetColor(45);int p=50,isFound=0;
    while(fread(&th,sizeof(th),1,fp)==1)
    {
        if(strcmp(a,th.cod)==0)
        {
            isFound=1;
            break;
        }
    }
    if(isFound==1)
    {
        gotoxy(p,10);printf("\xdb\xb2 Name        : %s.",th.nam);
        gotoxy(p,12);printf("\xdb\xb2 Position    : %s.",th.pos);
        gotoxy(p,14);printf("\xdb\xb2 Short Code  : \"%s\"",th.cod);
        gotoxy(p,16);printf("\xdb\xb2 Department  : %s.",th.dep);
        gotoxy(p,18);printf("\xdb\xb2 Subject     : %s.",th.sub);
        gotoxy(p,20);printf("\xdb\xb2 Address     : %s.",th.add);
        gotoxy(p,22);printf("\xdb\xb2 Blood Group : \"%s\"",th.bg);
        gotoxy(p,24);printf("\xdb\xb2 Nationality : %s.",th.nat);
        gotoxy(p,26);printf("\xdb\xb2 Mobile      : %s",th.pn);
    }
    fclose(fp);
    SetColor(1);
    gotoxy(65+20,27);printf("\xdb\xb2 Press 0 to go back");
    while(1)
    {
        int choice=_getch()-'0';
        int c=5;
        if(choice==0){ c=1;}
        switch(c)
        {
        case 1:
            teacher_option(a);
            break;
        default:
            break;
        }
    }
}
/// For change the password of the @Teacher
void tch_pass(char a[15])
{
    system("CLS");
    window();
    int ifFound=0;
    print_heading(74," Password Changing ");
    start:
    fp=fopen("teacher.txt","rb+");
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
    while(fread(&te,sizeof(te),1,fp)==1){
        if(strcmp(P,te.pas)==0&&strcmp(a,te.code)==0){
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
                strcpy(te.code,a);
                strcpy(te.pas,P);
                gotoxy(65,19);printf("\xdb\xdb\xb2 Password Successfully Changed---->>>");
                gotoxy(65,20);printf("\xdb\xdb\xb2 Press Any key to continue--->>>>>>>>");
                fseek(fp, -sizeof(te), SEEK_CUR);
                fwrite(&te,sizeof(te), 1,fp);
                fclose(fp);
                _getch();
                teacher_option(a);
            }
            else
            {
                SetColor(4);
                gotoxy(60,19);printf("\xdb\xdb\xb2 \aWarning! Password Doesn't match. Try Again--->>");
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
            gotoxy(57,19);printf("\xdb\xdb\xb2 \aWarning! Previous Password Doesn't match. Try Again--->>");
            _getch();
            fflush(stdin);
            fclose(fp);
            clearLine(19);
            clearLine(13);
            goto start;
        }

}

/// For Upload Student Marks for first time
void entry_marks(char a[15],char S[15])
{
    system("ClS");
    window();
    char sid[15];
    print_heading(77," Result  Entry ");
    start:
    fp=fopen("marks.txt","ab+");
    ft=fopen("record.txt","r");
    SetColor(45);
    isFound=0;
    gotoxy(65,10);printf("\xdb\xdb\xb2 Enter the id: ");
    memset(&sid[0],0,sizeof(sid));
    fflush(stdin);gets(sid);fflush(stdin);
    while(fread(&stu,sizeof(stu),1,ft)==1)
    {
        if(strcmp(stu.ID,sid)==0)
        {
            isFound=1;
            break;
        }
    }
    fclose(ft);
    if(isFound==0){
        SetColor(4);
        gotoxy(60,19);printf("\xdb\xdb This  student is not in the record !!");
        gotoxy(60,21);printf("\xdb\xdb Do you want to try again or back(y/n)?");
        while(1)
        {
            switch(_getch())
            {
            case 'y':
                clearLine(19);
                clearLine(21);
                clearLine(10);
                fclose(fp);
                goto start;
                break;
            case 'Y':
                clearLine(19);
                clearLine(21);
                clearLine(10);
                fclose(fp);
                goto start;
                break;
            case 'n':
                entry_option(a,S);
                break;
            case 'N':
                entry_option(a,S);
                break;
            default:
                break;
            }
        }
    }
    else {
          int notFound=0;
          while(fread(&mr,sizeof(mr),1,fp)==1)
    {
        if(strcmp(mr.id,sid)==0&&strcmp(mr.sub,S)==0)
        {
            notFound=1;
            break;
        }
    }
    if(notFound==0){
            int B;
            float m,f,att,A;
        strcpy(mr.id,sid);
        strcpy(mr.sub,S);
        gotoxy(65,12);printf("\xdb\xdb\xb2 Enter mid exam marks(Out of 30): ");scanf("%f",&m);mr.mid_marks=m;
        gotoxy(65,14);printf("\xdb\xdb\xb2 Enter final exam marks(Out of 40): ");scanf("%f",&f);mr.final_marks=f;
        gotoxy(65,16);printf("\xdb\xdb\xb2 Enter attendance(in %%): ");scanf("%d",&B);
        if(B>=90)A=5.00;
        else if(B>=85&&B<90)A=4.00;
        else if(B>=80&&B<85)A=3.00;
        else if(B>=75&&B<80)A=2.00;
        else if(B>=70&&B<75)A=1.00;
        else A=0;
        mr.attend=A;
        gotoxy(65,18);printf("\xdb\xdb\xb2 Enter Assignment & Class test number(Out of 25): ");scanf("%f",&att);mr.assignment=att;
        int total=0;
        total=m+f+att+A;
        mr.total=total;
        if(total>=80.00){strcpy(mr.grade,"A+");mr.gpa=4.00;}
        else if(total>=75.00&&total<80.00){strcpy(mr.grade,"A");mr.gpa=3.75;}
        else if(total>=70.00&&total<75.00){strcpy(mr.grade,"A-");mr.gpa=3.50;}
        else if(total>=65.00&&total<70.00){strcpy(mr.grade,"B+");mr.gpa=3.25;}
        else if(total>=60.00&&total<65.00){strcpy(mr.grade,"B");mr.gpa=3.00;}
        else if(total>=55.00&&total<60.00){strcpy(mr.grade,"B-");mr.gpa=2.75;}
        else if(total>=50.00&&total<55.00){strcpy(mr.grade,"C+");mr.gpa=2.50;}
        else if(total>=45.00&&total<50.00){strcpy(mr.grade,"C");mr.gpa=2.25;}
        else if(total>=40.00&&total<45.00){strcpy(mr.grade,"D");mr.gpa=2.00;}
        else if(total<40.00){strcpy(mr.grade,"F");mr.gpa=0.00;}
        fwrite(&mr,sizeof(mr), 1,fp);
        fclose(fp);
        SetColor(2);
        gotoxy(60,21);printf("\xdb\xdb The marks updated successfully-->>");
        gotoxy(60,23);SetColor(1);printf("\xdb\xdb Do you want to add more(y/n)?");
        while(1){
            switch(_getch())
            {
            case 'y':
                entry_marks(a,S);
                break;
            case 'Y':
                entry_marks(a,S);
                break;
            case 'n':
                entry_option(a,S);
                break;
            case 'N':
                entry_option(a,S);
                break;
            default:
                break;
            }
        }
     }
     else{
            SetColor(4);
        gotoxy(60,19);printf("\xdb\xdb\xb2 The mark is already uploaded!");
        gotoxy(60,21);printf("\xdb\xdb Do you want to try again or back(y/n)?");
        while(1)
        {
            switch(_getch())
            {
            case 'y':
                clearLine(19);
                clearLine(21);
                clearLine(10);
                fclose(fp);
                goto start;
                break;
            case 'Y':
                clearLine(19);
                clearLine(21);
                clearLine(10);
                fclose(fp);
                goto start;
                break;
            case 'n':
                entry_option(a,S);
                break;
            case 'N':
                entry_option(a,S);
                break;
            default:
                break;
            }
        }
     }
  }
}
/// For Updated a Mark Which was uploaded before
void update_marks(char a[15],char S[15])
{
    system("ClS");
    window();
    char sid[15];
    print_heading(77," Result Update ");
    start:
    fp=fopen("marks.txt","rb+");
    SetColor(45);
    isFound=0;
    gotoxy(65,10);printf("\xdb\xdb\xb2 Enter the id: ");
    memset(&sid[0],0,sizeof(sid));
    fflush(stdin);gets(sid);fflush(stdin);
    while(fread(&mr,sizeof(mr),1,fp)==1)
    {
        if(strcmp(mr.id,sid)==0&&strcmp(mr.sub,S)==0)
        {
            isFound=1;
            break;
        }
    }
    if(isFound==0){
        SetColor(4);
        gotoxy(60,19);printf("\xdb\xdb The marks isn't uploaded yet !!");
        gotoxy(60,21);printf("\xdb\xdb Do you want to try again or back(y/n)?");
        while(1)
        {
            switch(_getch())
            {
            case 'y':
                clearLine(19);
                clearLine(21);
                clearLine(10);
                fclose(fp);
                goto start;
                break;
            case 'Y':
                clearLine(19);
                clearLine(21);
                clearLine(10);
                fclose(fp);
                goto start;
                break;
            case 'n':
                entry_option(a,S);
                break;
            case 'N':
                entry_option(a,S);
                break;
            default:
                break;
            }
        }

    }
    else {
            int B;
            float m,f,att,A;
        strcpy(mr.id,sid);
        strcpy(mr.sub,S);
        gotoxy(65,12);printf("\xdb\xdb\xb2 Enter mid exam marks(Out of 30): ");scanf("%f",&m);mr.mid_marks=m;
        gotoxy(65,14);printf("\xdb\xdb\xb2 Enter final exam marks(Out of 40): ");scanf("%f",&f);mr.final_marks=f;
        gotoxy(65,16);printf("\xdb\xdb\xb2 Enter attendance(in %%): ");scanf("%d",&B);
        if(B>=90)A=5.00;
        else if(B>=85&&B<90)A=4.00;
        else if(B>=80&&B<85)A=3.00;
        else if(B>=75&&B<80)A=2.00;
        else if(B>=70&&B<75)A=1.00;
        else A=0;
        mr.attend=A;
        gotoxy(65,18);printf("\xdb\xdb\xb2 Enter Assignment & Class test number(Out of 25): ");scanf("%f",&att);mr.assignment=att;
        int total=0;
        total=m+f+att+A;
        mr.total=total;
        if(total>=80.00){strcpy(mr.grade,"A+");mr.gpa=4.00;}
        else if(total>=75.00&&total<80.00){strcpy(mr.grade,"A");mr.gpa=3.75;}
        else if(total>=70.00&&total<75.00){strcpy(mr.grade,"A-");mr.gpa=3.50;}
        else if(total>=65.00&&total<70.00){strcpy(mr.grade,"B+");mr.gpa=3.25;}
        else if(total>=60.00&&total<65.00){strcpy(mr.grade,"B");mr.gpa=3.00;}
        else if(total>=55.00&&total<60.00){strcpy(mr.grade,"B-");mr.gpa=2.75;}
        else if(total>=50.00&&total<55.00){strcpy(mr.grade,"C+");mr.gpa=2.50;}
        else if(total>=45.00&&total<50.00){strcpy(mr.grade,"C");mr.gpa=2.25;}
        else if(total>=40.00&&total<45.00){strcpy(mr.grade,"D");mr.gpa=2.00;}
        else if(total<40.00){strcpy(mr.grade,"F");mr.gpa=0.00;}
        fseek(fp,-sizeof(mr),SEEK_CUR);
        fwrite(&mr,sizeof(mr), 1,fp);
        fclose(fp);
        SetColor(2);
        gotoxy(60,21);printf("\xdb\xdb The marks updated successfully-->>");
        gotoxy(60,23);SetColor(1);printf("\xdb\xdb Do you want to update more(y/n)?");
        while(1){
            switch(_getch())
            {
            case 'y':
                update_marks(a,S);
                break;
            case 'Y':
                update_marks(a,S);
                break;
            case 'n':
                entry_option(a,S);
                break;
            case 'N':
                entry_option(a,S);
                break;
            default:
                break;
            }
        }
     }
}


/// this function will allow a teacher to view the result he or she uploaded

void result_sheet(char a[15],char S[15])
{
    system("CLS");
    window2();
    print_heading(76," Result  Sheet ");

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
    for(i=42;i<135;i+=17){
        gotoxy(i,10);
        printf("%c",203);
    }
    gotoxy(23,11);printf("%c",186);
    gotoxy(23,12);printf("%c",186);
    gotoxy(143,11);printf("%c",186);
    gotoxy(143,12);printf("%c",186);
    for(i=42;i<135;i+=17){
        gotoxy(i,11);
        printf("%c",186);
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
    for(i=42;i<135;i+=17){
        gotoxy(i,12);
        printf("%c",206);///plus line...
    }
    SetColor(45);
    gotoxy(29,11);printf("   ID   ");
    gotoxy(47,11);printf("MID EXAM");
    gotoxy(63,11);printf("FINAL EXAM");
    gotoxy(80,11);printf("ATTENDANCE");
    gotoxy(94,11);printf("CT & ASSIGNMENTS");
    gotoxy(116,11);printf("TOTAL");
    gotoxy(133,11);printf("GRADE");
    int ka=14,me=13;int sub=0;
    fp=fopen("marks.txt","rb+");
    while(fread(&mr,sizeof(mr),1,fp)==1){
        if(strcmp(S,mr.sub)==0){
                SetColor(45);
            gotoxy(27,me);printf("%s",mr.id);
            gotoxy(48,me);printf("%0.2f",mr.mid_marks);
            gotoxy(66,me);printf("%0.2f",mr.final_marks);
            gotoxy(85,me);printf("%0.0f",mr.attend);
            gotoxy(100,me);printf("%0.2f",mr.assignment);
            gotoxy(117,me);printf("%0.2f",mr.total);
            gotoxy(135,me);printf("%s",mr.grade);sub++;
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
        SetColor(45);gotoxy(67,ka+1);printf("\xdb\xb2 You didn't upload any result yet!");
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
            teacher_option(a);
            break;
        default:
            break;
        }
    }
}

