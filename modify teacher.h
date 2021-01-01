/// We will define all the function which is used by administrator for
/// teacher information.....



/// here start the functions definition...
/// this function is for making a substring from a Whole string
/*void substring(char s[], char sub[], int p, int l) {
   int c = 0;

   while (c < l) {
      sub[c] = s[p+c-1];
      c++;
   }
   sub[c] = '\0';
}
*/
int match(char T[30],char S[30])
{
    int i,j,flag=0;
    int len1=strlen(T);
    int len2=strlen(S);
    /// We  just make two string lower case here so that it can't be case sensitive anymore...
    for(i=0;i<len1;i++)
        if(T[i]>='A'&&T[i]<='Z')
            T[i]=tolower(T[i]);

    for(i=0;i<len2;i++)
        if(S[i]>='A'&&S[i]<='Z')
            S[i]=tolower(S[i]);


    if(len1<len2)
    {
        return 0;
    }
    else
    {
        int pos=0;
        for(i=0;i<=len1-len2;i++)
        {
            for(j=0;j<len2;j++)
            {
                if(S[j]!=T[pos+j])
                    break;
            }
            if(j==len2)
            {
                flag=1;
                break;
            }
            pos++;
        }
        if(flag==1)
            return 1;
        else
            return 0;

    }
}


