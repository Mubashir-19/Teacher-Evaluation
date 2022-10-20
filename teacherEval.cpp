#include <iostream>
#include<stdio.h>
#include<conio.h>
#include <string.h>
#include<windows.h>
#include <string.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}


struct teacher_evaluation {
	char Name[20];
	char subj[20];
	char rating[10];
	char remarks[500];
	
} t1, t2,t3;


#define MAX_LINE 1024

#define MAX 100
char filename[60];
FILE *file, *fptr, *temp;
char c,d;
bool decision = false;

void Evaluation() {
	
	int i;
	
	char oldtext[500];
	//char str_marks[MAX];
	float marks = 0.0;
	
	
	bool update = false;
	
	//char buffer[MAX_LINE];
	
	//char buf[256];
	
	
	char eval[15][200] = {
				  "1) Teacher is prepared for class ", 
				  "2) the Teacher knows his/her subject ",
				  "3) Teacher is organized and neat ",
				  "4) Teacher plans class time and assignments that help students to problem solve and think critically ",
				  "5) Teacher provides activities that make subject matter meaningful ",
				  "6) Teacher is flexible in accommodating for individual student needs ",
				  "7) Teacher is clear in giving directions and on explaining what is expected on assignments and tests ",
				  "8) Teacher allows you to be active in the classroom learning environment ",
				  "9) Teacher arrives in class on time ",
				  "10) Teacher leaves class on time ",
				  "11) Teacher grades fairly ",
				  "12) I have learned a lot from this teacher about this subject ",
				  "13) Teacher gives me good feedback on homework and projects so that I can improve ",
				  "14) Teacher is creative in developing activities and lessons ",
				  "15) Teacher encourages students to speak up and be active in the class "
				};
		
	printf("\n\n_________________Teacher Evaluation Form_________________\n\n");	
	
	do {
		
		fflush(stdin);
		
		printf("\nEnter Teacher Name: ");
		gets(t1.Name);
	
		printf("\nWhat Subject does He/She teaches you ? ");
		gets(t1.subj);
		
		printf("Did you put the names right ? (Enter y or n): ");
		d = getchar();
		
		if ( d == 'y'){
			decision = true;
		}
		
	}while (decision = false);
	
	//char name[1000];
	
	//for(i = 0; i < strlen(t1.Name); i++) {
		
  	//	name[i] = tolower(t1.Name[i]);
	//}
	
	//strcat(name, " ");
	//strcat(name, t1.subj);
	
	
	//printf("name: %s, name length: %d",name, strlen(name));
	
	//char subtext[strlen(name)+1];
	
	
	/*
	line = 0;
	while (fgets(buf, sizeof(buf), file) != NULL) {
    	fflush(stdin);
    	
    	strncpy(subtext,&buf[0],strlen(name));
    	
    	subtext[strlen(name)] = '\0';
		
		printf("\nline: %s,  line size: %d,name: %s, subtext: %s\n", buf, strlen(buf),name, subtext);
		
		if (strcmp(name, subtext) == 0) {
			update = true;
			printf("\n\n %s \n\n", strncpy(subtext,&buf[strlen(name)+1],));
			//strncpy(subtext,&buf[strlen(name)],);
		}
		line++;
		//printf("%s and length: %d\n\n",buf,strlen(buf));
	}*/
	
	
	
	
		
		// file = fopen("data.txt", "r");
		
		printf("\n\nInstructions:  \n");
		printf("	1) Answer with s if you Strongly Agree. \n");
		printf("	2) Answer with a if you Agree. \n");
		printf("	3) Answer with n if you are not sure (Neutral). \n");
		printf("	4) Answer with d if you Disagree. \n");
		printf("	5) Answer with D if you Strongly Disagree. \n");
		
		for ( i=0; i<14; i++ ) {
			
			fflush(stdin);
			
			printf("\n%s", eval[i]);
			c = getchar();
			
			switch(c) {
				case('s'):
					marks += 01.000;
					
					break;
				case('a'):
					marks += 00.750;
					break;
				case('n'):
					marks += 00.500;
					break;
				case('d'):
					marks += 00.250;
					break;
			}
			printf("\nMarks: %.2f\n", marks);
			
		}
		
		float rating_per = (marks*10)/14;
		
		fflush(stdin);
		
		printf("Anything you want to say to the teacher ? (Enter 0 if you dont want to.): ");
		
		
		gets(t1.remarks);
		
		t1.remarks[strlen(t1.remarks)] = '\0';
		strcat(t1.remarks, "\n");
		
		
		/*
		bool keep_reading = true;
		
		do{
			fgets(buffer, MAX_LINE, file)
			
			for (i=0;i<strlen(a);i++){
				strcat(b[i],buffer[i]);
			}
			printf("a:  %s,  b:  %s",a,b);
			
			if (feof(file)) {
				keep_reading = false;
			}else if (strcmp(a,b) != 0) {
				
			}else{
			
				
			}
			
		}while(keep_reading);*/
		
		file = fopen("data.txt", "r+");
		temp = fopen("temp.txt", "a+");
		
		while(fread(&t2,sizeof(t2),1,file)){
			
			if (strcmp(t2.Name, t1.Name) == 0 && strcmp(t2.subj, t1.subj) == 0) {
				
				float marks2 = atof(t2.rating);
				
				float newmarks = (marks2+rating_per)/2;
				
				
				sprintf (t2.rating, "%.2f", newmarks);
				
				sprintf (t1.rating, "%.2f", rating_per);
				
				
				printf("%s %s %s %s", t1.Name,t1.subj,t1.rating,t2.remarks);
				
				printf("\n%s %s %s %s\n", t2.Name,t2.subj,t2.rating,t1.remarks);
				
				strcat(oldtext,t2.remarks);
				strcat(oldtext," \n");
				
				strcpy(t2.remarks,t1.remarks);
				fflush(stdin);
				fwrite(&t2,sizeof(t2),1,temp);
				
				strcat(filename, t1.Name);
				strcat(filename, "_");
				strcat(filename, t1.subj);
				strcat(filename, ".txt");
				
				fptr = fopen(filename, "a+");
				
				fseek (fptr, 0, SEEK_END);
    			int size = ftell(fptr);
    			
    			if (size == 0) {
    				fputs(oldtext, fptr);
    				fputs(t1.remarks, fptr);
				}else {
					fputs(t1.remarks, fptr);
				}
    			
				fclose(fptr);
				
				update = true;
				
			}else {
				fwrite(&t2,sizeof(t2),1,temp);
			}
			
		}
		fclose(temp);
		fclose(file);
		
		remove("data.txt");
		rename("temp.txt","data.txt");
		
		if (update == false) {
			sprintf (t1.rating, "%.2f", rating_per);
			file = fopen("data.txt", "a+");
			
			fwrite(&t1,sizeof(t1),1,file);
			
			fclose(file);
		}
		

	
}

