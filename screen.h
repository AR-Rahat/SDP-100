/// @ We have welcome & Exit screen of  this program @ ///




/// THIS FUNCTION IS THE WELCOME SCREEN OF THE PROGRAM...
void Wlc_screen(){
    system("CLS");
    SetColor(29);
    Sleep(300);
    gotoxy(39,5); printf("\xdb\xdb\xb2  **       ** ********* **          ******    *****   *         * *********       ********        \xb2\xdb\xdb");
    gotoxy(39,6); printf("\xdb\xdb\xb2  **       ** ********* **         ********  *******  **       ** *********      **********       \xb2\xdb\xdb");
    gotoxy(39,7); printf("\xdb\xdb\xb2  **       ** **      * **        **      * **     ** ***     *** **      *     **        **      \xb2\xdb\xdb");
    gotoxy(39,8); printf("\xdb\xdb\xb2  **   *   ** **        **        **        **     ** ****   **** **           **  **  **  **     \xb2\xdb\xdb");
    gotoxy(39,9); printf("\xdb\xdb\xb2  **  ***  ** *******   **        **        **     ** ** ** ** ** *******      **  **  **  **     \xb2\xdb\xdb");
    gotoxy(39,10);printf("\xdb\xdb\xb2  ** ** ** ** *******   **        **        **     ** **  ***  ** *******      **          **     \xb2\xdb\xdb");
    gotoxy(39,11);printf("\xdb\xdb\xb2  ****   **** **        **        **        **     ** **   *   ** **           **  *    *  **     \xb2\xdb\xdb");
    gotoxy(39,12);printf("\xdb\xdb\xb2  ***     *** **      * **      * **      * **     ** **       ** **      *     **  ****  **      \xb2\xdb\xdb");
    gotoxy(39,13);printf("\xdb\xdb\xb2  **       ** ********* *********  ********  *******  **       ** *********      **********       \xb2\xdb\xdb");
    gotoxy(39,14);printf("\xdb\xdb\xb2  *         * ********* *********   ******    *****   **       ** *********       ********        \xb2\xdb\xdb");
    gotoxy(60,17);SetColor(1);
    Sleep(50);
    printf("\xdb\xb2\xb2  To BUBT Student Management System Project  \xb2\xb2\xdb");
    gotoxy(60,19);
    printf("\xdb\xb2\xb2              By TEAM PEGASUS                \xb2\xb2\xdb");
    Sleep(500);
    gotoxy(60,21);
    SetColor(28);
    char E[52]={"Press Any Key to Continue.........>>>>>>>>>"};
    for(int i=0;i<43;i++){
        Sleep(50);
        printf("%c",E[i]);
    }
    _getch();
}

