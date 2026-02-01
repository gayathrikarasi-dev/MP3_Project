#include "mp3_header.h"
void view(struct MP3 *mp3)
{
    printf("-----------------------------------------------------------------\n");
    printf("MP3 Tag Reader and editor for ID3V2\n");
    printf("-----------------------------------------------------------------\n");
    FILE *org_mp3_fptr =fopen(mp3->mp3_filename,"r"); // open mp3 file
    if (org_mp3_fptr == NULL)
    {
        printf("error open MP3 file\n");
        return;
    }
    fseek(org_mp3_fptr,10, SEEK_CUR); // skip ID3 header
    for(int i=1; i<=6; i++) // read 6 tags
    {
        char tag[5];  
        fread(tag, 4, 1, org_mp3_fptr);  // read tag
        int frame_size;
        tag[4] = '\0';
        fread(&frame_size, sizeof(int), 1,org_mp3_fptr); // read size
        toggle_endianess(mp3,(char *) & frame_size); // convert endian
        fseek(org_mp3_fptr, 3, SEEK_CUR); // skip flags
        tag_to_name(tag); // print tag name
        for(int i=0; i<frame_size-1; i++)   // print tag data
        {
            char ch;
            fread(&ch,1,1,org_mp3_fptr);
            printf("%c",ch);
        }
        printf("\n");
    }
    fclose(org_mp3_fptr); // close file
    printf("---------------------------------------------------------------------\n");
     
}
