/// We will define all the function which is used by administrator for
/// teacher information.....



///For Adding Student information.--------------------------------------------------------------------------------
void add_student(){
    system("CLS");
    window1();
    print_heading(74," Add Student  Record ");
    char s_id[15];SetColor(45);gotoxy(10+45,10);printf("\xb2 Enter id to add :");fflush(stdin);gets(s_id);
    int print = 50,isFound=0;
    FILE *fp;
    fp = fopen("record.txt","ab+");
    if(fp == NULL){
        MessageBox(0,"\aError in Opening file\nMake sure your file is not write protected","Warning",0);///if we fail to open file...

    }
    else{
        while(fread(&stu,sizeof(stu),1,fp) == 1){
        if(strcmp(s_id,stu.ID) == 0){///We check here is that Id is already exist or not....
            isFound = 1;
            break;
        }
    }
        if(isFound==0){///if The information was not exist already we entered in the loop...
        fflush(stdin);
        gotoxy(print,12);printf("\xB2 ID            : ");gets(stu.ID);
        gotoxy(print,14);printf("\xB2 Name          : ");gets(stu.name);
        gotoxy(print,16);printf("\xB2 Father's name : ");gets(stu.Fname);
        gotoxy(print,18);printf("\xB2 Mother's name : ");gets(stu.Mname);
        gotoxy(print,20);printf("\xB2 Date of birth : ");gets(stu.db);
        gotoxy(print,22);printf("\xB2 Address       : ");gets(stu.add);
        gotoxy(print,24);printf("\xB2 Department    : ");gets(stu.Dep);
        gotoxy(print,26);printf("\xB2 Intake        : ");scanf("%d",&stu.Intake);
        gotoxy(print,28);printf("\xB2 Section       : ");scanf("%d",&stu.sec);
        gotoxy(print,30);printf("\xb2 Blood group   : ");fflush(stdin);gets(stu.bgrp);
        gotoxy(print,32);printf("\xB2 Nationality   : ");gets(stu.nat);
        gotoxy(print,34);printf("\xB2 Mobile        : ");gets(stu.phone_no);
        fwrite(&stu, sizeof(stu), 1, fp);
        gotoxy(25+45,36); printf("The record is successfully added.");
        }
        else{///else the program will give  us a warning....
            gotoxy(15+45,15);printf("\xb2 \aThe Information Already Exist........");
        }
    }

    SetColor(28);
    fclose(fp);
    lol:gotoxy(10+45,38);printf("Do you want to add more(y/n)?");///Here we  ask user if he/she want to add more student info.
    int c;fflush(stdin);char d=_getch();
    if(d=='n'||d=='N')
            c=2;
    else if(d=='y'||d=='Y')
            c=1;
    switch(c)
    {
        case 1:
            add_student();
            break;
        case 2:
            add_option();
            break;
        default:
            goto lol;
    }
}
///For Search @Student information by their ID.--------------------------------------------------------------------------------
void src_ID(int a,char b[15]){
    system("CLS");
    window();
    print_heading(78," Search Record ");
    SetColor(45);
    char s_id[15];
    int isFound = 0,p=45;
    gotoxy(25+45,10);printf("\xB2 Enter ID to Search: ");fflush(stdin);
    gets(s_id);
    FILE *fp;
    fp = fopen("record.txt","rb");
    while(fread(&stu,sizeof(stu),1,fp) == 1){
        if(strcmp(s_id,stu.ID) == 0){
            isFound = 1;
            break;
        }
    }
    if(isFound == 1){
        gotoxy(5+p,12);printf("\xB2 The record is Found");
        gotoxy(5+p,14);printf("\xB2 ID            : %s",stu.ID);
        gotoxy(5+p,15);printf("\xB2 Name          : %s.",stu.name);
        gotoxy(5+p,16);printf("\xB2 Father's Name : %s.",stu.Fname);
        gotoxy(5+p,17);printf("\xB2 Mother's Name : %s.",stu.Mname);
        gotoxy(5+p,18);printf("\xB2 Date of birth : %s.",stu.db);
        gotoxy(5+p,19);printf("\xB2 Address       : %s.",stu.add);
        gotoxy(5+p,20);printf("\xB2 Department    : %s.",stu.Dep);
        gotoxy(5+p,21);printf("\xB2 Intake        : %d.",stu.Intake);
        gotoxy(5+p,22);printf("\xB2 Section       : %d.",stu.sec);
        gotoxy(5+p,23);printf("\xB2 Blood group   : \"%s\"",stu.bgrp);
        gotoxy(5+p,24);printf("\xB2 Nationality   : %s.",stu.nat);
        gotoxy(5+p,25);printf("\xB2 Mobile        : %s",stu.phone_no);
    }else{
        gotoxy(10+p,15);printf("Sorry, No record found in the database");
    }
    SetColor(28);
    fclose(fp);
    lol:gotoxy(10+p,27);printf("Do you want to search more(y/n)?");///Here we  ask user if he/she want to search for more student info.
    int c;fflush(stdin);char d=_getch();
    if(d=='n'||d=='N')
            c=2;
    else if(d=='y'||d=='Y')
            c=1;
    switch(c)
    {
        case 1:
            src_ID(a,b);break;
        case 2:
            stu_src(a,b);
            break;
        default:
            goto lol;
    }
}
/// this function is for search the information of a student by their name or part of the name
void src_name(int a,char b[15])
{
    system("CLS");
    window();
    char nam[35],comp[35],temp[35];int length ;
    print_heading(75+3," Search Name ");
    gotoxy(50,14);SetColor(45);printf("\xdb\xdb\xb2 Enter Name:");fflush(stdin);gets(nam);fflush(stdin);
    system("CLS");
    window2();
    print_heading(77," Student List ");
    int j=12,l=1,k=10;SetColor(45);gotoxy(8+23,10);printf("\xDB\xB2\xB2          ID                Student Name              Department         Intake            Sec      \xB2\xB2\xDB");
    FILE *fp;
    fp=fopen("record.txt","rb");
    while(fread(&stu,sizeof(stu),1,fp)==1)
    {
        strcpy(temp,stu.name);
        int res=match(temp,nam);
        if(res==1){
        k+=2;
        SetColor(45);
        gotoxy(11+23,j);printf("%d.",l);
        gotoxy(17+23,j);printf("%s",stu.ID);
        gotoxy(36+23,j);printf("%s",stu.name);
        gotoxy(69+23,j);printf("%s",stu.Dep);
        gotoxy(86+23,j);printf("%d",stu.Intake);
        gotoxy(103+23,j);printf("%d",stu.sec);
        j+=2;l++;SetColor(17);
        gotoxy(0+23,k-1);printf("%c",186);
        gotoxy(0+23,k);printf("%c",186);
        gotoxy(120+23,k-1);printf("%c",186);
        gotoxy(120+23,k);printf("%c",186);Sleep(50);
        }
    }
    fclose(fp);
    if(l==1)
    {
        SetColor(4);
        gotoxy(45+23,j);printf("No Matching result found!");
    }
    int i;
    SetColor(17);
    for(i=k+1;i<k+8;i++){
        gotoxy(0+23,i);printf("%c",186);
        gotoxy(120+23,i);printf("%c",186);
    }
    gotoxy(0+23,i);printf("%c",200);
    gotoxy(120+23,i);printf("%c",188);
    for(int f = 1+23; f <120+23; f++){
        gotoxy(f,i);
        printf("%c",205);///for top horizontal line...
    }
    SetColor(1);
    gotoxy(45+23,j+3);printf("Enter any key to Continue..........>>>>>>>> ");
    _getch();
    stu_src(a,b);
}
/// This function is  made for search for the information of a @student by their intake and section
void src_intake(int a,char b[15])
{
    system("CLS");
    window();
    int intake,sec;
    print_heading(67+5," Search Intake & Section ");
    gotoxy(50,14);SetColor(45);printf("\xdb\xdb\xb2 Enter Intake: ");scanf("%d",&intake);fflush(stdin);
    gotoxy(50,16); printf("\xdb\xdb\xb2 Enter Section: ");scanf("%d",&sec);fflush(stdin);
    system("CLS");
    window2();
    print_heading(77," Student List ");
    int j=12,l=1,k=10;SetColor(45);gotoxy(8+23,10);printf("\xDB\xB2\xB2          ID                Student Name              Department         Intake            Sec      \xB2\xB2\xDB");
    FILE *fp;
    fp=fopen("record.txt","rb");
    while(fread(&stu,sizeof(stu),1,fp)==1)
    {
        if(intake==stu.Intake&&sec==stu.sec){
        k+=2;
        SetColor(45);
        gotoxy(11+23,j);printf("%d.",l);
        gotoxy(17+23,j);printf("%s",stu.ID);
        gotoxy(36+23,j);printf("%s",stu.name);
        gotoxy(69+23,j);printf("%s",stu.Dep);
        gotoxy(86+23,j);printf("%d",stu.Intake);
        gotoxy(103+23,j);printf("%d",stu.sec);
        j+=2;l++;SetColor(17);
        gotoxy(0+23,k-1);printf("%c",186);
        gotoxy(0+23,k);printf("%c",186);
        gotoxy(120+23,k-1);printf("%c",186);
        gotoxy(120+23,k);printf("%c",186);Sleep(50);
        }
    }
    fclose(fp);
    if(l==1)
    {
        SetColor(4);
        gotoxy(45+23,j);printf("No Matching result found!");
    }
    int i;
    SetColor(17);
    for(i=k+1;i<k+8;i++){
        gotoxy(0+23,i);printf("%c",186);
        gotoxy(120+23,i);printf("%c",186);
    }
    gotoxy(0+23,i);printf("%c",200);
    gotoxy(120+23,i);printf("%c",188);
    for(int f = 1+23; f <120+23; f++){
        gotoxy(f,i);
        printf("%c",205);///for top horizontal line...
    }
    SetColor(1);
    gotoxy(45+23,j+3);printf("Enter any key to Continue..........>>>>>>>> ");
    _getch();
    stu_src(a,b);
}

