///This is the header file call @coord ///
///We will use this header file for set cursor position..
///set background and foreground color
///set text color
///Set the  compiler screen to full screen
///Clear text from a particular line

///Some standard header file from mingW......
///------------------------///
#include<time.h>          ///
#include<conio.h>        ///
#include<ctype.h>       ///
#include<stdlib.h>     ///
#include<string.h>    ///
#include<windows.h>  ///
#include<graphics.h>///
///----------------///



/// The functions which we used in the @Project.......*************************************************************
/*void substring(char s[], char sub[], int p, int l);*////Lagbe na so comment...........
void result_sheet(char a[15],char S[15]);
void update_marks(char a[15],char S[15]);
void entry_option(char a[15],char S[15]);
void entry_marks(char a[15],char S[15]);
int match(char T[30],char S[30]);
void Student_option(char a[15]);
void teacher_option(char a[15]);
void src_name(int a,char b[15]);
void view_result(char a[15]);
void tch_details(char a[15]);
void tch_pass(char a[15]);
void stu_pass(char a[15]);
void details(char a[15]);
void result_of_bubt();
void clearLine(int j);
void delete_student();
void delete_teacher();
void search_option();
void login_option();
void Student_list();
void Exit_program();
void th_src_name();
void main_window();
void add_student();
void mod_student();
void mod_teacher();
void add_teacher();
void th_src_code();
void mod_option();
void add_option();
void tch_option();
void tch_regist();
void stu_log_in();
void stu_option();
void stu_mod_op();
void tch_mod_op();
void th_src_dep();
void th_src_all();
void add_option();
void tch_login();
void Ad_login();
void window1();
void window2();
void image();
void stu_src(int a,char b[15]);
void tch_src();
void window();
void regist();
void Again();
void Exit();
///****************************************************************************************************************

/// Some global variable of the project..........****************************************************************
char stp1[30];
char sti1[15];
char p[20];
int isFound=0;
int notfound=0;
char P[30];
char p1[30];
char p2[30];
char c;
int i;
FILE *fp,*ft;
COORD coord = {0,0};///set the coordinate to 0, 0 (top-left corner of window)........
///**************************************************************************************************************

/// The structure we used in the program *************************************************************************
struct student{///Structure for a Student All Information.
    char ID[15];///Student_id...................
    char name[30];///Student_name...............
    char Fname[30];///Student's Father's name...
    char Mname[30];///Student's Mother's name...
    char db[15];///Student's Date of Birth......
    char add[40];///Address of student..........
    char Dep[10];///Student_department..........
    int Intake;///for intake....................
    int sec;///for section......................
    char bgrp[10];///for Blood group............
    char nat[15];///for Nationality.............
    char phone_no[15];///for Phone Number.......
};
struct teacher{
    char nam[40];///teacher's name
    char pos[30];///Teacher's Position
    char cod[10];///Teacher's Short Code
    char dep[20];///Department
    char sub[15];///Subject
    char add[40];///Address
    char bg[5];///Blood Group
    char nat[15];///Nationality
    char pn[15];///Phone number

};
struct pass_stu{
    char sti[15];
    char stp[30];
};
struct teach{
    char code[15];
    char pas[15];
};
struct marks
{
    char id[15];
    char sub[15];
    float mid_marks;
    float final_marks;
    float attend;
    float assignment;
    float total;
    float gpa;
    char grade[5];

};
///**************************************************************************************************************


/// The Object of the structure we used in the program***********************************************************
struct student stu;
struct teacher th;
struct pass_stu st;
struct teach te;
struct marks mr;
///**************************************************************************************************************


/// the definition of the functions.....
///For set the cursor in coordinate.-----------------------------------------------------------------------
void gotoxy(int x, int y){

    coord.X = x; coord.Y = y; /// X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

///This function work same as System("color __").------------------------------------
void ClearConsoleToColors(int ForgC, int BackC){

     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     ///Get the handle to the current output buffer...
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
      /* This is used to reset the carat/cursor to the top left.
      * COORD cord = {0, 0};
      * A return value... indicating how many chars were written
      *   not used but we need to capture this since it will be
      *   written anyway (passing NULL causes an access violation).*/
     DWORD count;
     ///This is a structure containing all of the console info
     /// it is used here to find the size of the console.
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     ///Here we will set the current color
     SetConsoleTextAttribute(hStdOut, wColor);
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          ///This fills the buffer with a given character (in this case 32=space).
          FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
          FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
          ///This will set our cursor position for the next print statement.
          SetConsoleCursorPosition(hStdOut, coord);
     }
     return;
}

///For Automated full screen.-------------------------------------------------------------------------------------
void Full_Screen(){
    keybd_event(
                VK_MENU,
                0x38,
                0,0
                );
    keybd_event(
                VK_RETURN,
                0x1c,
                0,0
                );
    keybd_event(
                VK_RETURN,
                0x1c,
                KEYEVENTF_KEYUP,
                0
                );
    keybd_event(
                VK_MENU,
                0x38,
                KEYEVENTF_KEYUP,
                0
                );
    return;
}

///Only for a specific console part background and text color.----------------------
void SetColorAndBackground(int ForgC, int BackC){
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}

///This will set the foreground color for printing in a console window.-------------------------------------
void SetColor(int ForgC){
     WORD wColor;
     ///We will need this handle to get the current background attribute
     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;

     ///We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
        ///Mask out all but the background attribute, and add in the foreground color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
}

/// For clearing a specific  line.....
void clearLine(int j){
    int i;
    for(i=50;i<120;i++){
    gotoxy(i,j);printf(" ");}
    return;
}
