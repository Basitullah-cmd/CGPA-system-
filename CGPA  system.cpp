#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

// Function prototypes
void add();     // Add a new student record
void del();     // Delete a student record
void modify();  // Modify a student record
void check();   // Check grades of a student by roll number
void gpa();     // Generate a GPA result file
void data();    // Display student records in the console

int num = 100; // Maximum number of student records
// Main function
int main() {
    char choice;
    do {
        int option;
        // Display the menu for user interaction
        cout << endl << "Choose one of the following options!" << endl;
        cout << "Press 1 to enter details of a new student!" << endl;
        cout << "Press 2 to delete student detail!" << endl;
        cout << "Press 3 to modify student detail!" << endl;
        cout << "Press 4 to check student grade!" << endl;
        cout << "Press 5 to create result file!" << endl;
        cout << "Press 6 to display data in console!" << endl;
        cout << "Press 0 to terminate program!" << endl;
        cin >> option;

        // Execute the appropriate function based on user input
        switch (option) {
            case 0:
                return 0;  // Exit the program
            case 1:
                add();
                break;
            case 2:
                del();
                break;
            case 3:
                modify();
                break;
            case 4:
                check();
                break;
            case 5:
                gpa();
                break;
            case 6:
                data();
                break;
            default:
                cout << "Invalid Input!";
                break;
        }
        // Ask user if they want to repeat the process
        cout << "\nDo You want to repeat steps again? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y'); // Continue until user chooses to exit
}

// Function to add a new student record
void add() {
    num++;  // Increment the student count
    fstream fout;
    fout.open("Sample.csv", ios::app); // Open file in append mode
    if (!fout) { // Check if the file opens successfully
        cout << "Error: Unable to open file." << endl;
        return;
    }
    
     // Variables to store student details
    string student_name, roll, oop, dld, la, pst, edc, oop_lab, edc_lab, dld_lab;
    

    // Input student details
    cout << "Enter Name: ";
    cin.ignore();  // Clear the input buffer
    getline(cin, student_name);
    cout << "Enter Roll Number: ";
    cin >> roll;
    cout << "Enter Grade in OOP: ";
    cin >> oop;
    cout << "Enter Grade in DLD: ";
    cin >> dld;
    cout << "Enter Grade in LA: ";
    cin >> la;
    cout << "Enter Grade in PST: ";
    cin >> pst;
    cout << "Enter Grade in EDC: ";
    cin >> edc;
    cout << "Enter Grade in OOP Lab: ";
    cin >> oop_lab;
    cout << "Enter Grade in EDC Lab: ";
    cin >> edc_lab;
    cout << "Enter Grade in DLD Lab: ";
    cin >> dld_lab;

    // Write data to file
    fout << student_name << "," << roll << "," << oop << "," << dld << "," << la;
    fout << "," << pst << "," << edc << "," << oop_lab << "," << edc_lab << "," << dld_lab << "\n";

    fout.close(); // Close the file
    cout << "Student details added successfully!" << endl;
}

// Function to delete a student record by roll number
void del() {
    fstream fout;
    fstream fin;
    fout.open("Sample.csv", ios::in); // Open file in read mode
    
     // Open the original file for reading
    fin.open("Sample.csv", ios::in);
    if (!fin) { // Check if the file opens successfully
        cout << "Error: Unable to open file." << endl;
        return;
    }
    // Temporary variables to store data
    string line, student_name[num], temp1, temp2, roll[num];
    string oop[num], dld[num], la[num], pst[num], edc[num], oop_lab[num], edc_lab[num], dld_lab[num];
    getline(fout, temp1); // Header line
    getline(fout, temp2); // Data header

    int i = 0;
    bool found = false; // Flag to check if record exists
    string check;

    // Read records into arrays
    while (getline(fout, line)) {
        istringstream sout(line);
        getline(sout, student_name[i], ',');
        getline(sout, roll[i], ',');
        getline(sout, oop[i], ',');
        getline(sout, dld[i], ',');
        getline(sout, la[i], ',');
        getline(sout, pst[i], ',');
        getline(sout, edc[i], ',');
        getline(sout, oop_lab[i], ',');
        getline(sout, edc_lab[i], ',');
        getline(sout, dld_lab[i], ',');
        i++;
    }
    fout.close();
	// Ask the user for the roll number to delete
    cout << "Enter Roll No to Delete: ";
    cin >> check;

    fstream fout1;
    fout1.open("Sample.csv", ios::out); // Open file in write mode
    fout1 << temp1 << endl;             // Write header
    fout1 << temp2 << endl;             // Write data header

    // Rewrite all records except the one to delete
    for (int j = 0; j < i; j++) {
        if (check == roll[j]) {
            num--;
            found = true; // Mark record as found
        } else {
            fout1 << student_name[j] << "," << roll[j] << "," << oop[j] << "," << dld[j] << "," << la[j];
            fout1 << "," << pst[j] << "," << edc[j] << "," << oop_lab[j] << "," << edc_lab[j] << "," << dld_lab[j] << "\n";
        }
    }
    fout1.close();
	 // Provide feedback to the user
    if (!found) {
        cout << "ROLL NO NOT FOUND!";
    } else {
        cout << "ROLL NO SUCCESSFULLY DELETED!";
    }
}

// Function to modify an existing student record
void modify() {
    // File reading logic and user input for modification...
    // Similar structure to the delete function, but prompts for and saves new data
    ifstream fin("Sample.csv");
    if (!fin) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    string line, header;
    string student_name[num], roll[num], oop[num], dld[num], la[num], pst[num], edc[num], oop_lab[num], edc_lab[num], dld_lab[num];
    int record_count = 0;

    // Read the header line
    getline(fin, header);

    // Read the data into arrays
    while (getline(fin, line) && record_count < num) {
        istringstream iss(line);

        getline(iss, student_name[record_count], ',');
        getline(iss, roll[record_count], ',');
        getline(iss, oop[record_count], ',');
        getline(iss, dld[record_count], ',');
        getline(iss, la[record_count], ',');
        getline(iss, pst[record_count], ',');
        getline(iss, edc[record_count], ',');
        getline(iss, oop_lab[record_count], ',');
        getline(iss, edc_lab[record_count], ',');
        getline(iss, dld_lab[record_count], ',');

        record_count++;
    }
    fin.close();

    // Ask for roll number to modify
    string roll_to_edit;
    cout << "Enter Roll Number to edit: ";
    cin >> roll_to_edit;

    // Find and modify the record
    bool found = false;
    for (int i = 0; i < record_count; ++i) {
        if (roll[i] == roll_to_edit) {
            found = true;

            cout << "Enter New Details:" << endl;
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, student_name[i]);
            cout << "Enter Roll Number: ";
            cin >> roll[i];
            cout << "Enter Grade in OOP: ";
            cin >> oop[i];
            cout << "Enter Grade in DLD: ";
            cin >> dld[i];
            cout << "Enter Grade in LA: ";
            cin >> la[i];
            cout << "Enter Grade in PST: ";
            cin >> pst[i];
            cout << "Enter Grade in EDC: ";
            cin >> edc[i];
            cout << "Enter Grade in OOP Lab: ";
            cin >> oop_lab[i];
            cout << "Enter Grade in EDC Lab: ";
            cin >> edc_lab[i];
            cout << "Enter Grade in DLD Lab: ";
            cin >> dld_lab[i];
            break;
        }
    }

    if (!found) {
        cout << "ROLL NUMBER NOT FOUND!" << endl;
        return;
    }

    // Write updated data back to the file
    ofstream fout("Sample.csv");
    if (!fout) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }

    fout << header << endl;
    for (int i = 0; i < record_count; ++i) {
        fout << student_name[i] << "," << roll[i] << "," << oop[i] << "," << dld[i] << "," << la[i]
             << "," << pst[i] << "," << edc[i] << "," << oop_lab[i] << "," << edc_lab[i] << "," << dld_lab[i] << "\n";
    }
    fout.close();

    cout << "Student record modified successfully!" << endl;
}