///This function will help for search all the student of department
void src_dep(int a,char b[15])
{
    system("CLS");
    window();
    char dep[10];
    print_heading(73+2," Search Department ");
    gotoxy(50,14);SetColor(45);printf("\xdb\xdb\xb2 Enter Department Name:");fflush(stdin);gets(dep);fflush(stdin);
    system("CLS");
    window2();
    print_heading(77," Student List ");
    int j=12,l=1,k=10;SetColor(45);gotoxy(8+23,10);printf("\xDB\xB2\xB2          ID                Student Name              Department         Intake            Sec      \xB2\xB2\xDB");
    FILE *fp;
    fp=fopen("record.txt","rb");
    while(fread(&stu,sizeof(stu),1,fp)==1)
    {
        if(strcmp(dep,stu.Dep)==0){
        k+=2;
        SetColor(45);
        gotoxy(11+23,j);printf("%d.",l);
        gotoxy(17+23,j);printf("%s",stu.ID);
        gotoxy(36+23,j);printf("%s",stu.name);
        gotoxy(69+23,j);printf("%s",stu.Dep);
        gotoxy(86+23,j);printf("%d",stu.Intake);
        gotoxy(103+23,j);printf("%d",stu.sec);
        j+=2;l++;SetColor(17);
        gotoxy(0+23,k-1);printf("%c",186);
        gotoxy(0+23,k);printf("%c",186);
        gotoxy(120+23,k-1);printf("%c",186);
        gotoxy(120+23,k);printf("%c",186);Sleep(50);
        }
    }
    fclose(fp);
    if(l==1)
    {
        SetColor(4);
        gotoxy(45+23,j);printf("No Matching result found!");
    }
    SetColor(17);
    int i;
    for(i=k+1;i<k+8;i++){
        gotoxy(0+23,i);printf("%c",186);
        gotoxy(120+23,i);printf("%c",186);
    }
    gotoxy(0+23,i);printf("%c",200);
    gotoxy(120+23,i);printf("%c",188);
    for(int f = 1+23; f <120+23; f++){
        gotoxy(f,i);
        printf("%c",205);///for top horizontal line...
    }
    SetColor(1);
    gotoxy(45+23,j+3);printf("Enter any key to Continue..........>>>>>>>> ");
    _getch();
    stu_src(a,b);
}

