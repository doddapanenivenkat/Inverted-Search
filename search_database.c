/*---------------------------------------------------------------------------
 		NAME		: D.VENKAT
 		DESCRIPTION	: SEARCH THE WORD FROM DATABASE
 		DATE		: 26/09/2024
 ----------------------------------------------------------------------------
 */
#include "main.h"
#include <string.h>
Status search_database(main_node **arr, char *word)
{
    int index = word[0];
    /* caluculate the index value */
    if(word[0] >= 'A' && word[0] <= 'Z')
    {
        index = word[0] - 'A';
    }
    else if(word[0] >= 'a' && word[0] <= 'z')
    {
        index = word[0] - 'a';
    }
    else if(word[0] >= '0' && word[0] <= '9')
    {
        index = 26;
    }
    else
    {
        index = 27;
    }
    /*if(arr[index] == NULL)
    {
        return DATA_NOT_FOUND;
    }*/
    main_node *temp = arr[index];
    /* till temp not equals to null */
    while (temp != NULL)
    {
        /* checking word is present or not */
        if(strcmp(temp->word,word) == e_success)
        {
            printf("\n[%d]",index);
            printf("\t%-15s",temp->word);
            printf("\t  %d",temp->file_count);
            //printf("[%d] [%s] %d files:\t",i,temp->word,temp->file_count);
            sub_node *temp_sub = temp->sub;
            while (temp_sub != NULL)
            {
                printf("\t  files  : %-15s  %d",temp_sub->file_name,temp_sub->word_count);
                //printf("%s %d\t",temp_sub->file_name, temp_sub->word_count);
                temp_sub = temp_sub->sub_link;
            }
            return e_success;
        }
        temp = temp->link;
    }

    //return data not found
    return DATA_NOT_FOUND;
}
