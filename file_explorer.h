#ifndef FILE_EXPLORER_H
#define FILE_EXPLORER_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct File File;
typedef struct Folder Folder;
tyepdef struct Globals Globals;

struct File
{
  char[255] name;
  char[100] path;
  uint8_t permissions;
  char* contents;
};

struct Folder
{
  char[255] name;
  char[100] path;
  File files[5];
  Folder *folders;
};

struct Globals
{
  Folder home;
  char[100] current_path;
  char[255] command;
  char[255] new_thing;
  char[255] input;
};

File touch ( char *name, uint8_t permissions );
Folder mkdir ( char *name );
File code( File file );
void cd( char *new_directory );
void run( void );

#endif
