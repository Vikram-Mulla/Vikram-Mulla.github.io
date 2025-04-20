#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Course {
public:
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;

    Course(string number, string title, vector<string> prereqs) {
        courseNumber = number;
        courseTitle = title;
        prerequisites = prereqs;
    }
};

vector<Course> courseData;

// Function to load data from the file into the vector
void loadVector(string fileName) {
    ifstream file(fileName);
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            stringstream ss(line);
            string courseNumber, courseTitle, prereq;

            getline(ss, courseNumber, ',');
            getline(ss, courseTitle, ',');

            vector<string> prereqs;
            while (getline(ss, prereq, ',')) {
                prereqs.push_back(prereq);
            }

            Course newCourse(courseNumber, courseTitle, prereqs);
            courseData.push_back(newCourse);
        }

        cout << "Successfully loaded course data." << endl;
    }
    else {
        cout << "File not found! Try again!";
    }
}

// Function to print an alphanumeric list of all the courses
void printCourseList() {
    sort(courseData.begin(), courseData.end(), [](const Course& a, const Course& b) {   // using sorting algorithm  //
        return a.courseNumber < b.courseNumber;
        });

    cout << "Here is a sample schedule:\n\n" << endl;
    for (const Course& course : courseData) {
        cout << course.courseNumber << ": " << course.courseTitle << endl;
    }
}

// Function to print course information based on the course number
void printCourseInfo(string courseNumber) {
    auto it = find_if(courseData.begin(), courseData.end(), [&](const Course& course) {
        return course.courseNumber == courseNumber;
        });

    if (it != courseData.end()) {
        cout << "Course Information for " << courseNumber << ":" << endl;
        cout << "Title: " << it->courseTitle << endl;
        cout << "Prerequisites: ";

        if (it->prerequisites.empty()) {
            cout << "None";
        }
        else {
            for (const string& prereq : it->prerequisites) {
                cout << prereq << " ";
            }
        }

        cout << endl;
    }
    else {
        cout << "Course not found." << endl;
    }
}

int main() {
    cout << "Welcome to the course planner." << endl;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Load Data Structure.\n";
        cout << "2. Print Course List.\n";
        cout << "3. Print Course.\n";
        cout << "9. Exit\n";
        cout << "What would you like to do?";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Enter the file name containing the course data: ";
            string fileName;
            cin >> fileName;
            loadVector(fileName);
            break;
        }
        case 2: {
            printCourseList();
            break;
        }
        case 3: {
            cout << "Enter the course ID with correct capitalization: ";
            string courseNumber;
            cin >> courseNumber;
            printCourseInfo(courseNumber);
            break;
        }
        case 9: {
            cout << "Thank you for using the course planner! Exiting program!" << endl;
            return 0;
        }
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}