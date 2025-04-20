
# Contact Management System - Enhanced

This is an enhanced version of the original Java-based Contact Management System. It features:

- Refactored to use a HashMap for contact storage (improves lookup efficiency).
- Input validation for contact fields (lengths, formatting).
- Modular design suitable for MVC architecture.
- Custom exception handling for safer operations.
- Enhanced unit tests using JUnit 5.

## How to Compile and Run

1. Make sure you have JDK 11+ and JUnit 5 available.
2. Place the `Contact` package and `Test` package in your source directory.
3. Compile using:

```bash
javac -cp .;junit-platform-console-standalone-1.8.0.jar Contact/*.java Test/*.java
```

4. Run tests:

```bash
java -jar junit-platform-console-standalone-1.8.0.jar --class-path . --scan-class-path
```

## Files Included

- `Contact.java` - The model class
- `ContactService.java` - Service class using HashMap
- `ContactServiceTest.java` - JUnit 5 tests
