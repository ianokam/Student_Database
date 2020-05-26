/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                          D O C U M E N T A T I O N                        */
//---------------------------------------------------------------------------*/
//  Filename:           menu.h
//  Program:            Student Database
//  Title:              Main Menu And SubMenu Functions
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
// FILE DESCRIPTION                               :
//-------------------------------------------------
//
// The File Holds The Programs Menu Function Definitions
//
//
/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                        G L O B A L    S E C T I O N                       */
//---------------------------------------------------------------------------*/
#ifndef menu_h
#define menu_h
//--------------------------------------------
// System-Defined                            :
// Libraries                                 :
//--------------------------------------------
#include <stdio.h>  
#include <iostream> 
#include <string>
#include <stdexcept>
using namespace std;

//--------------------------------------------
// Enumeration Prototypes -                  :
// PROGRAM STATUS                            :
//--------------------------------------------
enum PROGRAM_STATE{
    // QUIT A Menu OPTION:
    OFF    = 0,
    ON     = 1,
};
enum MENU_OPTIONS{
    // DEFAULT MENU OPTION:
    MAIN_MENU               = 0,
    // MAIN  MENU  OPTIONS:
    UPDATE_LIST             = 1,
    UPDATE_STUDENT_ACCOUNT  = 2,
    SEARCH_LIST             = 3,
    SORT_LIST               = 4,
    PRINT_LIST              = 5,
};
//--------------------------------------------
// Function Prototypes -                     :
// PROGRAM MENU                              :
//--------------------------------------------
void main_menu( PROGRAM_STATE &statusType,
                MENU_OPTIONS &choiceType   );
void update_student_list_menu      (  student_roster_list &studentList  );
void update_student_class_list_menu(  student_roster_list &studentList  );
void search_menu(  student_roster_list  studentList   );
void sort_menu  (  student_roster_list &studentList   );
void print_menu (  student_roster_list  studentList   );
//--------------------------------------------
// Helper Function Prototypes                :
//--------------------------------------------
bool    is_string_only_letters(  string input_val  );
bool    is_string_only_numbers(  string input_val  );
string  sentence_case( string name );


/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                   F U N C T I O N    D E F I N I T I O N S                */
/*---------------------------------------------------------------------------*/
// DESCRIPTION: THIS SECTION ONLY CONTAINS THE MAIN FUNCTIONS.
//		THE HELPER FUNCTIONS ARE LISTED BELOW THEM IN THEIR OWN
//		SECTION.
//
void main_menu( PROGRAM_STATE &statusType, MENU_OPTIONS &choiceType ){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// This Is The Main Menu
//-----------------------------------------------------------------------------
    
    
    //---------------------------------------------------------------------
    // Vairable Declaration                                               :
    //---------------------------------------------------------------------
    string menu_input_option="";
    bool is_done;
    
    //---------------------------------------------------------------------
    // PROGRAM DESCRIPTION                                                :
    //---------------------------------------------------------------------
    cout << "-----------------------------------------------------------------------------------------------"	<< endl;
    cout << "  SENIOR CLASS LIST DATABASE -  MAIN MENU                                                     :"	<< endl;
    cout << "-----------------------------------------------------------------------------------------------"	<< endl;
    cout << "  This Program Allows You To Update The Senior Class Student Database."				<< endl;
    cout << "  Enter One Of The Options Below To Query The Database:"						<< endl;
    cout << ""													<< endl;
    cout << "       - UPDATE_LIST"										<< endl;
    cout << "       - UPDATE_STUDENT_ACCOUNT"									<< endl;
    cout << "       - SEARCH_LIST"										<< endl;
    cout << "       - SORT_LIST"										<< endl;
    cout << "       - PRINT_LIST"										<< endl;
    cout << "       - QUIT"											<< endl;
    cout << endl; 
    
	// While-loop Flag:
	is_done = false;

    //--------------------------------------------------------------
    // Begin While-Loop - "MENU OPTIONS"
    while(    is_done == false	  ){
        
        cout << "QUERY INPUT:   ";
        
        try{
            // TAKE A USER QUERY:
            cin >> menu_input_option;
            
            // CHECK THE INPUT QUERY:  
            if (      menu_input_option ==  "UPDATE_LIST"            ){
                choiceType = UPDATE_LIST;
                statusType = ON;
		is_done = true;
		cout << endl << endl;
            }
            else if ( menu_input_option ==  "UPDATE_STUDENT_ACCOUNT" ){
                choiceType = UPDATE_STUDENT_ACCOUNT;
                statusType = ON;
		is_done = true;
		cout << endl << endl;
            }
            else if ( menu_input_option ==  "SEARCH_LIST"            ){
                choiceType = SEARCH_LIST;
                statusType = ON;
		is_done = true;
		cout << endl << endl;
            }
            else if ( menu_input_option ==  "SORT_LIST"              ){
                choiceType = SORT_LIST;
                statusType = ON;
		is_done = true;
		cout << endl << endl;
            }
            else if ( menu_input_option ==  "PRINT_LIST"             ){
                choiceType = PRINT_LIST;
                statusType = ON;
		is_done = true;
		cout << endl << endl;
            }
            else if ( menu_input_option ==  "QUIT"                   ){
                statusType = OFF;
		is_done = true;
		cout << endl << endl;
            }
            else{
                // ERROR REACHED:
                throw runtime_error("INVALID menu_input_option");
            }
        }
        catch(  runtime_error& excpt ){
            
            cout<< endl;
            cout<< "---------------------------------"<< endl;
            cout<< "ERROR:" << excpt.what()           << endl;
            cout<< "---------------------------------"<< endl;
            cout<< endl;
        }
    }
    // End While-Loop - "MENU OPTIONS"
    //--------------------------------------------------------------
}


