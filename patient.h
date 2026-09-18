#ifndef PATIENT_H
#define PATIENT_H

#define MAX_PATIENTS 100

extern char patientName[MAX_PATIENTS][100];
extern int patientAge[MAX_PATIENTS];
extern int patientUrgency[MAX_PATIENTS];
extern int patientSpecialty[MAX_PATIENTS];
extern int patientAdmitted[MAX_PATIENTS];
extern int patientWard[MAX_PATIENTS];
extern int patientBed[MAX_PATIENTS];
extern int patientDays[MAX_PATIENTS];
extern int patientCount;

void registerPatient(void);
void displayPatients(void);

#endif