/// This function print the whole @Student @list of the @INSTITUTION
void Student_list(int a,char b[15]){///For Student list function.------------------------------------------------------------------------------------
    system("CLS");
    window2();
    print_heading(77," Student List ");
    int j=12,l=1,k=10;SetColor(45);gotoxy(8+23,10);printf("\xDB\xB2\xB2          ID                Student Name              Department         Intake            Sec      \xB2\xB2\xDB");
    FILE *fp;
    fp=fopen("record.txt","rb");
    while(fread(&stu,sizeof(stu),1,fp)==1)
    {
        k+=2;
        SetColor(45);
        gotoxy(11+23,j);printf("%d.",l);
        gotoxy(17+23,j);printf("%s",stu.ID);
        gotoxy(36+23,j);printf("%s",stu.name);
        gotoxy(69+23,j);printf("%s",stu.Dep);
        gotoxy(86+23,j);printf("%d",stu.Intake);
        gotoxy(103+23,j);printf("%d",stu.sec);
        j+=2;l++;SetColor(17);
        gotoxy(0+23,k-1);printf("%c",186);
        gotoxy(0+23,k);printf("%c",186);
        gotoxy(120+23,k-1);printf("%c",186);
        gotoxy(120+23,k);printf("%c",186);Sleep(50);
    }
    fclose(fp);
    int i;
    for(i=k+1;i<k+8;i++){
        gotoxy(0+23,i);printf("%c",186);
        gotoxy(120+23,i);printf("%c",186);
    }
    gotoxy(0+23,i);printf("%c",200);
    gotoxy(120+23,i);printf("%c",188);
    for(int f = 1+23; f <120+23; f++){
        gotoxy(f,i);
        printf("%c",205);///for top horizontal line...
    }
    SetColor(1);
    gotoxy(45+23,j+3);printf("Enter any key to Continue..........>>>>>>>> ");
    _getch();
    stu_src(a,b);
}

