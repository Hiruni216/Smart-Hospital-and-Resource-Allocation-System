#include <stdio.h>
#include "billing.h"
#include "patient.h"


extern const double consultationFee[];
extern const int consultationTime[];

extern const double dailyBedRate[];



extern char patientName[][100];
extern int patientAge[];
extern int patientUrgency[];
extern int patientSpecialty[];
extern int patientAdmitted[];
extern int patientWard[];
extern int patientDays[];

extern int patientCount;



int specialtyQueue[4] = {0, 0, 0, 0};



double calculateWaitingTime(int specialtyID)
{
    int index;

    index = specialtyID - 1;

    return specialtyQueue[index] * consultationTime[index];
}



double calculateEmergencySurcharge(double baseFee, int urgencyLevel)
{
    if (urgencyLevel == 1)
    {
        return 0.0;
    }
    else if (urgencyLevel == 2)
    {
        return baseFee * 0.20;
    }
    else if (urgencyLevel == 3)
    {
        return baseFee * 0.50;
    }

    return 0.0;
}



double calculateWardCost(int wardID, int days)
{
    int index;

    if (wardID == 0 || days == 0)
    {
        return 0.0;
    }

    index = wardID - 1;

    return days * dailyBedRate[index];
}



double calculateGrossTotal(double baseFee,
                           double surcharge,
                           double wardCost)
{
    return baseFee + surcharge + wardCost;
}


double calculateDiscount(double grossTotal, int age)
{
    if (age < 5 || age > 65)
    {
        return grossTotal * 0.15;
    }

    return 0.0;
}



double calculateFinalAmount(double grossTotal, double discount)
{
    return grossTotal - discount;
}


void displayPatientBill(int patientIndex)
{
    int specialtyIndex=0;
    double baseFee=0.0;
    double waitingTime=0.0;
    double surcharge=0.0;
    double wardCost=0.0;
    double grossTotal=0.0;
    double discount=0.0;
    double finalAmount=0.0;

    specialtyIndex = patientSpecialty[patientIndex] - 1;


    baseFee = consultationFee[specialtyIndex];


    waitingTime = calculateWaitingTime(patientSpecialty[patientIndex]);


    surcharge = calculateEmergencySurcharge(baseFee,patientUrgency[patientIndex]);


    wardCost = calculateWardCost(patientWard[patientIndex],patientDays[patientIndex]);


    grossTotal = calculateGrossTotal(baseFee,surcharge,wardCost);


    discount = calculateDiscount(grossTotal,patientAge[patientIndex]);


    finalAmount = calculateFinalAmount(grossTotal,discount);


    printf("\n");
    printf("============================================================\n");
    printf("                 SMART HOSPITAL BILL\n");
    printf("============================================================\n");

    printf("Patient Name              : %s\n",
           patientName[patientIndex]);

    printf("Age                       : %d\n",
           patientAge[patientIndex]);

    printf("Urgency Level             : Level %d\n",
           patientUrgency[patientIndex]);

    printf("Specialty ID              : %d\n",
           patientSpecialty[patientIndex]);

    printf("------------------------------------------------------------\n");

    printf("Base Consultation Fee     : LKR %.2f\n",
           baseFee);

    printf("Emergency Surcharge       : LKR %.2f\n",
           surcharge);

    printf("Ward Stay Cost             : LKR %.2f\n",
           wardCost);

    printf("------------------------------------------------------------\n");

    printf("Gross Total Bill           : LKR %.2f\n",
           grossTotal);

    printf("Age Subsidy Discount       : LKR %.2f\n",
           discount);

    printf("------------------------------------------------------------\n");

    printf("Final Amount Payable       : LKR %.2f\n",
           finalAmount);

    printf("Estimated Waiting Time     : %.2f mins\n",
           waitingTime);

    printf("============================================================\n");
}