void update_student_list_menu( student_roster_list &studentList ){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// This Is Main Menu's Submenu For Updating The Student List
//-----------------------------------------------------------------------------
    
    //------------------------------------
    // Program Menu - Input Variables    :
    //------------------------------------
    int id;
    string f_name, l_name;
    string menu_input_option, search_val;
    bool is_done;
    int  index;
    bool condition_passed;
    bool condition2_passed;
    
    //---------------------------------------------------------------------
    // PROGRAM DESCRIPTION                                                :
    //---------------------------------------------------------------------
    cout << "-----------------------------------------------------------------------------------------------"	<< endl;
    cout << "  SENIOR CLASS LIST DATABASE -  UPDATE STUDENT LIST                                           :"	<< endl;
    cout << "-----------------------------------------------------------------------------------------------"	<< endl;
    cout << "  Add or delete students from the list."								<< endl;
    cout << "  You can Query The Database With These Options:"							<< endl;
    cout << ""													<< endl;
    cout << "       - ADD_STUDENT"						 				<< endl;
    cout << "       - DELETE_STUDENT"								                << endl;
    cout << "       - RETURN_TO_MAIN_MENU"									<< endl;
    cout << endl;

	// While-loop Flag:
	is_done = false;

	//--------------------------------------------------------------
	// Begin While-Loop - "MENU OPTIONS"
	while (is_done == false) {

		cout << "QUERY INPUT:   ";

		try {
			// TAKE A USER QUERY:
			cin >> menu_input_option;

			// CHECK THE INPUT QUERY:
			if (menu_input_option == "ADD_STUDENT") {

				//---------------------------------------------------------------------
				// Input First Name                                                   :
				//---------------------------------------------------------------------
				// Initialize The While-Loop Flag:
				condition_passed = false;

				while (condition_passed == false) {
					cout << "ENTER THE STUDENTS FIRST NAME:   ";
					try {
						cin >> f_name;

						//---------------------------------------------------------------------
						// Check If The Input Is All Letters                                  :
						//---------------------------------------------------------------------
						// Initialize The While-Loop Flag:
						condition2_passed = true;

						index = 0;

						while (index < static_cast<int>(f_name.size()) && condition2_passed == true)
						{

							if (!((static_cast<int>(f_name[index]) >= 65 && static_cast<int>(f_name[index]) <= 90) ||
							      (static_cast<int>(f_name[index]) >= 97 && static_cast<int>(f_name[index]) <= 122)) ) {

								condition2_passed = false;
							}
							index++;
						}

						// If The Input Doesn't Contain Numbers :                                            
						if (condition2_passed == false) {

							// ERROR REACHED:
							throw runtime_error("A Name Can Only Consist Of Letters");
						}


						// If The Input Exceeds Systems Limit Size Then ...:
						if (f_name.size() > 50) {

							// ERROR REACHED:
							throw runtime_error("The Name Exceeds The Maximum Number Of Characters, 50");
						}
						else { // ... If The Input Is A Number Then... :

							f_name = sentence_case(f_name);
							condition_passed = true;
						}
					}
					catch (runtime_error& excpt) {

						cout << endl; 
						cout << "---------------------------------------------------------------" << endl;
						cout << "ERROR:" << excpt.what() << endl;
						cout << "---------------------------------------------------------------" << endl;
						cout << endl;
					}
				}

				//---------------------------------------------------------------------
				// Input Last Name                                                    :
				//---------------------------------------------------------------------
				// Initialize The While-Loop Flag:
				condition_passed = false;

				while (condition_passed == false) {
					cout << "ENTER THE STUDENTS LAST NAME:   ";
					try {
						cin >> l_name;

						//---------------------------------------------------------------------
						// Check If The Input Is All Letters                                  :
						//---------------------------------------------------------------------
						// Initialize The While-Loop Flag:
						condition2_passed = true;

						index = 0;

						while (index < static_cast<int>(l_name.size()) && condition2_passed == true)
						{

							if (!((static_cast<int>(l_name[index]) >= 65 && static_cast<int>(l_name[index]) <= 90) ||
							      (static_cast<int>(l_name[index]) >= 97 && static_cast<int>(l_name[index]) <= 122))) {

								condition2_passed = false;
							}
							index++;
						}

						// If The Input Doesn't Contain Numbers :                                            
						if (condition2_passed == false) {

							// ERROR REACHED:
							throw runtime_error("A Name Can Only Consist Of Letters");
						}


						// If The Input Exceeds Systems Limit Size Then ...:
						if (l_name.size() > 50) {

							// ERROR REACHED:
							throw runtime_error("The Name Exceeds The Maximum Number Of Characters, 50");
						}
						else { // ... If The Input Is A Number Then... :

							l_name = sentence_case(l_name);
							condition_passed = true;
						}
					}
					catch (runtime_error& excpt) {

						cout << endl;
						cout << "---------------------------------------------------------------" << endl;
						cout << "ERROR:" << excpt.what()                                          << endl;
						cout << "---------------------------------------------------------------" << endl;
						cout << endl;
					}
				}
				//-----------------------------------------------------------------------------
				// INPUT IDENTIFICATION NUMBER                                                :
				//-----------------------------------------------------------------------------
				// Initialize The While-Loop Flag:
				condition_passed = false;

				while (condition_passed == false) {

					cout << "ENTER THE STUDENTS ID NUMBER:    ";
					try {
						
						// Test 1 - Check If The Correct Data Type Has Been Inserted:
						if (!(cin >> id)) {

							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							// ERROR REACHED:
							throw runtime_error("Invalid ID Number");
						}
						// Test 2 - Check The Length Of The ID Number ( IT MUST BE 5 DIGITS ):
						else if (!(id >= 10000 && id <= 99999)) {

							// ERROR REACHED:
							throw runtime_error("ID Number Must Have 5 Digits");
						}
						else {
							condition_passed = true;
						}
					}
					catch (runtime_error& excpt) {

						cout << endl;
						cout << "----------------------------------------------------" << endl;
						cout << "ERROR: " << excpt.what() << endl;
						cout << "----------------------------------------------------" << endl;
						cout << endl;
					}
				}

				//---------------------------------------------------------------------
				// Input The Student Into The List                                    :
				//---------------------------------------------------------------------
				studentList.InsertNewStudent(f_name, l_name, id);

				// Output The Student Count:
				cout << endl;
				cout << "=============================" << endl;
				cout << " UPDATED STUDENT LIST COUNT:   " << studentList.Student_Count( ) << endl;
				cout << "=============================" << endl;
				cout << endl;

				cout << "----------------------------------------------------" << endl;
				cout << endl << endl;
				cout << " PRESS ENTER TO CONTINUE PRINTING THE LIST ..." << endl;
				cout << endl << endl;
			
				// System Specific Macro.                                        
				// Pause The System:                                               
				#if defined(_WIN32) || defined(_WIN64)
					system("pause");
				#endif

				// Print the Student List:
				studentList.Print();

				// End The While-Loop:
				is_done = true;

				// Give Space Between The Previous Output And The Next One: 
				cout << endl << endl;
			}
			else if (menu_input_option == "DELETE_STUDENT") {

				//-----------------------------------------------------------------------------
				// INPUT IDENTIFICATION NUMBER                                                :
				//-----------------------------------------------------------------------------
				// Initialize The While-Loop Flag:
				condition_passed = false;

				while (condition_passed == false) {

					cout << "ENTER THE STUDENTS ID NUMBER:    ";
					try {

						// Test 1 - Check If The Correct Data Type Has Been Inserted:
						if (!(cin >> id)) {

							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							// ERROR REACHED:
							throw runtime_error("Invalid ID Number");
						}
						// Test 2 - Check The Length Of The ID Number ( IT MUST BE 5 DIGITS ):
						else if (!(id >= 10000 && id <= 99999)) {

							// ERROR REACHED:
							throw runtime_error("ID Number Must Have 5 Digits");
						}
						else {
							condition_passed = true;
						}
					}
					catch (runtime_error& excpt) {

						cout << endl;
						cout << "----------------------------------------------------" << endl;
						cout << "ERROR: " << excpt.what() << endl;
						cout << "----------------------------------------------------" << endl;
						cout << endl;
					}
				}


				//-----------------------------------------------------------------------------
				// DELETE THE STUDENT FROM THE LIST                                           :
				//-----------------------------------------------------------------------------
				studentList.DeleteStudent( id );

				// Output The Student Count:
				cout << endl;
				cout << "=============================" << endl;
				cout << " UPDATED STUDENT LIST COUNT:   " << studentList.Student_Count( ) << endl;
				cout << "=============================" << endl;
				cout << endl;

				cout << "----------------------------------------------------" << endl;
				cout << endl << endl;
				cout << " PRESS ENTER TO CONTINUE PRINTING THE LIST ..." << endl;
				cout << endl << endl;
			
				// System Specific Macro.                                        
				// Pause The System:                                               
				#if defined(_WIN32) || defined(_WIN64)
					system("pause");
				#endif

				// Print the Student List:
				studentList.Print();

				// End The While-Loop:
				is_done = true;

				// Give Space Between The Previous Output And The Next One: 
				cout << endl << endl;

			}
			else if (menu_input_option == "RETURN_TO_MAIN_MENU") {

				is_done = true;
				cout << endl << endl;
			}
			else {
				// ERROR REACHED:
				throw runtime_error("INVALID menu input option");
			}
		}
		catch (runtime_error& excpt) {

			cout << endl;
			cout << "---------------------------------" << endl;
			cout << "ERROR:" << excpt.what() << endl;
			cout << "---------------------------------" << endl;
			cout << endl;
		}
	}
	// End While-Loop - "MENU OPTIONS"
	//--------------------------------------------------------------
}




