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

File code( File file )
{
  system( "clear" );
  file.contents = fgets( input, sizeof( input ), stdin );
  reutrn file;
}

void cd( char *new_directory )
{
  if (strncmp( globals.current_path, "~", 1 ))
  {
    strcpy( globals.current_path, "" );
  }
  strcat( globals.current_path, "/" ):
  strcat( globals.currrent_path, strdup( new_directory ) );
}

void run( void )
{
  system( "clear" );
  int file_counter = 0;
  int folder_counter = 0;
  while (true)
  {
    printf( "parker@PAKRERMASON%s$ ", globals.current_path );
    fgets( input, sizeof(input), stdin );
    input[strcspn( input, "\n" )] = 0;
    memset( command, 0, strlen( command ) );
    memset( new_thing, 0, strlen( new_thing ) );

    if (strncmp( input, "touch ", 6 ) == 0)
    {
      int parser = strlen( TOUCH_COMMAND ) + 1;
      strcpy( command, TOUCH_COMMAND );

      for (int i = 0; i < strlen( input ) - strlen( TOUCH_COMMAND ) - 1; i++)
      {
        new_thing[i] = input[parser];
        parser++;
      }

      if (file_counter < 5)
      {
        globals.home.files[file_counter] = touch( new_thing, ADMIN_PERMSISSIONS );
        file_counter++;
      } else
      {
        puts( "ERROR: Max files reached" );
      }
    } else if (strncmp( input, "ls\0", 2 ))
    {
      strcpy( command, LS_COMMAND );
      for (int i = 0; i < sizeof( globals.home.files ) / sizeof( globals.home.files[0] ); i++)
      {
        if (globals.home.files[j].name != NULL)
        {
          printf( "%s ", globals.home.files[j].name );
        }
      }
      printf( "\n" );
    } else if (strncmp( input, "cd ", 3 ))
    {
      int parser = strlen( CD_COMMAND ) + 1;
      strcpy( command, CD_COMMAND );

      for (int i = 0; i < strlen( input ) - strlen( CD_COMMAND ) - 1; i++)
      {

      }
    }
  }
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