void Reviews() {
	filename[60] = '\0';
	
	c = '\0';
	d = '\0';
	decision = false;
	
	do {
		
		fflush(stdin);
		
		printf("\nEnter Teacher Name: ");
		gets(t1.Name);
	
		printf("\nWhat Subject does He/She teaches you ? ");
		gets(t1.subj);
		
		printf("Did you put the names right? (Enter y if yes and n if you want to re-enter): ");
		d = getchar();
		
		switch(d) {
			case('y'): 
				decision = true;
				break;
			default:
				continue;
		}
		
	}while (decision = false);
	
	strcat(filename, t1.Name);
	strcat(filename, "_");
	strcat(filename, t1.subj);
	strcat(filename, ".txt");
	
   fptr = fopen(filename , "r");
   
   if(fptr == NULL) {
      perror("Error opening file");
   }else {
   	   	c = fgetc(fptr);
   	   
    	while (c != EOF)
    	{
        	printf ("%c", c);
        	c = fgetc(fptr);
    	}
   }
   fclose(fptr);
	
}

void Read() {
	char ch;
	char Buffer[1000];
	FILE *fptr;
	fptr = fopen("data.txt", "r+");
	
	if (fptr == NULL) {
		printf("Sorry But the file does not exist !");	
	}else {
		while(fread(&t1,sizeof(t1),1,fptr) == 1){
			printf("%s %s %s %s", t1.Name,t1.subj,t1.rating,t1.remarks);
		}		
	}
	fclose(fptr);
	
}

int main() {
	char a;
	bool program = true;
	
	printf( "Enter 1 to Evaluate Teacher.\n" );
	
	printf( "Enter 2 to Read Data.\n" );
	
	printf( "Enter 3 to Read Reviews.\n" );
	
	printf("Enter 0 to Exit\n");
	
	do{
		fflush(stdin);
		
		printf("\n\n Enter Number Here: ");
		a = getchar();
		
		switch(a) {
			case('1'): 
				Evaluation();
				break;
			case('2'):
				Read();
				break;
			case('3'):
				Reviews();
				break;	
			default:
				program=false;
				break;
		}
	}while(program);
	
	return 0;
}


