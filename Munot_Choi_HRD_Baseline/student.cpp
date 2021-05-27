#include "student.h"
#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
using namespace std;

bool isBlank(string blank) { // method that checks if the string inputed is blank
	if (blank == " " || blank == "") {
		return true;
	}
	else {
		return false;
	}
}
bool getValidCourses(string course) { // method that checks if the number is between 1 and 8
	/*
	if (course >= 1 && course <= 8) {
		return true;
	}
	else {
		return false;
	}
	*/
	bool isValid = true;
	regex int_regex("[1-8]{1}");
	if (regex_match(course, int_regex)) {
		isValid = true;
	}
	else {
		isValid = false;
	}
	return isValid;
}
bool getValidInt(string number) { // method that checks if the number is an integer between 0 and 120
	regex int_regex("[0-9]{1,3}");
	if (regex_match(number, int_regex)) {
		if (stoi(number) <= 120) {

			return 	true;
		}
		else {
			cout << "Invalid Input\n";
			return false;
		}

	}
	else {
		cout << "Invalid Input\n";
		return false;
	}
}
bool disiplineIssue() { // return a true or faslse depending on random disciplinary infraction
	int randomNumber;
	srand((unsigned)time(NULL));
	randomNumber = (rand() % 100) + 1;
	bool hasDisciplineIssue = ((randomNumber <= 5)) ? true : false;
	return hasDisciplineIssue;
}
void formattable(vector<int> grade, vector<std::string> course, string name) { // formats vectors and string into a table.
	const char separator = ' ';
	const int nameWidth = 25;
	const int numWidth = 8;

	cout << name << "\n\n";

	cout << left << setw(nameWidth) << setfill(separator) << "Class ";
	cout << left << setw(nameWidth) << setfill(separator) << "Grade";
	cout << endl;

	for (int i = 0; i < grade.size(); i++) {
		cout << left << setw(nameWidth) << setfill(separator) << course.at(i);
		cout << left << setw(numWidth) << setfill(separator) << grade.at(i);
		cout << endl;
	}
}

