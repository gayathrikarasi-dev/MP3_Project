/* Name : K.Gayathri
   Date : 06-jan-2026
   Description : mp3_view.c */
#include "mp3_header.h"  // user-defined header file
int validate_cla(int argc, char *argv[], struct MP3 *mp3)
{
    if( argc == 1 ) //name entered
    {
		printf("------------------------------------------------------------------------------\n");
		printf("ERROR: ./a.out : INVALID ARGUMENTS\n");
		printf("USAGE : To view please pass like: ./a.out -v mp3filename\n");
		printf("To edit please pass like: ./a.out -e -t/-a/-A/-m/-y/-c changing_text mp3filename\n");
		printf("To get help pass like : ./a.out --help\n");
		printf("------------------------------------------------------------------------------\n");
		return 0;
    }

    if( (strcmp(argv[1], "--help") == 0) ) //help option 
    {
		printf("------------------------------->HELP<-----------------------------------------\n");
		printf("1. -v -> to view mp3 file contents\n");
		printf("2. -e -> to edit mp3 file contents\n");
		printf("\t\t2.1. -t -> to edit song title\n");
		printf("\t\t2.2. -a -> to edit artist name\n");
		printf("\t\t2.3. -A -> to edit album name\n");
		printf("\t\t2.4. -y -> to edit year\n");
		printf("\t\t2.5. -m -> to edit content\n");
		printf("\t\t2.6. -c -> to edit comment\n");
		printf("------------------------------------------------------------------------------\n");
		return 0; 
    }

    if(!strcmp(argv[1], "-v")) //view mode
    {
		if(argc ==3)
		{
			char *ptr = strstr(argv[2],".mp3"); // check file extension
			if(ptr)
			{
				if(strcmp(ptr,".mp3") == 0)
				{
					mp3->mp3_filename = argv[2]; //store the filename
					return VIEW;
				}
				else
				{
					printf("Invalid .mp3 file\n");
					return 0;
				}
			}
			else
			{
				printf("Invalid .mp3 file\n");
				return 0;
			}
		}
		else
		{
			printf("------------------------------------------------------------------------------\n");
			printf("ERROR: ./a.out : INVALID ARGUMENTS\n");
			printf("USAGE : To view please pass like: ./a.out -v mp3filename\n");
			printf("To edit please pass like: ./a.out -e -t/-a/-A/-m/-y/-c changing_text mp3filename\n");
			printf("To get help pass like : ./a.out --help\n");
			printf("------------------------------------------------------------------------------\n");
			return 0;
		}
    }

 	if(!strcmp(argv[1], "-e")) // edit mode
    {
		
		if(argc == 5) 
		{
			/*identify which tag user wants to edit */
			if(!(strcmp(argv[2], "-t" )) )
			{
				strcpy(mp3->given_tag,"TIT2");	// Title
			}
			else if(!(strcmp(argv[2], "-a" )) ) // Artist
			{
				strcpy(mp3->given_tag,"TPE1");	
			}
			else if(!(strcmp(argv[2], "-A" )) ) // Album
			{
				strcpy(mp3->given_tag,"TALB");	
			}
			else if(!(strcmp(argv[2], "-y" )) ) // Year
			{
				strcpy(mp3->given_tag,"TYER");	
			}
			else if(!(strcmp(argv[2], "-c" )) ) // Comment
			{
				strcpy(mp3->given_tag,"COMM"); 
			}
			else if(!(strcmp(argv[2], "-m" )) ) // Music
			{
				strcpy(mp3->given_tag,"TCON");	
			}
			else
			{
				printf("------------------------------------------------------------------------------\n");
				printf("ERROR: ./a.out : INVALID ARGUMENTS\n");
				printf("USAGE : To view please pass like: ./a.out -v mp3filename\n");
				printf("To edit please pass like: ./a.out -e -t/-a/-A/-m/-y/-c changing_text mp3filename\n");
				printf("To get help pass like : ./a.out --help\n");
				printf("------------------------------------------------------------------------------\n");
				return 0;
			}
			char *ptr = strstr(argv[4],".mp3");
			if(ptr)
			{
				if(strcmp(ptr,".mp3") == 0)
				{
					mp3->mp3_filename = argv[4];
					return EDIT;
				}
				else
				{
					printf("Invalid .mp3 file\n");
					return 0;
				}
			}

		}
		
    }

	else
	{
		printf("------------------------------------------------------------------------------\n");
		printf("ERROR: ./a.out : INVALID ARGUMENTS\n");
		printf("USAGE : To view please pass like: ./a.out -v mp3filename\n");
		printf("To edit please pass like: ./a.out -e -t/-a/-A/-m/-y/-c changing_text mp3filename\n");
		printf("To get help pass like : ./a.out --help\n");
		printf("------------------------------------------------------------------------------\n");
		return 0;
	}
}
void toggle_endianess(struct MP3 *mp3, char *size) // used reading frame size
{
	for(int i = 0;i<2;i++)
	{	
		char temp = size[i];
		size[i] = size[4-i-1];
		size[4 -i-1] = temp;
	}
	
}
void tag_to_name(char TAG[])  // prints tag name
{
	
	if(!(strcmp(TAG,"TIT2")))
	{
		printf("%-20s%-10s","Title",":");
	}
	else if(!(strcmp(TAG,"TPE1")))
	{
		printf("%-20s%-10s","Artist",":");
	}
	else if(!(strcmp(TAG,"TALB")))
	{
		printf("%-20s%-10s","Album",":");
	}
	else if(!(strcmp(TAG,"TYER")))
	{
		printf("%-20s%-10s","Year",":");
	}
	else if(!(strcmp(TAG,"TCON")))
	{
		printf("%-20s%-10s","Music",":");
	}
	else if(!(strcmp(TAG,"COMM")))
	{
		printf("%-20s%-10s","Comment",":");
	}
	else
	{
		printf("TAG not found");
		return ;
	}
}
void print_edit(char *argv[],struct MP3 *mp3) // after successful edit
{
	printf("---------------------------------------Select edit option -------------------------------------\n");
	if(!strcmp(mp3->given_tag,"TIT2"))
		printf("--------------------------------Select Title Change Option---------------------------------\n");
	else if(!strcmp(mp3->given_tag,"TPE1"))
		printf("--------------------------------Select Artist Change Option--------------------------------\n");
	else if(!strcmp(mp3->given_tag,"TALB"))
		printf("--------------------------------Select Album Change Option---------------------------------\n");
	else if(!strcmp(mp3->given_tag,"TYER"))
		printf("--------------------------------Select Year Change Option----------------------------------\n");
	else if(!strcmp(mp3->given_tag,"TCON"))
		printf("--------------------------------Select Music Change Option------------------------------\n");
	else if(!strcmp(mp3->given_tag,"COMM"))
		printf("--------------------------------Select Comment Change Option------------------------------\n");
	//printing the tag we are changing and the new data
	tag_to_name(mp3->given_tag); // print edited tag
	printf("%s \n",argv[3]); // new value

	if(!strcmp(mp3->given_tag,"TIT2"))
		printf("-------------------------------- Title Changed Successfully---------------------------------\n");
	else if(!strcmp(mp3->given_tag,"TPE1"))
		printf("--------------------------------Artist Changed Successfully---------------------------------\n");
	else if(!strcmp(mp3->given_tag,"TALB"))
		printf("--------------------------------Album Changed Successfully----------------------------------\n");
	else if(!strcmp(mp3->given_tag,"TYER"))
		printf("--------------------------------Year Changed Successfully-----------------------------------\n");
	else if(!strcmp(mp3->given_tag,"TCON"))
		printf("--------------------------------Music Changed Successfully---------------------------------\n");
	else if(!strcmp(mp3->given_tag,"COMM"))
		printf("--------------------------------Comment Changed Successfully-------------------------------\n");

}