/*
#include <iostream>
#include<stdio.h>
#include<conio.h>
#include <string.h>
#include<windows.h>
#include <string.h>
#include <stdlib.h>
 run this program using the console pauser or add your own getch, system("pause") or input loop 


void gotoxy(int x, int y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}


int evaluate() {
	
	char a,ch;
	
	int i = 0;
	
	const char y = 'y';
	const char n = 'n';
	
	
	
	const char arr[20][120] = {
						"Is the teacher prepared for each class", 
						"Teacher demonstrates knowledge of the Subject",
						"The Teacher has completed the whole course",  
						"The instructor provides additional material apart from the textbook",
						"The instructor gives citations regarding current situations with reference to Pakistani context",
						"The instructor communicates the subject matter effectively",
						"The instructor shows respect towards students and encourages class participation",
						"The instructor maintains an environment that is conductive to learning",
						"The instructor arrives on time",
						"The instructor is fair in examination"};
						
					

	
	gotoxy(40, 12.5);
	printf("Teacher Evaluation Form\n\n");
	
	printf("Note: i) Answer should be 'y' or 'n'\n");
	printf("      ii) Each answer carry 1 mark\n");
	printf("      iii) Total 10 Questions will be asked\n");
	
	
	
	printf("    Start\n\n");
	
	int marks = 0;
	
	while ( i < 10) {
		printf(" %d) %s: ",i+1, arr[i]);
		scanf("%s", &a);
		
		switch(a)
			{
				case(y):
					marks++;
					break;
				case(n):
					break;	
				default:
					i--;
					break;
			}		
		i++;
	}
	
	printf("Marks: %d", marks);
	
	return marks;
}

int main() {
	
	
	bool end = true;
	
	printf("Enter 0 to exit the program\n");
		
	printf("Enter 1 for Evaluation of Teacher\n");
	
	printf("Enter 2 for Evaluation of Student\n");
	
	int i = 0;
	
	while(end == true) {
		int a;
		
		if ( i > 0) {
			printf("\n\nEnter Number here: ");
			scanf( "%d", &a);
		}else {
			printf("Enter Number here: ");
			scanf( "%d", &a);
		}
		
		
		
		if (a == 0) {
		
			end = false;
		}
		else if (a == 1) {
		
				FILE *fpointer;
				
				
				char name[30], teacher[20], score[3], data[50],name1[20];
				
				printf("%d) Your Name:",i);
				scanf("%s", &name);

				strcpy(name1,name);
				
				printf("%d) Teacher Name: ",i);
				scanf("%s", &teacher);
				
				strcat(name,".txt");
				
				
				sprintf(score, "%d", evaluate());
				
				strcat(data, "   ");
				strcat(data, strcat(name1, "   "));
				strcat(data, strcat(teacher, "   "));
				strcat(data, strcat(score, "  \n"));
				
				fpointer = fopen(name, "w+");
				
				
				
				int c = fgetc(fpointer);
				
				if (c == EOF && i == 0) {
					
					fputs("  _Student_  _Teacher_  _Evaluation Score_ \n" ,fpointer);
					
					fputs(data,fpointer);
					
					fclose(fpointer);
					
				}else if ( i > 0 ){
					
					fclose(fpointer);
					
					fpointer = fopen(name, "a");
					
					fputs(data,fpointer);
					
					fclose(fpointer);
				}
				
		}else {
		
		
				printf("Please Enter Correct Value");
				break;	
		}
		i++;	
	}
	
	
	
}





	
	
	
	
	char full_name[26], firstname[12], lastname[12]; 
	
	printf("Enter FullName: ");
	gets(full_name);
	
	int i;
	int space = 0;
	
	const char chr = ' ';  
	
	strncat(full_name, &chr, 1);
	
	for (i=0;i<strlen(full_name);i++) {
		
		printf("fullname %d = %c\n", i, full_name[i] );
		
		if (full_name[i] != ' ' && space == 0){
	
			strncat(firstname, &full_name[i], 1);
			
		}else if (full_name[i] != ' ' && space == 1){
			
			strncat(lastname, &full_name[i], 1);
			
		}else if (full_name[i] == ' ') {
			space++;
			
		}else {
			break;
		}
		
	}
	
	printf("%s %s", firstname, lastname);

	return 0;
	
	
	
	
	*/