void update_student_class_list_menu( student_roster_list &studentList ){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// This Is Main Menu's Submenu For Updating A Particular Students Class List
// Information
//-----------------------------------------------------------------------------
    
    //------------------------------------
    // Program Menu - Input Variables    :
    //------------------------------------
    string menu_input_option;
    int id;
    string course__name;
    int    class_credit;
    char   current_grade;
    bool   is_done;
    bool   condition_passed;
    
    //---------------------------------------------------------------------
    // PROGRAM DESCRIPTION                                                :
    //---------------------------------------------------------------------
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "  SENIOR CLASS LIST DATABASE -  UPDATE A STUDENTS CLASS INFO                                  :" << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "  Searches and updates a students class info."						      << endl;
    cout << "  You can Query The Database With These Options:"						      << endl;
    cout << ""												      << endl;
    cout << "       - ADD_COURSE"									      << endl;
    cout << "       - DELETE_COURSE"									      << endl;
    cout << "       - UPDATE_COURSE_GRADE"								      << endl;
    cout << "       - RETURN_TO_MAIN_MENU"								      << endl;
    cout << endl;
     
    // While-loop Flag:
    is_done = false;
    
    //--------------------------------------------------------------
    // Begin While-Loop - "SUBMENU" :
    while ( is_done == false ){
        
         cout << "QUERY INPUT:   ";
         try{
             cin >> menu_input_option;
             
             if ( menu_input_option ==  "ADD_COURSE"    ){
                 

				 //-----------------------------------------------------------------------------
				 // INPUT IDENTIFICATION NUMBER                                                :
				 //-----------------------------------------------------------------------------
				 // Initialize The While-Loop Flag:
				 condition_passed = false;

				 while (condition_passed == false) {

					 cout << "ENTER THE STUDENTS ID NUMBER:    ";
					 try {

						 // Test 1 - Check If The Correct Data Type Has Been Inserted:
						 if (!(cin >> id)) {

							 cin.clear();
							 cin.ignore(numeric_limits<streamsize>::max(), '\n');
							 // ERROR REACHED:
							 throw runtime_error("Invalid ID Number");
						 }
						 // Test 2 - Check The Length Of The ID Number ( IT MUST BE 5 DIGITS ):
						 else if (!(id >= 10000 && id <= 99999)) {

							 // ERROR REACHED:
							 throw runtime_error("ID Number Must Have 5 Digits");
						 }
						 else {
							 condition_passed = true;
						 }
					 }
					 catch (runtime_error& excpt) {

						 cout << endl;
						 cout << "----------------------------------------------------" << endl;
						 cout << "ERROR: " << excpt.what() << endl;
						 cout << "----------------------------------------------------" << endl;
						 cout << endl;
					 }
				 }


                 //-----------------------------------------------------------------------------
                 // INPUT CLASS NAME                                                           :
                 //-----------------------------------------------------------------------------
                 // Reinitialize The While-Loop Flag:
                 condition_passed = false;
                     
                 while( condition_passed == false ){
                     
                     cout<< "ENTER THE STUDENTS CLASS NAME:   ";
                     try {

                         cin >> course__name;

                         // Test 1 - Check The Length Of The Class Name:
                         if (   !(course__name.size() >= 6  &&  course__name.size() <= 7)   ) {

                             // ERROR REACHED:
                             throw runtime_error("Class Name Must Have A Length Of 6 Or 7");
                         }
                     
                         condition_passed = true;
                     }
                     catch (runtime_error& excpt) {

                         cout << endl;
                         cout << "----------------------------------------------------" << endl;
                         cout << "ERROR: " << excpt.what() << endl;
                         cout << "----------------------------------------------------" << endl;
                         cout << endl;
                     }
                 }
                 //-----------------------------------------------------------------------------
                 // INPUT CLASS CREDIT                                                         :
                 //-----------------------------------------------------------------------------
                 // Reinitialize The While-Loop Flag:
                 condition_passed = false;
                    
                 while( condition_passed == false ){
                     
                     cout<< "ENTER THE STUDENTS COURSE CREDIT:    ";
                     try {

                         // Test 1 - Check If The Correct Data Type Has Been Inserted:
                         if (!(cin >> class_credit)) {

							 cin.clear();
							 cin.ignore(numeric_limits<streamsize>::max(), '\n');
                             // ERROR REACHED:
                             throw runtime_error("Invalid Class Credit Value");
                         }
                         // Test 2 - Check The Credit Size ( IT MUST BE FROM 0 - 4 ):
                         if (!(class_credit >= 0 && class_credit <= 4)) {

                             // ERROR REACHED:
                             throw runtime_error("Courses Can Only Have A Value From 0 To 4");
                         }
                     
                         condition_passed = true;
                     }
                     catch (runtime_error& excpt) {

                         cout << endl;
                         cout << "----------------------------------------------------" << endl;
                         cout << "ERROR: " << excpt.what() << endl;
                         cout << "----------------------------------------------------" << endl;
                         cout << endl;
                     }
                 }
                 //-----------------------------------------------------------------------------
                 // INPUT CLASS GRADE EARNED                                                   :
                 //-----------------------------------------------------------------------------
                 // Reinitialize The While-Loop Flag:
                 condition_passed = false;
                    
                 while( condition_passed == false ){
                     
                     cout<< "ENTER THE STUDENTS COURSE GRADE:    ";
                     try {

                         // Test 1 - Check If The Correct Data Type Has Been Inserted:
                         if (!(cin >> current_grade)) {

			     cin.clear();
			     cin.ignore(numeric_limits<streamsize>::max(), '\n');
                             // ERROR REACHED:
                             throw runtime_error("Invalid Letter Grade Value Length");
                         }
			// Test 2 - Check That ONLY A Grade Of A, B, C, D, E:
			if (!((current_grade >= 'A'  &&  current_grade <= 'E') ||
			      (current_grade >= 'a'  &&  current_grade <= 'e')))
			{

				// ERROR REACHED:
				throw runtime_error("Grade Can Only Be A Letter Of A,B,C,D, Or E");
			}
                     
			// Change to uppercase letters:
			if ( current_grade >= 'a'  &&  current_grade <= 'e' ){

				current_grade = static_cast<char>(  static_cast<int>(current_grade) - 32  );
			}

                         condition_passed = true;
                     }
                     catch (runtime_error& excpt) {

                         cout << endl;
                         cout << "----------------------------------------------------" << endl;
                         cout << "ERROR:" << excpt.what() << endl;
                         cout << "----------------------------------------------------" << endl;
                         cout << endl;
                     }
                 }

		 //-----------------------------------------------------------------------------
		 // INPUT DATA INTO LIST, INSIDE OF STUDENTS COURSE LIST	                   :
		 //-----------------------------------------------------------------------------
                 studentList.AddCourse( id, 
					course__name, 
					class_credit, 
					current_grade	);
		 is_done = true;
		 cout << endl << endl;



             }
             else if ( menu_input_option ==  "DELETE_COURSE" ){

                 
	     //-----------------------------------------------------------------------------
	     // INPUT IDENTIFICATION NUMBER                                                :
	     //-----------------------------------------------------------------------------
	     // Initialize The While-Loop Flag:
	     condition_passed = false;

	     while (condition_passed == false) {

	     cout << "ENTER THE STUDENTS ID NUMBER:    ";
	     try {

			// Test 1 - Check If The Correct Data Type Has Been Inserted:
			if (!(cin >> id)) {

				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				// ERROR REACHED:
				throw runtime_error("Invalid ID Number");
			}
			// Test 2 - Check The Length Of The ID Number ( IT MUST BE 5 DIGITS ):
			 else if (!(id >= 10000 && id <= 99999)) {

				 // ERROR REACHED:
				 throw runtime_error("ID Number Must Have 5 Digits");
			 }
			 else {
				 condition_passed = true;
			 }
		 }
		 catch (runtime_error& excpt) {

			 cout << endl;
			 cout << "----------------------------------------------------" << endl;
			 cout << "ERROR: " << excpt.what() << endl;
			 cout << "----------------------------------------------------" << endl;
			 cout << endl;
		 }
	 }


	 //-----------------------------------------------------------------------------
	 // INPUT CLASS NAME                                                           :
	 //-----------------------------------------------------------------------------
	 // Reinitialize The While-Loop Flag:
	 condition_passed = false;

	 while (condition_passed == false) {

		 cout << "ENTER THE STUDENTS CLASS NAME:   ";
		 try {

			 cin >> course__name;

			 // Test 1 - Check The Length Of The Class Name:
			 if (!(course__name.size() >= 6 && course__name.size() <= 7)) {

				 // ERROR REACHED:
				 throw runtime_error("Class Name Must Have A Length Of 6 Or 7");
			 }

			 condition_passed = true;
		 }
		 catch (runtime_error& excpt) {

			 cout << endl;
			 cout << "----------------------------------------------------" << endl;
			 cout << "ERROR: " << excpt.what() << endl;
			 cout << "----------------------------------------------------" << endl;
			 cout << endl;
		 }
	 }


	 //-----------------------------------------------------------------------------
	 // DELETE THE STUDENTS COURSE                                                 :
	 //-----------------------------------------------------------------------------
   	 studentList.DeleteCourse( id, course__name );
	 is_done = true;
	 cout << endl << endl;



     }
     else if ( menu_input_option ==  "UPDATE_COURSE_GRADE" ){

	 //-----------------------------------------------------------------------------
	 // INPUT IDENTIFICATION NUMBER                                                :
	 //-----------------------------------------------------------------------------
	 // Initialize The While-Loop Flag:
	 condition_passed = false;

	 while (condition_passed == false) {

		 cout << "ENTER THE STUDENTS ID NUMBER:    ";
		 try {

			 // Test 1 - Check If The Correct Data Type Has Been Inserted:
			 if (!(cin >> id)) {

				 cin.clear();
				 cin.ignore(numeric_limits<streamsize>::max(), '\n');
				 // ERROR REACHED:
				 throw runtime_error("Invalid ID Number");
			 }
			 // Test 2 - Check The Length Of The ID Number ( IT MUST BE 5 DIGITS ):
			 else if (!(id >= 10000 && id <= 99999)) {

				 // ERROR REACHED:
				 throw runtime_error("ID Number Must Have 5 Digits");
			 }
			 else {
				 condition_passed = true;
			 }
		 }
		 catch (runtime_error& excpt) {

			 cout << endl;
			 cout << "----------------------------------------------------" << endl;
			 cout << "ERROR: " << excpt.what() << endl;
			 cout << "----------------------------------------------------" << endl;
			 cout << endl;
		 }
	 }


	 //-----------------------------------------------------------------------------
	 // INPUT CLASS NAME                                                           :
	 //-----------------------------------------------------------------------------
	 // Reinitialize The While-Loop Flag:
	 condition_passed = false;

	 while (condition_passed == false) {

		 cout << "ENTER THE STUDENTS CLASS NAME:   ";
		 try {

			 cin >> course__name;

			 // Test 1 - Check The Length Of The Class Name:
			 if (!(course__name.size() >= 6 && course__name.size() <= 7)) {

				 // ERROR REACHED:
				 throw runtime_error("Class Name Must Have A Length Of 6 Or 7");
			 }

			 condition_passed = true;
		 }
		 catch (runtime_error& excpt) {

			 cout << endl;
			 cout << "----------------------------------------------------" << endl;
			 cout << "ERROR: " << excpt.what() << endl;
			 cout << "----------------------------------------------------" << endl;
			 cout << endl;
		 }
	 }

	 //-----------------------------------------------------------------------------
	 // INPUT CLASS GRADE EARNED                                                   :
	 //-----------------------------------------------------------------------------
	 // Reinitialize The While-Loop Flag:
	 condition_passed = false;

	 while (condition_passed == false) {

		 cout << "ENTER THE STUDENTS COURSE GRADE:    ";
		 try {

			 // Test 1 - Check If The Correct Data Type Has Been Inserted:
			 if (!(cin >> current_grade)) {

				 cin.clear();
				 cin.ignore(numeric_limits<streamsize>::max(), '\n');
				 // ERROR REACHED:
				 throw runtime_error("Invalid Letter Grade Value Length");
			 }
			 // Test 2 - Check That ONLY A Grade Of A, B, C, D, E:
			 if (!(( current_grade >= 'A'  &&  current_grade <= 'E' ) ||
				   ( current_grade >= 'a'  &&  current_grade <= 'e' )	 )	)
			 {

				 // ERROR REACHED:
				 throw runtime_error("Grade Can Only Be A Letter Of A,B,C,D, Or E");
			 }

			 // Change to uppercase letters:
			 if (current_grade >= 'a'  &&  current_grade <= 'e') {

				 current_grade = static_cast<char>(static_cast<int>(current_grade) - 32);
			 }

			 condition_passed = true;
		 }
		 catch (runtime_error& excpt) {

			 cout << endl;
			 cout << "----------------------------------------------------" << endl;
			 cout << "ERROR:" << excpt.what()                               << endl;
			 cout << "----------------------------------------------------" << endl;
			 cout << endl;
		 }
	 }

	//-----------------------------------------------------------------------------
	// MODIFY THE STUDENTS GRADE                                                  :
	//-----------------------------------------------------------------------------
	 studentList.Modify( id, course__name, current_grade );
			 is_done = true;
			 cout << endl << endl;

				 
        }
	 else if (menu_input_option == "RETURN_TO_MAIN_MENU") {

		 is_done = true;
		 cout << endl << endl;

	 }
	 else {
		 // ERROR REACHED:
		 throw runtime_error("INVALID menu input option");
	 }
   }
	 catch (runtime_error& excpt) {

		 cout << endl;
		 cout << "---------------------------------" << endl;
		 cout << "ERROR:" << excpt.what() << endl;
		 cout << "---------------------------------" << endl;
		 cout << endl;
	 }
    }
    // End While-Loop - "SUBMENU" :
    //--------------------------------------------------------------
}


