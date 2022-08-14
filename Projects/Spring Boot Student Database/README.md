# Spring Boot Student Database

<p align="center">
  <img src="Spring Boot Student Layers.JPG">
</p>

## Note
Note: the code for this project is in the [Spring-Boot-Student-Database repository](https://github.com/z1chh/Spring-Boot-Student-Database).

## Student Database
Implemented a Student Database using Spring Boot (and PosgresSQL).
* Implemented with an API layer (@RestController StudentController) that communicates to a service layer (@Service StudentService class) and a data access layer (@Configuration StudentConfig class and @Repository StudentRepository class) to retrieve/store/modify information from the PostgresSQL database.
* Initiated with a few students in the database (PostgresSQL).

## StudentController
@RestController class that allows to add new students to the database, modify existing students' information and delete existing students.
This is done through a service layer (@Autowired StudentService class).

### View the Database Information
The @GetMapping method getStudents allows to communicate to the database through the service layer (StudentService class), which itself communicates with the @Repository StudentRepository class (using the findAll method).

### Adding a New Student
The @PostMapping method registerNewStudent allows the StudentController to add a new student via the student service layer (StudentService class) if there is not already a student with the same email registered.
* The @Repository StudentRepository interface provides a @Query method findStudentByEmail to help for this method

### Delete an Existing Student
The @DeleteMapping method deleteStudent allows the StudentController to delete an existing student via the student service layer (StudentService class) if there is a student with the same ID registered.

### Update Information of an Existing Student
The @PutMapping method updateStudent allows the StudentController to modify the name and/or email of an existing student via the student service layer (StudentService class) if there is a student with the same ID registered. The service layer ensures that, if a new email is provided, no students with that email addess already exist.
* The @Repository StudentRepository interface provides a @Query method findStudentByEmail to help for this method

## Student Class
<p align="center">
  <img src="Spring Boot Student Class.JPG">
</p>

The @Entity @TableStudent class represents a student with the following information:
* ID: Long that represents the unique ID of the student (@Id @SequenceGenerator). Only the first student needs to be initialized with an ID, and the other students have an auto-generated ID.
* name: String that represents the name of the student.
* email: String that represents the unique email of the student.
* dob: LocalDate that represents the date of birth of the student.
* age: Integer that represents the age of the student. The age is computed automatically and will not be found in the actual Postgres database (@Transient field).
