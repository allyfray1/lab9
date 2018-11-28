#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_QUESTIONS_PER_STUDENT 11

void transfer_data_into_file(char *fname, char *fname2, char *csvFile);

/*
 *Location:     Temple University Computer Science
 * Programmer:  Allyson Fray
 * Class:       Introduction to C Programming 1057 Fall 2018 Section 007
 * Assignment:  Number 9 - Bubble CSV and GitHub
 * Date:        November 14, 2018
 * Version:     1
 * Description: combines two data files into one csv file
 */

int main()
{

	transfer_data_into_file("newomr.txt", "test_taker_names.txt", "full_data.csv");



	return EXIT_SUCCESS;

}

/*
 *Function:    transfer_data_into_file()
 *Programmer:  Allyson Fray
 *Date:        November 14, 2018
 *Inputs:      char *fname - name of first data file
 *             char *fname2 - name of second data file
 *             char *csvFile - name of csv file
 *Outputs:     None
 *Returns:     Nothing
 *Globals:     NUMBER_OF_QUESTIONS_PER_STUDENT - number of questions each student answered
 *Description: transfers all the data from the data files into the csv file in the correct format
 */

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
