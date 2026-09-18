#include <stdio.h>
#include "patient.h"
#include "hospital_data.h"

extern int specialtyQueue[4];

char patientName[MAX_PATIENTS][100];
int patientAge[MAX_PATIENTS];
int patientUrgency[MAX_PATIENTS];
int patientSpecialty[MAX_PATIENTS];
int patientAdmitted[MAX_PATIENTS];
int patientWard[MAX_PATIENTS];
int patientBed[MAX_PATIENTS];
int patientDays[MAX_PATIENTS];

int patientCount = 0;



int allocateBed(int wardID)
{
    int bed;

    for (bed = 0; bed < MAX_BEDS; bed++)
    {
        if (bedOccupancy[wardID - 1][bed] == 0)
        {
            bedOccupancy[wardID - 1][bed] = 1;
            return bed + 1;
        }
    }

    return 0;
}


void registerPatient(void)
{
    if (patientCount >= MAX_PATIENTS)
    {
        printf("\nPatient limit reached.\n");
        return;
    }

    printf("\n================ PATIENT REGISTRATION ================\n");

    printf("Enter patient name: ");
    scanf(" %[^\n]", patientName[patientCount]);

    printf("Enter patient age: ");
    scanf("%d", &patientAge[patientCount]);

    printf("\nTriage Level:\n");
    printf("1. Normal\n");
    printf("2. Urgent\n");
    printf("3. Critical\n");
    printf("Enter triage level: ");
    scanf("%d", &patientUrgency[patientCount]);

    printf("\nDoctor Specialties:\n");
    printf("1. General Practice\n");
    printf("2. Paediatrics\n");
    printf("3. Cardiology\n");
    printf("4. Neurology\n");
    printf("Enter specialty ID: ");
    scanf("%d", &patientSpecialty[patientCount]);

    specialtyQueue[patientSpecialty[patientCount] - 1]++;

    printf("\nAdmission Status:\n");
    printf("1. Admitted\n");
    printf("0. Not Admitted\n");
    printf("Enter admission status: ");
    scanf("%d", &patientAdmitted[patientCount]);

    patientWard[patientCount] = 0;
    patientBed[patientCount] = 0;
    patientDays[patientCount] = 0;

    if (patientAdmitted[patientCount] == 1)
    {
        printf("\nWard Information:\n");
        printf("1. General Ward\n");
        printf("2. Paediatric Ward\n");
        printf("3. Surgical Ward\n");
        printf("4. ICU\n");

        printf("Enter ward ID: ");
        scanf("%d", &patientWard[patientCount]);


        patientBed[patientCount] = allocateBed(patientWard[patientCount]);

        if (patientBed[patientCount] == 0)
        {
            printf("\nThe selected ward is FULL.\n");
            printf("Patient could not be assigned a bed.\n");

            patientWard[patientCount] = 0;
            patientAdmitted[patientCount] = 0;
            patientDays[patientCount] = 0;
        }
        else
        {
            printf("Enter number of days: ");
            scanf("%d", &patientDays[patientCount]);

            printf("\nBed allocated successfully.\n");
            printf("Assigned Bed: Bed #%02d\n", patientBed[patientCount]);
        }
    }

    patientCount++;

    printf("\nPatient registered successfully.\n");
}


void displayPatients(void)
{


    if (patientCount == 0)
    {
        printf("\nNo patients registered.\n");
        return;
    }

    printf("\n================ REGISTERED PATIENTS ================\n");

    for (int i = 0; i < patientCount; i++)
    {
        printf("\nPatient ID      : PAT-%04d\n", i + 1);
        printf("Name            : %s\n", patientName[i]);
        printf("Age             : %d\n", patientAge[i]);
        printf("Urgency Level   : %d\n", patientUrgency[i]);
        printf("Specialty ID    : %d\n", patientSpecialty[i]);

        if (patientAdmitted[i] == 1)
        {
            printf("Admitted        : Yes\n");
            printf("Ward ID         : %d\n", patientWard[i]);
            printf("Assigned Bed    : Bed #%02d\n", patientBed[i]);
            printf("Days            : %d\n", patientDays[i]);
        }
        else
        {
            printf("Admitted        : No\n");
        }

        printf("---------------------------------------------\n");
    }
}