/// This function is  for @Modifying @Student information
void mod_student(){///For Modify student function.-----------------------------------------------------------------------------------
    system("CLS");
    window1();
    print_heading(65," Modify Record ");
    SetColor(45);
    char s_id[15];
    int isFound = 0, print = 50;
    gotoxy(print,9);printf("\xb2 Enter ID to Modify: ");fflush(stdin);
    gets(s_id);
    FILE *fp;
    fp = fopen("record.txt","rb+");
    while(fread(&stu, sizeof(stu),1,fp) == 1){
        if(strcmp(s_id, stu.ID) == 0){///Check the id is exist or not
            fflush(stdin);
            gotoxy(print,11);printf("\xB2 ID            : ");gets(stu.ID);
            gotoxy(print,13);printf("\xB2 Name          : ");gets(stu.name);
            gotoxy(print,15);printf("\xB2 Father's name : ");gets(stu.Fname);
            gotoxy(print,17);printf("\xB2 Mother's name : ");gets(stu.Mname);
            gotoxy(print,19);printf("\xB2 Date of birth : ");gets(stu.db);
            gotoxy(print,21);printf("\xB2 Address       : ");gets(stu.add);
            gotoxy(print,23);printf("\xB2 Department    : ");gets(stu.Dep);
            gotoxy(print,25);printf("\xB2 Intake        : ");scanf("%d",&stu.Intake);
            gotoxy(print,27);printf("\xB2 Section       : ");scanf("%d",&stu.sec);
            gotoxy(print,29);printf("\xB2 Blood group   : ");fflush(stdin);gets(stu.bgrp);
            gotoxy(print,31);printf("\xB2 Nationality   : ");gets(stu.nat);
            gotoxy(print,33);printf("\xB2 Phone Number  : ");gets(stu.phone_no);
            fseek(fp,-sizeof(stu), SEEK_CUR);
            fwrite(&stu,sizeof(stu), 1, fp);
            isFound = 1;
            break;
        }
    }
    if(!isFound){
        gotoxy(10+45, 21);printf("\xdb No Record Found");
    }
    fclose(fp);
    SetColor(28);
    lol:gotoxy(10+45,37);printf("\xdb\xb2 Do you want to modify more(y/n)?");///Here we  ask user if he/she want to modify more student info.
    int c;fflush(stdin);char d=_getch();
    if(d=='n'||d=='N')
            c=2;
    else if(d=='y'||d=='Y')
            c=1;
    switch(c)
    {
        case 1:
            mod_student();break;
        case 2:
            stu_mod_op();
            break;
        default:
            goto lol;
    }
}

/// This function is for @Deleting a @Student Information...
void delete_student(){///For Delete student function.--------------------------------------------------------------------------------
    system("CLS");
    window();
    print_heading(65,"Delete Record");
    SetColor(45);
    char s_id[15];
    int isFound = 0,p=45;
    gotoxy(25+p,10);printf("\xB2 Enter ID to Delete: ");fflush(stdin);
    gets(s_id);
    FILE *fp, *temp;
    fp = fopen("record.txt","rb+");
    temp = fopen("temp.txt","wb+");
    while(fread(&stu, sizeof(stu),1,fp) == 1){
        if(strcmp(s_id, stu.ID) != 0){
            fseek(temp,0,SEEK_CUR);
            fwrite(&stu,sizeof(stu),1,temp);
        }
        else{
                isFound=1;
            }
    }
    fclose(fp);
    fclose(temp);
    fflush(stdin);
    remove("record.txt");
    rename("temp.txt","record.txt");
    if(isFound==0){
        gotoxy(15+p,12);printf("The Record Not Found..");
    }
    else{
        gotoxy(15+p,13);printf("The record is successfully deleted");
    }
    SetColor(28);
    lol:gotoxy(15+p,18);printf("Do you want to delete more(y/n)?");
    int c;fflush(stdin);char d=_getch();
    if(d=='n'||d=='N')
            c=2;
    else if(d=='y'||d=='Y')
            c=1;
    switch(c)
    {
        case 1:
            delete_student();
            break;
        case 2:
            stu_mod_op();
            break;
        default:
            goto lol;
    }
}
