/* Priya Gupta 
	L20444930 
	RPC Sort Program
	COSC_5302_02_1 - Adv Operating Systems_AUG_27  
*/

/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "sort.h"

void
sort_prog_1(char *host)
{
	CLIENT *clnt;
	Array  *result_1;
	Array  *result_2;
	Array  *result_3;
	Array  bsort_1_arg;
	FILE *file; FILE *file1;
	int lower = 33, upper = 126,count=0,num[40],i=0,k=0;
	int upper1=40, lower1=15;
	char temp[40];
	
#ifndef	DEBUG
	clnt = clnt_create (host, SORT_PROG, Bubble_Sort_algo, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	//##############################Creating file and writing randomly generated ASCII charaters####################################################
	file = fopen("input.txt","w");
	while(k<3){
		//generate variable length for each array
		count = (rand() % (upper1 - lower1 + 1)) + lower1;
	for (i = 0; i < count; i++) { 
		//generate random integer value for each array
        num[i] = (rand() % (upper - lower + 1)) + lower;
		temp[i] = (char)num[i];
		fprintf(file, "%c",temp[i]);
	}
		fprintf(file, "\n"); // For 
		k++;
	}
	fclose(file);
	//##################################Taking Input from file and sending to the server#################################################################
	file1 = fopen("input.txt","r");
	int j=0, x=0, itr=0;
	size_t len = 0;
	char * line = NULL;
	ssize_t read;
	if (file1 == NULL)
        exit(EXIT_FAILURE);
	  while ((read = getline(&line, &len, file1)) != -1) {
		  itr++;
        //printf("Retrieved line of length %zu :\n", read);
        //printf("%s", line);
		if(itr==1){printf("\n");}
		printf("Line %d randomly generated with the length %zu:\n",itr,read);
		while(x <= read ) {
			bsort_1_arg.val[x] = (char)*(line+x);
			// print the unsorted char array sending to server
			printf("%c",bsort_1_arg.val[x]);
			x++;	
		}
		x=0;
		//sending the array to the server
		printf("Line %d after sorting:",itr);
		if(itr==1){
			result_1 = bsort_1(&bsort_1_arg, clnt);
				for (j = 0; j < read; j++) { 
					char c1=(char)(result_1->val[j]);
					printf("%c",c1);
					} 
					printf("\n");
					printf("\n");
		}
		if(itr==2){
			result_2 = bsort_1(&bsort_1_arg, clnt);
				for (j = 0; j < read; j++) { 
					char c1=(char)(result_2->val[j]);
					printf("%c",c1);
					} 
					printf("\n");
					printf("\n");		
		}
		if(itr==3){
			result_3 = bsort_1(&bsort_1_arg, clnt);
				for (j = 0; j < read; j++) { 
					char c1=(char)(result_3->val[j]);
					printf("%c",c1);
					}
					printf("\n");
					printf("\n");					
		}
    }
	
	if (result_1 == (Array *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	if (result_2 == (Array *) NULL) {
		clnt_perror (clnt, "call failed");
	}if (result_3 == (Array *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
	fclose(file1);
#endif	 /* DEBUG */


}

void
sort_prog_2(char *host)
{
	CLIENT *clnt;
	Array  *result_1;
	Array  *result_2;
	Array  *result_3;
	Array  msort_2_arg;
	FILE *file; FILE *file1;
	int lower = 33, upper = 126,count=0,num[40],i=0,k=0;
	int upper1=40, lower1=15;
	char temp[40];

#ifndef	DEBUG
	clnt = clnt_create (host, SORT_PROG, Merge_Sort_algo, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	file = fopen("input.txt","w");
	while(k<3){
		//generate variable length for each array
		count = (rand() % (upper1 - lower1 + 1)) + lower1;
	for (i = 0; i < count; i++) { 
		//generate random integer value for each array
        num[i] = (rand() % (upper - lower + 1)) + lower;
		temp[i] = (char)num[i];
		fprintf(file, "%c",temp[i]);
	}
		fprintf(file, "\n"); // For next line in the file
		k++;
	}
	fclose(file);
	//#################################Taking Input from file and sending to the server#########################################################
	file1 = fopen("input.txt","r");
	int j=0, x=0, itr=0;
	size_t len = 0;
	char * line = NULL;
	ssize_t read;
	if (file1 == NULL)
        exit(EXIT_FAILURE);
	  while ((read = getline(&line, &len, file1)) != -1) {
		  itr++;
        //printf("Retrieved line of length %zu :\n", read);
        //printf("%s", line);
		printf("Line %d randomly generated with the length %zu:\n",itr,read);
		while(x <= read ) {
			msort_2_arg.val[x] = (char)*(line+x);
			// print the unsorted char array sending to server
			printf("%c",msort_2_arg.val[x]);
			x++;	
		}
		x=0;
		//sending the array to the server
		printf("Line %d after sorting:",itr);
		if(itr==1){
			result_1 = bsort_1(&msort_2_arg, clnt);
				for (j = 0; j < read; j++) { 
					char c1=(char)(result_1->val[j]);
					printf("%c",c1);
					} 
					printf("\n");
					printf("\n");
			
		}
		if(itr==2){
			result_2 = bsort_1(&msort_2_arg, clnt);
				for (j = 0; j < read; j++) { 
					char c1=(char)(result_2->val[j]);
					printf("%c",c1);
					} 
					printf("\n");
					printf("\n");
					
		}
		if(itr==3){
			result_3 = bsort_1(&msort_2_arg, clnt);
				for (j = 0; j < read; j++) { 
					char c1=(char)(result_3->val[j]);
					printf("%c",c1);
					}
					printf("\n");
					printf("\n");
					
		}
		
	
    }
	if (result_1 == (Array *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	if (result_2 == (Array *) NULL) {
		clnt_perror (clnt, "call failed");
	}if (result_3 == (Array *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
	fclose(file1);
#endif	 /* DEBUG */
}

int
main (int argc, char *argv[])
{
	char *host;
	char a;  
	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	printf("Select the algorithm Bubble or Merge (B/M)");
	scanf("%c", &a);
	if (a == 'B'){
		sort_prog_1 (host);
	}
	else{
		sort_prog_2 (host);
	}
exit (0);
}