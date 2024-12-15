/*--------------------------------------------------------------------------
 			NAME		: D.VENKAT
 			DESCRIPTION	: SAVE THE CONTENT TO DATABASE 
			DATE		: 26/09/2024
 ---------------------------------------------------------------------------
 */
#include "main.h"
/* function to save database */
Status save_database(main_node **arr,char *file_name)
{
    FILE *fptr = fopen(file_name, "w");
    if(fptr == NULL)
    {
        printf("INFO : Error while opening %s file",file_name);
        return e_failure;
    }
    /* iterate upto array size */
    for(int index = 0;index < SIZE_ARR;index++)
    {
        main_node *temp = arr[index];
        while (temp != NULL)
        {
            fprintf(fptr, "%s" , "#");
	    fprintf(fptr, "%d;" , index);
	    fprintf(fptr, "%s;" , temp->word);
	    fprintf(fptr, "%d;" , temp->file_count);
            sub_node *stemp = temp->sub;
            while (stemp != NULL)
            {
                fprintf(fptr,"%s;",stemp->file_name);
	       	fprintf(fptr,"%d;",stemp->word_count);
		stemp = stemp->sub_link;
            }
            temp = temp->link;
            fprintf(fptr, "%s" , "#");
	    fprintf(fptr, "%s" , "\n"); 
        }
    }
    fclose(fptr);
    return e_success;
}
