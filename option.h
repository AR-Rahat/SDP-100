/// We define all the menu or selection functions here.......



/// this function is for users selection weather as Admin or Teacher or Student.....
void login_option(){
    system("CLS");
    window();
    print_heading(78,"Log in choice");
    int choice;
    SetColor(0);
    Sleep(50);
    gotoxy(64,12);
    printf("\xdb\xdb\xb2 >>> 1. Administration Log in <<<  \xb2\xdb\xdb");
    gotoxy(64,15);Sleep(50);
    printf("\xdb\xdb\xb2    >>>  2. Teacher Log in  <<<    \xb2\xdb\xdb");
    gotoxy(64,18);Sleep(50);
    printf("\xdb\xdb\xb2     >>> 3. Student Log in <<<     \xb2\xdb\xdb");
    gotoxy(64,21);Sleep(50);
    printf("\xdb\xdb\xb2       >>>    4. Exit    <<<       \xb2\xdb\xdb");
    SetColor(0);gotoxy(70+14,28);t();
    gotoxy(64+9,24);Sleep(50);SetColor(1);
    printf("\xdb\xdb\xb2 Enter your choice: ");
    while(1){
    choice=_getch()-'0';
    switch(choice)
    {
        case 1:
            Ad_login();
            break;
        case 2:
            tch_option();
            break;
        case 3:
            stu_option();
            break;
        case 4:
            Exit_program();
            break;
        default:
            break;
    }
    }
}

/// this function is the main menu for Admin
void main_window(){
    window();
    int choice;
    print_heading(79," Admin Menu ");
    SetColor(1);
    int x = 18+45;
        gotoxy(39+45,28);SetColor(0);t();
        Sleep(100);gotoxy(x,10);printf("\xDB\xDB\xDB\xB2\xB2  >>> 1. Add  Information <<<  \xB2\xB2\xDB\xDB\xDB");
        Sleep(100);gotoxy(x,13);printf("\xDB\xDB\xDB\xB2\xB2 >>> 2. Search Information <<< \xB2\xB2\xDB\xDB\xDB");
        Sleep(100);gotoxy(x,16);printf("\xDB\xDB\xDB\xB2\xB2   >>> 3. Modify  Record <<<   \xB2\xB2\xDB\xDB\xDB");
        Sleep(100);gotoxy(x,19);printf("\xDB\xDB\xDB\xB2\xB2     >>> 4.Total Result <<<    \xB2\xB2\xDB\xDB\xDB");
        Sleep(100);gotoxy(x,22);printf("\xDB\xDB\xDB\xB2\xB2      >>> 5. Log  Out <<<      \xB2\xB2\xDB\xDB\xDB");
        Sleep(100);gotoxy(x+8,25);SetColor(1);printf("\xDB\xDB\xB2 Enter your choice: ");
        while(1){
        choice = _getch()-'0';
        switch(choice){
            case 1:
                add_option();
                break;
            case 2:
                search_option();
                break;
            case 3:
                mod_option();
                break;
            case 4:
                result_of_bubt();
                break;
            case 5:
                Again();
                break;
            default:
                break;
        }

    }

}
/// when you want to log in as student it will ask you for log in or registration............
void stu_option(){
    system("CLS");
    window();
    print_heading(77,"Log in Option");
    SetColor(0);
    gotoxy(65,12);printf("\xdb\xdb\xb2         >> 1. Log in <<         \xb2\xdb\xdb");
    gotoxy(65,15);printf("\xdb\xdb\xb2      >> 2. Registration <<      \xb2\xdb\xdb");
    gotoxy(65,18);printf("\xdb\xdb\xb2          >> 3. Back <<          \xb2\xdb\xdb");
    SetColor(1);gotoxy(73,22);printf("\xdb\xdb\xb2  Enter your choice: ");
    while(1)
    {
        int choice=_getch()-'0';
        switch(choice)
        {
            case 1:
                stu_log_in();
                break;
            case 2:
                regist();
                break;
            case 3:
                 login_option();
                break;
            default:
                break;
        }
    }

}

