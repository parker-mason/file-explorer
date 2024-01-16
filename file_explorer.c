#include "file_explorer.h"

Globals globals;

File touch( char *name, uint8_t permissions )
{
  File file = {
    .name = strdup( name ),
    .path = globals.current_path,
    .permissions = permissions,
    .contents = NULL
  };
  return file;
}

Folder * mkdir( char *name )
{
  Folder *folder = (Folder * ) malloc( sizeof( Folder ) );
  folder->name = strdup( name );
  folder->path = globals.current_path;
  return folder;
}

File code( File file )
{
  system( "clear" );
  file.contents = strdup( fgets( globals.input, sizeof( globals.input ), stdin ) );
  return file;
}

void cd( char *new_directory )
{
  static char last_dir[50];
  if (strncmp( globals.current_path, "~", 1 ) == 0)
  {
    strcpy( globals.current_path, "" );
  } if (strncmp( new_directory, "..\0", 2 ) == 0)
  {

  }
  strcat( globals.current_path, "/" );
  strcat( globals.current_path, strdup( new_directory ) );
}

void run( void )
{
  globals = (Globals) {
    .home = mkdir( "home" ),
    .current_path = "~",
    .command = "",
    .new_thing = "",
    .input = ""
  };
  system( "clear" );
  int file_counter = 0;
  int folder_counter = 0;
  while (true)
  {
    printf( "parker@PAKRERMASON%s$ ", globals.current_path );
    fgets( globals.input, sizeof( globals.input ), stdin );
    globals.input[strcspn( globals.input, "\n" )] = 0;
    memset( globals.command, 0, strlen( globals.command ) );
    memset( globals.new_thing, 0, strlen( globals.new_thing ) );

    if (strncmp( globals.input, "touch ", 6 ) == 0)
    {
      int parser = strlen( TOUCH_COMMAND ) + 1;
      strcpy( globals.command, TOUCH_COMMAND );

      for (int i = 0; i < strlen( globals.input ) - strlen( TOUCH_COMMAND ) - 1; i++)
      {
        globals.new_thing[i] = globals.input[parser];
        parser++;
      }

      if (file_counter < 5)
      {
        globals.home->files[file_counter] = touch( globals.new_thing, ADMIN_PERMISSIONS );
        file_counter++;
      } else
      {
        puts( "ERROR: Max files reached" );
      }
    } else if (strncmp( globals.input, "ls\0", 2 ) == 0)
    {
      strcpy( globals.command, LS_COMMAND );
      
      for (int i = 0; i < 2; i++)
      {
        if (globals.home->folders[i] != NULL)
        {
          printf( "|%s| ", globals.home->folders[i]->name );
        }
      }

      for (int i = 0; i < 5; i++)
      {
        if (globals.home->files[i].name != NULL)
        {
          printf( "%s ", globals.home->files[i].name );
        }
      }
      if (file_counter || folder_counter) {
        printf( "\n" );
      }
    } else if (strncmp( globals.input, "cd ", 3 ) == 0)
    {
      int parser = strlen( CD_COMMAND ) + 1;
      strcpy( globals.command, CD_COMMAND );

      for (int i = 0; i < strlen( globals.input ) - strlen( CD_COMMAND ) - 1; i++)
      {
        globals.new_thing[i] = globals.input[parser];
        parser++;
      }
      
      cd( globals.new_thing );
    } else if (strncmp( globals.input, "mkdir ", 5 ) == 0)
    {
      int parser = strlen( MKDIR_COMMAND ) + 1;
      strcpy( globals.command, MKDIR_COMMAND );
  
      for (int i = 0; i < strlen( globals.input ) - strlen( MKDIR_COMMAND ) + 1; i++)
      {
        globals.new_thing[i] = globals.input[parser];
        parser++;
      }
      if (folder_counter < 2)
      {
        globals.home->folders[folder_counter] = mkdir( globals.new_thing );
        folder_counter++;
      } else
      {
        puts( "ERROR: Max folders reached" );
      }
    } else if (strncmp( globals.input, "clear\0", 5) == 0)
    {
      strcpy( globals.command, CLEAR_COMMAND );
      
      system( "clear" );
    }
  }
}
