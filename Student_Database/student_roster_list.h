/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                          D O C U M E N T A T I O N                        */
//---------------------------------------------------------------------------*/
//  Filename:           student_roster_list.h
//  Program:            Student Database
//  Title:              Database Functions
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
// The File Holds The Student Roster Class Definition
// And Its Function Definitions.
//
//
/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                        G L O B A L    S E C T I O N                       */
//---------------------------------------------------------------------------*/
#ifndef student_roster_list_h
#define student_roster_list_h

//--------------------------------------------
// System-Defined                            :
// Libraries                                 :
//--------------------------------------------
#include <stdio.h>      // Standard Buffered Input/Output
#include <iostream>     // Character Input/Output
#include <fstream>      // Input/Output File Stream
#include <string>       // Allows strings
#include <array>
#include <vector>       // Dynamic Array
using namespace std;


/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*                        C L A S S    S E C T I O N                         */
//---------------------------------------------------------------------------*/
//--------------------------------------------
// ADT: ADJACENCY LIST Prototype             :
//--------------------------------------------
class student_roster_list{
     
    //----------------------------------------
    // Public Member Functions               :
    //----------------------------------------
    public:
        //------------------------------------
        // DEFUALT  CONSTRUCTOR              :
        //------------------------------------
            student_roster_list( );
        
        //------------------------------------
        // MUTATOR -  FUNCTION MEMBERS       :
        //------------------------------------
            // Initializes The Student Roster
            // With Data From A .txt File:
            void CreateClassList(  ifstream &inputData  );
    
            //-----------------------------------------------------
            // Searches The Student Roster
            // Using Either Their First Name,
            // Last Name, Or ID And Inserts The Course For Them:
            void AddCourse(     int    identification_num,
                                string course__name,          
				                int    class_credit,
						        char   current_grade	    	  );
    
            // Searches The Student Roster
            // Using Either Their First Name,
            // Last Name, Or ID And Deletes The Course For Them:
            void DeleteCourse(  int identification_num,
                                string course_name                );
    
            //-----------------------------------------------------
            // Inserts A New Student Into
            // The Student Roster.
            // It Asks the User To Insert For Classes
            // For The student Once They Have Been Added:
            void InsertNewStudent( string  f_name,
                                   string  l_name,
                                   int     identification_num    );
    
            // Deletes A Student From
            // The Student Roster:
            void DeleteStudent(    int identification_num        );
    
    
            //-----------------------------------------------------
            // Sorts The Class Roster Either By
            // First Name, GPA, Or ID:
            void Sort (   string sort_data_type           );
    
            // Changes The Students Grade In A Class They Are
            // Currently Registered In:
            void Modify(  int     identification_num,
                          string  course_name,
                          char    class_letter_grade       );
   
        
        //------------------------------------
        // ACCESSOR - FUNCTION MEMBERS       :
        //------------------------------------
			// Calculates The GPA For ALL Students: ***
			void FindGPA(  );

			//-----------------------------------------------------
            // Searches And Prints The Students Info -
            // First Name, Last Name, ID, GPA,
            // And Their Registered Courses:
            void Search ( int  identification_num  );
    
            //-----------------------------------------------------
            // Printing All The Students In The Roster
            // With A GPA Greater Than 3.6
            // And The Total Number Of Honor Students:
            void HonorStudent(  );
            
            // Printing All The Students In The Roster
            // With A GPA Less Than 2.5
            // And The Total Number Of Those Students:
            void WarnStudent(  );
    
            // Printing All The Students In The Roster
            // With A GPA Less Than 2.0
            // And The Total Number Of Those Students:
            void FailStudent(  );
    
            //-----------------------------------------------------
            // Printing All The Students In The Roster,
            // Alphabetically, Sorted By Last Name :
            void Print(  );

			//-----------------------------------------------------
			// Printing All The Students In The Roster,
			// In Any Order ( Used With The Sort Function )
			void Sort_Print(  );

			//-----------------------------------------------------
			// Returns The Number Of Students
			// In The DataBase:
			int Student_Count(  ) const;
    
    //----------------------------------------
    // Private Data Members (Variables)      :
    //----------------------------------------
    private:
        //------------------------------------
        // DATA MEMBERS                      :
        //------------------------------------
			// The vriable Checks If print function 
			// has been initialized:
			bool print_initialized = false;

            //  Students Personal Class List
            // ( Singly Linked List )
            // Node Prototype:
            struct personal_class_record
            {
                // DATA FIELDS:
                string  class_name;
                int     class_credit;
                char    current_grade;
                
                // SLL POINTER FIELD:
                personal_class_record* next;
            };

            //-----------------------------------------------------
            //  Senior Students List Buffer
            // ( Singly Linked List )
            // Node Prototype:
            struct student_record_buffer
            {
                // DATA FIELDS pt1:
                string  f_name;
                string  l_name;
                int     identification_num;
                
                // DATA FIELDS pt2:
                string  class_name;
                int     class_credit;
                char    current_grade;
            };
        
            // Dynamic Array Container:
            vector< student_record_buffer* > student_list_buffer;

    
            //-----------------------------------------------------
            //  Senior Students List
            // ( Doubly Linked List )
            // Node Prototype:
            struct student_record
            {
                // Printable DATA FIELDS:
                string  f_name;
                string  l_name;
                int     identification_num;
                
                // Non-Printable DATA FIELDS:
                float gpa; // Default Value Of -1 Is Given If The Student Has Not Taken A Class
                int   num_of_classes = 0;
                
                // RELATIONAL DATABASE POINTER FIELD:
                personal_class_record* personal_class_record = nullptr;
            };
    
            // Dynamic Array Container:
            vector< student_record* > student_list_arr;

			// Student Roster ( Doubly Linked List )¬ // Head Pointer:¬
			student_record* student_record_head_ptr;

			// Student Counter:
			int max_student_counter = 0;

		//------------------------------------
		// HELPER - FUNCTION MEMBERS         :
		//------------------------------------
			// This Checks If The New Student Input Already Exists In The List:
			bool student_exists( string  f_name,
                                 string  l_name,
                                 int     identification_num    );

			//-----------------------------------------------------
			// Formats the GPA to 2 decimal places:
			string gpa_formatter
			(   vector< student_record* > &student_list_arr_container,
				int    index											);

			//-----------------------------------------------------
			// Calculates The GPA For One Student When Inserting/Deleting Classes:
			void Find_one_GPA(	vector< student_record* > &student_list_arr_container,
								int    index											);

			//-----------------------------------------------------
			// Split A Set/Subset Into 
			// Multiples Subsets ( subarrays )
			// Then Merge It Back Together 
			// ( With The help Of MergeList ):
			void mergeSort
			(   vector< student_record* > &student_list_arr_container,
				int    leftmost_index,
				int    rightmost_index,
				string searchVal										);

			// Merge two
			// subsets ( subarrays ), L and M, 
			// Back Together, Sorted:
			void mergeList
			(   vector< student_record* > &student_list_arr_container,
				int    leftmost_index,
				int    middle_index,
				int    rightmost_index,
				string searchVal										);

};


/*///////////////////////////////////////////////////////////////////////////*/
/*---------------------------------------------------------------------------*/
/*           C L A S S    F U N C T I O N    D E F I N I T I O N S           */
/*																             */
/*                              S E C T I O N                                */		
/*---------------------------------------------------------------------------*/
// DESCRIPTION: THE FUNCTIONS BELOW ARE ORGANIZED BY THEIR RELATION TO EACH 
//				OTHER, UNLIKE ABOVE, WHERE IN THE CLASS, THEY ARE ORGANIZED BY 
//				THEIR MEMBER TYPE
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------   F U N C T I O N S :  S E C T I O N   00   --------------------------------//


student_roster_list::student_roster_list( ){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// This Is The Default Constructor Function That Initializes The 
// Student_roster_lists Student Node.
//-----------------------------------------------------------------------------

    //---------------------------------------------------------------------
    // Defualt Student List  Head Pointer Initialization                  :
    //---------------------------------------------------------------------
    student_record_head_ptr        = nullptr;
}