///when Admin want to add a information about student or teacher it will help him/her to do so
void add_option(){
    system("CLS");
    window();
    print_heading(75," Add  Information ");
    SetColor(0);
    gotoxy(61-1,13);printf("\xdb\xdb\xb2    >>> 1. Add Student Information   <<<    \xb2\xdb\xdb");
    gotoxy(61-1,16);printf("\xdb\xdb\xb2    >>> 2. Add Teacher Information   <<<    \xb2\xdb\xdb");
    gotoxy(61-1,19);printf("\xdb\xdb\xb2    >>>           3. Back            <<<    \xb2\xdb\xdb");
    gotoxy(68+5,22);SetColor(1);printf("\xdb\xdb\xb2    Enter Your Choice: ");
    while(1)
    {
        int choice=_getch()-'0';
        switch(choice)
        {
            case 1:
                add_student();
                break;
            case 2:
                add_teacher();
                break;
            case 3:
                main_window();
            default:
                break;
        }
    }


}

///same as add option........
void search_option(){
    system("CLS");
    window();
    char b[15]=" ";
    print_heading(74," Search Information ");
    SetColor(0);
    gotoxy(61,13);printf("\xdb\xdb\xb2    >>> 1.  Student Information   <<<    \xb2\xdb\xdb");
    gotoxy(61,16);printf("\xdb\xdb\xb2    >>> 2.  Teacher Information   <<<    \xb2\xdb\xdb");
    gotoxy(61,19);printf("\xdb\xdb\xb2    >>>          3.  Back         <<<    \xb2\xdb\xdb");
    gotoxy(68,22);SetColor(1);printf("\xdb\xdb\xb2    Enter Your Choice: ");
    while(1)
    {
        int choice=_getch()-'0';
        switch(choice)
        {
            case 1:
                stu_src(1,b);
                break;
            case 2:
                tch_src();
                break;
            case 3:
                main_window();
            default:
                break;
        }
    }


}
/// Same as add and search option
void mod_option()
{
    system("CLS");
    window();
    print_heading(74," Modify Information ");
    SetColor(0);
    gotoxy(61,13);printf("\xdb\xdb\xb2    >>> 1.  Student Information   <<<    \xb2\xdb\xdb");
    gotoxy(61,16);printf("\xdb\xdb\xb2    >>> 2.  Teacher Information   <<<    \xb2\xdb\xdb");
    gotoxy(61,19);printf("\xdb\xdb\xb2    >>>          3.  Back         <<<    \xb2\xdb\xdb");
    gotoxy(68,22);SetColor(1);printf("\xdb\xdb\xb2    Enter Your Choice: ");
    while(1)
    {
        int choice=_getch()-'0';
        switch(choice)
        {
            case 1:
                stu_mod_op();
                break;
            case 2:
                tch_mod_op();
                break;
            case 3:
                main_window();
            default:
                break;
        }
    }

}

/// this function is made for both Admin and teacher where they can search for student information in various way
void stu_src(int a,char b[15]){
    system("ClS");
    window();
    print_heading(73," Student Search option ");
    SetColor(0);
    gotoxy(60,10);Sleep(50);printf("\xdb\xdb\xb2  >>> 1.  Search By Intake & Section  <<<  \xb2\xdb\xdb");
    gotoxy(60,12);Sleep(50);printf("\xdb\xdb\xb2     >>> 2.  Search By Department   <<<    \xb2\xdb\xdb");
    gotoxy(60,14);Sleep(50);printf("\xdb\xdb\xb2       >>> 3.  All Student List   <<<      \xb2\xdb\xdb");
    gotoxy(60,16);Sleep(50);printf("\xdb\xdb\xb2        >>> 4.  Search By Name   <<<       \xb2\xdb\xdb");
    gotoxy(60,18);Sleep(50);printf("\xdb\xdb\xb2         >>>  5. Search By ID   <<<        \xb2\xdb\xdb");
    gotoxy(60,20);Sleep(50);printf("\xdb\xdb\xb2           >>>    6. Back     <<<          \xb2\xdb\xdb");
    gotoxy(73,24);Sleep(50);SetColor(1);printf("\xdb\xdb\xb2  Enter your Choice: ");
    while(1)
    {
        int c=_getch()-'0';
        switch(c)
        {
            case 1:
                src_intake(a,b);
                break;
            case 2:
                src_dep(a,b);
                break;
            case 3:
                Student_list(a,b);
                break;
            case 4:
                src_name(a,b);
                break;
            case 5:
                src_ID(a,b);
                break;
            case 6:
                if(a==1){search_option();break;}
                else if(a==2){teacher_option(b);break;}
            default:
                break;
        }
    }
}

