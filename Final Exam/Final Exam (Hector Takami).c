//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Final Exam)

#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#define OPT_SUCCESS 1
#define ARG_OUT_OF_RANGE -1


//SensorValues Struct
typedef struct SensorValues
{
	double *values;
	int length;
}  SensorValues;

//AirPressureSensorsValues Struct
typedef struct AirPressureSensorsValues 
{
    SensorValues* ps;
    SensorValues* pfv;
} AirPressureSensorsValues;


//Functions Definition
unsigned long long getMixedCC(int entries, ...);
AirPressureSensorsValues* createAirPressureSensorsValues(const int psLength, const  int pfvLength, int *output);
void freeAirPressureSensorsValues(AirPressureSensorsValues* apsv);
void applyFilter(AirPressureSensorsValues *apsv, double *const arr, const char aLength);

//Test Definition
int test1_createAirPressureSensorsValues();
int test2_createAirPressureSensorsValues();


//********************************************* MAIN_SECTION **************************************************
//*************************************************************************************************************

int main(void) {
    printf(" \n  CreateAirPressureSensorsValues Tests: \n\n");
    int option;
    printf(" * Enter (1) to try test #1\n * Enter (2) to try test #2\n\n Option ->");
    scanf("%d",&option);
    
    if(option==1){
        printf(test1_createAirPressureSensorsValues() ? printf(" * Test 1 -> Successfull :)\n\n") : printf(" * Test 1 -> Failed :(\n\n") );
    }
    
    if(option==2){
        printf(test2_createAirPressureSensorsValues() ? printf(" * Test 2 -> Successfull :)\n\n") : printf(" * Test 2 -> Failed :(\n\n") );
    }
    
    else{
        printf("Invalid option... try again! :/");
    }

    return 0;
}

//********************************************* TEST_SECTION **************************************************
//*************************************************************************************************************

int test_getMixedCC(){
    unsigned long long CC1 = 14;
    unsigned long long CC2 = 24;
    unsigned long long CC3 = 12;
    if(getMixedCC(CC1,CC2,CC3)==30){
        return 1;
    }else{
        return 0;
    }
}

int test1_createAirPressureSensorsValues(){
    int output;
	AirPressureSensorsValues* result = createAirPressureSensorsValues(-1, 2, &output);
	if(output == ARG_OUT_OF_RANGE && result == NULL){
		return 1;
	} else {
		freeAirPressureSensorsValues(result);
		return 0;
	}
}


int test2_createAirPressureSensorsValues(){
    int output;
	AirPressureSensorsValues* result = createAirPressureSensorsValues(1, 2, &output);
	if(output == OPT_SUCCESS && result->ps->length == 1 && result->pfv->length == 2) {
		freeAirPressureSensorsValues(result);
		return 1;
	} else {
		freeAirPressureSensorsValues(result);
		return 0;
	}

}

int test_applyFilter() {
	return (1);
}



//*********************************************** getMixedCC **************************************************
//*************************************************************************************************************

unsigned long long getMixedCC(int entries, ...) {
	unsigned long long resultCC = 0;
	va_list cylinderCodesList;
	va_start(cylinderCodesList, entries);

	for (int i = 0; i < entries; i++) {
		resultCC = resultCC|va_arg(cylinderCodesList, unsigned long long);	
	}
	//printf("%llu",resultCC);
	va_end(cylinderCodesList);
	return resultCC;
}

//************************************* createAirPressureSensorValues *****************************************
//*************************************************************************************************************


AirPressureSensorsValues* createAirPressureSensorsValues(const int psLength, const  int pfvLength, int *output) {
    
	if (psLength <= 0 || pfvLength <= 0) {
		*output = ARG_OUT_OF_RANGE;
		return NULL;
	} else {
		*output = OPT_SUCCESS;
	}

	AirPressureSensorsValues* apsv = (AirPressureSensorsValues*) malloc(sizeof(AirPressureSensorsValues));
	(*apsv).ps = (SensorValues*) malloc(sizeof(SensorValues)); 
	(*apsv).pfv = (SensorValues*) malloc(sizeof(SensorValues));
	apsv->ps->length = psLength; 
	apsv->pfv->length = pfvLength;
	apsv->ps->values = (double*) calloc(psLength, sizeof(double));
	apsv->pfv->values = (double*) calloc(pfvLength, sizeof(double));

	return apsv;
}

//************************************* freeAirPressureSensorsValues *****************************************
//*************************************************************************************************************

void freeAirPressureSensorsValues(AirPressureSensorsValues* apsv){
  free(apsv->ps->values);
  free(apsv->pfv->values);
  free((*apsv).ps);
  free((*apsv).pfv);
  free(apsv);
}

//********************************************* applyFilter *************************************************** 
//*************************************************************************************************************

void applyFilter(AirPressureSensorsValues *apsv, double *const arr, const char aLength) {
    
	int k = (aLength/2);
	for (int i = 0; i < apsv->ps->length; ++i)	{
		int sum = 0;
		for (int j = 0; j < aLength; ++j) {
			if (i != 0 && i != apsv->ps->length){
				sum = sum + arr[k+j] * apsv->ps->values[j];
			}
		}
		apsv->ps->values[i] = sum;
	}

	for (int i = 0; i < apsv->pfv->length; ++i) {
		int sum = 0;
		for (int j = 0; j < aLength; ++j) {
			if (i != 0 && i != apsv->pfv->length) {
				sum = sum + arr[k+j] * apsv->pfv->values[j];
			}
		}
		apsv->pfv->values[i] = sum;
	}
}