/// THIS FUNCTION WILL APPEAR WHEN WE LOGOUT FROM ONE USER...
void Again(){
    system("CLS");
    SetColor(1);
    gotoxy(13,7); printf("\xdb\xdb\xdb\xb2  ******      *****      **      **   *****   **     **    **     **   *****   **     ** **********    **********   *****              \xb2\xdb\xdb\xdb");
    gotoxy(13,8); printf("\xdb\xdb\xdb\xb2  *******    *******      **    **   *******  **     **    **     **  *******  ***    ** **********    **********  *******             \xb2\xdb\xdb\xdb");
    gotoxy(13,9); printf("\xdb\xdb\xdb\xb2  **    **  **     **      **  **   **     ** **     **    **  *  ** **     ** ****   **     **            **     **     **            \xb2\xdb\xdb\xdb");
    gotoxy(13,10);printf("\xdb\xdb\xdb\xb2  **     ** **     **       ****    **     ** **     **    ** *** ** ********* ** **  **     **            **     **     **    ******  \xb2\xdb\xdb\xdb");
    gotoxy(13,11);printf("\xdb\xdb\xdb\xb2  **     ** **     **        **     **     ** **     **    **** **** ********* **  ** **     **            **     **     **    ******  \xb2\xdb\xdb\xdb");
    gotoxy(13,12);printf("\xdb\xdb\xdb\xb2  **    **  **     **        **     **     ** **     **    ***   *** **     ** **   ****     **            **     **     **            \xb2\xdb\xdb\xdb");
    gotoxy(13,13);printf("\xdb\xdb\xdb\xb2  *******    *******         **      *******   *******     **     ** **     ** **    ***     **            **      *******             \xb2\xdb\xdb\xdb");
    gotoxy(13,14);printf("\xdb\xdb\xdb\xb2  *****       *****         ****      *****     *****      *       * **     ** **     **     **            **       *****              \xb2\xdb\xdb\xdb");
    SetColor(2);
    gotoxy(36,17);printf("\xdb\xdb\xdb\xb2     ******    *****   **     ** **********  ********  **     ** **     ** *********    \xb2\xdb\xdb\xdb");
    gotoxy(36,18);printf("\xdb\xdb\xdb\xb2    ********  *******  ***    ** **********  ********  ***    ** **     ** *********    \xb2\xdb\xdb\xdb");
    gotoxy(36,19);printf("\xdb\xdb\xdb\xb2   **      * **     ** ****   **     **         **     ****   ** **     ** **           \xb2\xdb\xdb\xdb");
    gotoxy(36,20);printf("\xdb\xdb\xdb\xb2   **        **     ** ** **  **     **         **     ** **  ** **     ** ******       \xb2\xdb\xdb\xdb");
    gotoxy(36,21);printf("\xdb\xdb\xdb\xb2   **        **     ** **  ** **     **         **     **  ** ** **     ** ******       \xb2\xdb\xdb\xdb");
    gotoxy(36,22);printf("\xdb\xdb\xdb\xb2   **      * **     ** **   ****     **         **     **   **** **     ** **           \xb2\xdb\xdb\xdb");
    gotoxy(36,23);printf("\xdb\xdb\xdb\xb2    ********  *******  **    ***     **      ********  **    ***  *******  *********    \xb2\xdb\xdb\xdb");
    gotoxy(36,24);printf("\xdb\xdb\xdb\xb2     ******    *****   **     **     **      ********  **     **   *****   *********    \xb2\xdb\xdb\xdb");
    SetColor(1);
    gotoxy(57,28);printf("\xdb\xdb\xdb\xb2                   **               *****      \xb2\xdb\xdb\xdb");
    gotoxy(57,29);printf("\xdb\xdb\xdb\xb2                  **               *******     \xb2\xdb\xdb\xdb");
    gotoxy(57,30);printf("\xdb\xdb\xdb\xb2                 **               **     **    \xb2\xdb\xdb\xdb");
    gotoxy(57,31);printf("\xdb\xdb\xdb\xb2                **                 **   **     \xb2\xdb\xdb\xdb");
    gotoxy(57,32);printf("\xdb\xdb\xdb\xb2               **                      **      \xb2\xdb\xdb\xdb");
    gotoxy(57,33);printf("\xdb\xdb\xdb\xb2              **                       **      \xb2\xdb\xdb\xdb");
    gotoxy(57,34);printf("\xdb\xdb\xdb\xb2             **                                \xb2\xdb\xdb\xdb");
    gotoxy(57,35);printf("\xdb\xdb\xdb\xb2            **                         **      \xb2\xdb\xdb\xdb");
    gotoxy(57,36);printf("\xdb\xdb\xdb\xb2           **                          **      \xb2\xdb\xdb\xdb");
    SetColor(2);
    gotoxy(64,28);printf("**      **");
    gotoxy(64,29);printf(" **    **");
    gotoxy(64,30);printf("  **  **");
    gotoxy(64,31);printf("   ****");
    gotoxy(64,32);printf("    **");
    gotoxy(64,33);printf("    **");
    gotoxy(64,34);printf("    **");
    gotoxy(64,35);printf("    **");
    gotoxy(64,36);printf("   ****");
    SetColor(4);
    gotoxy(83,28);printf("*      **");
    gotoxy(83,29);printf("**     **");
    gotoxy(83,30);printf("***    **");
    gotoxy(83,31);printf("****   **");
    gotoxy(83,32);printf("** **  **");
    gotoxy(83,33);printf("**  ** **");
    gotoxy(83,34);printf("**   ****");
    gotoxy(83,35);printf("**    ***");
    gotoxy(83,36);printf("**     **");
    SetColor(28);gotoxy(57+14,41);printf("\xdb\xdb\xb2  Enter Your Choice: ");
    while(1){
    int c=0;char d;
    d =_getch();fflush(stdin);
    if(d=='y'||d=='Y')
        c=1;
    else if(d=='n'||d=='N')
        c=2;
    switch(c)
    {
    case 1:
        login_option();
        break;
    case 2:
        Exit_program();
        break;
    default:
        break;
    }
 }

}

