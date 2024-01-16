#ifndef FILE_EXPLORER_H
#define FILE_EXPLORER_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define CD_COMMAND    "cd"
#define LS_COMMAND    "ls"
#define CLEAR_COMMAND "clear"
#define MKDIR_COMMAND "mkdir"
#define TOUCH_COMMAND "touch"
#define READ_PERMISSIONS    0x04
#define WRITE_PERMISSIONS   0x02
#define EXECUTE_PERMISSIONS 0x01
#define ADMIN_PERMISSIONS   0x07

typedef struct File File;
typedef struct Folder Folder;
typedef struct Globals Globals;

struct File
{
  char *name;
  char *path;
  uint8_t permissions;
  char* contents;
};

struct Folder
{
  char *name;
  char *path;
  File files[5];
  Folder *folders[2];
};

struct Globals
{
  Folder *home;
  char current_path[256];
  char command[128];
  char new_thing[128];
  char input[256];
};

File touch ( char *name, uint8_t permissions );
Folder * mkdir ( char *name );
File code( File file );
void cd( char *new_directory );
void run( void );

#endif
