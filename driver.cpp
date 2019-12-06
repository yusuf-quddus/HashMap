
/*
Yusuf Quddus

psuedocode:
	create person object
	request file location from user
	open file 
	rean in file and increment counter
	close and reopen file
	read file information into variables and out them into person object
	inset person object and birthday(key) into hash map
	repeat for each person and birthday in file
	output load factor, collision and number of items loaded
	request user search a birthday
	output person with matching birthday/key
	loop until user requests to not repeat the search
*/

#include <iostream>
#include <string>
#include <fstream>
#include "Person.h"
#include "HashMap.h"
#include "HashNode.h"


using namespace std;

int main()
{
	// variables
	bool loop = 0;
	string fileLocation = "",
		fname = "",
		lname = "",
		birthday = "";
	ifstream inFile;
	ofstream outFile;
	int size = 0;
	Person Pb("", "", "birthday");

	// find and open file
	do
	{
		cout << "Enter the file location of your input file: " << endl;
		getline(cin, fileLocation);

		inFile.open(fileLocation);
		// if file can't be opened 
		if (inFile.fail()) 
		{
			loop = 1;
			cout << "Please Try Again, input file is not found" << endl;
		}
		else
			loop = 0;
	} while (loop); 

	// Count number of person will be created
	int numObjects = 0;
	while (inFile >> fname && inFile >> lname && inFile >> birthday)
	{
		string name = fname + " " + lname;
		Pb.setName(name);
		Pb.setBirthday(birthday);
		numObjects++;
	}

	inFile.close();
	inFile.open(fileLocation);

	// create hashmap with number of people found in file
	HashMap<Person, string> h((numObjects));

	// read file data into person object and insert person into hashmap
	while (inFile >> fname && inFile >> lname && inFile >> birthday)
	{
		string name = fname + " " + lname;
		Pb.setName(name);
		Pb.setBirthday(birthday);
		h.insertValue(Pb, birthday);
	}

	inFile.close();

	cout << endl << endl;

	// output info about hash table
	cout << "Number of Items loaded: " <<  h.getSize() << endl;
	cout << "Load factor: " << h.getLoadFactor() << endl;
	cout << "Load collisions: " << h.getCollisions() << endl;
	
	// h.displayTable();

	// search hash table to values
	int choice = 1;
	do {
		cout << "\n\nSearch person by entering a birthdate: ";
		cin >> birthday;
		cout << endl;
		h.displayData(birthday);
		cout << endl << endl;
		cout << "If you would like to output another value, type the number 1, type any other number to quite: ";
		cin >> choice;
	} while (choice == 1);

	system("pause");
	return 0;
}
