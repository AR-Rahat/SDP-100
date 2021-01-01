/// @ All the  Log in system of  this  project are  coded here @ ///

/// For the @Administrator @Login
void Ad_login(){
    system("CLS");
    window();
    print_heading(78,"Admin Log in");
    char User_id[20] ={"team pegasus"};///This is the program User_Id....................
    char password[15]={"beaking12"};///This Is The Password..............................
    SetColor(3);
    char d[25]="Password Protected";
    char ch,pass[15],uid[20];
    int i=0,j;
    gotoxy(55,10);
    for(j=0;j<20;j++)
    {
        Sleep(50);
        printf("*");
    }
    for(j=0;j<18;j++)
    {
        Sleep(50);
        printf("%c",d[j]);
    }
    for(j=0;j<20;j++)
    {
        Sleep(50);
        printf("*");
    }
    again1:
        gotoxy(55+12,12);
        memset(&uid[0],0, sizeof(uid));
        SetColor(3);
        printf("Enter User Id :");
        fflush(stdin);
        gets(uid);
    again:
        gotoxy(55+12,14);
        fflush(stdin);
        SetColor(3);
        memset(&pass[0],0, sizeof(pass));
        ch='0';
        i=0;
        printf("Enter Password:");

    while(ch!=13)
    {
        ch=_getch();
        if(ch!=13 && ch!=8){///in this loop we put a * in case we enter a character in pass string..........
            putch('*');
            pass[i] = ch;
            i++;
        }
    }
    pass[i] = '\0';
    if(strcmp(uid,User_id)==0){
        if(strcmp(pass,password)==0){
            gotoxy(55,20);
            SetColor(2);
            printf("---->>\xb2\xdb Password match  \xdb\xb2<<------");
            gotoxy(55,21);
            printf("---->>\xb2\xdb Press any key to continue----->>>>");
            _getch();
            main_window();
        }
    else
        {
            gotoxy(55,19);
            SetColor(4);
            printf("\a\xb3\xb3\xb3\xb3 Warning!! Incorrect Password-->>Try Again..");
            _getch();
            fflush(stdin);
            clearLine(19);
            clearLine(14);
            goto again;
        }
    }
    else{
        gotoxy(55,19);
        SetColor(4);
        printf("\a\xb3\xb3\xb3\xb3 Warning !! User Doesn't Exist-->>Try Again..");
        _getch();
        fflush(stdin);
        clearLine(19);
        clearLine(12);
        clearLine(14);
        goto again1;
    }
}

/// For @Student @Login...........
void stu_log_in(){
    col:
    system("CLS");
    ClearConsoleToColors(17,15);
    window();
    print_heading(77," Student Log in ");
    fp=fopen("record.txt","r");
    ft=fopen("student.txt","r");
    SetColor(45);memset(&sti1[0],0,sizeof(sti1));fflush(stdin);
    gotoxy(65,11);printf("\xdb\xb2 Enter the id: ");gets(sti1);fflush(stdin);
        while(fread(&stu,sizeof(stu),1,fp) == 1){
                isFound=0;
        if(strcmp(sti1,stu.ID) == 0){///We check here is that Id is already exist or not....
            isFound = 1;
            break;
        }
    }
    if(isFound==0)
    {
        gotoxy(63,20);printf("\xdb\xb2 \aNot a student of this institution.");
        _getch();
        fclose(fp);
        fclose(ft);
        clearLine(11);
        clearLine(20);
        goto col;
    }
    else
    {
        while(fread(&st,sizeof(st),1,ft)==1){
                notfound=0;
            if(strcmp(sti1,st.sti)==0){
                notfound=1;
                break;
            }
        }
        if(notfound==1)
        {
          K: fflush(stdin);
            gotoxy(65,13);
            c='0';
            memset(&stp1[0], 0, sizeof(stp1));
            SetColor(45);
            i=0;
            printf("\xdb\xb2 Enter Password:");
           while(c!=13)
           {
               c=_getch();
               if(c!=13&&c!=8)
               {
                   putch('*');
                   stp1[i]=c;
                   i++;
               }
           }
           stp1[i]='\0';
           if(strcmp(stp1,st.stp)==0){
           gotoxy(65,17);SetColor(2);printf("\xdb\xb2\xb2 Log in Successfully---->>>>");
            fclose(fp);
            fclose(ft);
            _getch();
            Student_option(sti1);
            }
            else {
                    SetColor(4);
                gotoxy(65,17);printf("\xdb\xb2 Invalid Password!");
                gotoxy(65,19);printf("\a\xdb\xb2 Do you want to try again or exit ? (y/e)");
                while(1)
                    {
                        switch(_getch())
                        {
                            case 'y':
                                clearLine(17);
                                clearLine(19);
                                clearLine(13);
                                goto K;
                                break;
                            case 'Y':
                                clearLine(17);
                                clearLine(19);
                                clearLine(13);
                                goto K;
                                break;
                            case 'e':
                                stu_option();
                                break;
                            case 'E':
                                stu_option();
                                break;
                            default:
                                break;
                        }
                    }
                }
        }
        else
        {
            SetColor(4);
            gotoxy(65,17);printf("\xdb\xb2 Not in Register yet! \aRegistration First-->>");
            fclose(fp);
            fclose(ft);
            _getch();
            regist();
        }
    }
}

