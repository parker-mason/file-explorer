#include "file_explorer.h"

Globals globals = {
  .home = new_folder( "home" ),
  .current_path = "~",
  .command = "",
  .new_thing = "",
  .input = ""
};

File touch( char *name, uint8_t permissions )
{
  File file = {
    .name = strdup( name ),
    .path = golbals.current_path,
    .permissions = permissions,
    .contents = NULL
  };
  return file;
}

Folder mkdir( char *name )
{
  Folder folder = {
    .name = strdup( name ),
    .path = globals.current_path,
    .files = NULL,
    .folders = NULL
  };
  return folder;
}

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