/// @When you want to log in as Teacher this function will as for registration or login
void tch_option(){
    system("CLS");
    window();
    print_heading(77,"Log in Option");
    SetColor(0);
    gotoxy(65,12);printf("\xdb\xdb\xb2         >> 1. Log in <<         \xb2\xdb\xdb");
    gotoxy(65,15);printf("\xdb\xdb\xb2      >> 2. Registration <<      \xb2\xdb\xdb");
    gotoxy(65,18);printf("\xdb\xdb\xb2          >> 3. Back <<          \xb2\xdb\xdb");
    gotoxy(73,22);SetColor(1);printf("\xdb\xb2  Enter your choice: ");
    while(1)
    {
        int c=_getch()-'0';
        switch(c)
        {
            case 1:
                tch_login();
                break;
            case 2:
                tch_regist();
                break;
            case 3:
                login_option();
                break;
            default:
                break;
        }
    }
}

/// This Function will ask weather modify or delete an information of a student
void stu_mod_op()
{
    system("CLS");
    window();
    print_heading(74," Modify   Options ");
    SetColor(0);
    gotoxy(61,13);printf("\xdb\xdb\xb2    >>> 1.  update  Information   <<<    \xb2\xdb\xdb");
    gotoxy(61,16);printf("\xdb\xdb\xb2    >>> 2.  delete  Information   <<<    \xb2\xdb\xdb");
    gotoxy(61,19);printf("\xdb\xdb\xb2    >>>          3.  Back         <<<    \xb2\xdb\xdb");
    gotoxy(68,22);SetColor(1);printf("\xdb\xdb\xb2    Enter Your Choice: ");
    while(1)
    {
        int choice=_getch()-'0';
        switch(choice)
        {
            case 1:
                mod_student();
                break;
            case 2:
                delete_student();
                break;
            case 3:
                mod_option();
            default:
                break;
        }
    }

}
/// This Function will ask weather modify or delete an information of a teacher
void tch_mod_op()
{
    system("CLS");
    window();
    print_heading(74," Modify   Options ");
    SetColor(0);
    gotoxy(61,13);printf("\xdb\xdb\xb2    >>> 1.  update  Information   <<<    \xb2\xdb\xdb");
    gotoxy(61,16);printf("\xdb\xdb\xb2    >>> 2.  delete  Information   <<<    \xb2\xdb\xdb");
    gotoxy(61,19);printf("\xdb\xdb\xb2    >>>          3.  Back         <<<    \xb2\xdb\xdb");
    gotoxy(68,22);SetColor(1);printf("\xdb\xdb\xb2    Enter Your Choice: ");
    while(1)
    {
        int choice=_getch()-'0';
        switch(choice)
        {
            case 1:
                mod_teacher();
                break;
            case 2:
                delete_teacher();
                break;
            case 3:
                mod_option();
            default:
                break;
        }
    }


}

/// this function is the main menu when you log in as a @Student
void Student_option(char a[15]){
    window();
    print_heading(78," Main Menu ");
    int x=67;
    SetColor(0);
    gotoxy(x,11);printf("\xDB\xDB\xB2    >>>   1. View profile   <<<     \xB2\xDB\xDB");
    gotoxy(x,13);printf("\xDB\xDB\xB2    >>>   2. View Result    <<<     \xB2\xDB\xDB");
    gotoxy(x,15);printf("\xDB\xDB\xB2    >>>  3. Change Password <<<     \xB2\xDB\xDB");
    gotoxy(x,17);printf("\xDB\xDB\xB2    >>>      4. Log Out     <<<     \xB2\xDB\xDB");

    SetColor(1);
    gotoxy(x+6,20);printf("\xdb\xb2 Enter Your Choice: ");
    while(1){
        int c=_getch()-'0';
        switch(c)
        {
            case 1 :
                details(a);
                break;
            case 2:
                view_result(a);
                break;
            case 3:
                stu_pass(a);
                break;
            case 4:
                Again();
                break;
            default:
                break;
        }
    }
}

