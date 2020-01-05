//Autor: Hector Manuel Takami Flores - A01377647
//Advanced Programming (Assignment no.9)

#include "stdio.h"
#include "stdlib.h"
#include "math.h"

typedef enum {
	numerical,
	nominal
} FeatureType;

typedef struct Instance
{
	double *features;
	FeatureType *featureTypes;
	int length;
} Instance;

Instance* someInstance(int size)
{
	Instance* ptrInstance = (Instance*)malloc(sizeof(Instance));
	(*ptrInstance).features = (double*)calloc(size, sizeof(double));
	(*ptrInstance).featureTypes = (FeatureType*)calloc(size, sizeof(FeatureType));
	(*ptrInstance).length = size;	
	return ptrInstance;
}

void freeInstance(Instance* ptrInst)
{
	free((*ptrInst).features);
	free((*ptrInst).featureTypes);
	free(ptrInst);
}

//Compute Euclidean Dissimilarity Method
double computeEuclideanDissimilarity(const Instance *instance_A, const Instance *instance_B);
//Tests computeEuclideanDissimilarity
int test_1_computeEuclideanDissimilarity();
int test_2_computeEuclideanDissimilarity();
int test_3_computeEuclideanDissimilarity();
int test_4_computeEuclideanDissimilarity();

//Find Nearest Neighbor Method
Instance *findNearestNeighbor(Instance* inst, int length, Instance* query, Instance* inst_near);
//Tests findNearestNeighbor
int test_1_findNearestNeighbor();
int test_2_findNearestNeighbor();
int test_3_findNearestNeighbor();
int test_4_findNearestNeighbor();


int main(void) {
    printf("\n***********************Compute_Euclidean_Dissimilarity***********************\n");
    (test_1_computeEuclideanDissimilarity()==1) ? printf(" --> Test 1: Successfull\n") : printf(" --> Test 1: Failed\n");
    (test_2_computeEuclideanDissimilarity()==1) ? printf(" --> Test 2: Successfull\n") : printf(" --> Test 2: Failed\n");
    (test_3_computeEuclideanDissimilarity()==1) ? printf(" --> Test 3: Successfull\n") : printf(" --> Test 3: Failed\n");
    (test_4_computeEuclideanDissimilarity()==1) ? printf(" --> Test 4: Successfull\n") : printf(" --> Test 4: Failed\n");
    printf("*****************************************************************************\n\n");

    printf("****************************Find_Nearest_Neighbor****************************\n");
    (test_1_findNearestNeighbor()==1) ? printf(" --> Test 1: Successfull\n") : printf(" --> Test 1: Failed\n");
    (test_2_findNearestNeighbor()==1) ? printf(" --> Test 2: Successfull\n") : printf(" --> Test 2: Failed\n");
    (test_3_findNearestNeighbor()==1) ? printf(" --> Test 3: Successfull\n") : printf(" --> Test 3: Failed\n");
    (test_4_findNearestNeighbor()==1) ? printf(" --> Test 4: Successfull\n") : printf(" --> Test 4: Failed\n");
    printf("*****************************************************************************");
    return 0;
}

//**************************computeEuclideanDissimilarity****************************************

double computeEuclideanDissimilarity(const Instance* instance_A, const Instance* instance_B) {
	if((*instance_A).length == 0 || 
	(*instance_B).length == 0) {
		return -1;
	}
	
	if((*instance_A).length != 
	(*instance_B).length) {
		return -2;
	}

	double result;
	int i;	
	for(i = 0; i < (*instance_A).length; ++i) {
		double feature_A = (*instance_A).features[i];
		double feature_B = (*instance_B).features[i];

		FeatureType featureType_A = (*instance_A).featureTypes[i];
		FeatureType featureType_B = (*instance_B).featureTypes[i];
		
		if(featureType_A != featureType_B)	{
			return -3;
		}
		
		if(featureType_A == numerical) 	{
			result += pow(feature_A - feature_B, 2);
		}
		
		if(featureType_A == nominal) {
			if(feature_A == feature_B) 	{
				result += 0.0;
			} else if(feature_A != feature_B) {
				result += 1.0;
			}	
		}
	}

	result = pow(result, 0.5);
	return result;
}


