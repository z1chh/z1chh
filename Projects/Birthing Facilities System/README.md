# Birthing Facilities System

## Note
Note: the code for this project is in the [Birthing-Facilities-System](https://github.com/z1chh/Birthing-Facilities-System).

## Relational Model
<p align="center">
  <img src="Screenshots/Midwife ER.jpg">
</p>

## Project Overview
I first carefully designed a relational model, as shown above, to represent the entities, their attributes, and the relations between entity sets.

I then modelled the relational translation with its pending constraints (constraints that cannot be enforced within the relational translation).

The next step was to implement the database by creating tables and populating them with some values.

Finally, I developed a simple console-based application program with a simple and friendly user-interface for midwives to use. This JDBC program allows midwives to interact with the system via a menu to perform some actions, such as managing notes for their clients or viewing their appointments.

The [Tables](https://github.com/z1chh/Birthing-Facilities-System/tree/main/Tables) folder contains .sh files that can be used to run the provided sql files to create tables, load data, and drop tables. Note that you must run createtbl.sh and loaddata.sh in order to populate the database if you wish to reproduce the same results on your own DB2.


## Relational Translation
* Mother(qchcardid, name, phone_number, email, profession, dob, address, estimated_birth_date, blood_type)
* Baby(bid, qchcardid, dob, birth_time, name, gender, blood_type), qchcardid references mother
* Father(name, phone_number, profession, dob, qchcardid, email, address, blood_type)
* Couple(cid, qchcardid, phone_number), qchcardid references mother, phone_number references father
* Health_institution(email, name, address, phone_number)
*	Community_clinic(email), email references health_institution
*	Birthing_center(email), email references health_institution
*	Midwife(pid, name, email, phone_number, hi_email), hi_email references health_institution
*	Pregnancy(pid, cid, first_m, second_m, location, pregnancy_number, expected_birth_date, birthed, final_date_set, interested, babies), cid references couple, first_m references midwife, second_m references midwife
*	Technician(tid, name, phone_number)
*	Test(tid, techid, qchcardid, bid, pid, type, results, sample_date, lab_date, prescription_date), techid references technician, qchcardid references mother, bid references baby, pid references pregnancy
*	Appointment(aid, pid, date, time), pid references pregnancy
*	Birth_test_appointment(aid, expected_birth_date), aid references appointment
*	Note(aid, date, time, observations), aid references appointment
*	Online_information_session(sid, host, date, time, language), host references midwife
*	Registration(sid, cid), sid references online_information_session, cid references couple
*	Attendance(sid, cid), sid references online_information_session, cid references couple

## Application Interaction Examples
### Mother M1
<p>
  No midwife has the practitioner ID 0 (starts at 1) (database query):
  <img src="Screenshots/pid 0.JPG">
  
  No midwife with practioner ID 0 (application interaction):
  <img src="Screenshots/pid 0 - app.JPG">
  
  Pregnancies of mother M1 (database query):
  <img src="Screenshots/m1 pregnancies.JPG">
  
  Midwife with ID 2 views information on M1 (application interaction):
  <img src="Screenshots/pid 2 with m1.JPG">
</p>

### Creating a New Test Prescription
<p>
  Tests associated with M2 (database query):
  <img src="Screenshots/m2 tests.JPG">
  
  Appointment with M2 (from midwife with ID 2) (application interaction):
  <img src="Screenshots/appointment with m2.JPG">
  
  Pregnancy notes of mother M2 (application interaction):
  <img src="Screenshots/pregnancy notes.JPG">
  
  New test prescription for M2 (application interaction):
  <img src="Screenshots/new test.JPG">
  
  Tests associated with M2 (database query):
  <img src="Screenshots/m2 tests updated.JPG">
</p>

## Other
### Indexing
<p>
  Index to retrieve the mother's address given the phone number only:
  
  Note that I stated previously (in the pending constraints section) that a phone number should be unique not only with a table, but across the whole tables. Therefore, it is valid to create a unique index on a phone number.
  
  <img src="Screenshots/indexing example.JPG">
</p>

### Data Analytics
<p>
  Query to produce the number of births for each month (only babies born):
  
  <img src="Screenshots/births per month.JPG">
  
  Chart:
  
  <img src="Screenshots/births per month - chart.JPG">
</p>

## Additional Notes
The GoBabbyApp.java file imports other java files from a getters package (the other .java files are in the getters folder). Without this, the code will not compile and run.
