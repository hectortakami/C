//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Partial Exam no.2)

#include "stdio.h"
#include "stdlib.h"
#include "math.h"

//MinutiaType Enum
typedef enum {
	Ending,
	Bifurcation,
	Unknown
} MinutiaType;

//Minutia Struct
typedef struct Minutia {
	unsigned short int x;
	unsigned short int y;
	float angle;
	MinutiaType type;
} Minutia;

//MinutiaArray Struct
typedef struct MinutiaArray {
    Minutia *minutiae;
    unsigned short int length;
} MinutiaArray;

//Compute Distance Function Pointer
typedef double (*FUNC_PTR)(Minutia*,Minutia*);

//Functions Definition
Minutia *createMinutia(unsigned short int x, unsigned short int y, float angle, MinutiaType type);
MinutiaArray* createMinutiaArray(int size);
void releaseMinutiaArray(MinutiaArray* ptrMinutiaArray);
Minutia *findCentroid(MinutiaArray* minutiaArray, FUNC_PTR computeDistancePtr );
double computeDistance(Minutia* minutia1, Minutia* minutia2 );

//Test Definition
int testFindCentroid();

//********************************************* MAIN_SECTION **************************************************
//*************************************************************************************************************

int main(void) {
    testFindCentroid() == 1 ? printf("Test Find Centroid: Successfull :)") : printf("Test Find Centroid: Failed :(");
    return 0;
}

//********************************************* TEST_SECTION **************************************************
//*************************************************************************************************************

int testFindCentroid(){
    int length_A = 10;
    
	MinutiaArray* minutia_Array_A = createMinutiaArray(length_A);
	
    (*minutia_Array_A).minutiae[0] = *createMinutia(2,7,12,Ending);
    (*minutia_Array_A).minutiae[1] = *createMinutia(5,3,90,Ending);
    (*minutia_Array_A).minutiae[2] = *createMinutia(9,5,90,Ending);
    (*minutia_Array_A).minutiae[3] = *createMinutia(1,2,3,Ending);
    (*minutia_Array_A).minutiae[4] = *createMinutia(4,7,12,Ending);
    (*minutia_Array_A).minutiae[5] = *createMinutia(5,9,66,Ending);
    (*minutia_Array_A).minutiae[6] = *createMinutia(2,7,1.2,Ending);
    (*minutia_Array_A).minutiae[7] = *createMinutia(5,3,9,Ending);
    (*minutia_Array_A).minutiae[8] = *createMinutia(3,7,16.8,Ending);
    (*minutia_Array_A).minutiae[9] = *createMinutia(5,7,90,Ending);

	(*minutia_Array_A).length = length_A;
	
	Minutia *resultMinutia = findCentroid(minutia_Array_A, &computeDistance);

	releaseMinutiaArray(minutia_Array_A);
	
	if(resultMinutia!=NULL){
	    return 1;
	}else{
	    return 0;
	}
}

//***************************************** COMPUTE_DISTANCE **************************************************
//*************************************************************************************************************


double computeDistance(Minutia* minutia1, Minutia* minutia2 ){
    Minutia m1 = (*minutia1);
    Minutia m2 = (*minutia2);
    double a = sqrt(pow(((m2.x)-(m1.x)),2)+pow(((m2.y)-(m1.y)),2));
    return a;
}

//***************************************** FIND_CENTROID  ****************************************************
//*************************************************************************************************************

Minutia *findCentroid(MinutiaArray* minutiaArray, FUNC_PTR computeDistancePtr ){
    double acumulatedDitance = 0;
    double lastAcumulatedDitance = 0;
    int index = 0;
    for(int i = 0; i<sizeof((*minutiaArray)); i++){
        acumulatedDitance = 0;
        for(int j = 0; j< sizeof((*minutiaArray)); j++){
            acumulatedDitance += computeDistance(&minutiaArray[i],&minutiaArray[j]);
        }
        if(acumulatedDitance < lastAcumulatedDitance){
            index = i;
        }
        lastAcumulatedDitance = acumulatedDitance;
    }
    Minutia *minutiaInCentroid = &minutiaArray[index];
    return minutiaInCentroid;
}

//******************************************* CREATE_MINUTIA **************************************************
//*************************************************************************************************************

Minutia *createMinutia(unsigned short int xVal, unsigned short int yVal, float angleVal, MinutiaType typeVal) {
	Minutia* ptrMinutia = (Minutia*)malloc(sizeof(Minutia));
	(*ptrMinutia).x = xVal;
	(*ptrMinutia).y = yVal;
	(*ptrMinutia).angle = angleVal;
	(*ptrMinutia).type = typeVal;
	return ptrMinutia;
}

//************************************* CREATE_MINUTIA_ARRAY **************************************************
//*************************************************************************************************************

MinutiaArray* createMinutiaArray(int size) {
	MinutiaArray* ptrMinutiaArray = (MinutiaArray*)malloc(sizeof(MinutiaArray));
	(*ptrMinutiaArray).minutiae = (Minutia*)calloc(size, sizeof(Minutia));
	(*ptrMinutiaArray).length = size;
	return ptrMinutiaArray;
}

//******************************************* REALESE_MINUTIA *************************************************
//*************************************************************************************************************

void releaseMinutiaArray(MinutiaArray* ptrMinutiaArray) {
	free((*ptrMinutiaArray).minutiae);
	free(ptrMinutiaArray);
}

/*
void computeDistanceTEST1(){
  Minutia* m1;
  Minutia* m2;
  m1 = createMinutia(2,7,12,(MinutiaType)Ending);
  m2 = createMinutia(5,3,90,(MinutiaType)Ending);
  double r = computeDistance(m1,m2);
  if(r == 5){
    printf("Test satisfactorio");
  }
  else{
    printf("Test fallido");
  }
}
*/