void search_menu( student_roster_list studentList ){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// This Is Main Menu's Submenu For Searching For A Particular Students
// In The List
//-----------------------------------------------------------------------------
    
    //------------------------------------
    // Program Menu - Input Variables    :
    //------------------------------------
    string id;
    bool is_done;
    
    //---------------------------------------------------------------------
    // PROGRAM DESCRIPTION                                                :
    //---------------------------------------------------------------------
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "  SENIOR CLASS LIST DATABASE -  SEARCH THE STUDENT LIST                                       :" << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "  Search for students in the database."							      << endl;
    cout << endl;
    
    // While-loop Flag:
    is_done = false;
    
    //--------------------------------------------------------------
    // Begin While-Loop - "SUBMENU" :
    while ( is_done == false ){
        
		cout<< " ENTER A  STUDENT ID  OR  ' RETURN_TO_MAIN_MENU ':   ";


		//-----------------------------------------------------------------------------
		// INPUT IDENTIFICATION NUMBER                                                :
		//-----------------------------------------------------------------------------
		try {
			
			cin >> id;

			//---------------------------------------------------------------------
			// Check If User Wants To Return To The Main Menu                     :
			//---------------------------------------------------------------------
			if (id == "RETURN_TO_MAIN_MENU") {

				is_done = true;
			}

			//---------------------------------------------------------------------
			// Check If The Input Is An Number                                    :
			//---------------------------------------------------------------------
			// If The Input Is NOT A Number Then... :                                            
			if (  is_string_only_numbers(id) == false  ) {


				// ERROR REACHED:
				throw runtime_error("Invalid ID Number");
			}
			else if (!(id.size() == 5)) {

				// ERROR REACHED:
				throw runtime_error("ID Number Must Have 5 Digits");
			}
			else { // ... If The Input Is A Number Then... :
	
				// Convert The String To An Integer:
				studentList.Search(stoi(id));
				is_done = true;
			}
			cout << endl << endl;


		}
		catch (runtime_error& excpt) {

			cout << endl;
			cout << "----------------------------------------------------" << endl;
			cout << "ERROR: " << excpt.what() << endl;
			cout << "----------------------------------------------------" << endl;
			cout << endl;
		}
    }
    // End While-Loop - "SUBMENU" :
    //--------------------------------------------------------------
}