/// THIS IS THE EXIT SCREEN OF THE PROGRAM....
void Exit_program(){

    system("CLS");
    system("color F2");
    int p=50;
    Sleep(50);
    gotoxy(p,2);
    Sleep(50);
    printf("\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\t      Software Development 1 ; CSE 100     \t\xB2\xB2\xB2\xB2\xDB\xDB\xDB");
    gotoxy(p,4);
    Sleep(100);
    printf("\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\t    Student Information Management system  \t\xB2\xB2\xB2\xB2\xDB\xDB\xDB");
    gotoxy(p,6);
    Sleep(100);
    printf("\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\t             is brought to you by         \t\xB2\xB2\xB2\xB2\xDB\xDB\xDB");
    gotoxy(p,8);
    Sleep(100);
    printf("\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2\t                 TEAM PEGASUS             \t\xB2\xB2\xB2\xB2\xDB\xDB\xDB");


    SetColor(29);
    gotoxy(p-7,14);Sleep(100);printf("\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2   ********** **     **   *****   **     ** **   **   *******     \xB2\xB2\xB2\xB2\xDB\xDB\xDB");
    gotoxy(p-7,15);Sleep(100);printf("\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2   ********** **     **  *******  ***    ** **  **   *********    \xB2\xB2\xB2\xB2\xDB\xDB\xDB");
    gotoxy(p-7,16);Sleep(100);printf("\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2       **     **     ** **     ** ****   ** ** **    **           \xB2\xB2\xB2\xB2\xDB\xDB\xDB");
    gotoxy(p-7,17);Sleep(100);printf("\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2       **     ********* ********* ** **  ** ****     ********     \xB2\xB2\xB2\xB2\xDB\xDB\xDB");
    gotoxy(p-7,18);Sleep(100);printf("\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2       **     ********* ********* **  ** ** ****      ********    \xB2\xB2\xB2\xB2\xDB\xDB\xDB");
    gotoxy(p-7,19);Sleep(100);printf("\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2       **     **     ** **     ** **   **** ** **           **    \xB2\xB2\xB2\xB2\xDB\xDB\xDB");
    gotoxy(p-7,20);Sleep(100);printf("\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2       **     **     ** **     ** **    *** **  **   *********    \xB2\xB2\xB2\xB2\xDB\xDB\xDB");
    gotoxy(p-7,21);Sleep(100);printf("\t\xDB\xDB\xDB\xB2\xB2\xB2\xB2       **     **     ** **     ** **     ** **   **   *******     \xB2\xB2\xB2\xB2\xDB\xDB\xDB");


    gotoxy(p-6,24);
    SetColor(4);
    char E[40]={"Exiting in 2 second...........>>>>>>>>>"};
    for(int i=0;i<39;i++){
        Sleep(50);
        printf("%c",E[i]);
    }
    printf("\n\n");
    Sleep(2000);///This will delay 3 second......
    SetColor(0);
    Exit();

}
///----------------------------------------------------------------------------------------------------------------------------------///

