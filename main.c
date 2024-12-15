/*----------------------------------------------------------------------------------
 		NAME 		: D.VENKAT
 		DESCRIPTION	: INVERTED SEARCH
 		DATE 		: 26/09/2024
------------------------------------------------------------------------------------
*/
#include "main.h"
#include <string.h>

int main(int argc, char *argv[])
{
    main_node *arr[SIZE_ARR] = {NULL}; 
    file_t *head = NULL;
    if(read_and_validate(argc,argv,&head) == e_success){
    int option,result,flag = 0,flag1 = 0,flag2 = 0;
    while (1)
    {
        printf("Select your choice :\n1. Create DataBase\n2. Search DataBase\n3. Update DataBase\n4. Save DataBase\n5. Display DataBase\n6. Exit\nEnter option : ");
        scanf("%d",&option);
        switch (option)
        {
            case 1:
                if(create_database(arr,&head,flag) == e_failure){
                    printf("DataBase not created\n");
                }
                else{
                    printf("Create DataBase Successfully Done\n");
                }
                flag = 1;
                break;
            case 2:
                printf("Enter word to search\n");
                char word[SIZE];
                printf("Enter the word to search : ");
                scanf("%s",word);
                result = search_database(arr,word);
                if (result == DATA_NOT_FOUND)
				{
					printf("INFO : Data not found\n");
				}
				else
				{
					printf("\nINFO : Data found\n");
				}
                break;
            case 3:
                if(update_database(arr,&head,flag1,flag) == SUCCESS)
                {
                    printf("INFO : Database updated successfully\n");
                }
                else{
                    printf("INFO : Database not updated\n");
                }
                //flag1 = 1;
                break;
            case 4:
                printf("Enter the filename you want save in database \n");
                char file_name[SIZE];
                scanf("%s", file_name);
                if(strcmp((strstr(file_name,".")),".txt") == e_success)
                {
                    if(save_database(arr,file_name) == e_success)
                    {
                        printf("INFO : Database saved successfully in %s\n", file_name);
                    }
                    else{
                        printf("INFO : Database not saved successfully in %s\n",file_name);
                    }
                }
                else{
                    printf("INFO : %s file have doesn't have .txt\n",file_name);
                }
                break;
            case 5:
                display_database(arr);
                break;
            case 6:
                exit(0);
                break;
        default:
            printf("Enter proper choice!!\n");
            break;
        }
    }
    }
}
Status read_and_validate(int argc, char *argv[], file_t **head)
{
    int flag = 0;
    if(argc > 1)
    {
        for(int i = 1;i < argc;i++)
        {
            if(open_files(argv[i]) == e_success)
            {
                file_t *new = malloc(sizeof(file_t));
                if(*head == NULL)
                {
                    *head = new;
                    strcpy(new->file,argv[i]);
                    new->link = NULL;
                }
                else
                {
                    file_t *temp,*prev;
                    temp = *head;
                    while (temp)
                    {
                        if(strcmp(temp->file,argv[i]) == e_success)
                        {
                            printf("INFO : %s file is duplicate\n",argv[i]);
                            flag = 1;
                            break;
                        }
                        prev = temp;
                        temp = temp->link;
                    }
                    if(flag == 0)
                    {
                        strcpy(new->file,argv[i]);
                        prev->link = new;
                        new->link = NULL;
                    }
                    flag = 0;
                }
            }
        }
        printf("INFO : Open files have successfull\n");
        return e_success;
    }
    else
    {
        printf("INFO : Insufficinet arguments\n");
        return FAILURE;
    }
}

Status open_files(char *argv)
{
    FILE *fptr = fopen(argv,"r");
    if(fptr == NULL)
    {
        printf("INFO : Cannot open file %s\n",argv);
        return e_failure;
    }
    if(fptr != NULL)
    {
        if(strcmp((strstr(argv,".")),".txt") == e_success)
        {
            fseek(fptr, 0, SEEK_END);
            if(ftell(fptr) != e_success)
            {
                fclose(fptr);
                return e_success;
            }
            else{
                printf("INFO : file is Empty %s\n",argv);
                return e_success;
            }
        }
        else{
            printf("INFO : %s file have doesn't have .txt\n",argv);
            return e_success;
        }
    }
}