// Function to check a student's grades by roll number
void check() {
    // File reading logic and display specific student grades
    fstream fout;
    		fout.open("Sample.csv",ios::in);	// Open the CSV file for reading
    		// Declare variables and arrays to store student data
    		string line,student_name[num],temp1,temp2,oop[num],dld[num],la[num],pst[num],edc[num],oop_lab[num],edc_lab[num],dld_lab[num],roll[num];
    		string roll1; // To store the roll number entered by the user
    		// Read and discard the first two lines of the file (possibly headers)
    		getline(fout,temp1);
    		getline(fout,temp2);
    		int i=0;  // Index for storing data in arrays
    		bool oo=0;  // Flag to check if the roll number is found
			string check;
			// Loop to read data from each line in the CSV file
    		while (getline(fout,line))
    		{
    			istringstream sout(line); // Create a stringstream object to split the line by commas
    			// Extract student data from the line and store it in respective arrays
    			getline(sout,student_name[i],',');
   				getline(sout,roll[i],',');
				getline(sout,oop[i],','); 	
				getline(sout,dld[i],',');
				getline(sout,la[i],',');
				getline(sout,pst[i],',');
				getline(sout,edc[i],',');
				getline(sout,oop_lab[i],',');
				getline(sout,edc_lab[i],',');
				getline(sout,dld_lab[i],',');
							
    			i++;  // Move to the next index for the next student's data
			}
			fout.close();   // Close the file after reading all data
			// Prompt the user to enter a roll number to search for
			cout<<"Enter Roll No to find: ";
			cin>>roll1;
			// Loop through the data to find the student with the entered roll number
			for (int i=0;i<num;i++)  
			{
				if(roll1==roll[i])  // If the roll number matches
				{
					oo=1;  // Set the flag to indicate the student is found
				 // Display the student's information
				cout<<"Name: "<<student_name[i]<<endl;
    			cout<<"Roll Number: "<<roll[i]<<endl;
    			cout<<"Grade in OOP: "<<oop[i]<<endl;
    			cout<<"Grade in dld: "<<dld[i]<<endl;
    			cout<<"Grade in la: "<<la[i]<<endl;
    			cout<<"Grade in Pst: "<<pst[i]<<endl;
    			cout<<"Grade in edc: "<<edc[i]<<endl;
    			cout<<"Grade in OOP_lab: "<<oop_lab[i]<<endl;
    			cout<<"Grade in edc_lab: "<<edc_lab[i]<<endl;
    			cout<<"Grade in dld_lab: "<<dld_lab[i]<<endl;
				break;	// Exit the loop after finding the student
				}
			}
// If the roll number is not found, display an error message
if (oo==0) 
{
cout<<"ROLL NO NOT FOUND!";
}
}

