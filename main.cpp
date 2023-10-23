/// first we use the standard header file which is define in mingW........
///***********************///
#include<stdio.h>        ///
///*********************///


///then we use some header file which are not included in mingW but defined by user that mean us :) ..........
///*********************************///
#include"coord.h"                  ///
#include"box.h"                   ///
#include"screen.h"               ///
#include"student.h"             ///
#include"login.h"              ///
#include"teacher.h"           ///
#include"modify teacher.h"   ///
#include"modify student.h"  ///
#include"option.h"         ///
#include"admin.h"         ///
#include"image.h"        ///
///*********************///

/// ***** Software Development Project **** ///

/// ***** SUBMiTTED BY ***** ///

/// **** TEAM PEGASUS **** ///

/// *** MEMBERS *** ///

/// **** MD ASFAKUR RAHAT **** ///
/// *** ID: 18192103015 *** ///

/// @ The Main Function of our @Project @ ///
int main()
{
    ClearConsoleToColors(17,15);
    SetConsoleTitle("A CSE 100 Project By Team Pegasus - BUBT Student Management System");
    Full_Screen();
    image();
    Wlc_screen();
    login_option();
    return 0;
}
///  @ End of the @Project @ /

/// *** SUBMITTED TO: *** ///
/// *** MIYA MOHAMMAD FAZLE RABBI *** ///
/// *** ASSISTANT PROFESSOR *** ///
/// *** DEPARTMENT OF CSE *** ///
/// *** BANGLADESH UNIVERSITY OF BUSSINESS & TECHNOLOGY *** ///
