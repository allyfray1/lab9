#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_QUESTIONS_PER_STUDENT 11

void transfer_data_into_file(char *fname, char *fname2, char *csvFile);

int main()
{

	transfer_data_into_file("newomr.txt", "test_taker_names.txt", "full_data.csv");



	return EXIT_SUCCESS;

}

void transfer_data_into_file( char *fname, char *fname2, char *csvFile)
{

	FILE *IN = fopen( fname, "r");
	FILE *fp;
	int i;
	int j, count;
	int id;
	int omrId;
	double grade;
	char name[300];
	char scores[NUMBER_OF_QUESTIONS_PER_STUDENT];
	char key[NUMBER_OF_QUESTIONS_PER_STUDENT];
	FILE *NAMES = fopen(fname2, "r");


	fp = fopen(csvFile, "w+");

	fprintf(fp, "IDENTITY, NAME,Q1,Q2,Q3,Q4,Q5,Q6,Q7,Q8,Q9 ,Q10 ,Q11 ,GRADE\n ");

	fscanf(IN, "%d", &id);
	for( j = 0; j < NUMBER_OF_QUESTIONS_PER_STUDENT; j++)
	{
		fscanf( IN, "%c", &key[j]);
	}
		

	while(fscanf(IN, "%d", &id) == 1)
	{	
		fscanf(NAMES, "%d", &omrId);
		fscanf(NAMES, "%[^\n]", &name);
		count = 0;
		fprintf(fp, "%d,", id);	
		fprintf(fp, "%s,", name);
		
		for( i = 0; i < NUMBER_OF_QUESTIONS_PER_STUDENT; i++)
		{
			fscanf(IN, "%c", &scores[i]);
			fprintf(fp, "%c, ", scores[i]);
		
			if(scores[i] == key[i]){
				count++;
			}

		}
		
		grade = (count/11.00) * 100;
		fprintf(fp, "%.2lf%%\n", grade);
	}
	
	fclose(fp);
	printf("\n %s file created\n", csvFile);


}
