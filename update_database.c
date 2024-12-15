/*-----------------------------------------------------------------------------------------
 		NAME		: D.VENKAT
 		DESCRIPTION 	: UPDATE THE FILES TO DATABASE
 		DATE		: 26/09/2024
-------------------------------------------------------------------------------------------
*/
#include"main.h"
#include <string.h>
/*Function to remove the files that already present in backup file*/
int remove_(file_t**head,char*file){
   file_t*temp=*head,*prev=NULL;
   while(temp){
      if(strcmp(temp->file,file)==0){
        if(temp==*head){
            (*head)=(*head)->link;
            return 1;
        }
        prev->link=temp->link;
        free(temp);
        return 1;
      }
      prev=temp;
      temp=temp->link;
   }
}
/*Updating the backup content to the structure*/
Status update_database(main_node**arr,file_t**head,int f,int flag){
    if(flag == 1 || f == 1) 
    {
        printf("Database already is created\n");
        return FAILURE;
    }
    char backup[20];
    printf("\nEnter the backup file name: ");
    scanf("%s",backup);
    if(strcmp(strstr(backup,"."),".txt")!=0) return FAILURE;
    FILE*fptr=fopen(backup,"r");
    if(fptr==NULL) return FAILURE;
    char ch=fgetc(fptr),k;
    //fseek(fptr,-1,SEEK_END);
    //k=fgetc(fptr);
    if(ch!='#') return FAILURE;
    rewind(fptr);
    f=1;
    char str[100];
    char *ind,word[20];
    int i,file_cnt;
    while(fscanf(fptr,"%s",str)!=EOF){
        main_node*new=malloc(sizeof(main_node)); 
        ind=strtok(str,"#;");
        i=atoi(ind);
        char *k=strtok('\0',";");
        strcpy(word,k);
        char *l=strtok('\0',";");
        file_cnt=atoi(l);
        sub_node*snew=malloc(sizeof(sub_node)),*temp=snew;
        char *file_name=strtok('\0',";");
        strcpy(snew->file_name,file_name);
        remove_(head,snew->file_name);
        char*m=strtok('\0',";");
        snew->word_count=atoi(m);
        new->file_count=file_cnt;
        new->link=NULL;
        new->sub=snew;
        strcpy(new->word,word);
        if(file_cnt>1){
            for(int m=1;m<file_cnt;m++){
                sub_node*snew=malloc(sizeof(sub_node));
                char *file_name=strtok('\0',";");
                strcpy(snew->file_name,file_name);
                remove_(head,snew->file_name);
                char*l=strtok('\0',";#");
                snew->word_count=atoi(l);
                temp->sub_link=snew;
                temp=temp->sub_link;
            }
        }
        /*Creating new main node*/
        if(arr[i]==NULL)
            arr[i]=new;
        else{
            main_node*temp=arr[i],*prev=NULL;
            while(temp){
                prev=temp;
                temp=temp->link;
            }
            prev->link=new;
        }
    }
    return SUCCESS;
    //printf("%s",word);
}