void sort_menu( student_roster_list &studentList ){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// This Is Main Menu's Submenu For Sorting The Students In The List
//-----------------------------------------------------------------------------
    
    //------------------------------------
    // Program Menu - Input Variables    :
    //------------------------------------
    string search_val;
    bool is_done;
    
    //---------------------------------------------------------------------
    // PROGRAM DESCRIPTION                                                :
    //---------------------------------------------------------------------
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "  SENIOR CLASS LIST DATABASE -  SORT THE STUDENT LIST                                         :" << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "  Sorts students in the database."								      << endl;
    cout << "  Query The Database With This Options:"							      << endl;
    cout << ""												      << endl;
    cout << "       - FIRST_NAME"									      << endl;
    cout << "       - LAST_NAME"									      << endl;
    cout << "       - ID_NUM"										      << endl;
    cout << "       - GPA"										      << endl;
    cout << "       - RETURN_TO_MAIN_MENU"								      << endl;
    cout << endl;
    
    
    // While-loop Flag:
    is_done = false;
    
    //--------------------------------------------------------------
    // Begin While-Loop - "SUBMENU" :
    while ( is_done == false ){
        
		cout << " QUERY INPUT:   ";

		try {
			cin >> search_val;

			if (search_val == "RETURN_TO_MAIN_MENU") {

				is_done = true;
			}
			else if(	search_val == "FIRST_NAME" ||
					search_val == "LAST_NAME"  ||
					search_val == "ID_NUM"	   ||	
					search_val == "GPA"				)
			{
				studentList.Sort(search_val);
				
				// Print The Sorted List:
				studentList.Sort_Print();

				// Exit While-Loop:
				is_done = true;
			}
			else {

				// ERROR REACHED:
				throw runtime_error("INVALID menu input option");
			}
			cout << endl << endl;
		}
		catch (runtime_error& excpt) {

			cout << endl;
			cout << "---------------------------------" << endl;
			cout << "ERROR:" << excpt.what() << endl;
			cout << "---------------------------------" << endl;
			cout << endl;
		}

    }
    // End While-Loop - "SUBMENU" :
    //--------------------------------------------------------------
}