//*******************************findNearestNeighbor***********************************
Instance *findNearestNeighbor(Instance* inst, int length, Instance* query, Instance* inst_near) {
	Instance* null_Instance;

	double dissimilar = computeEuclideanDissimilarity(&inst[0], query);;
	double contrast;

	if(inst[0].length == 0)
	{
		return null_Instance;
	}
	
	for(int i = 1; i < length; ++i)	{
		contrast = computeEuclideanDissimilarity(&inst[i], query);
		if (contrast < dissimilar)	{	
			dissimilar = contrast;
			inst_near = &inst[i];
		}
	}

    if (contrast == -1)	{
		return null_Instance;
	} else if (contrast == -2) 	{
		return null_Instance;
	} else if (contrast == -3)	{
		return null_Instance;
	} else {
		return inst_near;
	}


}

//*********************computeEuclideanDissimilarity TESTS*****************************

// At least one of the instance has length equal to 0 and has no dimentional array values
int test_1_computeEuclideanDissimilarity() {
	int length_A = 0;
    
	Instance* instance_A = someInstance(length_A);

	int length_B = 4;

	Instance* instance_B = someInstance(length_B);
	(*instance_B).features[0] = 4;
	(*instance_B).features[1] = 5;
	(*instance_B).features[2] = 6;
	(*instance_B).features[3] = 7;
	(*instance_B).featureTypes[0] = nominal;
	(*instance_B).featureTypes[1] = nominal;
	(*instance_B).featureTypes[2] = nominal;
	(*instance_B).featureTypes[3] = nominal;
	(*instance_B).length = length_B;
	
	double result = computeEuclideanDissimilarity(instance_A, instance_B);

	freeInstance(instance_A);
	freeInstance(instance_B);

	if(result == -1)	{
		return 1; 
	} else {
		return 0; 
	}

}

//Both instance has different length values in their sizes
int test_2_computeEuclideanDissimilarity() {
	int length_A = 2; 

	Instance* instance_A = someInstance(length_A);
	(*instance_A).features[0] = 10;
	(*instance_A).features[1] = 21;
	(*instance_A).featureTypes[0] = numerical;
	(*instance_A).featureTypes[1] = numerical;
	(*instance_A).length = length_A;


	int length_B = 4;

	Instance* instance_B = someInstance(length_B);
	(*instance_B).features[0] = 17;
	(*instance_B).features[1] = 96;
	(*instance_B).features[2] = 35;
	(*instance_B).features[3] = 44;
	(*instance_B).featureTypes[0] = nominal;
	(*instance_B).featureTypes[1] = nominal;
	(*instance_B).featureTypes[2] = nominal;
	(*instance_B).featureTypes[3] = nominal;
	(*instance_B).length = length_B;
	
	double result = computeEuclideanDissimilarity(instance_A, instance_B);

	freeInstance(instance_A);
	freeInstance(instance_B);

	if(result == -2){
		return 1; 
	}else{
		return 0;
	}
}

//Both instances has the same lenth values but at least one of their 
//array values in featuresTypes is different
int test_3_computeEuclideanDissimilarity() {
	int length_A = 4;

	Instance* instance_A = someInstance(length_A);	
	(*instance_A).features[0] = 10;
	(*instance_A).features[1] = 21;
	(*instance_A).features[2] = 34;
	(*instance_A).features[3] = 46;
	(*instance_A).featureTypes[0] = numerical;
	(*instance_A).featureTypes[1] = numerical;
	(*instance_A).featureTypes[2] = nominal;
	(*instance_A).featureTypes[3] = nominal;
	(*instance_A).length = length_A;


	int length_B = 4;

	Instance* instance_B = someInstance(length_B);
	(*instance_B).features[0] = 17;
	(*instance_B).features[1] = 96;
	(*instance_B).features[2] = 35;
	(*instance_B).features[3] = 46;
	(*instance_B).featureTypes[0] = numerical;
	(*instance_B).featureTypes[1] = numerical;
	(*instance_B).featureTypes[2] = numerical;
	(*instance_B).featureTypes[3] = nominal;
	(*instance_B).length = length_B;
	
	double result = computeEuclideanDissimilarity(instance_A, instance_B);

	freeInstance(instance_A);
	freeInstance(instance_B);

	if(result == -3) {
		return 1; 
	} else {
		return 0; 
	}
}

