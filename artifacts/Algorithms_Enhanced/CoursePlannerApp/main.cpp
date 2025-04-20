#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Course {
public:
    string courseNumber;
    string courseTitle;
    vector<string> prerequisites;

    Course() = default;
    Course(string number, string title, vector<string> prereqs)
        : courseNumber(number), courseTitle(title), prerequisites(prereqs) {}
};

vector<Course> courseList;
unordered_map<string, Course> courseMap;

void merge(vector<Course>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<Course> L(n1), R(n2);

    for (int i = 0; i < n1; ++i) L[i] = arr[l + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].courseNumber <= R[j].courseNumber) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(vector<Course>& arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void loadCourses(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cout << "Error: Could not open file." << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string number, title, prereq;
        getline(ss, number, ',');
        getline(ss, title, ',');

        vector<string> prereqs;
        while (getline(ss, prereq, ',')) {
            prereqs.push_back(prereq);
        }

        Course c(number, title, prereqs);
        courseList.push_back(c);
        courseMap[number] = c;
    }

    cout << "Courses loaded successfully!" << endl;
}

void printCourseList() {
    mergeSort(courseList, 0, courseList.size() - 1);
    for (const auto& c : courseList) {
        cout << c.courseNumber << ": " << c.courseTitle << endl;
    }
}

void printCourseInfo(const string& courseNumber) {
    auto it = courseMap.find(courseNumber);
    if (it != courseMap.end()) {
        cout << "Course: " << it->second.courseNumber << endl;
        cout << "Title: " << it->second.courseTitle << endl;
        cout << "Prerequisites: ";
        if (it->second.prerequisites.empty()) {
            cout << "None";
        } else {
            for (const auto& p : it->second.prerequisites) {
                cout << p << " ";
            }
        }
        cout << endl;
    } else {
        cout << "Course not found." << endl;
    }
}

int main() {
    string filename;
    cout << "Enter course data filename (e.g., courses.csv): ";
    cin >> filename;
    loadCourses(filename);

    int choice;
    do {
        cout << "\nMenu:\n1. Print Course List\n2. Print Course\n9. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                printCourseList();
                break;
            case 2: {
                string courseID;
                cout << "Enter course ID: ";
                cin >> courseID;
                printCourseInfo(courseID);
                break;
            }
            case 9:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != 9);

    return 0;
}
