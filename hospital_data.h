#ifndef HOSPITAL_DATA_H
#define HOSPITAL_DATA_H

#define NUM_SPECIALTIES 4
#define NUM_WARDS 4
#define MAX_BEDS 20

extern const int specialtyID[NUM_SPECIALTIES];
extern const char specialtyName[NUM_SPECIALTIES][30];
extern const double consultationFee[NUM_SPECIALTIES];
extern const int consultationTime[NUM_SPECIALTIES];
extern const int dailyPatientCap[NUM_SPECIALTIES];

extern const int wardID[NUM_WARDS];
extern const char wardName[NUM_WARDS][30];
extern const double dailyBedRate[NUM_WARDS];
extern const int bedCapacity[NUM_WARDS];

extern int bedOccupancy[NUM_WARDS][MAX_BEDS];

void displaySpecialties(void);
void displayWards(void);
void initializeBeds(void);
void displayBedOccupancy(void);

#endif
