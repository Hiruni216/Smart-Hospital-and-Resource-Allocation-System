🏥 Smart Hospital \& Resource Allocation System



A modular C-based hospital management system designed to manage patients, medical specialties, hospital wards, bed allocation, billing, priority handling, reporting, and basic file persistence.



🎯 Project Overview



The system provides a menu-driven solution for managing hospital resources and patient information. It demonstrates fundamental C programming concepts including arrays, structures of data, functions, loops, conditionals, file handling, sorting, and modular programming.



✨ Key Features



\- 👨‍⚕️ Specialty Management – View consultation fees, treatment times, and daily capacities.

\- 🏥 Ward Management – View ward rates and available capacities.

\- 🛏️ Automatic Bed Allocation – Assigns the first available bed to admitted patients.

\- 👤 Patient Registration – Stores patient details, urgency, specialty, admission status, and ward information.

\- 💰 Dynamic Billing – Calculates consultation fees, urgency surcharges, ward costs, discounts, and final payments.

\- ⏱️ Waiting-Time Calculation – Estimates waiting time based on the specialty queue.

\- 🚨 Priority Management – Sorts patients according to urgency while preserving registration order.

\- 📊 Performance Reports – Generates patient statistics, revenue, discounts, and bed occupancy information.

\- 💾 File Persistence – Saves bed occupancy and patient billing records to text files.



🏗️ System Architecture



Smart Hospital System

│

├── main.c

├── hospital\_data.c / hospital\_data.h

├── patient.c / patient.h

├── billing.c / billing.h

├── priority.c / priority.h

├── report.c / report.h

├── file\_handler.c / file\_handler.h

│

├── beds\_status.txt

└── patient\_records.txt



The project follows a modular architecture, where each major responsibility is separated into its own source and header files.



🧮 Core Calculations



The system implements:



\- Waiting Time = Queue Count × Average Consultation Time

\- Surcharge based on urgency level

\- Ward Cost = Daily Rate × Number of Days

\- Gross Total = Consultation Fee + Surcharge + Ward Cost

\- Eligible patients receive a 15% age-based discount

\- Final Amount = Gross Total − Discount



🛠️ Technologies Used



\- Language: C

\- IDE: Code::Blocks

\- Version Control: Git \& GitHub

\- Data Storage: Text Files

\- Programming Concepts: Modular Programming, Arrays, Functions, Sorting, File Handling



📋 Main Menu



1\.  Display Doctor Specialties

2\.  Display Ward Information

3\.  Display Bed Occupancy

4\.  Register Patient

5\.  Display All Patients

6\.  Display Patient Bill

7\.  Display Patients by Priority

8\.  Generate Performance Report

9\.  Save Bed Status

10\. Load Bed Status

0\.  Exit



👨‍💻 Project Information



Student: H.D.GALBADAARACHCHI

Index: AS20250457

Course: CSC 1012 – Introduction to Computer Programming



GitHub Repository:

https://github.com/Hiruni216/Smart-Hospital-and-Resource-Allocation-System.git



📌 Assumptions



\- Maximum patient capacity is 100.

\- Bed capacity is defined for each ward.

\- Bed allocation uses the first available bed.

\- Patients without admission are treated as outpatients.

\- Patient records are maintained using parallel arrays.

\- File-based data is stored as plain text.

