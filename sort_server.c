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
#define __USE_C99_MATH

#include <stdbool.h>
#define MAX 40

// ########################Bubble sort##################################
Array *
bsort_1_svc(Array *argp, struct svc_req *rqstp)
{
	static Array  result;
	int i=0;  int j=0, k=0;   bool swapped;
	int m=0; char new_char[m];
	while(argp->val[i]!=NULL){ 
	result.val[i] = argp->val[i];
	i++;	
	}
	int new[i]; int x=0;
	for(x=0;x<i;x++)
	{
		new[x]=(int)(argp->val[x]);
	}	
	for (k = 0; k < i; k++)    {     
       for (j = 0; j < i-k; j++) { 
          if (new[j] > new[j+1]) {
             int temp = new[j]; 
				new[j] = new[j+1]; 
				new[j+1] = temp; 
			 swapped = true; 
		  }
	   }
		   if (swapped == false) 
			break;
	}	 
	for (m = 0; m < i; m++){
	  new_char[m] = (char) new[m];
	  result.val[m] = new_char[m];
	}

	return &result;
}
// #################Iterative version of merge sort #######################
Array *
msort_2_svc(Array *argp, struct svc_req *rqstp)
{
	static Array  result;
	int i=0;  int j=0, k=0,temp,g; 
	while(argp->val[i]!=NULL){ 
	result.val[i] = argp->val[i];
	i++;	
	}
	int new[i]; int x=0;
	for(x=0;x<i;x++)
	{
		new[x]=(int)(argp->val[x]);
	}	
	for(k=1;k<i;k++)
	{
		temp = new[k];
		j=k-1;
		while(temp<new[j] && j>=0)
		{
			new[j+1] = new[j];
			--j;
		}
		new[j+1]=temp;
	}
	int new_char[i];
	for (g = 0; g < i; g++){
	  new_char[g] = (char) new[g];
	  result.val[g] = new_char[g];
	}
	return &result;
}