//Compute the Dissimilarity between two instances with a length equal or bigger than 4 
int test_4_computeEuclideanDissimilarity() {
	int length_A = 4;

	Instance* instance_A = someInstance(length_A);
	(*instance_A).features[0] = 10;
	(*instance_A).features[1] = 21;
	(*instance_A).features[2] = 34;
	(*instance_A).features[3] = 46;
	(*instance_A).featureTypes[0] = numerical;
	(*instance_A).featureTypes[1] = numerical;
	(*instance_A).featureTypes[2] = nominal;
	(*instance_A).featureTypes[3] = nominal;
	(*instance_A).length = length_A;


	int length_B = 5;

	Instance* instance_B = someInstance(length_B);
	(*instance_B).features[0] = 17;
	(*instance_B).features[1] = 96;
	(*instance_B).features[2] = 35;
	(*instance_B).features[3] = 46;
	(*instance_B).features[4] = 95;

	(*instance_B).featureTypes[0] = nominal;
	(*instance_B).featureTypes[1] = numerical;
	(*instance_B).featureTypes[2] = numerical;
	(*instance_B).featureTypes[3] = nominal;
	(*instance_B).featureTypes[4] = nominal;

	(*instance_B).length = length_B;
	
	double result = computeEuclideanDissimilarity(instance_A, instance_B);

	freeInstance(instance_A);
	freeInstance(instance_B);

	if(result -95.3426 < 0.0001) {
		return 1; 
	} else {
		return 0; 
	}
}


//*****************************findNearestNeighbor TESTS*************************************

//The query Instance has a length equal to 0
int test_1_findNearestNeighbor() {
	int length_A = 4;

	Instance* instance_A = someInstance(length_A);
	(*instance_A).features[0] = 1;
	(*instance_A).features[1] = 4;
	(*instance_A).features[2] = -3;
	(*instance_A).features[3] = 2;
	(*instance_A).featureTypes[0] = numerical;
	(*instance_A).featureTypes[1] = numerical;
	(*instance_A).featureTypes[2] = numerical;
	(*instance_A).featureTypes[3] = numerical;
	(*instance_A).length = length_A;

	
	int length_B = 4;
	Instance* instance_B = someInstance(length_B);
	(*instance_B).features[0] = 1;
	(*instance_B).features[1] = 3;
	(*instance_B).features[2] = 5;
	(*instance_B).features[3] = 2;
	(*instance_B).featureTypes[0] = numerical;
	(*instance_B).featureTypes[1] = nominal;
	(*instance_B).featureTypes[2] = numerical;
	(*instance_B).featureTypes[3] = numerical;
	(*instance_B).length = length_B;	

	int length_query = 0;
	Instance* instance_query = someInstance(length_query);


	Instance* ptrArrInstance = (Instance*)calloc(2, sizeof(Instance));

	ptrArrInstance[0] = *instance_A;
	ptrArrInstance[1] = *instance_B;

	Instance * result;
	Instance* ptrResult;

	result = findNearestNeighbor(ptrArrInstance, 2, instance_query, ptrResult);

	freeInstance(instance_A);
	freeInstance(instance_B);
	freeInstance(instance_query);
	
	if(result == NULL )	{
		return 1;
	} else {
		return 0;
	}
	
}

