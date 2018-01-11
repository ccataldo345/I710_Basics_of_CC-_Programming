#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()

{
    //############################################
    //read input file
	char fileName[] = "input.txt";
	
	FILE* file = fopen(fileName, "r");

	if (file == NULL) {
		printf("The file does not exist!\n");
		return -1;
	}
	
	long numChar = ftell(file);
	char textInput[] = malloc((numChar + 1) * sizeof(char));
	
	while (!feof(file)) {
		size_t count = fread(textInput, 1, sizeof(char), file);
		if (count < 1)
			break;
		//text[count] = "\0";	
	}
	
	printf("\nInput text: %s\n", textInput);	//print array text
  
	fclose(file);
	file = NULL;
	
	//############################################
	// convert char array textInput into Int array
    
    //char srt[50] = "1,3; 2,4; 0,-2; 3,11; 5,4";
    char* p = textInput;
    
    // count pairs
    int pairsCount = 0;
    while (*p) {
		if (*p++ == ',')
        pairsCount++;
    }

    int pairs[pairsCount][2];

	// remove ";" 
    p = strtok(textInput, ";");
    pairsCount = 0;
    while (p) {
        int index = 0, value = 0;
        if (sscanf(p, "%d,%d", &index, &value) == 2) {
            pairs[pairsCount][0] = index;
            pairs[pairsCount][1] = value;
            pairsCount++;
        }
        p = strtok(NULL, ";");
    }
    
    printf("Int array pairs[%d][2] = {", pairsCount);
    for ( int i=0 ; i<pairsCount; i++ ) {
		if (i==pairsCount-1) {
			// print last number without coma
			printf("{%d,%d}", pairs[i][0], pairs[i][1]);
		}
		else {
			printf("{%d,%d}, ", pairs[i][0], pairs[i][1]);
		}
    }
    printf("}");
    printf("\n");
    
    //############################################
    // sort pairs
    
    printf("Sorted pairs: ");
    int i, min0, min1;

    for (i=0; i<pairsCount; i++) {
		for (int j=i+1; j<pairsCount; j++) {
			if(pairs[i][0]>pairs[j][0]) {
				
				min0=pairs[i][0];
				pairs[i][0]=pairs[j][0];
				pairs[j][0]=min0;
		   
				min1=pairs[i][1];
				pairs[i][1]=pairs[j][1];
				pairs[j][1]=min1;
			}
		}
	}
	
	// printing sorted array	
	for (i=0; i <pairsCount; i++ ) {
		if (i==pairsCount-1) {
			// print last number without coma
			printf("%d,%d", pairs[i][0], pairs[i][1]);
		}
		else {
			printf ("%d,%d; ", pairs[i][0], pairs[i][1]) ;
		}
	}

	//############################################
	// print operation (valueP1 - value P0)
	
	printf("\n"); 
     
    printf("Output text: "); 
    for ( i=0; i<pairsCount-1; i++ ) {
		int outputText = pairs[i+1][1]-pairs[i][1];
		if (i==pairsCount-2) {
			// print last number without coma
			printf("%d", outputText);
		}
		else {
			printf("%d, ", outputText);
		}
	}

	//############################################
	// print to file 
	
	FILE *fptr;

	fptr = fopen("output.txt", "w"); 	// "w" = write to file
	//fptr = fopen("output.txt", "a"); 	// "a" = append to file
	if(fptr == NULL)
	{
		printf("Error!");
		return 1;
	}
   	
	for (int i=0; i<pairsCount-1; i++) {
		int outputText = pairs[i+1][1]-pairs[i][1];
		if (i == pairsCount-2) {
			fprintf(fptr, "%d", outputText);
		}
		else {
			fprintf(fptr, "%d, ", outputText);
		}
	}
	
	fclose(fptr);
		
	return 0;
 }