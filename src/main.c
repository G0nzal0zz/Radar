#include <stdio.h>
#include "oop/new/new.h"
#include "object/object.h"
#include "window/window.h"
#include "game/game.h"
#include "system/file/file.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "system/entities/entities.h"

void flag_h(char **argv)
{
    if(my_strcmp("-h", argv[1]) == 0)
    {
        my_putstr("My_radar, game created by Gonzalo Larroya.\n");
        my_putstr("This game consist on a 2D air traffic simulation, with towers and aircrafts.\n");
        my_putstr("Parameters are given in a file:\n");
        my_putstr("Giving an 'A' for an aircraft followed by 6 integers:\n-2 determining departure coordenates.\n-2 determining arraival coordenates.\n-1 for pixels per second.\n-1 for delay in seconds.\n");
        my_putstr("Giving an 'T' for a tower followed by 3 integers:\n-2 determining its position.\n-1 for the tower radius.\n");
        my_putstr("08-01-2023.\n");
    }
}
int error_handling(int argc, char **argv)
{
    int fd;
    char *buf;
    struct stat sb;
    stat(argv[1], &sb);
    buf = malloc(sizeof(char)* (sb.st_size + 1));
    fd = open(argv[1], 0);
    if (sb.st_size < 5)
        return (84);
    if (argc != 2)
        return (84);
    if (open(argv[1], 0) == -1)
        exit (84);
    if (read(fd, buf, sb.st_size) == -1)
        exit (84);
    return (0);
}

int main (int argc, char **argv)
{
    flag_h(argv);
    if (error_handling(argc, argv) == 84)
        return (84);
    EntitiesClass *_Entities = new(Entities, argv[1]);
    GameClass *s = new(Game);
    process_game(s, _Entities);
}