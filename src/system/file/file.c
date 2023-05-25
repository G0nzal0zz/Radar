/*
** EPITECH PROJECT, 2022
** oop
** File description:
** game.c
*/

#include "../../oop/new/new.h"
#include "../../window/window.h"
#include "../../../include/my.h"
#include "file.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "../entities/towers/towers.h"
#include "../entities/aircrafts/aircrafts.h"
#include "../entities/entities.h"

static void nb_entities(FileClass *this, EntitiesClass *_Entities)
{
    _Entities->nb_airplanes = 0;
    _Entities->nb_towers = 0;
    for (int y = 0; y < this->_size; y++) {
        if (this->content[y] == 'A')
            _Entities->nb_airplanes = _Entities->nb_airplanes + 1;
        if (this->content[y] == 'T')
            _Entities->nb_towers = _Entities->nb_towers + 1;;
    }
}

static void get_entities(FileClass *this, EntitiesClass *_Entities, AircraftsClass **_aircraft, TowersClass **_towers)
{
    nb_entities(this, _Entities);
    int num = 0;
    int num_2 = 0;
    this->sep_content = my_str_to_word_array(this->content, ' ');
    for (int count = 0; this->sep_content[count]; count++) {
        if (this->sep_content[count][0] == 'A'){
            _aircraft[num]= new(Aircraft, this->sep_content, count);
            num++;
        }
        if (this->sep_content[count][0] == 'T'){
            _towers[num_2]= new(Towers, this->sep_content, count);
            num_2++;
        }
    }
}

static void file_ctor(FileClass *this, va_list *args)
{
    // Initialize internal resources
    this->path = va_arg(*args, char*);
    int fd;
    struct stat sb;
    stat(this->path, &sb);
    this->_size = sb.st_size;
    fd = open(this->path, 0);
    this->content = malloc(sizeof(char) * (this->_size + 1));
    read(fd,this->content, this->_size);
}

//destructor
static void file_dtor(FileClass *this)
{
    // Release internal resources
}

static const FileClass _description = {
    {   /* Class Structure */
        .__size__ = sizeof(FileClass),
        .__name__ = "File",
        .__ctor__ = (ctor_t)&file_ctor,
        .__dtor__ = (dtor_t)&file_dtor,
    },
    /* Mehtods */
    .__get_entitites__ = &get_entities,
    .__nb_entitites__ = &nb_entities,
};

const Class *File = (const Class*)&_description;