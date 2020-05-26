/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                          D O C U M E N T A T I O N                        */
//---------------------------------------------------------------------------*/
//  Filename:           main.cpp
//  Program:            Student Database
//  Title:              Main Program
//
//  Author:             Ibeawuchi Anokam
//  Date of Creation:   05/05/20
//  Version:            1.0.0
//  Revised by:         n/a
//  Revision Date:      n/a
//
//  Copyright:          Copyright © 2020 Ibeawuchi Anokam. 
//                      All rights reserved.
//
//-------------------------------------------------
// PROGRAM DESCRIPTION                            :
//-------------------------------------------------
//
// The program implement a database.
// It takes the information from an input file called “StudentList.txt”
// The database shows the students registered in different courses.
// The database will only include:
//
//      1) the student’s first name,
//      2) last name, ID, list of courses,
//      3) credit hours for each course,
//      4) and the course grade.
//
//
// The program will be able to calculate the GPA for each student.
//
//
/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                        G L O B A L    S E C T I O N                       */
//---------------------------------------------------------------------------*/
//--------------------------------------------
// System-Defined                            :
// Libraries                                 :
//--------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;

//--------------------------------------------
// Input/Output File Stream                  :
//--------------------------------------------
ifstream StudentList_input;

//--------------------------------------------
// User-Defined                              :
// Libraries                                 :
//--------------------------------------------
#include "student_roster_list.h"
#include "menu.h"

//--------------------------------------------
// Function Prototypes -                     :
// PROGRAM MENU                              :
//--------------------------------------------
void title_screen( );


/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                           M A I N    M O D U L E                          */
/*---------------------------------------------------------------------------*/
//------------------------
// Start Application     :
//------------------------
int main(  ){
	//---------------------------------------------------------------------
	// Opening Title Screen                                               :
	//---------------------------------------------------------------------
	title_screen( );

    //---------------------------------------------------------------------
    // Open Input File Stream                                             :
    //---------------------------------------------------------------------
    StudentList_input.open("StudentList.txt");		   
    //---------------------------------------------------------------------
    // Database Initialization                                            :
    //---------------------------------------------------------------------
    // Database Initialization:
    student_roster_list StudentList;                   // Create a database 
                                                       // instance

    StudentList.CreateClassList( StudentList_input );  // Populate the 
                                                       // database

	StudentList.FindGPA(  );                           // Populate the
													   // database with
													   // Grade Point Averages

    //---------------------------------------------------------------------
    // Program And Menu -  Variable Initializations                       :
    //---------------------------------------------------------------------
    // While-Loop Flag - Program Status Indicator:
    PROGRAM_STATE program_status   = ON;               // Allow The Menu Module
													   // To Start
    // While-Loop Choice Selection:
    MENU_OPTIONS  main_menu_choice = MAIN_MENU;        // Default Main Menu
													   // Choice


    //---------------------------------------------------------------------
    // START PROGRAM                                                      :
    //---------------------------------------------------------------------
    // BEGIN - "PROGRAM WHILE-LOOP":
    while(  program_status != OFF  ){
        
        //-----------------------------------------------------------------
        // Run The Main Menu -                                            :
        // Return The Program Status Of Either OFF Or ON                  :
        // And The Users main menu choice                                 :
        // When Exiting the menu                                          :
        //-----------------------------------------------------------------
        main_menu(   program_status,
                     main_menu_choice    );
        
        //-----------------------------------------------------------------
        // Run A SubMenu -                                                :
        // IF Program Status is still 'ON'                                :
        //-----------------------------------------------------------------
        if( program_status == ON  ){

            //-------------------------------------------------------------
            // Choice 1 of 5 -                                            :
            // Access The "Update The Student List" Menu                  :
            //-------------------------------------------------------------
            if(      main_menu_choice == UPDATE_LIST              ){
                
                update_student_list_menu( StudentList );
            } 
            //-------------------------------------------------------------
            // Choice 2 of 5 -                                            :
            // Access The "Update The Students Class List" Menu           :
            //-------------------------------------------------------------
            else if( main_menu_choice == UPDATE_STUDENT_ACCOUNT   ){
                
                update_student_class_list_menu( StudentList );
            }
            //-------------------------------------------------------------
            // Choice 3 of 5 -                                            :
            // Access The "Search The Student List" Menu                  :
            //-------------------------------------------------------------
            else if( main_menu_choice == SEARCH_LIST              ){
                
                search_menu( StudentList );
            }
            //-------------------------------------------------------------
            // Choice 4 of 5 -                                            :
            // Access The "Sort The Student List" Menu                    :
            //-------------------------------------------------------------
            else if( main_menu_choice == SORT_LIST                ){
                
                sort_menu( StudentList );
            }
            //-------------------------------------------------------------
            // Choice 5 of 5 -                                            :
            // Access The "Print The Student List" Menu                   :
            //-------------------------------------------------------------
            else if( main_menu_choice == PRINT_LIST               ){

                print_menu( StudentList );
            }
            //-------------------------------------------------------------
            // Default -                                                  :
            // ... IFF No Option Was Chosen Then...                       :
            //-------------------------------------------------------------
            else{
                
                cout<< endl;
                cout<< "---------------------------------"<< endl;
                cout<< "No Option Was Chosen."            << endl;
                cout<< "---------------------------------"<< endl;
                cout<< endl;
            }
        }
        //-----------------------------------------------------------------
        // Stop The Program -                                             :
        // IF Program Status is 'OFF'                                     :
        //-----------------------------------------------------------------
        else{
            
            cout<< endl;
            cout<< "---------------------------------"<< endl;
            cout<< "Goodbye  ;-)"                     << endl;
            cout<< "---------------------------------"<< endl;
            cout<< endl;
        }
        
    }// END - "PROGRAM WHILE-LOOP"
    
    
    //---------------------------------------------------------------------
    // Close Input File Stream                                            :
    //---------------------------------------------------------------------
    StudentList_input.close(   );
    //---------------------------------------------------------------------
    // System Specific Macro.                                             :
    // Pause The System                                                   :
    //---------------------------------------------------------------------
    #if defined(_WIN32) || defined(_WIN64)
        system("pause");
    #endif
    //---------------------------------------------------------------------
    // End The Application                                                :
    //---------------------------------------------------------------------
    return 0;

}
// END Main Function