void student_roster_list::CreateClassList( ifstream &inputData ){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// Reads the student’s information from the input file and  place
// all student’s names along with their information  in a linked list,
// in alphabetically order, by last name.
//-----------------------------------------------------------------------------

    //---------------------------------------------------------------------
    // Variable Declarations                                              :
    //---------------------------------------------------------------------
    string f_name, l_name;
    int    identification;
    string class_name;
    int    class_credit;
    char   class_grade;
    
    int    counter_i;
    int    counter_j;
    
    int    id_flag;
	bool   is_done = false;
    //---------------------------------------------------------------------
    // Class Variable Declarations                                        :
    //---------------------------------------------------------------------
    student_record_buffer* buffer_newNode;
    
    student_record*        currentStudentNode;
    
    personal_class_record* traverseNode;
    personal_class_record* currentStudentClassNode;
    
    
    //---------------------------------------------------------------------
    // Insert .txt Data Into A Buffer                                     :
    //---------------------------------------------------------------------
    // Load .txt File Info Into Memory:
    while( !inputData.eof()  ){
        
        while( inputData >> f_name
                         >> l_name
                         >> identification
                         >> class_name
                         >> class_credit
                         >> class_grade   )
        {
            // Create A New Buffer Node:
            buffer_newNode                       = new student_record_buffer;
            buffer_newNode -> f_name             = f_name;
            buffer_newNode -> l_name             = l_name;
            buffer_newNode -> identification_num = identification;
            buffer_newNode -> class_name         = class_name;
            buffer_newNode -> class_credit       = class_credit;
            buffer_newNode -> current_grade      = class_grade;
            
            // Insert The New Node Into The Dynamic Array Buffer:
            student_list_buffer.push_back( buffer_newNode );
        }
    }
    
    
    //---------------------------------------------------------------------
    // Organize And Insert Buffer Data Into A Useable Student Database    :
    //---------------------------------------------------------------------
    // Set Flags:
    counter_i = 0;  // Insertion Node Counter
	
    //---------------------------------------------------------------------
    // Begin While-Loop  -  Load Data Into The Database:
    while(  counter_i <  static_cast<int>(student_list_buffer.size())  ){

		// Set/Reset The While-loop Flag:
		is_done = false;
        // Traversed Untile A New Student Identification Has Been Found:
        while(  counter_i < static_cast<int>(student_list_buffer.size())     && is_done == false )
        {
			if (student_list_buffer[counter_i]->identification_num == -1) {
				counter_i++;
			}
			else {
				is_done = true;
			}
        }
        
        //------------------------------------------------------------------
        // Begin If-Statement:
        if(  counter_i < static_cast<int>(student_list_buffer.size())  ){
            // Set/Reset Student Identification Flag:
            id_flag = student_list_buffer[ counter_i ] -> identification_num;
            
            
            // Create Student Personal Info:
            currentStudentNode                          = new student_record;
            currentStudentNode -> f_name                = student_list_buffer[ counter_i ] -> f_name;
            currentStudentNode -> l_name                = student_list_buffer[ counter_i ] -> l_name;
            currentStudentNode -> identification_num    = student_list_buffer[ counter_i ] -> identification_num;
            
            
            // Set Flags:
            counter_j = counter_i;  // Traversal Counter
            
            // Insert ALL EVERY OTHER NODES WITH THAT ID AND DELETE IT FROM THE BUFFER -  Student Personal Info:
            while(  counter_j < static_cast<int>(student_list_buffer.size())   )
            {
      
                if(  student_list_buffer[ counter_j ] -> identification_num == id_flag  ){
                    
                    // Create Student Class Info:
                    currentStudentClassNode                  = new personal_class_record;
                    currentStudentClassNode -> class_name    = student_list_buffer[ counter_j ] -> class_name;
                    currentStudentClassNode -> class_credit  = student_list_buffer[ counter_j ] -> class_credit;
                    currentStudentClassNode -> current_grade = student_list_buffer[ counter_j ] -> current_grade;
                    currentStudentClassNode -> next          = nullptr;
                    

                    if( currentStudentNode -> personal_class_record == nullptr  ){
                        
                        // Insert The First Node:
                        currentStudentNode -> personal_class_record = currentStudentClassNode;
                        
                    }
                    else{
                        // Initialize The Traverse Node:
                        traverseNode = (currentStudentNode -> personal_class_record);
                        while(  traverseNode -> next != nullptr  )
                        {

                            traverseNode = (traverseNode -> next);
                        }
                        traverseNode -> next = currentStudentClassNode;
                    }
                    
                    // Remove Buffer Index From The Search Pool:
                    student_list_buffer[ counter_j ] -> identification_num = -1;
                }

				// Count The Class:
				currentStudentNode -> num_of_classes++;

                // Go To The Next Node:
                counter_j++;
            }
            // Insert Student Personal Info:
            student_list_arr.push_back( currentStudentNode );
            // Count The New Student Entry:
            max_student_counter++;
        }
        // END If-Statement
        //-----------------------------------------------------------------
    }
    // End While-Loop  -  Load Data Into The Database:
    //---------------------------------------------------------------------
    
    // Once Done, Free Up Memory. Clear Out All The Data In The Buffer:
    student_list_buffer.clear();

}
void student_roster_list::FindGPA(  ){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// Calculates the GPA for any student by multiplying the credit hours
// (which is given below for each course) by the grade value
// (A=4.0, B= 3.0, C=2.0, D=1.0, and F=0) for each course.
// Then you calculate the sum of the GPA for all the courses
// and divide it by the total credits of all the courses.
//-----------------------------------------------------------------------------


    //---------------------------------------------------------------------
    // Variable Declarations                                              :
    //---------------------------------------------------------------------
	float   total_grade_summation;	 	 // This is the summation of all 
										 // the gradesthe student recieved
										 // in their courses

	float   total_credit_summation;		 // This is the summation of all 
										 // the course credits the student 
										 // is taking
	//------------------------
    int index;							 // Used For Traversing The 
										 // Student List

    personal_class_record* traverseNode; // Used For Traversing The 
										 // Student List
    

    //---------------------------------------------------------------------
    // Calculate And Store The GPA                                        :
    //---------------------------------------------------------------------
    // Go Through The List Of Students:
    for( index = 0; index < static_cast<int>(student_list_arr.size( )); index++ ){
		
		// Set The Defaults For The GPA Parameters:
		total_grade_summation		    = 0.0;
		total_credit_summation			= 0.0;

        // Traverse Each Particular Students Class Info:
        traverseNode = student_list_arr[ index ] -> personal_class_record;
        while(  traverseNode  !=  nullptr ){
		      
			// Add For A GRADE Of A:
			if (    static_cast<int>(traverseNode->current_grade)  == 65 || static_cast<int>(traverseNode->current_grade) == 97)
			{
				total_grade_summation += static_cast<float>((traverseNode->class_credit)*4.0);
			}
			// Add For A GRADE Of B:
			else if (static_cast<int>(traverseNode->current_grade) == 66 || static_cast<int>(traverseNode->current_grade) == 98)
			{
				total_grade_summation += static_cast<float>((traverseNode->class_credit)*3.0);
			}
			// Add For A GRADE Of C:
			else if (static_cast<int>(traverseNode->current_grade) == 67 || static_cast<int>(traverseNode->current_grade) == 99)
			{
				total_grade_summation += static_cast<float>((traverseNode->class_credit)*2.0);
			}
			// Add For A GRADE Of D:
			else if (static_cast<int>(traverseNode->current_grade) == 68 || static_cast<int>(traverseNode->current_grade) == 100)
			{
				total_grade_summation += static_cast<float>((traverseNode->class_credit)*1.0);
			}
			// No Grade Given ( e.g. incomplete grade ):
			else {
				total_grade_summation += 0.0;
			}

			// ADD The Credit:
			total_credit_summation  += static_cast<float>(( traverseNode->class_credit ));


            // Move To The Next Node:
            traverseNode = (traverseNode -> next);
        }


		// If No Classes Are Available Then Change The Value To -1.
		// This Default Value Of -1 Denotes The Student Has Not Taken A Class:
		if (  student_list_arr[index]->personal_class_record == nullptr  ) {

			student_list_arr[index]->gpa = -1.00;
		}
		else { // ... If Classes Are Available:

			// Insert Student Grade Point Average (GPA):
			student_list_arr[index]->gpa = (total_grade_summation / total_credit_summation);
		}
     
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------   F U N C T I O N S :  S E C T I O N   01   --------------------------------//


void student_roster_list::InsertNewStudent( string  f_name,
											string  l_name,
											int     identification_num	)
{
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// Will insert a new student into the class, along with all  the student’s
// information as: first name, last name, ID, course name, credits, and grade,
// in the proper location in the list sorted alphabetically by last name.
// After insertion, you should show the count of the class.
//-----------------------------------------------------------------------------


	// If The Student Doesn't Already Exist Then You May Continue Inserting
	// Them Into The List:
	if (   student_exists(f_name, l_name, identification_num)   ==   false   ) {
		//---------------------------------------------------------------------
		// Class Variable Declarations                                        :
		//---------------------------------------------------------------------
		student_record*        currentStudentNode;

		//---------------------------------------------------------------------
		// Create Student Personal Info										  :
		//---------------------------------------------------------------------
		currentStudentNode = new student_record;
		currentStudentNode->f_name = f_name;
		currentStudentNode->l_name = l_name;
		currentStudentNode->identification_num = identification_num;

		currentStudentNode->gpa = -1.00;  // Default Value Of -1 
										  // Is Given Since The 
										  // Student Has Not 
										  // Taken Any Classes

		//---------------------------------------------------------------------
		// Insert New Student Personal Info                                   :
		//---------------------------------------------------------------------
		student_list_arr.push_back(currentStudentNode);
		// Count The New Student Entry:
		max_student_counter++;

		//---------------------------------------------------------------------
		// Sort List                                                          :
		//---------------------------------------------------------------------
		if (print_initialized == false) {

			// Change initialization value:
			print_initialized = true;

			// Sort By Last Name:
			Sort("LAST_NAME");
		}
	}

}
bool student_roster_list::student_exists( string  f_name,
										  string  l_name,
										  int     identification_num    ){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// This Helper Function Searches The Student List To Check If A Student Exists
// Within it. It Returns True If The Student Is Found Else It Returns False 
// If The Sudent Was Not Found.
//
// NOTE: Multiple Students With The Same First Name And Last name Can Exists,
//		 As Such Can Be True, But, As They Are Seperate Individuals, 
//		 They MUST Have Different ID Numbers.
//-----------------------------------------------------------------------------


	if (!student_list_arr.empty()) {

		//---------------------------------------------------------------------
		// Variable Declarations                                              :
		//---------------------------------------------------------------------
		int index;
		bool is_found;


		//-------------------------------------------------------------------------
		// Begin While-Loop  - "Check Students":
		index = 0;
		is_found = false;
		while (index < static_cast<int>(student_list_arr.size()) && is_found == false) {


			if ( student_list_arr[index]->f_name			 == f_name  
				 &&
				 student_list_arr[index]->l_name			 == l_name  
				 &&
				 student_list_arr[index]->identification_num == identification_num ) {


				// Student Has Been Found. Change The Flag Value:
				is_found = true;
			}

			// Increment To The Next Student In The List:
			index++;
		}
		// If The Flag Is Still False Then ... :
		if (is_found == false) {

			// Output That The Student Was NOT Found:
			return false;
		}
		else {

			// Output That The Student Was Found:
			return true;
		}
		// End While-Loop  - "Check Students"
		//-------------------------------------------------------------------------
	}
	else {
		
		// Output That The Student Was NOT Found:
		return false;
	}
}



void student_roster_list::DeleteStudent(int identification_num)
{
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// Deletes the student’s record, once you enter student’s
// first name followed by last name, or by using the student’s ID.
// If the student is not registered in the class, a message should appear
// indicating that the student is not registered.  Show the count of the class
// after deleting.
//-----------------------------------------------------------------------------


	//---------------------------------------------------------------------
	// Variable Declarations                                              :
	//---------------------------------------------------------------------
	int index;
	bool is_done;

	//-------------------------------------------------------------------------
	// Begin While-Loop  - "Check Students":
	index = 0;
	is_done = false;
	while (index < static_cast<int>(student_list_arr.size()) && is_done == false) {


		if (student_list_arr[index]->identification_num == identification_num) {

			// Erase 1 Student ( 1 Element ):
			student_list_arr.erase(student_list_arr.begin() + index,
				student_list_arr.begin() + index + 1);


			// Decrement The Count Of Students:
			max_student_counter--;

			// Change Flag Value:
			is_done = true;
		}

		index++;
	}
	if (is_done == false) {

		cout << "No Student Was Found.";
		cout << endl << endl << endl;
	}
	// End While-Loop  - "Check Students"
	//-------------------------------------------------------------------------
}



////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------   F U N C T I O N S :  S E C T I O N   02   --------------------------------//



void student_roster_list::AddCourse(  int    identification_num,
									  string course__name,
									  int    class_credit,
									  char   current_grade				)
{
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// Adds a new course given the student’s name or ID.
// It also makes other necessary updates once you add the course.
//-----------------------------------------------------------------------------


   //---------------------------------------------------------------------
   // Variable Declarations                                              :
   //---------------------------------------------------------------------
	int  index;
	bool is_done;
	bool repitition_exists;
	personal_class_record* traverseNode;
	personal_class_record* secondary_traverseNode;
	personal_class_record* newNode;


	//-------------------------------------------------------------------------
	// Begin While-Loop  - "Check Students":
	index   = 0;
	is_done = false;
	while ( index < static_cast<int>(student_list_arr.size())   &&  is_done == false  ) {


		//---------------------------------------------------------------------
		// Begin The If-Statement - "Check GPA" :
		if (student_list_arr[index]->identification_num == identification_num) {
			

			// Traverse Student Class Info:
			traverseNode = student_list_arr[index]->personal_class_record;
			secondary_traverseNode = student_list_arr[index]->personal_class_record;
			if ((student_list_arr[index]->personal_class_record) != nullptr) {


				// Set The While-Loop Flag:
				repitition_exists = false;

				// If At Least 1 Node Exists, 
				// Then Traverse To The End Of The Course Records List:
				while (traverseNode != nullptr  && repitition_exists == false) {

					// Check If The Class Already Exists For The Student:
					if (traverseNode->class_name == course__name) {

						repitition_exists = true;
					}
					else { // ... If The Class Doesn't Exists For The Student:

						// Move To The Next Node:
						secondary_traverseNode = traverseNode;
						traverseNode = (traverseNode->next);
					}
				}


				// If The Class Can Be Inserted Into The Students List:
				if (repitition_exists == false) {

					// Create The New Course Node:
					newNode = new personal_class_record;
					newNode->class_name = course__name;
					newNode->class_credit = class_credit;
					newNode->current_grade = current_grade;
					newNode->next = nullptr;

					// Insert The Node:
					secondary_traverseNode->next = newNode;
				}
				else { // ... If The Class Already Exists Then ... :

					cout << endl;
					cout << "--------------------------------------------------------------" << endl;
					cout << "ERROR: The Class Already Exists In The Students Roster"		 << endl;
					cout << "--------------------------------------------------------------" << endl;
					cout << endl;
				}
			}
			else{ // ... If ( (student_list_arr[index]->personal_class_record) == nullptr) 


				// Create The New Course Node:
				newNode = new personal_class_record;
				newNode->class_name = course__name;
				newNode->class_credit = class_credit;
				newNode->current_grade = current_grade;
				newNode->next = nullptr;

				// Make The First Node equal the newNode:
				(student_list_arr[index]->personal_class_record) = newNode;
			}


			// Set/Reset GPA Value:
			Find_one_GPA(student_list_arr, index);


			// Change While-Loop Parameter Value:
			is_done = true;
		}
		// End Of If-Statement  - "Check GPA" 
		//---------------------------------------------------------------------

		// Move To The Next Index:
		index++;

	}
	// End While-Loop  - "Check Students"
	//-------------------------------------------------------------------------
}

void student_roster_list::DeleteCourse(	int identification_num,
										string course_name		)
{
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// You should be able to delete any of the courses a student is registered in.
// To do so, you will have to ask for the student’s name or ID, and the course
// that needs to be deleted.
//-----------------------------------------------------------------------------


	//---------------------------------------------------------------------
	// Variable Declarations                                              :
	//---------------------------------------------------------------------
	int  index;					// While-Loop Counter
	bool is_done;				// Checks For Abrupt Endings In The While-Loop
	bool is_exiting;			// Check If The Process Is Done And Exits The While-loop
	bool is_student_found;		// Checks If Student Value Was Found
	bool is_class_found;		// Checks If The Class Was Found
	personal_class_record* traverseNode;
	personal_class_record* deleterNode;
	personal_class_record* linkerNode;


	//-------------------------------------------------------------------------
	// Begin While-Loop  - "Check Students":
	index = 0;
	is_done  = false;
	is_student_found = false;
	is_class_found = false;
	deleterNode = nullptr;
	while (index < static_cast<int>(student_list_arr.size()) && is_done == false) {


		//---------------------------------------------------------------------
		// Begin The If-Statement :
		if (student_list_arr[index]->identification_num == identification_num) {
			
			// Change The Statement To True. The Student Was Found:
			is_student_found = true;

			// Traverse Student Class Info:
			traverseNode = student_list_arr[index]->personal_class_record;
			if ((student_list_arr[index]->personal_class_record) != nullptr) {


				//---------------------------------------------------------------------
				// If At Least 1 Node Exists,
				// Then Traverse To The End Of The Course Records List:
				is_exiting = false;
				while (traverseNode != nullptr  &&  is_exiting == false) {



					// Find The Course To Delete:
					if (traverseNode->class_name == course_name)
					{

						// Change The Statement To True. The Student Was Found:
						is_class_found = true;


						// If This Node Is The First Node And ... :
						if (traverseNode == student_list_arr[index]->personal_class_record) {


							// If First Node is the only node that exists:
							if (traverseNode->next == nullptr)
							{

								// Reset The Node Value:
								student_list_arr[index]->personal_class_record = nullptr;

							}

							// If First Node is NOT the only node that exists:
							else if (traverseNode->next != nullptr)
							{
								deleterNode = traverseNode;
								traverseNode = (traverseNode->next);

								// Delete The First Node :
								delete deleterNode;

								// Reset The First (Head) Node:
								student_list_arr[index]->personal_class_record = traverseNode;


							}

						}
						else { // ... If This Node Is NOT The First Node And ... :

							   // If the Node Is In The Middle Of Two Node:
							if (traverseNode->next != nullptr)
							{
								// Set The Node That You Will Use To Relink The List:
								linkerNode = (traverseNode->next);

								// Relink:
								deleterNode->next = linkerNode;

								// Delete The Last Node:
								deleterNode = traverseNode;
								delete deleterNode;

							}
							// If The Node Is The Last Node In The List:
							else if (traverseNode->next == nullptr)
							{

								// Remove The Last Node From The List:
								deleterNode->next = nullptr;

								// Delete The Last Node:
								deleterNode = traverseNode;
								delete deleterNode;

							}
						}

						// Change While-Loop Flag Since The Node Has Been Found:
						is_exiting = true;
					}
					else {

						// Move To The Next Node:
						deleterNode = traverseNode;
						traverseNode = (traverseNode->next);

					}

				}
				// End While-Loop  - "Check Students"
				//-------------------------------------------------------------------------
			}
			else { // ... If ( (student_list_arr[index]->personal_class_record) == nullptr)

				cout << endl;
				cout << "----------------------------------------------------" << endl;
				cout << " There Is No Course To Delete."					   << endl;
				cout << "----------------------------------------------------" << endl;
				cout << endl;
			}


			// Set/Reset GPA Value:
			Find_one_GPA(student_list_arr, index);

			// Change While-Loop Parameter Value:
			is_done = true;
		}
		// End The If-Statement :
		//---------------------------------------------------------------------
		index++;
	}


	// If No Student Was Found Then Let The User Know:
	if (is_student_found == false) {

		cout << endl;
		cout << "---------------------------------------------------------" << endl;
		cout << " There Is Nothing To Delete. The Student Was Not Found."   << endl;
		cout << "---------------------------------------------------------" << endl;
		cout << endl;
	}

	if (is_student_found == true && is_class_found == false) {

		cout << endl;
		cout << "---------------------------------------------------------" << endl;
		cout << " There Is Nothing To Delete. The Class Does Not Exist."    << endl;
		cout << "---------------------------------------------------------" << endl;
		cout << endl;
	}

}



void student_roster_list::Modify(int     identification_num,
	string  course_name,
	char    class_letter_grade)
{
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// You should be able to modify the student’s grade.
// So you should be able to ask the user for the student’s name or ID,
// then ask what course grade needs to be modified. You should show update
// the student’s information and print the updated student’s information.
//-----------------------------------------------------------------------------


	//---------------------------------------------------------------------
	// Variable Declarations                                              :
	//---------------------------------------------------------------------
	int  index;					// While-Loop Counter
	bool is_done;				// Checks For Abrupt Endings In The While-Loop
	bool is_exiting;			// Check If The Process Is Done And Exits The While-loop
	bool is_student_found;		// Checks If Deletion Value Was Found
	personal_class_record* traverseNode;

	//-------------------------------------------------------------------------
	// Begin While-Loop  - "Check Students":
	index = 0;
	is_done = false;
	is_student_found = false;
	while (index < static_cast<int>(student_list_arr.size()) && is_done == false) {


		//---------------------------------------------------------------------
		// Begin The If-Statement  :
		if (student_list_arr[index]->identification_num == identification_num) {

			// Change The Statement To True. The Student Was Found:
			is_student_found = true;

			// Traverse Student Class Info:
			traverseNode = student_list_arr[index]->personal_class_record;
			if ((student_list_arr[index]->personal_class_record) != nullptr) {


				// If At Least 1 Node Exists, 
				// Then Traverse To The End Of The Course Records List:
				is_exiting = false;
				while (traverseNode != nullptr  &&  is_exiting == false) {

					if (traverseNode->class_name == course_name) {

						traverseNode->current_grade = class_letter_grade;
						is_exiting = true;
					}
					else {
						// Move To The Next Node:
						traverseNode = (traverseNode->next);
					}
				}
				// If Nothing Was STILL not found then ... :
				if (is_exiting == false) {

					cout << endl;
					cout << "----------------------------------------------------" << endl;
					cout << " The Class Was Not Found."							   << endl;
					cout << "----------------------------------------------------" << endl;
					cout << endl;
				}

			}
			else {

				cout << endl;
				cout << "----------------------------------------------------" << endl;
				cout << " The Class Was Not Found."							   << endl;
				cout << "----------------------------------------------------" << endl;
				cout << endl;
			}


			// Set/Reset GPA Value:
			Find_one_GPA(student_list_arr, index);


			// Change While-Loop Parameter Value:
			is_done = true;
		}
		// End Of If-Statement   
		//---------------------------------------------------------------------

		// Move To The Next Index:
		index++;

	}
	// End While-Loop  - "Check Students"
	//-------------------------------------------------------------------------

	// If No Student Was Found Then Let The User Know:
	if (is_student_found == false) {

		cout << endl;
		cout << "---------------------------------------------------------" << endl;
		cout << " There Is Nothing To Delete. The Student Was Not Found." << endl;
		cout << "---------------------------------------------------------" << endl;
		cout << endl;
	}
}

void student_roster_list::Find_one_GPA(	  vector< student_record* > &student_list_arr_container,
										  int    index											  )
{
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// This Helper Function calculates the GPA For One Student When 
// Inserting/Deleting A Classes For Them.
//-----------------------------------------------------------------------------


	//---------------------------------------------------------------------
	// Variable Declarations                                              :
	//---------------------------------------------------------------------
	float   total_grade_summation;	 	 // This is the summation of all 
										 // the gradesthe student recieved
										 // in their courses

	float   total_credit_summation;		 // This is the summation of all 
										 // the course credits the student 
										 // is taking

	personal_class_record* traverseNode;

	//---------------------------------------------------------------------
	// Calculate And Store The GPA                                        :
	//---------------------------------------------------------------------
	// Set The Defaults For The GPA Parameters:
	total_grade_summation = 0.0;
	total_credit_summation = 0.0;

	// Traverse Each Particular Students Class Info:
	traverseNode = student_list_arr_container[index]->personal_class_record;
	while (traverseNode != nullptr) {

		// Add For A GRADE Of A:
		if (    static_cast<int>(traverseNode->current_grade)  == 65 || static_cast<int>(traverseNode->current_grade) == 97)
		{
			total_grade_summation += static_cast<float>((traverseNode->class_credit)*4.0);
		}
		// Add For A GRADE Of B:
		else if (static_cast<int>(traverseNode->current_grade) == 66 || static_cast<int>(traverseNode->current_grade) == 98)
		{
			total_grade_summation += static_cast<float>((traverseNode->class_credit)*3.0);
		}
		// Add For A GRADE Of C:
		else if (static_cast<int>(traverseNode->current_grade) == 67 || static_cast<int>(traverseNode->current_grade) == 99)
		{
			total_grade_summation += static_cast<float>((traverseNode->class_credit)*2.0);
		}
		// Add For A GRADE Of D:
		else if (static_cast<int>(traverseNode->current_grade) == 68 || static_cast<int>(traverseNode->current_grade) == 100)
		{
			total_grade_summation += static_cast<float>((traverseNode->class_credit)*1.0);
		}
		// No Grade Given ( e.g. incomplete grade ):
		else {
			total_grade_summation += 0.0;
		}

		// ADD The Credit:
		total_credit_summation += static_cast<float>((traverseNode->class_credit));


		// Move To The Next Node:
		traverseNode = (traverseNode->next);
	}


	// If No Classes Are Available Then Change The Value To -1.
	// This Default Value Of -1 Denotes The Student Has Not Taken A Class:
	if (  student_list_arr[index]->personal_class_record == nullptr  ) {

		student_list_arr[index]->gpa = -1.00;
	}
	else { // ... If Classes Are Available:

		// Insert Student Grade Point Average (GPA):
		student_list_arr[index]->gpa = (total_grade_summation / total_credit_summation);
	}
}




////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------   F U N C T I O N S :  S E C T I O N   03   --------------------------------//




void student_roster_list::Search(int  identification_num) {
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// By giving the student ID, you should be able to search for that student
// in the list. You should return the student’s first name, last name, ID, GPA,
// and the courses registered.
//
// Note: If the student is not found in the list, then the function prints
//       a message indicating so.
//-----------------------------------------------------------------------------


	if (!student_list_arr.empty()) {
		//---------------------------------------------------------------------
		// Variable Declarations                                              :
		//---------------------------------------------------------------------
		int index;
		bool is_done;
		personal_class_record* traverseNode;

		//---------------------------------------------------------------------
		// Print                                                              :
		//---------------------------------------------------------------------
		// Divider:
		cout << endl;
		cout << "------------------------------------------------------------------------------------" << endl;
		cout << "////////////////////////////////////////////////////////////////////////////////////" << endl;
		cout << "/////////////`                                                       `//////////////" << endl;
		cout << "////////////   S E A R C H I N G  F O R   S T U D E N T   I N F O     //////////////" << endl;
		cout << "///////////																		 " << endl;
		cout << endl;


		//-------------------------------------------------------------------------
		// Begin While-Loop  - "Check Students":
		index = 0;
		is_done = false;
		while (index < static_cast<int>(student_list_arr.size()) && is_done == false) {


			//---------------------------------------------------------------------
			// Begin The If-Statement - "Check GPA" :
			if (student_list_arr[index]->identification_num == identification_num) {


				cout << "==========================================" << endl;
				cout << "                                        ::" << endl;
				cout << "   S T U D E N T    I N F O             ::" << endl;
				cout << "                                        ::" << endl;
				cout << "==========================================" << endl;
				//-----------------------------------------------------------------
				// Output Students Personal Info			    		          :
				//-----------------------------------------------------------------
				cout << "   Name:    " << student_list_arr[index]->f_name << " "
					 << student_list_arr[index]->l_name << "  ";
				cout << endl;

				//-----------------------------------------------------------------
				// Output Identification Number					                  :
				//-----------------------------------------------------------------
				cout << "   ID# :    " << student_list_arr[index]->identification_num;
				cout << endl;

				//-----------------------------------------------------------------
				// Output Students GPA					                          :
				//-----------------------------------------------------------------
				cout << "   GPA :    ";

				// If No Classes have Been Taken:
				if (student_list_arr[index]->gpa == -1.00) {

					cout << "N/A";
				}
				else { // ... If Classes have Been Taken:

					cout << gpa_formatter(student_list_arr, index);
				}
				cout << endl << endl;

				//-----------------------------------------------------------------
				// Output Students Classes						                  :
				//-----------------------------------------------------------------
				cout << "=======================================" << endl;
				cout << "                                     ::" << endl;
				cout << "   C L A S S    L I S T              ::" << endl;
				cout << "                                     ::" << endl;
				cout << "=======================================" << endl;
				cout << "   Class Name  |  Credits  |  Grade   |" << endl;
				cout << "--------------- ----------- -----------" << endl;


				// Traverse Student Class Info:
				traverseNode = student_list_arr[index]->personal_class_record;
				while (traverseNode != nullptr) {

					// Output Student Class Info:
					cout << "   " << traverseNode->class_name;
					if ((traverseNode->class_name).size() <= 6) {
						cout << " ";
					}
					cout << "     |  ";
					cout << traverseNode->class_credit << "        |  "
						<< traverseNode->current_grade << "  ";
					cout << endl;

					// Move To The Next Node:
					traverseNode = (traverseNode->next);
				}
				if ((student_list_arr[index]->personal_class_record) == nullptr) {

					cout << "No Classes Available.";
					cout << endl;
				}

				cout << endl << endl << endl;
				is_done = true;
			}
			// End Of If-Statement  - "Check GPA" 
			//---------------------------------------------------------------------

			index++;
		}
		// If The Flag Is Still False Then ... :
		if (is_done == false) {

			// Divider:
			cout << endl << endl;

			cout << "No Students Was Found." << endl;
		}
		// End While-Loop  - "Check Students"
		//-------------------------------------------------------------------------
	}
	else {
		// Divider:
		cout << endl;
		cout << "------------------------------------------------------------------------------------" << endl;
		cout << "////////////////////////////////////////////////////////////////////////////////////" << endl;
		cout << endl << endl;

		cout << "No Students Were Found. The List Is Empty." << endl;
	}

	// Output Divider:
	cout << endl;
	cout << "///////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "///////////////////////////////////////////////////////////////////////////////////////////////" << endl;
}




////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------   F U N C T I O N S :  S E C T I O N   04   --------------------------------//




void student_roster_list::Sort( string search_val ){
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// You should be able to sort the list by first name, GPA, and ID.
// You could use any sorting algorithm.  Then print the list after you sort.
// You should ask the user how you want to sort, either by
// first name, or  GPA, or  ID.
// When you print, you will have to use a different print function than the one
// described below, because the one below prints the names sorted
// alphabetically by last name.
//-----------------------------------------------------------------------------

	
	//
	int size = static_cast<int>(student_list_arr.size());

	// CHeck THe Value That You Will Be Using As The Reference Key To Sort The List:
	if (      search_val == "FIRST_NAME"   ) {
		
		mergeSort(  student_list_arr,  0,  size - 1,  "FIRST_NAME"	 );
	}
	else if ( search_val == "LAST_NAME"   ) {

		mergeSort(  student_list_arr,  0,  size - 1,  "LAST_NAME"  );
	}
	else if ( search_val == "ID_NUM"   ) {

		mergeSort(  student_list_arr,  0,  size - 1,  "ID_NUM"  );
	}
	else if (search_val == "GPA") {

		mergeSort(student_list_arr, 0, size - 1, "GPA");
	}
	else {

		cout << "No Valid Input." << endl;
	}

    
}
void student_roster_list::mergeSort
(   vector< student_record* > &student_list_arr_container,
	int    leftmost_index,
	int    rightmost_index,
	string searchVal										)
{
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// mergeSort - This is A helper function for the "Sort" function
//-----------------------------------------------------------------------------


	// If You Are Searching By ID Numbers:
	if (leftmost_index < rightmost_index) {
		// midpoint is the point where the array is divided into two subsets ( subarrays )
		int middle_index = leftmost_index + (rightmost_index - leftmost_index) / 2;

		// FIRST  HALF (CUT) - Subset:
		mergeSort(student_list_arr_container, leftmost_index, middle_index, searchVal);
		// SECOND HALF (CUT) - Subset:
		mergeSort(student_list_arr_container, middle_index + 1, rightmost_index, searchVal);
		// Merge ALL the sorted subsets ( subarrays ):
		mergeList(student_list_arr_container, leftmost_index, middle_index, rightmost_index, searchVal);
	}
}
void student_roster_list::mergeList
(   vector< student_record* > &student_list_arr_container,
	int    leftmost_index,
	int    middle_index,
	int    rightmost_index,
	string searchVal										)
{
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// MmrgeList - This is A helper function for the "Sort" function
//-----------------------------------------------------------------------------


	// Create L ← A[leftmost_index..middle_index] and M ← A[middle_index+1..rightmost_index]
	int n1 = middle_index - leftmost_index + 1;
	int n2 = rightmost_index - middle_index;

	//---------------------------------------------------------------------
	// Declare The Dynamic Arrays Checking				                  :
	//---------------------------------------------------------------------
	vector< student_record* > L(n1);
	vector< student_record* > M(n2);

	//---------------------------------------------------------------------
	// Initialize/Populate The Dynamic Array  			                  :
	//---------------------------------------------------------------------
	for (int i = 0; i < n1; i++) {
		L[i] = student_list_arr_container[  leftmost_index + i    ];
	}
	for (int j = 0; j < n2; j++) {
		M[j] = student_list_arr_container[  middle_index + 1 + j  ];
	}
	//---------------------------------------------------------------------
	// Maintain current index of sub-arrays and main array	   ***
	//---------------------------------------------------------------------
	// Variable Declarations:
	int i, j, k;
	i = 0;
	j = 0;
	k = leftmost_index;

	

	while (i < n1 && j < n2) {

		if (searchVal == "FIRST_NAME") {

			if (  L[i]->f_name  <=  M[j]->f_name  ){
				student_list_arr_container[k] = L[i];
				i++;
			}
			else {
				student_list_arr_container[k] = M[j];
				j++;
			}
		}
		else if (searchVal == "LAST_NAME") {

			if (  L[i]->l_name  <=  M[j]->l_name  ){
				student_list_arr_container[k] = L[i];
				i++;
			}
			else {
				student_list_arr_container[k] = M[j];
				j++;
			}
		}
		else if (searchVal == "ID_NUM") {

			if (  L[i]->identification_num  <=  M[j]->identification_num){
				student_list_arr_container[k] = L[i];
				i++;
			}
			else {
				student_list_arr_container[k] = M[j];
				j++;
			}
		}
		else if (searchVal == "GPA") {

			if (L[i]->gpa <= M[j]->gpa) {
				student_list_arr_container[k] = L[i];
				i++;
			}
			else {
				student_list_arr_container[k] = M[j];
				j++;
			}
		}
		else {
			// Do Nothing ...
		}

		k++;

	}


	while (i < n1) {
		// Swap (Chenge) The Contents
		// At The Specified Index:
		student_list_arr_container[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		// Swap (Chenge) The Contents
		// At The Specified Index:
		student_list_arr_container[k] = M[j];
		j++;
		k++;
	}
}

void student_roster_list::Sort_Print() {
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// Prints all the students information alphabetically, sorted by last name,
// and the total number of students in the class.
//-----------------------------------------------------------------------------

	if (!student_list_arr.empty()) {
		//---------------------------------------------------------------------
		// Variable Declarations                                              :
		//---------------------------------------------------------------------
		int index;
		personal_class_record* traverseNode;


		//---------------------------------------------------------------------
		// Print                                                              :
		//---------------------------------------------------------------------
		// Divider:
		cout << endl;
		cout << "------------------------------------------------------------------------------------" << endl;
		cout << "////////////////////////////////////////////////////////////////////////////////////" << endl;
		cout << "///////////////////////////`                             `//////////////////////////" << endl;
		cout << "//////////////////////////    A L L   S T U D E N T S     //////////////////////////" << endl;
		cout << "/////////////////////////		                 									 " << endl;
		cout << endl;

		//-------------------------------------------------------------------------
		// Begin For-Loop  - "Printing":
		for (index = 0; index < static_cast<int>(student_list_arr.size()); index++) {

			cout << "==========================================" << endl;
			cout << "                                        ::" << endl;
			cout << "   S T U D E N T    I N F O             ::" << endl;
			cout << "                                        ::" << endl;
			cout << "==========================================" << endl;
			//-----------------------------------------------------------------
			// Output Students Personal Info			    		          :
			//-----------------------------------------------------------------
			cout << "   Name:    " << student_list_arr[index]->f_name << " "
				<< student_list_arr[index]->l_name << "  ";
			cout << endl;

			//-----------------------------------------------------------------
			// Output Identification Number					                  :
			//-----------------------------------------------------------------
			cout << "   ID# :    " << student_list_arr[index]->identification_num;
			cout << endl;

			//-----------------------------------------------------------------
			// Output Students GPA					                          :
			//-----------------------------------------------------------------
			cout << "   GPA :    ";

			// If No Classes have Been Taken:
			if (student_list_arr[index]->gpa == -1.00) {

				cout << "N/A";
			}
			else { // ... If Classes have Been Taken:

				cout << gpa_formatter(student_list_arr, index);
			}
			cout << endl << endl;

			//-----------------------------------------------------------------
			// Output Students Classes						                  :
			//-----------------------------------------------------------------
			cout << "=======================================" << endl;
			cout << "                                     ::" << endl;
			cout << "   C L A S S    L I S T              ::" << endl;
			cout << "                                     ::" << endl;
			cout << "=======================================" << endl;
			cout << "   Class Name  |  Credits  |  Grade   |" << endl;
			cout << "--------------- ----------- -----------" << endl;


			// Traverse Student Class Info:
			traverseNode = student_list_arr[index]->personal_class_record;
			while (traverseNode != nullptr) {

				// Output Student Class Info:
				cout << "   " << traverseNode->class_name;
				if ((traverseNode->class_name).size() <= 6) {
					cout << " ";
				}
				cout << "     |  ";
				cout << traverseNode->class_credit << "        |  "
					<< traverseNode->current_grade << "  ";
				cout << endl;

				// Move To The Next Node:
				traverseNode = (traverseNode->next);
			}
			if ((student_list_arr[index]->personal_class_record) == nullptr) {

				cout << "No Classes Available.";
				cout << endl;
			}


			// Student Info Divider:
			if (index < static_cast<int>(student_list_arr.size()) - 1) {

				cout << endl;
				cout << "////////////////////////////////////////////////";
			}
			cout << endl << endl << endl;
		}
		// End For-Loop  - "Printing"
		//-------------------------------------------------------------------------

	}
	else {
		// Divider:
		cout << endl;
		cout << "------------------------------------------------------------------------------------" << endl;
		cout << "////////////////////////////////////////////////////////////////////////////////////" << endl;
		cout << endl << endl;

		cout << "No Students Were Found. The List Is Empty." << endl;
	}

	// Output Divider:
	cout << endl;
	cout << "///////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "///////////////////////////////////////////////////////////////////////////////////////////////" << endl;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------   F U N C T I O N S :  S E C T I O N   05   --------------------------------//




void student_roster_list::Print() {
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// Prints all the students information alphabetically, sorted by last name,
// and the total number of students in the class.
//-----------------------------------------------------------------------------

	if (!student_list_arr.empty()) {
		//---------------------------------------------------------------------
		// Variable Declarations                                              :
		//---------------------------------------------------------------------
		int index;
		personal_class_record* traverseNode;


		//---------------------------------------------------------------------
		// Sort List                                                          :
		//---------------------------------------------------------------------
		if( print_initialized == false ){

			// Change initialization value:
			print_initialized = true;

			// Sort By Last Name:
			Sort( "LAST_NAME" );
		}


		//---------------------------------------------------------------------
		// Print                                                              :
		//---------------------------------------------------------------------
		// Divider:
		cout << endl;
		cout << "------------------------------------------------------------------------------------" << endl;
		cout << "////////////////////////////////////////////////////////////////////////////////////" << endl;
		cout << "///////////////////////////`                             `//////////////////////////" << endl;
		cout << "//////////////////////////    A L L   S T U D E N T S     //////////////////////////" << endl;
		cout << "/////////////////////////															 " << endl;
		cout << endl;

		//-------------------------------------------------------------------------
		// Begin For-Loop  - "Printing":
		for (index = 0; index < static_cast<int>(student_list_arr.size()); index++) {

			cout << "==========================================" << endl;
			cout << "                                        ::" << endl;
			cout << "   S T U D E N T    I N F O             ::" << endl;
			cout << "                                        ::" << endl;
			cout << "==========================================" << endl;
			//-----------------------------------------------------------------
			// Output Students Personal Info			    		          :
			//-----------------------------------------------------------------
			cout << "   Name:    " << student_list_arr[index]->f_name << " "
				<< student_list_arr[index]->l_name << "  ";
			cout << endl;

			//-----------------------------------------------------------------
			// Output Identification Number					                  :
			//-----------------------------------------------------------------
			cout << "   ID# :    " << student_list_arr[index]->identification_num;
			cout << endl;

			//-----------------------------------------------------------------
			// Output Students GPA					                          :
			//-----------------------------------------------------------------
			cout << "   GPA :    ";

			// If No Classes have Been Taken:
			if (student_list_arr[index]->gpa == -1.00) {

				cout << "N/A";
			}
			else { // ... If Classes have Been Taken:

				cout << gpa_formatter(student_list_arr, index);
			}
			cout << endl << endl;

			//-----------------------------------------------------------------
			// Output Students Classes						                  :
			//-----------------------------------------------------------------
			cout << "=======================================" << endl;
			cout << "                                     ::" << endl;
			cout << "   C L A S S    L I S T              ::" << endl;
			cout << "                                     ::" << endl;
			cout << "=======================================" << endl;
			cout << "   Class Name  |  Credits  |  Grade   |" << endl;
			cout << "--------------- ----------- -----------" << endl;


			// Traverse Student Class Info:
			traverseNode = student_list_arr[index]->personal_class_record;
			while (traverseNode != nullptr) {

				// Output Student Class Info:
				cout << "   " << traverseNode->class_name;
				if ((traverseNode->class_name).size() <= 6) {
					cout << " ";
				}
				cout << "     |  ";
				cout << traverseNode->class_credit << "        |  "
					<< traverseNode->current_grade << "  ";
				cout << endl;

				// Move To The Next Node:
				traverseNode = (traverseNode->next);
			}
			if ((student_list_arr[index]->personal_class_record) == nullptr) {

				cout << "No Classes Available.";
				cout << endl;
			}


			// Student Info Divider:
			if (index < static_cast<int>(student_list_arr.size()) - 1) {

				cout << endl;
				cout << "////////////////////////////////////////////////";
			}
			cout << endl << endl << endl;
		}
		// End For-Loop  - "Printing"
		//-------------------------------------------------------------------------

	}
	else {
		// Divider:
		cout << endl;
		cout << "------------------------------------------------------------------------------------" << endl;
		cout << "////////////////////////////////////////////////////////////////////////////////////" << endl;
		cout << endl << endl;

		cout << "No Students Were Found. The List Is Empty." << endl;
	}

	// Output Divider:
	cout << endl;
	cout << "///////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "///////////////////////////////////////////////////////////////////////////////////////////////" << endl;
}

void student_roster_list::HonorStudent() {
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// Prints the number of students and names of  students whose GPA is
// greater than 3.6
//-----------------------------------------------------------------------------


	//---------------------------------------------------------------------
	// Initial Variable Declarations                                      :
	//---------------------------------------------------------------------
	bool is_found;

	//---------------------------------------------------------------------
	// Begin Checking The Student List                                    :
	//---------------------------------------------------------------------
	// Set A Flag To Check If Students Are Found:
	is_found = false;

	if (!student_list_arr.empty()) {
		//---------------------------------------------------------------------
		// Variable Declarations                                              :
		//---------------------------------------------------------------------
		int index;
		personal_class_record* traverseNode;

		//---------------------------------------------------------------------
		// Print                                                              :
		//---------------------------------------------------------------------
		// Divider:
		cout << endl;
		cout << "------------------------------------------------------------------------------------" << endl;
		cout << "////////////////////////////////////////////////////////////////////////////////////" << endl;
		cout << "/////////////`                                                         `////////////" << endl;
		cout << "////////////   H O N O R   S T U D E N T S   WHERE ( G P A  >  3.6 )    ////////////" << endl;
		cout << "///////////																		 " << endl;
		cout << endl;


		//-------------------------------------------------------------------------
		// Begin For-Loop  - "Check Students":
		for (index = 0; index < static_cast<int>(student_list_arr.size()); index++) {


			//---------------------------------------------------------------------
			// Begin The If-Statement - "Check GPA" :
			if (student_list_arr[index]->gpa > 3.6) {

				// Change The Flag Value:
				if (is_found == false) {

					is_found = true;
				}
				cout << "==========================================" << endl;
				cout << "                                        ::" << endl;
				cout << "   S T U D E N T    I N F O             ::" << endl;
				cout << "                                        ::" << endl;
				cout << "==========================================" << endl;
				//-----------------------------------------------------------------
				// Output Students Personal Info			    		          :
				//-----------------------------------------------------------------
				cout << "   Name:    " << student_list_arr[index]->f_name << " "
					<< student_list_arr[index]->l_name << "  ";
				cout << endl;

				//-----------------------------------------------------------------
				// Output Identification Number					                  :
				//-----------------------------------------------------------------
				cout << "   ID# :    " << student_list_arr[index]->identification_num;
				cout << endl;

				//-----------------------------------------------------------------
				// Output Students GPA					                          :
				//-----------------------------------------------------------------
				cout << "   GPA :    ";

				// If No Classes have Been Taken:
				if (student_list_arr[index]->gpa == -1.00) {

					cout << "N/A";
				}
				else { // ... If Classes have Been Taken:

					cout << gpa_formatter(student_list_arr, index);
				}
				cout << endl << endl;

				//-----------------------------------------------------------------
				// Output Students Classes						                  :
				//-----------------------------------------------------------------
				cout << "=======================================" << endl;
				cout << "                                     ::" << endl;
				cout << "   C L A S S    L I S T              ::" << endl;
				cout << "                                     ::" << endl;
				cout << "=======================================" << endl;
				cout << "   Class Name  |  Credits  |  Grade   |" << endl;
				cout << "--------------- ----------- -----------" << endl;


				// Traverse Student Class Info:
				traverseNode = student_list_arr[index]->personal_class_record;
				while (traverseNode != nullptr) {

					// Output Student Class Info:
					cout << "   " << traverseNode->class_name;
					if ((traverseNode->class_name).size() <= 6) {
						cout << " ";
					}
					cout << "     |  ";
					cout << traverseNode->class_credit << "        |  "
						<< traverseNode->current_grade << "  ";
					cout << endl;

					// Move To The Next Node:
					traverseNode = (traverseNode->next);
				}
				if ((student_list_arr[index]->personal_class_record) == nullptr) {

					cout << "No Classes Available.";
					cout << endl;
				}


				// Student Info Divider:
				if (index < static_cast<int>(student_list_arr.size()) - 1) {

					cout << endl;
					cout << "////////////////////////////////////////////////";
				}
				cout << endl << endl << endl;

			}
			// End Of If-Statement  - "Check GPA" 
			//---------------------------------------------------------------------

		}
		// End For-Loop  - "Check Students"
		//-------------------------------------------------------------------------


		// If The Flag Is Still False Then ... :
		if (is_found == false) {

			// Divider:
			cout << endl << endl;

			cout << "No Students Were Found." << endl;
		}

	}
	else {
        // Divider:
        cout << endl;
		cout << "------------------------------------------------------------------------------------" << endl;
		cout << "////////////////////////////////////////////////////////////////////////////////////" << endl;
        cout << endl << endl;

        cout << "No Students Were Found. The List Is Empty." << endl;
    }

    // Output Divider:
    cout << endl;
	cout << "///////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "///////////////////////////////////////////////////////////////////////////////////////////////" << endl;
}

void student_roster_list::WarnStudent() {
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// Prints the number of students and the names of the students whose GPA is
// less than 2.5
//-----------------------------------------------------------------------------


	//---------------------------------------------------------------------
    // Initial Variable Declarations                                      :
    //---------------------------------------------------------------------
    bool is_found;

    //---------------------------------------------------------------------
    // Begin Checking The Student List                                    :
    //---------------------------------------------------------------------
    // Set A Flag To Check If Students Are Found:
    is_found = false;

	if (!student_list_arr.empty()) {
		//---------------------------------------------------------------------
		// Variable Declarations                                              :
		//---------------------------------------------------------------------
		int index;
		personal_class_record* traverseNode;

		//---------------------------------------------------------------------
		// Print                                                              :
		//---------------------------------------------------------------------
		// Divider:
		cout << endl;
		cout << "------------------------------------------------------------------------------------" << endl;
		cout << "////////////////////////////////////////////////////////////////////////////////////" << endl;
		cout << "///////////////////`                                             `//////////////////" << endl;
		cout << "//////////////////   S T U D E N T S   WHERE ( G P A  <  2.5 )    //////////////////" << endl;
		cout << "/////////////////																	 " << endl;
		cout << endl;


		//-------------------------------------------------------------------------
		// Begin For-Loop  - "Check Students":
		for (index = 0; index < static_cast<int>(student_list_arr.size()); index++) {


			//---------------------------------------------------------------------
			// Begin The If-Statement - "Check GPA" :
			if (student_list_arr[index]->gpa < 2.5) {


				// Change The Flag Value:
				if (is_found == false) {

					is_found = true;
				}

				cout << "==========================================" << endl;
				cout << "                                        ::" << endl;
				cout << "   S T U D E N T    I N F O             ::" << endl;
				cout << "                                        ::" << endl;
				cout << "==========================================" << endl;
				//-----------------------------------------------------------------
				// Output Students Personal Info			    		          :
				//-----------------------------------------------------------------
				cout << "   Name:    " << student_list_arr[index]->f_name << " "
					<< student_list_arr[index]->l_name << "  ";
				cout << endl;

				//-----------------------------------------------------------------
				// Output Identification Number					                  :
				//-----------------------------------------------------------------
				cout << "   ID# :    " << student_list_arr[index]->identification_num;
				cout << endl;

				//-----------------------------------------------------------------
				// Output Students GPA					                          :
				//-----------------------------------------------------------------
				cout << "   GPA :    ";

				// If No Classes have Been Taken:
				if (student_list_arr[index]->gpa == -1.00) {

					cout << "N/A";
				}
				else { // ... If Classes have Been Taken:

					cout << gpa_formatter(student_list_arr, index);
				}
				cout << endl << endl;

				//-----------------------------------------------------------------
				// Output Students Classes						                  :
				//-----------------------------------------------------------------
				cout << "=======================================" << endl;
				cout << "                                     ::" << endl;
				cout << "   C L A S S    L I S T              ::" << endl;
				cout << "                                     ::" << endl;
				cout << "=======================================" << endl;
				cout << "   Class Name  |  Credits  |  Grade   |" << endl;
				cout << "--------------- ----------- -----------" << endl;


				// Traverse Student Class Info:
				traverseNode = student_list_arr[index]->personal_class_record;
				while (traverseNode != nullptr) {

					// Output Student Class Info:
					cout << "   " << traverseNode->class_name;
					if ((traverseNode->class_name).size() <= 6) {
						cout << " ";
					}
					cout << "     |  ";
					cout << traverseNode->class_credit << "        |  "
						<< traverseNode->current_grade << "  ";
					cout << endl;

					// Move To The Next Node:
					traverseNode = (traverseNode->next);
				}
				if ((student_list_arr[index]->personal_class_record) == nullptr) {

					cout << "No Classes Available.";
					cout << endl;
				}


				// Student Info Divider:
				if (index < static_cast<int>(student_list_arr.size()) - 1) {

					cout << endl;
					cout << "////////////////////////////////////////////////";
				}
				cout << endl << endl << endl;

			}
			// End Of If-Statement  - "Check GPA" 
			//---------------------------------------------------------------------

		}
		// End For-Loop  - "Check Students"
		//-------------------------------------------------------------------------


		// If The Flag Is Still False Then ... :
		if (is_found == false) {

			// Divider:
			cout << endl << endl;

			cout << "No Students Were Found." << endl;
		}
	}
	else {
		// Divider:
		cout << endl;
		cout << "------------------------------------------------------------------------------------" << endl;
		cout << "////////////////////////////////////////////////////////////////////////////////////" << endl;
		cout << endl << endl;

		cout << "No Students Were Found. The List Is Empty." << endl;
	}

	// Output Divider:
	cout << endl;
	cout << "///////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "///////////////////////////////////////////////////////////////////////////////////////////////" << endl;
}

void student_roster_list::FailStudent() {
	//-----------------------------------------------------------------------------
	// Function Description                                                       :
	//-----------------------------------------------------------------------------
	// Prints the names of students whose GPA is
	// less than 2.0
	//-----------------------------------------------------------------------------


	//---------------------------------------------------------------------
	// Initial Variable Declarations                                      :
	//---------------------------------------------------------------------
	bool is_found;

	//---------------------------------------------------------------------
	// Begin Checking The Student List                                    :
	//---------------------------------------------------------------------
	// Set A Flag To Check If Students Are Found:
	is_found = false;

	if (!student_list_arr.empty()) {
		//---------------------------------------------------------------------
		// Variable Declarations                                              :
		//---------------------------------------------------------------------
		int index;
		personal_class_record* traverseNode;

		//---------------------------------------------------------------------
		// Print                                                              :
		//---------------------------------------------------------------------
		// Divider:
		cout << endl;
		cout << "------------------------------------------------------------------------------------" << endl;
		cout << "////////////////////////////////////////////////////////////////////////////////////" << endl;
		cout << "///////////////////`                                             `//////////////////" << endl;
		cout << "//////////////////   S T U D E N T S   WHERE ( G P A  <  2.0 )    //////////////////" << endl;
		cout << "/////////////////																	 " << endl;
		cout << endl;


		//-------------------------------------------------------------------------
		// Begin For-Loop  - "Check Students":
		for (index = 0; index < static_cast<int>(student_list_arr.size()); index++) {


			//---------------------------------------------------------------------
			// Begin The If-Statement - "Check GPA" :
			if (student_list_arr[index]->gpa < 2.0) {


				// Change The Flag Value:
				if (is_found == false) {

					is_found = true;
				}

				cout << "==========================================" << endl;
				cout << "                                        ::" << endl;
				cout << "   S T U D E N T    I N F O             ::" << endl;
				cout << "                                        ::" << endl;
				cout << "==========================================" << endl;
				//-----------------------------------------------------------------
				// Output Students Personal Info			    		          :
				//-----------------------------------------------------------------
				cout << "   Name:    " << student_list_arr[index]->f_name << " "
					<< student_list_arr[index]->l_name << "  ";
				cout << endl;

				//-----------------------------------------------------------------
				// Output Identification Number					                  :
				//-----------------------------------------------------------------
				cout << "   ID# :    " << student_list_arr[index]->identification_num;
				cout << endl;

				//-----------------------------------------------------------------
				// Output Students GPA					                          :
				//-----------------------------------------------------------------
				cout << "   GPA :    ";

				// If No Classes have Been Taken:
				if (student_list_arr[index]->gpa == -1.00) {

					cout << "N/A";
				}
				else { // ... If Classes have Been Taken:

					cout << gpa_formatter(student_list_arr, index);
				}
				cout << endl << endl;

				//-----------------------------------------------------------------
				// Output Students Classes						                  :
				//-----------------------------------------------------------------
				cout << "=======================================" << endl;
				cout << "                                     ::" << endl;
				cout << "   C L A S S    L I S T              ::" << endl;
				cout << "                                     ::" << endl;
				cout << "=======================================" << endl;
				cout << "   Class Name  |  Credits  |  Grade   |" << endl;
				cout << "--------------- ----------- -----------" << endl;


				// Traverse Student Class Info:
				traverseNode = student_list_arr[index]->personal_class_record;
				while (traverseNode != nullptr) {

					// Output Student Class Info:
					cout << "   " << traverseNode->class_name;
					if ((traverseNode->class_name).size() <= 6) {
						cout << " ";
					}
					cout << "     |  ";
					cout << traverseNode->class_credit << "        |  "
						<< traverseNode->current_grade << "  ";
					cout << endl;

					// Move To The Next Node:
					traverseNode = (traverseNode->next);
				}
				if ((student_list_arr[index]->personal_class_record) == nullptr) {

					cout << "No Classes Available.";
					cout << endl;
				}


				// Student Info Divider:
				if (index < static_cast<int>(student_list_arr.size()) - 1) {

					cout << endl;
					cout << "////////////////////////////////////////////////";
				}
				cout << endl << endl << endl;

			}
			// End Of If-Statement  - "Check GPA" 
			//---------------------------------------------------------------------

		}
		// End For-Loop  - "Check Students"
		//-------------------------------------------------------------------------


		// If The Flag Is Still False Then ... :
		if (is_found == false) {

			// Divider:
			cout << endl << endl;

			cout << "No Students Were Found." << endl;
		}

	}
	else {
		// Divider:
		cout << endl;
		cout << "------------------------------------------------------------------------------------" << endl;
		cout << "////////////////////////////////////////////////////////////////////////////////////" << endl;
		cout << endl << endl;

		cout << "No Students Were Found. The List Is Empty." << endl;
	}

	// Output Divider:
	cout << endl;
	cout << "///////////////////////////////////////////////////////////////////////////////////////////////" << endl;
	cout << "///////////////////////////////////////////////////////////////////////////////////////////////" << endl;
}

string student_roster_list::gpa_formatter(	vector< student_record* > &student_list_arr_container,
											int    index											)
{
//-----------------------------------------------------------------------------
// Function Description                                                       :
//-----------------------------------------------------------------------------
// This Function Takes in the Student list array with the current array index 
// and returns the formatted gpa
//-----------------------------------------------------------------------------


	//-----------------------------------------------------------------
	// Variable Declarations                                          :
	//-----------------------------------------------------------------
	float  formatted_gpa_container;
	string formatted_gpa_output;

	//-----------------------------------------------------------------
	// Input The Whole Number Part                                    :
	//-----------------------------------------------------------------
	formatted_gpa_container = static_cast<float>(static_cast<int>(student_list_arr_container[index]->gpa));

	//-----------------------------------------------------------------
	// Input The  Decimal part (two decimal places)                   :
	//-----------------------------------------------------------------
	// If All decimal places are zeros:
	if (static_cast<int>(student_list_arr_container[index]->gpa * 100 - static_cast<int>(student_list_arr_container[index]->gpa) * 100) == 0) {

		// Return The Whole Number:
		formatted_gpa_output = to_string(static_cast<int>(formatted_gpa_container)) + ".00";
		return formatted_gpa_output;
	}
	else {

		// Check if the 3rd deciaml place for rounding:
		if (static_cast<int>((((student_list_arr_container[index]->gpa) * 100 - static_cast<int>(student_list_arr_container[index]->gpa) * 100) - static_cast<int>((student_list_arr_container[index]->gpa) * 100 - static_cast<int>(student_list_arr_container[index]->gpa) * 100)) * 10) >= 5) {

			// Return the decimal number rounded up.
			// ... If ONLY 1 decimal place is zero   OR   If none of the decimal places are zero:
			formatted_gpa_output = to_string(static_cast<int>(formatted_gpa_container)) + "." + to_string((static_cast<int>((student_list_arr_container[index]->gpa) * 100 - static_cast<int>(student_list_arr_container[index]->gpa) * 100) + 1));
			return formatted_gpa_output;
		}
		else {

			// Return the decimal number without rounding up.
			// ... If ONLY 1 decimal place is zero   OR   If none of the decimal places are zero:
			formatted_gpa_output = to_string(static_cast<int>(formatted_gpa_container)) + "." + to_string(static_cast<int>((student_list_arr_container[index]->gpa) * 100 - static_cast<int>(student_list_arr_container[index]->gpa) * 100));
			return formatted_gpa_output;
		}
	}
}




////////////////////////////////////////////////////////////////////////////////////////////////////////
//-----------------------   F U N C T I O N S :  S E C T I O N   06   --------------------------------//



int  student_roster_list::Student_Count() const {
	//-----------------------------------------------------------------------------
	// Function Description                                                       :
	//-----------------------------------------------------------------------------
	// Return The Number Of Students In The DataBase.
	//-----------------------------------------------------------------------------

	return max_student_counter;
}


#endif
