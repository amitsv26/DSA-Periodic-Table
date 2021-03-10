#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<math.h>

struct node
{
	int atnu;
	char atsl[5];
	char atom[20];
	struct node *link;	
}stud;
typedef struct node *NODE;

NODE insertFront(int no,char sym[],char name[], NODE first) 
{
	NODE temp;
	temp = (NODE*)malloc(sizeof(NODE));
	 FILE *fp;
 	fp = fopen("Record.txt", "a");
	if(temp!=NULL)
	{
		temp->atnu = no;
		strcpy(temp->atsl,sym);
		strcpy(temp->atom,name);
		temp->link = first;
		//return temp;
	}	
	else
	{
		printf("\n Insufficient  Memory");
		exit(0);
	}

	 fwrite(&stud, sizeof(stud), 1, fp);
 	 fclose(fp);
	 return temp;
}

/*void insert(NODE first)
{
 FILE *fp;
 fp = fopen("Record", "a");
 printf("Enter the Roll no   :");
 scanf("%d", &stud.rollno);
 printf("Enter the Name      :");
 scanf("%s", &stud.name);
 printf("Enter the mark      :");
 scanf("%f", &stud.mark);
 fwrite(&first, sizeof(first), 1, fp);
 fclose(fp);
}*/


void displayLinkedList(NODE first)
{
	NODE current = NULL;
	 FILE *fp1;
	 fp1 = fopen("Record.txt", "r");
	if(first == NULL)
	{
		printf("\n Nothing to display, Linked list is empty !! \n");
	}
	else
	{
		current = first;
		//current = stud;
		while (fread(&stud, sizeof(stud), 1, fp1))
		while(current != NULL)
		{
			printf("Details of elements:\n");
			printf("%d\t%s\t%s",current->atnu,current->atsl,current->atom);
			current = current->link;
		}
		fclose(fp1);
	}

}

/*void disp()
{
 FILE *fp1;
 fp1 = fopen("Record", "r");
 printf("\nRoll Number\tName\tMark\n\n");
 while (fread(&stud, sizeof(stud), 1, fp1))
 printf("  %d\t\t%s\t%.2f\n", stud.rollno, stud.name, stud.mark);
 fclose(fp1);
}
/*void searchLinkedList(int key, NODE first)
{
	NODE current = NULL;
	current = first;
	int found = 0;
	
	if(first == NULL)
		printf("\n Linked list is empty \n");
	else
	{
		while(current != NULL)
		{
			if(current->data == key)
			{
				found=1;
				break;
			}
			current = current->link;
		}
		
		if(found == 1)
			printf("\n Element %d found in the linked list \n",key);
		else
			printf("\n Element %d could not be found in the linked list \n",key);
	}
}*/



int main()
{
	NODE first = NULL;
	int no,choice;
	char sym[5],name[20];
	while(1>0)
	{
		printf("\n LINKED LIST IMPLEMENTATION \n");
		printf("\n 1) Insert at front end  \n");
		printf("\n 2) Display \n");
		printf("\n 3) Search \n");
		printf("\n 4) Exit \n");
		printf("\n Enter your choice : \n");
		scanf("%d",&choice);
	
		switch(choice)
		{
			case 1:
				printf("\n Enter the atomic number, atomic Symbol and atomic name of element respectively: \n");
        			scanf("%d%s%s",&no,sym,name); 
				first = insertFront(no,sym,name,first);
				//insert(first);
				break;
			case 2:
				displayLinkedList(first);
				break;
			/*case 3:
				printf("\n Enter the element to be searched in the linked list : \n");
                                scanf("%d",&element);
				searchLinkedList(element,first);
				break;*/
			case 4:
				exit(0);
				break;
		}

	}
}
