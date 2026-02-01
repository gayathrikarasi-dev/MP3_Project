#ifndef MP3_HEADER_H
#define MP3_HEADER_H

#include <stdio.h>
#include <string.h>

/* -------- Modes -------- */
#define VIEW 	1
#define EDIT 	2

/* -------- MP3 Structure -------- */
struct MP3
{
    char *mp3_filename;
    FILE *org_mp3_fptr;
    FILE *dup_mp3_fptr;
    char given_tag[5];
};
/* -------- Function prototypes -------- */
int validate_cla(int argc, char *argv[], struct MP3 *mp3);
void view(struct MP3 *mp3);
void edit(int argc, char *argv[],struct MP3 *mp3);
void toggle_endianess(struct MP3 *mp3, char *size);
void print_tag_data(struct MP3 *mp3);
void tag_to_name(char *);
void print_edit(char *argv[],struct MP3 *MP3);
#endif