// Function to generate a GPA result file
void gpa() {
    // GPA calculation logic and file generation
    fstream fin, fout;
    fin.open("Sample.csv", ios::in);
    fout.open("Result.csv", ios::out);

    if (!fin || !fout) {
        cerr << "Error opening file!" << endl;
        return;
    }
   // Write the header and credit hours only once
    fout << "Student Name,Roll Number,OOP,DLD,LA,PST,EDC,OOP Lab,EDC Lab,DLD Lab,GPA\n";
    fout << "CH.Hr, ,3,3,3,2,3,1,1,1\n";
    
    
    string line, student_name, roll, oop, dld, la, pst, edc, oop_lab, edc_lab, dld_lab;
    int oop_ch = 3, dld_ch = 3, la_ch = 3, pst_ch = 2, edc_ch = 3, oopl_ch = 1, edcl_ch = 1, dldl_ch = 1;
    int total_ch = oop_ch + dld_ch + la_ch + pst_ch + edc_ch + oopl_ch + edcl_ch + dldl_ch;

    getline(fin, line); // Skip header in Sample.csv
    while (getline(fin, line)) {
        istringstream iss(line);
        getline(iss, student_name, ',');
        getline(iss, roll, ',');
        getline(iss, oop, ',');
        getline(iss, dld, ',');
        getline(iss, la, ',');
        getline(iss, pst, ',');
        getline(iss, edc, ',');
        getline(iss, oop_lab, ',');
        getline(iss, edc_lab, ',');
        getline(iss, dld_lab, ',');

        // GPA calculation for each course
        float oop_gpa = (oop == "A") ? 4 : (oop == "B") ? 3.5 : (oop == "C") ? 2.67 : (oop == "D") ? 2 : (oop == "E") ? 1.67 : 0;
        float dld_gpa = (dld == "A") ? 4 : (dld == "B") ? 3.5 : (dld == "C") ? 2.67 : (dld == "D") ? 2 : (dld == "E") ? 1.67 : 0;
        float la_gpa = (la == "A") ? 4 : (la == "B") ? 3.5 : (la == "C") ? 2.67 : (la == "D") ? 2 : (la == "E") ? 1.67 : 0;
        float pst_gpa = (pst == "A") ? 4 : (pst == "B") ? 3.5 : (pst == "C") ? 2.67 : (pst == "D") ? 2 : (pst == "E") ? 1.67 : 0;
        float edc_gpa = (edc == "A") ? 4 : (edc == "B") ? 3.5 : (edc == "C") ? 2.67 : (edc == "D") ? 2 : (edc == "E") ? 1.67 : 0;
        float oopl_gpa = (oop_lab == "A") ? 4 : (oop_lab == "B") ? 3.5 : (oop_lab == "C") ? 2.67 : (oop_lab == "D") ? 2 : (oop_lab == "E") ? 1.67 : 0;
        float edcl_gpa = (edc_lab == "A") ? 4 : (edc_lab == "B") ? 3.5 : (edc_lab == "C") ? 2.67 : (edc_lab == "D") ? 2 : (edc_lab == "E") ? 1.67 : 0;
        float dldl_gpa = (dld_lab == "A") ? 4 : (dld_lab == "B") ? 3.5 : (dld_lab == "C") ? 2.67 : (dld_lab == "D") ? 2 : (dld_lab == "E") ? 1.67 : 0;

        // Calculate total GPA
        float total_gpa = (oop_gpa * oop_ch + dld_gpa * dld_ch + la_gpa * la_ch +
                           pst_gpa * pst_ch + edc_gpa * edc_ch +
                           oopl_gpa * oopl_ch + edcl_gpa * edcl_ch + dldl_gpa * dldl_ch) / total_ch;

        // Write to Result.csv
        fout << student_name << "," << roll << "," << oop << "," << dld << "," << la << ","
             << pst << "," << edc << "," << oop_lab << "," << edc_lab << "," << dld_lab << ","
             << fixed << setprecision(2) << total_gpa << "\n";
    }

    cout << "Result file generated successfully!" << endl;

    fin.close();
    fout.close();
}

