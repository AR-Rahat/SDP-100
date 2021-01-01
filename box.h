///@ We use This file for  various kind of @Box That used  in
///program
///& also use  this  for print various heading
///of this program @


///For time.-------------------------------------------------------------------------------------------------------------
int t(void){
    time_t t;
    time(&t);
    printf("Date and time:%s\n",ctime(&t));/* *This will take the time date from system.
                                              *Then print it.
                                            */
    return 0 ;
}

/// This function will draw a rectangle which one is smallest one..............
void drawRectangle(){
    ClearConsoleToColors(17,15);
    int i, j;
    gotoxy(45,0);
    printf("%c",201);///for top left corner...
    for(i = 1; i < 78; i++){
        gotoxy(i+45, 0);
        printf("%c",205);///for top horizontal line...
    }
    gotoxy(78+45,0);
    printf("%c",187);///for top right corner.....
    for(i = 1; i < 29; i++){
        gotoxy(78+45, i);
        if(i == 6){
            printf("%c",185);///for middle right corner...
        }else{
            printf("%c",186);///for right vertical line...
        }
    }
    gotoxy(78+45, 29);
    printf("%c",188);///for bottom right corner...
    for(i = 77; i > 0; i--){
        gotoxy(i+45,29);
            printf("%c",205);///for bottom horizontal line.....

    }
    gotoxy(45,29);
    printf("%c",200);///for bottom left corner...
    for(i = 28; i > 0; i--){
        gotoxy(0+45,i);
        if(i == 6){
            printf("%c",204);///for middle left corner....
        }else{
            printf("%c",186);///for left vertical line...
        }
    }

    for(i = 1; i < 78; i++){
        gotoxy(i+45,6);
        printf("%c",205);///for middle horizontal line....
    }


}

/// This function also draw a rectangle but a bigger one......
void drawRectangle1(){
    ClearConsoleToColors(17,15);
    int i, j;
    gotoxy(45,0);
    printf("%c",201);///for top left corner...
    for(i = 1+45; i < 78+45; i++){
        gotoxy(i, 0);
        printf("%c",205);///for top horizontal line...
    }
    gotoxy(78+45,0);
    printf("%c",187);///for top right corner.....
    for(i = 1; i < 40; i++){
        gotoxy(78+45, i);
        if(i == 6){
            printf("%c",185);///for middle right corner...
        }else{
            printf("%c",186);///for right vertical line...
        }
    }
    gotoxy(78+45, 40);
    printf("%c",188);///for bottom right corner...
    for(i = 77+45; i > 0+45; i--){
        gotoxy(i,40);
            printf("%c",205);///for bottom horizontal line.....

    }
    gotoxy(0+45,40);
    printf("%c",200);///for bottom left corner...
    for(i = 39; i > 0; i--){
        gotoxy(0+45,i);
        if(i == 6){
            printf("%c",204);///for middle left corner....
        }else{
            printf("%c",186);///for left vertical line...
        }
    }

    for(i = 1; i < 78; i++){
        gotoxy(i+45,6);
        printf("%c",205);///for middle horizontal line....
    }


}

/// This Function draw the biggest box of this program..........
void Uper_box(){
    ClearConsoleToColors(17,15);
    int i, j;
    gotoxy(23,0);
    printf("%c",201);///for top left corner...
    for(i = 1; i <120; i++){
        gotoxy(i+23, 0);
        printf("%c",205);///for top horizontal line...
    }
    gotoxy(143,0);
    printf("%c",187);///for top right corner.....
    for(i = 1; i < 11; i++){
        gotoxy(143, i);
          printf("%c",186);///for right vertical line...
    }
    gotoxy(143,6);
    printf("%c",185);///for bottom right corner...
    for(i = 10 ; i > 0; i--){
        gotoxy(23,i);
        if(i == 6){
            printf("%c",204);///for middle left corner....
        }else{
            printf("%c",186);///for left vertical line...
        }
    }
    for(i = 1; i <120; i++){
        gotoxy(i+23,6);
        printf("%c",205);///for middle horizontal line....
    }
}

/// This Function is used for printing Our Institution name
void window(){///We use this in //main menu,Search_student,Delete_student// search --------------------------------------------------
    system("CLS");
    drawRectangle();
    gotoxy(59,2);
    SetColor(17);
    printf("\xDB\xB2 ======= INFORMATION MANAGEMENT SYSTEMS ======= \xB2\xDB");
    gotoxy(10+45,3);
    printf("\xDB\xB2 ====Bangladesh University of Business & Technology==== \xB2\xDB");
    gotoxy(26+45,4);
    printf("\xDB\xDB\xDB\xB2\xB2 = Estd : 2003 = \xB2\xB2\xDB\xDB\xDB");
    gotoxy(25+45,24);
    SetColor(17);

}

/// This Function is also used for printing Our Institution name........
void window1(){///We use this window for //Add_student and Modify_Student// search --------------------------------------------------
    system("CLS");
    drawRectangle1();
    gotoxy(59,2);
    SetColor(17);
    printf("\xDB\xB2 ======= INFORMATION MANAGEMENT SYSTEMS ======= \xB2\xDB");
    gotoxy(10+45,3);
    printf("\xDB\xB2 ====Bangladesh University of Business & Technology==== \xB2\xDB");
    gotoxy(26+45,4);
    printf("\xDB\xDB\xDB\xB2\xB2 = Estd : 2003 = \xB2\xB2\xDB\xDB\xDB");
    gotoxy(25+45,24);
    SetColor(17);

}
/// This Function is also used for printing Our Institution name
void window2(){///We use this window for //Student_list// search --------------------------------------------------------------------
    system("cls");
    Uper_box();
    gotoxy(57,2);
    SetColor(17);
    printf("\xDB\xB2 ======= INFORMATION MANAGEMENT SYSTEMS ======= \xB2\xDB");
    gotoxy(30+23,3);
    printf("\xDB\xB2 ====Bangladesh University of Business & Technology==== \xB2\xDB");
    gotoxy(46+23,4);
    printf("\xDB\xDB\xDB\xB2\xB2 = Estd : 2003 = \xB2\xB2\xDB\xDB\xDB");
    gotoxy(45+23,24);
    SetColor(17);
}

/// We use this function for the Heading of  all the function of the program..
void print_heading(int x,const char st[]){
    SetColorAndBackground(31,28);
    gotoxy(x,8);printf("%s",st);
    SetColorAndBackground(17,15);
}