/// for adding a @Teacher information
void add_teacher(){
    system("CLS");
    int isFound=0;
    int x=50;
    window1();
    print_heading(70," Teacher Registration ");
    FILE *l;
    char b[10];
    gotoxy(55,10);SetColor(45);printf("Enter teacher code: ");fflush(stdin);gets(b);
    l=fopen("record teacher.txt","ab+");
    if(l == NULL){
        MessageBox(0,"\aError in Opening file\nMake sure your file is not write protected","Warning",0);///if we fail to open file...
    }
    else
    {
        while(fread(&th,sizeof(th),1,l)==1){
            if(strcmp(b,th.cod)==0){
                isFound=1;
                break;
            }
        }
        if(isFound==0){
            clearLine(10);
            fflush(stdin);
            gotoxy(x,12);printf("\xb2 Name         : ");gets(th.nam);
            gotoxy(x,14);printf("\xb2 Position     : ");gets(th.pos);
            gotoxy(x,16);printf("\xb2 Short code   : ");gets(th.cod);
            gotoxy(x,18);printf("\xb2 Department   : ");gets(th.dep);
            gotoxy(x,20);printf("\xb2 Subject      : ");gets(th.sub);
            gotoxy(x,22);printf("\xb2 Address      : ");gets(th.add);
            gotoxy(x,24);printf("\xb2 Blood group  : ");gets(th.bg);
            gotoxy(x,26);printf("\xb2 Nationality  : ");gets(th.nat);
            gotoxy(x,28);printf("\xb2 Phone Number : ");gets(th.pn);
            fwrite(&th,sizeof(th),1,l);
            gotoxy(70,34);printf("\xdb\xb2 The record is successfully added.");
        }
        else
        {
            gotoxy(60,36);printf("\xb2 \aThe information already exist....");
        }

    }
    SetColor(28);
    fclose(l);
    lol: gotoxy(55,38);printf("Do you want to add more(y/n)?");
    int c=0;fflush(stdin);char d=_getch();
    if(d=='n'||d=='N')
            c=2;
    else if(d=='y'||d=='Y')
            c=1;
        switch(c)
    {
        case 1:
            add_teacher();break;
        case 2:
            add_option();break;
        default:
            goto lol;
    }

}
/// For modify @teacher information
void mod_teacher(){///For Modify student function.-----------------------------------------------------------------------------------
    system("CLS");
    window1();
    print_heading(65," Modify Record ");
    SetColor(45);
    char s_id[15];
    int isFound = 0, x = 50;
    gotoxy(x,9);printf("\xb2 Enter Short code to Modify: ");fflush(stdin);
    gets(s_id);fflush(stdin);
    FILE *fp;
    fp = fopen("record teacher.txt","rb+");
    while(fread(&th, sizeof(th),1,fp) == 1){
        if(strcmp(s_id, th.cod) == 0){///Check the id is exist or not
            fflush(stdin);
            clearLine(9);
            gotoxy(x,12);printf("\xb2 Name         : ");gets(th.nam);
            gotoxy(x,14);printf("\xb2 Position     : ");gets(th.pos);
            gotoxy(x,16);printf("\xb2 Short code   : ");gets(th.cod);
            gotoxy(x,18);printf("\xb2 Department   : ");gets(th.dep);
            gotoxy(x,20);printf("\xb2 Subject      : ");gets(th.sub);
            gotoxy(x,22);printf("\xb2 Address      : ");gets(th.add);
            gotoxy(x,24);printf("\xb2 Blood group  : ");gets(th.bg);
            gotoxy(x,26);printf("\xb2 Nationality  : ");gets(th.nat);
            gotoxy(x,28);printf("\xb2 Phone Number : ");gets(th.pn);
            fseek(fp,-sizeof(th), SEEK_CUR);
            fwrite(&th,sizeof(th), 1, fp);
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
            mod_teacher();break;
        case 2:
            tch_mod_op();
            break;
        default:
            goto lol;
    }
}

/// For Delete @Teacher @information
void delete_teacher(){///For Delete student function.--------------------------------------------------------------------------------
    system("CLS");
    window();
    print_heading(65,"Delete Record");
    SetColor(45);
    char s_id[15];
    int isFound = 0,p=45;
    gotoxy(25+p,10);printf("\xB2 Enter short code to Delete: ");fflush(stdin);
    gets(s_id);
    FILE *fp, *temp;
    fp = fopen("record teacher.txt","rb+");
    temp = fopen("temp.txt","wb+");
    while(fread(&stu, sizeof(stu),1,fp) == 1){
        if(strcmp(s_id, th.cod) != 0){
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
    remove("record teacher.txt");
    rename("temp.txt","record teacher.txt");
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
            delete_teacher();
            break;
        case 2:
            tch_mod_op();
            break;
        default:
            goto lol;
    }
}
/// For Search teacher list by their Department
void th_src_dep()
{
    system("CLS");
    window();
    char dep[10];
    print_heading(73+2," Search Department ");
    gotoxy(50,14);SetColor(45);printf("\xdb\xdb\xb2 Enter Department Name:");fflush(stdin);gets(dep);fflush(stdin);
    system("CLS");
    window2();
    print_heading(77," Teacher List ");
    int j=12,l=1,k=10;SetColor(45);gotoxy(8+23,10);printf("\xDB\xB2\xB2       Code             Teacher Name           Department      Subject         Mobile Number         \xB2\xB2\xDB");
    FILE *fp;
    fp=fopen("record teacher.txt","rb");
    while(fread(&th,sizeof(th),1,fp)==1)
    {
        if(strcmp(dep,th.dep)==0){
        k+=2;
        SetColor(45);
        gotoxy(11+23,j);printf("%d.",l);
        gotoxy(17+23,j);printf("%s",th.cod);
        gotoxy(36+20-3,j);printf("%s",th.nam);
        gotoxy(69+16,j);printf("%s",th.dep);
        gotoxy(97,j);printf("%s",th.sub);
        gotoxy(113,j);printf("%s",th.pn);
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
    tch_src();
}
/// For Searching @Teacher information by Name
void th_src_name()
{
    system("CLS");
    window();
    char nam[35],comp[35],temp[35];int length ;
    print_heading(75+3," Search Name ");
    gotoxy(50,14);SetColor(45);printf("\xdb\xdb\xb2 Enter Name:");fflush(stdin);gets(nam);fflush(stdin);
    //length=strlen(nam);
    system("CLS");
    window2();
    print_heading(77," Teacher List ");
    int j=12,l=1,k=10;SetColor(45);gotoxy(8+23,10);printf("\xDB\xB2\xB2       Code             Teacher Name           Department      Subject         Mobile Number         \xB2\xB2\xDB");
    FILE *fp;
    fp=fopen("record teacher.txt","rb");
    while(fread(&th,sizeof(th),1,fp)==1)
    {
        strcpy(temp,th.nam);
        int res=match(temp,nam);
        if(res==1){
        k+=2;
        SetColor(45);
        gotoxy(11+23,j);printf("%d.",l);
        gotoxy(17+23,j);printf("%s",th.cod);
        gotoxy(36+20-3,j);printf("%s",th.nam);
        gotoxy(69+16,j);printf("%s",th.dep);
        gotoxy(97,j);printf("%s",th.sub);
        gotoxy(113,j);printf("%s",th.pn);
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
    tch_src();
}

/// For Printing All the @Teache @list of the institution
void th_src_all()
{
    system("CLS");
    window2();
    print_heading(77," Teacher List ");
    int j=12,l=1,k=10;SetColor(45);gotoxy(8+23,10);printf("\xDB\xB2\xB2       Code             Teacher Name           Department      Subject         Mobile Number         \xB2\xB2\xDB");
    FILE *fp;
    fp=fopen("record teacher.txt","rb");
    while(fread(&th,sizeof(th),1,fp)==1)
    {
        k+=2;
        SetColor(45);
        gotoxy(11+23,j);printf("%d.",l);
        gotoxy(17+23,j);printf("%s",th.cod);
        gotoxy(36+20-3,j);printf("%s",th.nam);
        gotoxy(69+16,j);printf("%s",th.dep);
        gotoxy(97,j);printf("%s",th.sub);
        gotoxy(113,j);printf("%s",th.pn);
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
    tch_src();
}
/// For Search information By @Teacher information by their @Short @Code
void th_src_code()
{
    system("CLS");
    window();
    print_heading(78," Search Record ");
    SetColor(45);
    char s_id[15];
    int isFound = 0,p=45;
    gotoxy(25+45,10);printf("\xB2 Enter Code to Search: ");fflush(stdin);
    gets(s_id);
    FILE *fp;
    fp = fopen("record teacher.txt","rb+");
    while(fread(&th,sizeof(th),1,fp) == 1){
        if(strcmp(s_id,th.cod) == 0){
            isFound = 1;
            break;
        }
    }
    if(isFound == 1){
        gotoxy(5+p,12);printf("\xB2 The record is Found");
        gotoxy(5+p,14);printf("\xB2 Short Code    : %s",th.cod);
        gotoxy(5+p,15);printf("\xB2 Name          : %s.",th.nam);
        gotoxy(5+p,16);printf("\xb2 Position      : %s.",th.pos);
        gotoxy(5+p,17);printf("\xB2 Department    : %s.",th.dep);
        gotoxy(5+p,18);printf("\xb2 Subject       : %s.",th.sub);
        gotoxy(5+p,19);printf("\xB2 Address       : %s.",th.add);
        gotoxy(5+p,20);printf("\xB2 Blood group   : \"%s\"",th.bg);
        gotoxy(5+p,21);printf("\xB2 Nationality   : %s.",th.nat);
        gotoxy(5+p,22);printf("\xB2 Mobile        : %s",th.pn);

        }
        else{
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
            th_src_code();break;
        case 2:
            tch_src();
            break;
        default:
            goto lol;
    }
}
