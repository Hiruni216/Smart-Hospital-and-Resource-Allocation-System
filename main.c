#include <stdio.h>

#include "hospital_data.h"
#include "patient.h"
#include "billing.h"
#include "priority.h"
#include "report.h"
#include "file_handler.h"

int main(void)
{
    int choice;

    initializeBeds();
    loadBedStatus();

    do
    {
        printf("\n");
        printf("===============================================================\n");
        printf("                 SMART HOSPITAL SYSTEM\n");
        printf("===============================================================\n");
        printf("1.  Display Doctor Specialties\n");
        printf("2.  Display Ward Information\n");
        printf("3.  Display Bed Occupancy\n");
        printf("4.  Register Patient\n");
        printf("5.  Display All Patients\n");
        printf("6.  Display Patient Bill\n");
        printf("7.  Display Patients by Priority\n");
        printf("8.  Generate Performance Report\n");
        printf("9.  Save Bed Status\n");
        printf("10. Load Bed Status\n");
        printf("0.  Exit\n");
        printf("===============================================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                displaySpecialties();
                break;

            case 2:
                displayWards();
                break;

            case 3:
                displayBedOccupancy();
                break;

            case 4:
            {
                int oldPatientCount;

                oldPatientCount = patientCount;

                registerPatient();

                if (patientCount > oldPatientCount)
                {
                    savePatientRecord(patientCount - 1);
                }

                break;
            }

            case 5:
                displayPatients();
                break;

            case 6:
            {
                int patientIndex;

                if (patientCount == 0)
                {
                    printf("\nNo patients have been registered.\n");
                }
                else
                {
                    printf("\nEnter patient number (1-%d): ", patientCount);
                    scanf("%d", &patientIndex);

                    if (patientIndex >= 1 && patientIndex <= patientCount)
                    {
                        displayPatientBill(patientIndex - 1);
                    }
                    else
                    {
                        printf("\nInvalid patient number.\n");
                    }
                }

                break;
            }

            case 7:
                displayPatientsByPriority();
                break;

            case 8:
                generateReport();
                break;

            case 9:
                saveBedStatus();
                break;

            case 10:
                loadBedStatus();
                break;

            case 0:
                saveBedStatus();
                printf("\nBed status saved successfully.\n");
                printf("Thank you for using Smart Hospital System.\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}