void print_menu( student_roster_list studentList ){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// This Is Main Menu's Submenu For Printing The Students In The List
//-----------------------------------------------------------------------------
    
    //------------------------------------
    // Program Menu - Input Variables    :
    //------------------------------------
    string menu_input_option;
    bool is_done;
    
    //---------------------------------------------------------------------
    // PROGRAM DESCRIPTION                                                :
    //---------------------------------------------------------------------
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "  SENIOR CLASS LIST DATABASE -  PRINT FROM THE STUDENT LIST                                   :" << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;
    cout << "  Prints students in the database."	 					              << endl;
    cout << "  Query The Database With This Options:"							      << endl;
    cout << ""												      << endl;
    cout << "       - STUDENT_LIST"									      << endl;
    cout << "       - HONOR_STUDENTS"									      << endl;
    cout << "       - PROBATION_STUDENTS"								      << endl;
    cout << "       - FAILING_STUDENTS"									      << endl;
    cout << "       - RETURN_TO_MAIN_MENU"								      << endl;
    cout << endl;
    
    // While-loop Flag:
    is_done = false;

    //--------------------------------------------------------------
    // Begin While-Loop - "MENU OPTIONS"
    while(    is_done == false	  ){
        
        cout << "QUERY INPUT:   ";
        
        try{
            // TAKE A USER QUERY:
            cin >> menu_input_option;
            
            // CHECK THE INPUT QUERY:
            if (      menu_input_option ==  "STUDENT_LIST"        ){
				studentList.Sort_Print();
				is_done = true;
            }
            else if ( menu_input_option ==  "HONOR_STUDENTS"      ){
				studentList.HonorStudent();
				is_done = true;
            }
            else if ( menu_input_option ==  "FAILING_STUDENTS"    ){
				studentList.FailStudent();
				is_done = true;
            }
            else if ( menu_input_option ==  "PROBATION_STUDENTS"  ){
				studentList.WarnStudent();
				is_done = true;
            }
            else if ( menu_input_option ==  "RETURN_TO_MAIN_MENU" ){
				is_done = true;
				is_done = true;
            }
            else{
                // ERROR REACHED:
                throw runtime_error("INVALID menu input option");
            }
			cout << endl << endl;
        }
        catch(  runtime_error& excpt ){
            
            cout<< endl;
            cout<< "---------------------------------"<< endl;
            cout<< "ERROR:" << excpt.what() << endl;
            cout<< "---------------------------------"<< endl;
            cout<< endl;
        }
    }
    // End While-Loop - "MENU OPTIONS"
    //--------------------------------------------------------------
}