//The query Instance and some other instance have different length values between them
int test_2_findNearestNeighbor() {
	int length_A = 3;
	Instance* instance_A = someInstance(length_A);
	(*instance_A).features[0] = 1;
	(*instance_A).features[1] = 4;
	(*instance_A).features[2] = -3;
	(*instance_A).featureTypes[0] = numerical;
	(*instance_A).featureTypes[1] = numerical;
	(*instance_A).featureTypes[2] = numerical;
	(*instance_A).length = length_A;

	
	int length_B = 5;
	Instance* instance_B = someInstance(length_B);
	(*instance_B).features[0] = 1;
	(*instance_B).features[1] = 2;
	(*instance_B).features[2] = 3;
	(*instance_B).features[3] = 4;
	(*instance_B).features[4] = 4;
	(*instance_B).featureTypes[0] = numerical;
	(*instance_B).featureTypes[1] = numerical;
	(*instance_B).featureTypes[2] = numerical;
	(*instance_B).featureTypes[3] = numerical;
	(*instance_B).featureTypes[4] = numerical;

	(*instance_B).length = 3;	

	int length_query = 4;
	Instance* instance_query = someInstance(length_query);
	(*instance_query).features[0] = 1;
	(*instance_query).features[1] = 3;
	(*instance_query).features[2] = 5;
	(*instance_query).features[3] = 2;
	(*instance_query).featureTypes[0] = numerical;
	(*instance_query).featureTypes[1] = numerical;
	(*instance_query).featureTypes[2] = numerical;
	(*instance_query).featureTypes[3] = numerical;
	(*instance_query).length = length_B;

	Instance* ptrArrInstance = (Instance*)calloc(2, sizeof(Instance));

	ptrArrInstance[0] = *instance_A;
	ptrArrInstance[1] = *instance_B;

	Instance* result;
	Instance* ptrResult;

	result = findNearestNeighbor(ptrArrInstance, 2, instance_query, ptrResult);

	freeInstance(instance_A);
	freeInstance(instance_B);
	freeInstance(instance_query);
		
	if(result == NULL)	{
		return 1;
	} else {
		return 0;
	}
}

//The query Instance and some other Instance has the same length value but at least one of
//their featuresTypes elements has different values
int test_3_findNearestNeighbor() {
	int length_A = 4;
	Instance* instance_A = someInstance(length_A);
	(*instance_A).features[0] = 1;
	(*instance_A).features[1] = 4;
	(*instance_A).features[2] = -3;
	(*instance_A).features[3] = 2;
	(*instance_A).featureTypes[0] = numerical;
	(*instance_A).featureTypes[1] = numerical;
	(*instance_A).featureTypes[2] = numerical;
	(*instance_A).featureTypes[3] = numerical;
	(*instance_A).length = length_A;

	
	int length_B = 5;
	Instance* instance_B = someInstance(length_B);
	(*instance_B).features[0] = 1;
	(*instance_B).features[1] = 2;
	(*instance_B).features[2] = 3;
	(*instance_B).features[3] = 4;
	(*instance_B).features[4] = 4;
	(*instance_B).featureTypes[0] = numerical;
	(*instance_B).featureTypes[1] = numerical;
	(*instance_B).featureTypes[2] = nominal;
	(*instance_B).featureTypes[3] = numerical;
	(*instance_B).featureTypes[4] = numerical;
	(*instance_B).length = length_B;	

	int length_query = 5;
	Instance* instance_query = someInstance(length_query);
	(*instance_query).features[0] = 1;
	(*instance_query).features[1] = 3;
	(*instance_query).features[2] = 5;
	(*instance_query).features[3] = 2;
	(*instance_query).features[4] = 2;
	(*instance_query).featureTypes[0] = numerical;
	(*instance_query).featureTypes[1] = nominal;
	(*instance_query).featureTypes[2] = numerical;
	(*instance_query).featureTypes[3] = numerical;
	(*instance_query).featureTypes[4] = numerical;

	(*instance_query).length = length_B;

	Instance* ptrArrInstance = (Instance*)calloc(2, sizeof(Instance));

	ptrArrInstance[0] = *instance_A;
	ptrArrInstance[1] = *instance_B;

	Instance* result;
	Instance* ptrResult;

	result = findNearestNeighbor(ptrArrInstance, 2, instance_query, ptrResult);

	freeInstance(instance_A);
	freeInstance(instance_B);
	freeInstance(instance_query);
		
	if(result == NULL) {
		return 1;
	} else {
		return 0;
	}
}

