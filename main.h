#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1
#define DATA_NOT_FOUND -2
#define SIZE 20
#define SIZE_ARR 27

typedef enum
{
    e_success,
    e_failure
}Status;

typedef struct main
{
    int file_count;
    char word[SIZE];
    struct main *link;
    struct sub *sub;
}main_node;

typedef struct file
{
    char file[SIZE];
    struct file *link;
}file_t;

typedef struct sub
{
    int word_count;
    char file_name[SIZE];
    struct sub *sub_link;
}sub_node;

/*Create main node*/
main_node *create_main_node(char *);

/*Create sub node*/
sub_node *create_sub_node(char *);

/*Read and validate*/
Status read_and_validate(int, char *argv[],file_t **);

/*Open files*/
Status open_files(char *);

/*Create Database*/
Status create_database(main_node **, file_t **,int);

/*Display Database*/
Status display_database(main_node **head);

/*Search Database*/
Status search_database(main_node **arr,char *word);

/*Save Database*/
Status save_database(main_node **arr,char *file_name);

/*Update Database*/
Status update_database(main_node **arr,file_t **,int,int);


