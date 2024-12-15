/*-------------------------------------------------------------------------------
 		NAME 		: D.VENKAT
 		DESCRIPTION	: DISPLAY CURRENT DATABASE
 		DATE 		: 26/09/2024
 --------------------------------------------------------------------------------
 */
#include "main.h"
/* function to display the contents */
Status display_database(main_node **arr)
{
    printf("[index]\t[word]\t\tfilecount file/s : file_name \tword_count\n");
    for(int i = 0;i < SIZE_ARR;i++)
    {
        main_node *temp = arr[i];
        while (temp != NULL)
        {
            printf("\n[%d]",i);
            printf("\t%-15s",temp->word);
            printf("\t  %d",temp->file_count);
            sub_node *temp_sub = temp->sub;
            while (temp_sub != NULL)
            {
                printf("\t  files  : %-15s  %d",temp_sub->file_name,temp_sub->word_count);
                temp_sub = temp_sub->sub_link;
            }
            printf("\n");
            temp = temp->link;
        }
    }
    return e_success;
}
