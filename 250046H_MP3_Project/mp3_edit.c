#include "mp3_header.h"
void edit(int argc, char *argv[],struct MP3 *mp3)
{
    mp3->org_mp3_fptr= fopen(mp3->mp3_filename,"r"); // open original mp3
    mp3->dup_mp3_fptr= fopen("temp.mp3","w"); // create temp file
    if(mp3->org_mp3_fptr == NULL )
    {
        printf("File Not Availble\n");
        return ;
    }
    char header[10];
    fread(header,10,1,mp3->org_mp3_fptr); // read ID3 header
    fwrite(header,10,1,mp3->dup_mp3_fptr); // copy header
    
    for(int i=1;i<=6;i++)  // loop through tags
    {
        char tag[5]= {0};
        fread(tag,4,1,mp3->org_mp3_fptr); // read tag
        fwrite(tag,4,1,mp3->dup_mp3_fptr);  // write tag
        if(strcmp(tag,mp3->given_tag) == 0) // tag matched
        {
            int size;
            fread(&size,4,1,mp3->org_mp3_fptr);
            toggle_endianess(mp3, (char *)&size);
            int new_size = strlen(argv[3])+1; // new data size
            toggle_endianess(mp3, (char *)&new_size);
            fwrite(&new_size,4,1,mp3->dup_mp3_fptr);
            char flag[3];
            fread(flag,3,1,mp3->org_mp3_fptr);
            fwrite(flag,3,1,mp3->dup_mp3_fptr);
            toggle_endianess(mp3, (char *)&new_size); 
            fwrite(argv[3],new_size-1,1,mp3->dup_mp3_fptr); // write new data
            fseek(mp3->org_mp3_fptr,size-1,SEEK_CUR);  // skip old data
            print_edit(argv,mp3); // print success msg
            break;
        }
        else // other tags
        {
            int size;
            fread(&size,sizeof(int),1,mp3->org_mp3_fptr);
            fwrite(&size,sizeof(int),1,mp3->dup_mp3_fptr);
            char flag[3];
            fread(flag,3,1,mp3->org_mp3_fptr);
            fwrite(flag,3,1,mp3->dup_mp3_fptr);
            toggle_endianess(mp3, (char *)&size);
            for(int i=0;i<size-1;i++)
            {
                char ch;
                fread(&ch,1,1,mp3->org_mp3_fptr);
                fwrite(&ch,1,1,mp3->dup_mp3_fptr);
            }
        }
  
    }
    print_tag_data(mp3);   // copy remaining data
    remove(mp3->mp3_filename); // delete old mp3
    rename("temp.mp3",mp3->mp3_filename);  // rename temp file
    fclose(mp3->org_mp3_fptr);
    fclose(mp3->dup_mp3_fptr);
}
void print_tag_data(struct MP3 *mp3)
{
    char ch;
    while(fread(&ch,1,1,mp3->org_mp3_fptr ) == 1)
    {
        fwrite(&ch,1,1,mp3->dup_mp3_fptr );
    }
    
}