/// For @Student @Registration.......
void regist(){
    start:
    system("CLS");
    window();
    isFound=0;
    print_heading(74,"Student  Registration");
    fp=fopen("record.txt","r");
    ft=fopen("student.txt","ab+");
    SetColor(45);
    gotoxy(60,10);printf("\xdb\xb2 Enter the id to register: ");memset(&sti1[0],0,sizeof(sti1));fflush(stdin);gets(sti1);fflush(stdin);
        while(fread(&stu,sizeof(stu),1,fp) == 1){
        if(strcmp(sti1,stu.ID) == 0){///We check here is that Id is already exist or not....
            isFound = 1;
            break;
        }
    }
    fclose(fp);
    if(isFound==0)
    {
        SetColor(4);
        fclose(ft);
       gotoxy(60,18); printf("\xdb\xb2 \aNot a student of this institution.");
       gotoxy(62,22);printf("\xdb\xb2 Do you want to continue or back(c/b)?");
            while(1){
                    switch(_getch())
                    {
                    case 'c':
                        regist();
                        break;
                    case 'C':
                        regist();
                        break;
                    case 'b':
                        stu_option();
                        break;
                    case 'B':
                        stu_option();
                        break;
                    default:
                        break;
                    }
            }
    }
    else
    {
        notfound=0;
        while(fread(&st,sizeof(st),1,ft)==1){
            if(strcmp(sti1,st.sti)==0){
                notfound++;
                break;
            }
        }
        if(notfound){
                SetColor(4);
            gotoxy(62,20);printf("\xdb\xb2 \aThis id  is  already registered!");
            fclose(ft);
            gotoxy(62,22);printf("\xdb\xb2 Do you want to continue or back(c/b)?");
            while(1){
                    switch(_getch())
                    {
                    case 'c':
                        regist();
                        break;
                    case 'C':
                        regist();
                        break;
                    case 'b':
                        stu_option();
                        break;
                    case 'B':
                        stu_option();
                        break;
                    default:
                        break;
                    }
            }
        }
        else {
                SetColor(45);
            strcpy(st.sti,sti1);
            char p2[30];char p1[30];
            lol:
            memset(&p1[0],0,sizeof(p1));
            gotoxy(62,12);printf("\xdb\xb2 Enter password: ");
            fflush(stdin);
            i=0;
            c=0;
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
           gotoxy(62,14);printf("\xdb\xb2 Confirm password: ");
           i=0;
           c=0;
           memset(&p2[0], 0, sizeof(p2));
           while(c!=13)
           {
               c=_getch();
               if(c!=13&&c!=8)
               {
                   putch('*');
                   p2[i]=c;
                   i++;
               }
           }
           p2[i]='\0';
           if(strcmp(p1,p2)==0)
           {
                SetColor(2);
                strcpy(st.stp,p1);
                gotoxy(62,18);printf("\xdb\xb2 Registration Successful--->>>");
                fwrite(&st,sizeof(st),1,ft);
                fclose(ft);
                gotoxy(62,20);printf("\xdb\xb2Press any key to continue----->>>");_getch();
                stu_option();
           }
           else
           {
               SetColor(4);
               gotoxy(62,18);printf("\xdb\xb2 \aPassword doesn't match----");
               gotoxy(62,20);printf("\xdb\xb2 Enter & confirm password  again---->>");
               gotoxy(62,22);printf("\xdb\xb2 Press any key to continue or exit.(1/0)");
               int ch;
               li:ch=_getch()-'0';
               if(ch==1){
                SetColor(45);
               clearLine(12);
               clearLine(14);
               clearLine(18);
               clearLine(22);
               clearLine(20);
               goto lol;}
               else if(ch==0)
                stu_option();
                else
                    goto li;
           }
        }
}


}
char a[15];
/// For @Teacher @Login........
void tch_login(){
    system("CLS");
    ClearConsoleToColors(17,15);
    window();
    print_heading(77," Teacher Log in ");
    col:
    fp=fopen("record teacher.txt","r");
    ft=fopen("teacher.txt","r");
        SetColor(45);memset(&a[0],0,sizeof(a));
    gotoxy(65,11);printf("\xdb\xb2 Enter teacher Short code: ");
    fflush(stdin);
    gets(a);
    while(fread(&th,sizeof(th),1,fp)==1){
        if(strcmp(a,th.cod)==0){
            isFound=1;
            break;
        }
    }
    fclose(fp);
    if(isFound==0){
            SetColor(4);
        gotoxy(63,20);printf("\xdb\xb2 \aNo short code as given one--->>");
        _getch();
        fclose(ft);
        clearLine(11);clearLine(20);
        goto col;
    }
    else{
        while(fread(&te,sizeof(te),1,ft)==1){
            if (strcmp(a,te.code)==0){
                notfound=1;
                break;
        }
    }
    if(notfound==1)
    {
        K:fflush(stdin);
        SetColor(45);
        gotoxy(63,15);
        c=0;
        memset(&p[0],0,sizeof(p));
        SetColor(45);
        i=0;
        printf("\xdb\xb2 Enter Password: ");
        while(c!=13)
        {
            c=_getch();
            if(c!=13&&c!=8)
            {
                putch('*');
                p[i]=c;
                i++;
            }
        }
        p[i]='\0';
        if(strcmp(p,te.pas)==0)
        {
            gotoxy(65,22);
            SetColor(2);
            printf("\xdb\xb2 Log in  successful ----->>");
            fclose(ft);
            _getch();
            fflush(stdin);
            teacher_option(te.code);
        }
        else
        {
                SetColor(4);
                gotoxy(65,17);printf("\xdb\xb2 Invalid Password!");
                gotoxy(65,19);printf("\a\xdb\xb2 Do you want to try again or exit ? (y/e)");
                while(1)
                    {
                    switch(_getch())
                        {
                        case 'y':
                            clearLine(17);
                            clearLine(19);
                            clearLine(15);
                            goto K;
                            break;
                        case 'Y':
                            clearLine(17);
                            clearLine(19);
                            clearLine(15);
                            goto K;
                            break;
                        case 'e':
                            tch_option();
                            break;
                        case 'E':
                            tch_option();
                            break;
                        default:
                            break;
                    }
                }
            }
        }
    else
        {
            SetColor(4);
            gotoxy(60,19);
            printf("\xdb\xb2 Not in Register yet! Please Registration first-->>");
            fclose(ft);
            _getch();
            tch_regist();
        }

    }
}