/// this is the main menu when you log in as a @Teacher
void teacher_option(char a[15]){
    system("CLS");
    window();
    char S[15];
    memset(&S[0],0,sizeof(S));
    print_heading(77," Teacher  Menu ");
    fp=fopen("record teacher.txt","rb+");
    while(fread(&th,sizeof(th),1,fp)==1)
    {
        if(strcmp(a,th.cod)==0)
        {
            isFound=1;
            break;
        }
    }
    strcpy(S,th.sub);
    fclose(fp);
    int choice,x=67;
    SetColor(0);
    gotoxy(x,11);printf("\xDB\xDB\xB2    >>>   1. View profile   <<<     \xB2\xDB\xDB");
    gotoxy(x,13);printf("\xdb\xdb\xb2    >>>  2. Search Student  <<<     \xb2\xdb\xdb");
    gotoxy(x,15);printf("\xDB\xDB\xB2    >>>   3. Entry Marks    <<<     \xB2\xDB\xDB");
    gotoxy(x,17);printf("\xDB\xDB\xB2    >>> 4.View Result Sheet <<<     \xB2\xDB\xDB");
    gotoxy(x,19);printf("\xDB\xDB\xB2    >>> 5. Change Password  <<<     \xB2\xDB\xDB");
    gotoxy(x,21);printf("\xDB\xDB\xB2    >>>      6. Log Out     <<<     \xB2\xDB\xDB");
    SetColor(1);
    gotoxy(x+7,23);printf("\xdb\xb2 Enter Your Choice: ");
    while(1)
    {
        choice=_getch()-'0';
        switch(choice)
        {
            case 1:
                tch_details(a);
                break;
            case 2:
                stu_src(2,a);
                break;
            case 3:
                entry_option(a,S);
                break;
            case 4:
                result_sheet(a,S);
            case 5:
                tch_pass(a);
                break;
            case 6:
                Again();
                break;
            default:
                break;
        }
    }

}

/// This function will help teacher to choose weather he/she want to upload a new mark or update a mark which one  was entered in past
void entry_option(char a[15],char S[15])
{
    system("CLS");
    window();
    print_heading(77," Entry Option ");
    int choice,x=67;
    SetColor(0);
    gotoxy(x,13);printf("\xDB\xDB\xB2    >>>   1. Upload Marks   <<<     \xB2\xDB\xDB");
    gotoxy(x,16);printf("\xdb\xdb\xb2     >>>  2. Update Marks  <<<      \xb2\xdb\xdb");
    gotoxy(x,19);printf("\xDB\xDB\xB2      >>>     3. Back     <<<       \xB2\xDB\xDB");
    SetColor(1);
    gotoxy(x+7,22);printf("\xdb\xb2 Enter Your Choice: ");
    while(1)
    {
        switch(_getch()-'0')
        {
            case 1:
                entry_marks(a,S);
                break;
            case 2:
                update_marks(a,S);
                break;
            case 3:
                teacher_option(a);
            default:
                break;
        }
    }

}

/// This function is  only accessible by Admin and he/she can search teacher information in different way
void tch_src(){
    system("CLS");
    window();
    print_heading(73," Teacher Search option ");
    SetColor(0);
    gotoxy(60,10);Sleep(50);printf("\xdb\xdb\xb2  >>> 1.     Search By Department     <<<  \xb2\xdb\xdb");
    gotoxy(60,12);Sleep(50);printf("\xdb\xdb\xb2     >>> 2.     Search By Name      <<<    \xb2\xdb\xdb");
    gotoxy(60,14);Sleep(50);printf("\xdb\xdb\xb2       >>> 3.  All Teacher List   <<<      \xb2\xdb\xdb");
    gotoxy(60,16);Sleep(50);printf("\xdb\xdb\xb2        >>> 4.  Search By Code  <<<       \xb2\xdb\xdb");
    gotoxy(60,18);Sleep(50);printf("\xdb\xdb\xb2         >>>  5.     Back     <<<        \xb2\xdb\xdb");
    gotoxy(73,22);Sleep(50);SetColor(1);printf("\xdb\xdb\xb2  Enter your Choice: ");
    while(1)
    {
        int c=_getch()-'0';
        switch(c)
        {
            case 1:
                th_src_dep();
                break;
            case 2:
                th_src_name();
                break;
            case 3:
                th_src_all();
                break;
            case 4:
                th_src_code();
                break;
            case 5:
                search_option();
                break;
            default:
                break;
        }
    }
}