//Return the correct index of the less dissimilar query with instances up to 4 length
int test_4_findNearestNeighbor() {
	int length_A = 4;
	Instance* instance_A = someInstance(length_A);
	(*instance_A).features[0] = 1;
	(*instance_A).features[1] = 4;
	(*instance_A).features[2] = -3;
	(*instance_A).features[3] = 2;
	(*instance_A).featureTypes[0] = nominal;
	(*instance_A).featureTypes[1] = numerical;
	(*instance_A).featureTypes[2] = nominal;
	(*instance_A).featureTypes[3] = numerical;
	(*instance_A).length = length_A;

	
	int length_B = 4;
	Instance* instance_B = someInstance(length_B);
	(*instance_B).features[0] = 1;
	(*instance_B).features[1] = 3;
	(*instance_B).features[2] = 5;
	(*instance_B).features[3] = 2;
	(*instance_B).featureTypes[0] = nominal;
	(*instance_B).featureTypes[1] = numerical;
	(*instance_B).featureTypes[2] = numerical;
	(*instance_B).featureTypes[3] = nominal;
	(*instance_B).length = length_B;

	int length_C = 4;
	Instance* instance_C = someInstance(length_C);
	(*instance_C).features[0] = 1;
	(*instance_C).features[1] = 3;
	(*instance_C).features[2] = 5;
	(*instance_C).features[3] = 2;
	(*instance_C).featureTypes[0] = nominal;
	(*instance_C).featureTypes[1] = numerical;
	(*instance_C).featureTypes[2] = numerical;
	(*instance_C).featureTypes[3] = nominal;
	(*instance_C).length = length_C;	

	int length_D = 4;
	Instance* instance_D = someInstance(length_D);
	(*instance_D).features[0] = 1;
	(*instance_D).features[1] = 3;
	(*instance_D).features[2] = 5;
	(*instance_D).features[3] = 2;
	(*instance_D).featureTypes[0] = nominal;
	(*instance_D).featureTypes[1] = numerical;
	(*instance_D).featureTypes[2] = nominal;
	(*instance_D).featureTypes[3] = numerical;
	(*instance_D).length = length_D;	

	int length_query = 4;
	Instance* instance_query = someInstance(length_query);
	(*instance_query).features[0] = 1;
	(*instance_query).features[1] = 3;
	(*instance_query).features[2] = 5;
	(*instance_query).features[3] = 2;
	(*instance_query).featureTypes[0] = numerical;
	(*instance_query).featureTypes[1] = nominal;
	(*instance_query).featureTypes[2] = numerical;
	(*instance_query).featureTypes[3] = nominal;
	(*instance_query).length = length_query;

	Instance* ptrArrInstance = (Instance*)calloc(2, sizeof(Instance));

	ptrArrInstance[0] = *instance_A;
	ptrArrInstance[1] = *instance_B;

	Instance* result;
	int flag, i;
	Instance* ptrResult = someInstance(length_query);

	result = findNearestNeighbor(ptrArrInstance, 2, instance_query, ptrResult);

	for(i = 0; i < (*instance_B).length; ++i)
	{
		if ((*instance_B).features[i] == (*ptrResult).features[i])
		{
			flag = 1;
		}
	}

	freeInstance(instance_A);
	freeInstance(instance_B);
	freeInstance(instance_query);
	
	if(result == NULL)	{
		return 1;
	} else {
		return 0;
	}
}