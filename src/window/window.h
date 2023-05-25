#ifndef WINDOW_H_
    #define WINDOW_H_

    #include <string.h>
    #include "../../include/my.h"
    #include "../object/object.h"

    typedef struct s_WindowClass {

        /* Inheritance */
        Class base;

        /* Attributes Definition*/
        sfVideoMode mode;
        sfRenderWindow *window;

        /* Methods definitions */

    } WindowClass;

    extern const Class *Window;


    #endif /* !WINDOW_H_ */