// Function to display student data in the console
void data() {
    // Reads Result.csv and displays it neatly in the console
    	fstream fout;
    		fout.open("Result.csv",ios::in);
    		string line,student_name[num],temp1,temp2,oop[num],dld[num],la[num],pst[num],edc[num],oop_lab[num],edc_lab[num],dld_lab[num],roll[num],gpa[num];
    		// Read and discard the first two lines (possibly header)
    		getline(fout,temp1);
    		getline(fout,temp2);
    		int i=0;  // Initialize the index for reading student data
			string check;
			// Loop to read the data from each line in the CSV file
    		while (getline(fout,line))
    		{
    			istringstream sout(line);  // Create a stringstream to split the line by commas
    			// Read individual columns into respective arrays
    			getline(sout,student_name[i],',');  //students name
				getline(sout,roll[i],','); 	//students roll no
				getline(sout,oop[i],','); 	//grade in OOP
				getline(sout,dld[i],',');  //grade in DLD
				getline(sout,la[i],',');   //grade in LA
				getline(sout,pst[i],',');	 //grade in PST
				getline(sout,edc[i],',');	 //grade in EDC
				getline(sout,oop_lab[i],',');	 //grade in OOP LAB
				getline(sout,edc_lab[i],',');	 //grade in EDC LAB
				getline(sout,dld_lab[i],',');	 //grade in DLD LAB
				getline(sout,gpa[i],',');		 //GPA
    			i++; // Increment the index for the next student
			}
			// Display the header for the table in the console with neat formatting using setw
cout << setw(20) << "Student Name" << setw(10) << "Roll No" << setw(10) << "OOP" << setw(10) << "DLD"
         << setw(10) << "LA" << setw(10) << "PST" << setw(10) << "EDC" << setw(10) << "OOP LAB"
         << setw(10) << "EDC LAB" << setw(10) << "DLD LAB" << setw(10) << "GPA" << endl;
// Loop to display the student data in a neat table format
    for (int i = 0; i < num; i++)
    {
    	 // Print each student's information with formatting using setw for proper alignment
        cout << setw(20) << student_name[i] << setw(10) << roll[i] << setw(10) << oop[i] << setw(10) << dld[i]
             << setw(10) << la[i] << setw(10) << pst[i] << setw(10) << edc[i] << setw(10) << oop_lab[i]
             << setw(10) << edc_lab[i] << setw(10) << dld_lab[i]<< setw(10) << gpa[i] << "\n";
    }
}