/// For @Teacher @Registration............
void tch_regist(){
    col:system("CLS");
    window();
    print_heading(74,"Teacher  Registration");
    SetColor(45);
    isFound=0;
    notfound=0;
    fp=fopen("record teacher.txt","r");
    ft=fopen("teacher.txt","ab+");
    memset(&a[0],0,sizeof(a));
    gotoxy(57,10);printf("\xdb\xb2 Enter the Short Code to register: ");gets(a);fflush(stdin);
        while(fread(&th,sizeof(th),1,fp) == 1){
        if(strcmp(a,th.cod) == 0){///We check here is that Id is already exist or not....
            isFound = 1;
            break;
        }
    }
    fclose(fp);
    if(isFound==0)
    {
        SetColor(4);
       gotoxy(60,18); printf("\xdb\xb2 \aNo short code as  given one! Try again->");
       _getch();
       goto col;
    }
    else
    {
        while(fread(&te,sizeof(te),1,ft)==1){
            if(strcmp(a,te.code)==0){
                notfound=1;
                break;
            }
        }
        if(notfound==0){
            strcpy(te.code,a);
            char p2[30];char p1[30];
            lol:
            memset(&p1[0],0,sizeof(p1));
            gotoxy(62,12);printf("\xdb\xb2 Enter password: ");
            fflush(stdin);
            i=0;
            c=0;
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
           gotoxy(62,14);printf("\xdb\xb2 Confirm password: ");
           i=0;
           c=0;
           memset(&p2[0], 0, sizeof(p2));
           while(c!=13)
           {
               c=_getch();
               if(c!=13&&c!=8)
               {
                   putch('*');
                   p2[i]=c;
                   i++;
               }
           }
           p2[i]='\0';
           if(strcmp(p1,p2)==0)
           {
                SetColor(2);
                strcpy(te.pas,p1);
                gotoxy(62,18);printf("\xdb\xb2 Registration Successful--->>>");
                fwrite(&te,sizeof(te),1,ft);
                fclose(ft);
                gotoxy(62,20);printf("\xdb\xb2 Press any key to continue----->>>");_getch();
                tch_option();
           }
           else
           {
               SetColor(4);
               gotoxy(62,18);printf("\xdb\xb2 \aPassword doesn't match----");
               gotoxy(62,20);printf("\xdb\xb2 Enter & confirm password  again---->>");
               gotoxy(62,22);printf("\xdb\xb2 Press any key to continue or exit.(1/0)");
               int ch;
               li:ch=_getch()-'0';
               if(ch==1){
                    SetColor(45);
               clearLine(12);
               clearLine(14);
               clearLine(18);
               clearLine(22);
               clearLine(20);
               goto lol;}
               else if(ch==0)
                tch_option();
                else
                    goto li;
           }
        }
        else {
            SetColor(4);
            fclose(ft);
            gotoxy(62,20);printf("\xdb\xb2 \aThis code  is  already registered!");
            gotoxy(62,22);printf("\xdb\xb2 Do you want to continue or back(c/b)?");
            while(1){
                    switch(_getch())
                    {
                    case 'c':
                        tch_regist();
                        break;
                    case 'C':
                        tch_regist();
                        break;
                    case 'b':
                        tch_option();
                        break;
                    case 'B':
                        tch_option();
                        break;
                    default:
                        break;
                    }
            }
        }
}



}

/// @ @LOL @ ///
/// @ @BE @COOL @ ///
