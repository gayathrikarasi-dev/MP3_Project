#include "mp3_header.h"
int main(int argc, char *argv[])
{
    struct MP3 mp3;
    int ret = validate_cla(argc, argv, &mp3); // validate command-line arguments
    printf("It is a mp3 file\n");
    if (ret == VIEW)  // ./mp3editor -v song.mp3
    {
        view(&mp3);
    }
    else if (ret == EDIT)  // ./mp3editor -e -t/-a/-A/-y/-m/-c "text" song.mp3
    {
        edit(argc,argv,&mp3);   
    }

    return 0;
}
