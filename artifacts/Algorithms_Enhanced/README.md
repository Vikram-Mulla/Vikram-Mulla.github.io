# Course Planner System (Enhanced)

This project is a C++ console application that loads and displays course information from a CSV file. It features enhancements such as:
- Efficient sorting using Merge Sort
- Fast course lookup using `unordered_map`
- Modular structure for maintainability

## 📁 Project Structure

```
CoursePlannerApp/
├── main.cpp             # Main application logic
├── courses.csv          # Sample input file with course data
└── CoursePlannerApp.vcxproj  # Visual Studio 2022 project file
```

## 🧰 Requirements

- Microsoft Visual Studio 2022 (with Desktop development with C++ workload)

## 🚀 How to Run the Project in Visual Studio 2022

1. **Extract the ZIP**  
   Unzip the `CoursePlannerApp_VisualStudio.zip` file to a folder.

2. **Open Visual Studio 2022**  
   Launch Visual Studio.

3. **Open the Project**  
   Go to **File → Open → Project/Solution**, then select `CoursePlannerApp.vcxproj` from the extracted folder.

4. **Set as Startup Project**  
   In the **Solution Explorer**, right-click the project name and select **Set as Startup Project**.

5. **Build the Project**  
   Press `Ctrl + Shift + B` or click **Build → Build Solution**.

6. **Run the Program**  
   Press `Ctrl + F5` (Start Without Debugging).

7. **When prompted**, enter:
   ```
   courses.csv
   ```

## 📄 Input Format (CSV)

The input file `courses.csv` should have lines formatted as:
```
CourseID,Course Title,Prereq1,Prereq2,...
```

Example:
```
CS101,Intro to Programming,
CS102,Data Structures,CS101
CS103,Algorithms,CS102
```

## ✅ Features

- Displays all courses sorted alphanumerically by course number.
- Allows user to look up a specific course and view its title and prerequisites.
- CSV file is automatically copied to the output directory at build time.

---

© 2025 - Developed for CS-499 Final Project Enhancement