/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                   F U N C T I O N    D E F I N I T I O N S                */
/*---------------------------------------------------------------------------*/
// DESCRIPTION: THIS SECTION CONTAINS THE TITLE SCREEN
//
void title_screen( ){

	//---------------------------------------------------------------------
	// Print The Title Screen                                             :
	//---------------------------------------------------------------------
	#if defined(_WIN32) || defined(_WIN64)
		system("CLS");
	

		//-----------------------------------------------------------------
		// Title Block                                                    :
		//-----------------------------------------------------------------
		cout << "      .     .     .      .      .      .      .     .     .      .      .     .     .      .   " << endl;
		cout << " .--------------------------------------------------------------------------------------------." << endl;
		cout << " |  .--------------------------------------------------------------------------------------.  |" << endl;
		cout << " |  | ::`                                                                                ` |  |" << endl;
		cout << " |  | :`                      P R O G R A M M I N G   P R O J E C T                      : |  |" << endl;
		cout << " |  | :                                                                                 .: |  |" << endl;
		cout << " ``````````````````````````````````````````````````````````````````````````````````````````````" << endl;
		cout << " |  | :               ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~               .|  |" << endl;
		cout << " |  | :`                            S   T   U   D   E   N   T                             .|  |" << endl;
		cout << " |  | :                                                                                   .|  |" << endl;
		cout << " |  | :               .   D  A  T  A  B  A  S  E      S  Y  S  T  E  M   .                :|  |" << endl;
		cout << " |  | :               ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~               .|  |" << endl;
		cout << " |  | ::.                                                                               .::|  |" << endl;
		cout << " |  | :::::::::::::.                                                           . . .:::::::|  |" << endl;
		cout << " |  .--------------------------------------------------------------------------------------.  |" << endl;
		cout << " *--------------------------------------------------------------------------------------------*" << endl;
		cout << endl << endl;
		cout << "                                 PRESS ENTER TO CONTINUE ..." << endl;
		cout << endl << endl;
		cout << "-----------------------------------------------------------------------------------------------" << endl;
		cout << "   Copyright (C) 2020 Ibeawuchi Anokam. All rights reserved."                                    << endl;
		cout << endl << endl;


		//-----------------------------------------------------------------
		// System Specific Macro.                                         :
		// Pause The System                                               :
		//-----------------------------------------------------------------
		system("pause");

		//-----------------------------------------------------------------
		// Flush The Screen                                               :
		//-----------------------------------------------------------------
		cout << flush;


	#endif
}