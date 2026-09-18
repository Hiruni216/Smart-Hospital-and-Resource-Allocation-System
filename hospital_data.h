#ifndef HOSPITAL_DATA_H
#define HOSPITAL_DATA_H

#define NUM_SPECIALTIES 4
#define NUM_WARDS 4
#define MAX_BEDS 20

extern int bedOccupancy[NUM_WARDS][MAX_BEDS];

void displaySpecialties(void);
void displayWards(void);
void initializeBeds(void);
void displayBedOccupancy(void);

#endif