/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*          H E L P E R    F U N C T I O N    D E F I N I T I O N S          */
/*---------------------------------------------------------------------------*/
// DESCRIPTION: THIS SECTION ONLY CONTAINS THE HELPER FUNCTIONS.
//
bool is_string_only_letters(  string input_val  ) {
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// This helper function checks to see if an input 
// is only letters.
//-----------------------------------------------------------------------------


	//---------------------------------------------------------------------
	// Variable Declarations                                              :
	//---------------------------------------------------------------------
	bool  is_id = true;
	int   index = 0;

	//---------------------------------------------------------------------
	// Check If The Input Is An Number                                    :
	//---------------------------------------------------------------------
	while (index < static_cast<int>(input_val.size()) && is_id == true)
	{

		if (  !(static_cast<int>(input_val[index]) >= 65 && static_cast<int>(input_val[index]) <= 90 )  ||
			  !(static_cast<int>(input_val[index]) >= 97 && static_cast<int>(input_val[index]) <= 122)        )
		{

			is_id = false;
		}
		index++;
	}

	return is_id;
}

bool is_string_only_numbers(  string input_val  ) {
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// This helper function checks to see if an input 
// is only numbers.
//-----------------------------------------------------------------------------


	//---------------------------------------------------------------------
	// Variable Declarations                                              :
	//---------------------------------------------------------------------
	bool  is_id = true;
	int   index = 0;

	//---------------------------------------------------------------------
	// Check If The Input Is An Number                                    :
	//---------------------------------------------------------------------
	while (index < static_cast<int>(input_val.size()) && is_id == true)
	{

		if (!(static_cast<int>(input_val[index]) >= 48 && static_cast<int>(input_val[index]) <= 57))
		{

			is_id = false;
		}
		index++;
	}

	return is_id;
}
string  sentence_case(string name) {
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// This helper function returns a name in sentence case 
//-----------------------------------------------------------------------------


	//---------------------------------------------------------------------
	// Variable Declaration                                               :
	//---------------------------------------------------------------------
	int index;

	//---------------------------------------------------------------------
	// Check Each INdividual Letter In The Name                           :
	//---------------------------------------------------------------------
	// Set The While-Loop Flag:
	index = 0;

	// Begin Checking The Case Of Each Letter:
	while ( index < static_cast<int>( name.size() ) ) {

		// Check The First Letter In The Name:
		if (index == 0) {

			// Change to an uppercase letter:
			if (name[index] >= 'a'  &&  name[index] <= 'z') {

				name[index] = static_cast<char>(static_cast<int>(name[index]) - 32);
			}
		}
		// Check Every Other Letter In The Name That's Not The First One:
		else {

			// Change to lowercase letters:
			if (name[index] >= 'A'  &&  name[index] <= 'Z') {

				name[index] = static_cast<char>(static_cast<int>(name[index]) + 32);
			}
		}

		// Move To THe Next Letter In The Name:
		index++;
	}

	// return the name in sentence case:
	return name;
}


#endif
