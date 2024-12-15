/*--------------------------------------------------------------------------------------------
 			NAME		: D.VENKAT
 			DESCRIPTION	: CREATE THE DATABASE FROM THE INPUT FILE
 			DATE 		: 26/09/2024
 ---------------------------------------------------------------------------------------------
 */
#include "main.h"
#include <string.h>
Status create_database(main_node **arr,file_t **head,int flag)
{
    if(flag)
    {
        printf("INFO : Database is already created\n");
        return e_failure;
    }
    file_t *temp = *head;
    while(temp)
    {
        FILE *fptr = fopen(temp->file,"r");
        if(fptr == NULL)
        {
            printf("INFO : Error while opening %s file\n",temp->file);
            return e_failure;
        }
        char word[SIZE];
        int index = 0;
        while(fscanf(fptr, "%s" , word) != EOF)
        {
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

            if(arr[index] == NULL)
            {
                main_node *new_main_node = create_main_node(word);
                sub_node *new_sub_node = create_sub_node(temp->file);

                new_main_node->sub = new_sub_node;
                arr[index] = new_main_node;
            }
            else if(arr[index] != NULL)
            {
                int flag = 0,var = 0;
                main_node *temp1 = arr[index],*prev = NULL;
                while (temp1 != NULL)
                {
                    if(strcmp(temp1->word,word) == e_success)
                    {
                        var = 1;
                        sub_node *temp_sub = temp1->sub;
                        sub_node *temp_prev = NULL;
                        while(temp_sub)
                        {
                            if(strcmp(temp_sub->file_name,temp->file) == e_success)
                            {
                                temp_sub->word_count++;
                                flag = 1;
                                break;
                            }
                            temp_prev= temp_sub;
                            temp_sub = temp_sub->sub_link;
                        }
                        if(flag == 0)
                        {
                            sub_node *new_sub = create_sub_node(temp->file);
                            temp_prev->sub_link = new_sub;
                            temp1->file_count++;
                            break;
                        }
                    }
                    prev = temp1;
                    temp1 = temp1->link;
                    if(var == 0)
                    {
                        
                        main_node *new_main_node = create_main_node(word);
                        sub_node *new_sub_node = create_sub_node(temp->file);
                        new_main_node->sub = new_sub_node;
                        prev->link = new_main_node;
                    }
                }
            }   
        }
        fclose(fptr);
        temp = temp->link;
    }
    return e_success;
}
main_node *create_main_node(char *word)
{
    main_node *new_main_node = malloc(sizeof(main_node));
    if(new_main_node == NULL)
    {
        return new_main_node;
    }
    strcpy(new_main_node->word,word);
    new_main_node->file_count = 1;
    new_main_node->link = NULL;
    return new_main_node;
}

sub_node *create_sub_node(char *file)
{
    sub_node *new_sub_node = malloc(sizeof(sub_node));
    if(new_sub_node == NULL)
    {
        return new_sub_node;
    }
    new_sub_node->sub_link = NULL;
    strcpy(new_sub_node->file_name,file);
    new_sub_node->word_count = 1;
    return new_sub_node;
}
