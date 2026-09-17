#include <stdio.h>
#include "priority.h"
#include "patient.h"

extern char patientName[][100];
extern int patientAge[];
extern int patientUrgency[];
extern int patientSpecialty[];
extern int patientAdmitted[];
extern int patientWard[];
extern int patientDays[];

extern int patientCount;



void displayPatientsByPriority(void)
{
    int order[100]={0};

    int temp=0;

    if (patientCount == 0)
    {
        printf("\nNo patients registered.\n");
        return;
    }


    for (int i = 0; i < patientCount; i++)
    {
        order[i] = i;
    }



    for (int i = 0; i < patientCount - 1; i++)
    {
        for (int j = 0; j < patientCount - 1 - i; j++)
        {
            if (patientUrgency[order[j]]
                < patientUrgency[order[j + 1]])
            {
                temp = order[j];
                order[j] = order[j + 1];
                order[j + 1] = temp;
            }
        }
    }


    printf("\n");
    printf("============================================================\n");
    printf("              PATIENTS BY PRIORITY\n");
    printf("============================================================\n");

    for (int i = 0; i < patientCount; i++)
    {
        int index = order[i];

        printf("\nPriority %d\n", i + 1);
        printf("--------------------------------------------\n");

        printf("Registration No. : %d\n", index + 1);
        printf("Patient Name     : %s\n", patientName[index]);
        printf("Age              : %d\n", patientAge[index]);
        printf("Urgency Level    : Level %d\n", patientUrgency[index]);
        printf("Specialty ID     : %d\n", patientSpecialty[index]);

        if (patientAdmitted[index] == 1)
        {
            printf("Ward ID          : %d\n", patientWard[index]);
            printf("Days Admitted    : %d\n", patientDays[index]);
        }
        else
        {
            printf("Ward             : Outpatient / OPD\n");
        }
    }

    printf("\n============================================================\n");
}
