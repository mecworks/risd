#include <linux/uinput.h>
#include <string.h>
#include <stdio.h>

#include "keys.h"
#include "utility.h"

struct key_lookup keys[200];

int find_key (char* name)
{
    for (int i = 0; i < KEYLIST_SIZE; i++)
    {
        if (strcmp(keys[i].name, name) == 0)
            return keys[i].code;
    }

    return -1;
}

struct key_lookup create_key (char* name, int code)
{
    struct key_lookup k;
    strcpy(k.name, name);
    k.code = code;

   return k;
}

void fill_keylist()
{
    int i=0;

    // Number row (0-9)
    keys[i++] = create_key("KEY_0", KEY_0);
    keys[i++] = create_key("KEY_1", KEY_1);
    keys[i++] = create_key("KEY_2", KEY_2);
    keys[i++] = create_key("KEY_3", KEY_3);
    keys[i++] = create_key("KEY_4", KEY_4);
    keys[i++] = create_key("KEY_5", KEY_5);
    keys[i++] = create_key("KEY_6", KEY_6);
    keys[i++] = create_key("KEY_7", KEY_7);
    keys[i++] = create_key("KEY_8", KEY_8);
    keys[i++] = create_key("KEY_9", KEY_9);

    // Top letter keys
    keys[i++] = create_key("KEY_Q", KEY_Q);
    keys[i++] = create_key("KEY_W", KEY_W);
    keys[i++] = create_key("KEY_E", KEY_E);
    keys[i++] = create_key("KEY_R", KEY_R);
    keys[i++] = create_key("KEY_T", KEY_T);
    keys[i++] = create_key("KEY_Y", KEY_Y);
    keys[i++] = create_key("KEY_U", KEY_U);
    keys[i++] = create_key("KEY_I", KEY_I);
    keys[i++] = create_key("KEY_O", KEY_O);
    keys[i++] = create_key("KEY_P", KEY_P);

    // Middle letter keys
    keys[i++] = create_key("KEY_A", KEY_A);
    keys[i++] = create_key("KEY_S", KEY_S);
    keys[i++] = create_key("KEY_D", KEY_D);
    keys[i++] = create_key("KEY_F", KEY_F);
    keys[i++] = create_key("KEY_G", KEY_G);
    keys[i++] = create_key("KEY_H", KEY_H);
    keys[i++] = create_key("KEY_J", KEY_J);
    keys[i++] = create_key("KEY_K", KEY_K);
    keys[i++] = create_key("KEY_L", KEY_L);

    // Bottom letter keys
    keys[i++] = create_key("KEY_Z", KEY_Z);
    keys[i++] = create_key("KEY_X", KEY_X);
    keys[i++] = create_key("KEY_C", KEY_C);
    keys[i++] = create_key("KEY_V", KEY_V);
    keys[i++] = create_key("KEY_B", KEY_B);
    keys[i++] = create_key("KEY_N", KEY_N);
    keys[i++] = create_key("KEY_M", KEY_M);

    // Special characters (top row)
    keys[i++] = create_key("KEY_GRAVE", KEY_GRAVE);     // ` ~
    keys[i++] = create_key("KEY_MINUS", KEY_MINUS);     // - _
    keys[i++] = create_key("KEY_EQUAL", KEY_EQUAL);     // = +
    keys[i++] = create_key("KEY_PLUS", KEY_KPPLUS);     // + (numpad)

    // Right side of top rows
    keys[i++] = create_key("KEY_LBRACKET", KEY_LEFTBRACE);   // [ {
    keys[i++] = create_key("KEY_RBRACKET", KEY_RIGHTBRACE);  // ] }
    keys[i++] = create_key("KEY_BACKSLASH", KEY_BACKSLASH);  // \ |

    // Middle row special
    keys[i++] = create_key("KEY_SEMICOLON", KEY_SEMICOLON);  // ; :
    keys[i++] = create_key("KEY_APOSTROPHE", KEY_APOSTROPHE);// ' "
    keys[i++] = create_key("KEY_COMMA", KEY_COMMA);      // , <
    keys[i++] = create_key("KEY_DOT", KEY_DOT);          // . >
    keys[i++] = create_key("KEY_SLASH", KEY_SLASH);      // / ?

    // Space
    keys[i++] = create_key("KEY_SPACE", KEY_SPACE);

    // Function keys
    keys[i++] = create_key("KEY_F1", KEY_F1);
    keys[i++] = create_key("KEY_F2", KEY_F2);
    keys[i++] = create_key("KEY_F3", KEY_F3);
    keys[i++] = create_key("KEY_F4", KEY_F4);
    keys[i++] = create_key("KEY_F5", KEY_F5);
    keys[i++] = create_key("KEY_F6", KEY_F6);
    keys[i++] = create_key("KEY_F7", KEY_F7);
    keys[i++] = create_key("KEY_F8", KEY_F8);
    keys[i++] = create_key("KEY_F9", KEY_F9);
    keys[i++] = create_key("KEY_F10", KEY_F10);
    keys[i++] = create_key("KEY_F11", KEY_F11);
    keys[i++] = create_key("KEY_F12", KEY_F12);

    // Arrow keys
    keys[i++] = create_key("KEY_UP", KEY_UP);
    keys[i++] = create_key("KEY_DOWN", KEY_DOWN);
    keys[i++] = create_key("KEY_LEFT", KEY_LEFT);
    keys[i++] = create_key("KEY_RIGHT", KEY_RIGHT);

    // Page keys
    keys[i++] = create_key("KEY_PAGEDOWN", KEY_PAGEDOWN);
    keys[i++] = create_key("KEY_PAGEUP", KEY_PAGEUP);

    // Home and End
    keys[i++] = create_key("KEY_HOME", KEY_HOME);
    keys[i++] = create_key("KEY_END", KEY_END);

    // Enter and Return
    keys[i++] = create_key("KEY_ENTER", KEY_ENTER);
    keys[i++] = create_key("KEY_RETURN", KEY_ENTER);

    // Escape
    keys[i++] = create_key("KEY_ESC", KEY_ESC);

    // Modifier keys
    keys[i++] = create_key("WINKEY", KEY_LEFTMETA);
    keys[i++] = create_key("GUI", KEY_LEFTMETA);
    keys[i++] = create_key("LMETA", KEY_LEFTMETA);
    keys[i++] = create_key("RMETA", KEY_RIGHTMETA);

    keys[i++] = create_key("CTRL", KEY_LEFTCTRL);
    keys[i++] = create_key("LCTRL", KEY_LEFTCTRL);
    keys[i++] = create_key("RCTRL", KEY_RIGHTCTRL);

    keys[i++] = create_key("ALT", KEY_LEFTALT);
    keys[i++] = create_key("LALT", KEY_LEFTALT);
    keys[i++] = create_key("RALT", KEY_RIGHTALT);

    keys[i++] = create_key("SHIFT", KEY_LEFTSHIFT);
    keys[i++] = create_key("LSHIFT", KEY_LEFTSHIFT);
    keys[i++] = create_key("RSHIFT", KEY_RIGHTSHIFT);

    // Tab and Backspace
    keys[i++] = create_key("KEY_TAB", KEY_TAB);
    keys[i++] = create_key("KEY_BACKSPACE", KEY_BACKSPACE);

    // Delete and Insert
    keys[i++] = create_key("KEY_DELETE", KEY_DELETE);
    keys[i++] = create_key("KEY_INSERT", KEY_INSERT);

    // Lock keys
    keys[i++] = create_key("KEY_CAPSLOCK", KEY_CAPSLOCK);
    keys[i++] = create_key("KEY_NUMLOCK", KEY_NUMLOCK);
    keys[i++] = create_key("KEY_SCROLLLOCK", KEY_SCROLLLOCK);

    // System key
    keys[i++] = create_key("KEY_SYSRQ", KEY_SYSRQ);

    // Numpad keys
    keys[i++] = create_key("KEY_KP0", KEY_KP0);
    keys[i++] = create_key("KEY_KP1", KEY_KP1);
    keys[i++] = create_key("KEY_KP2", KEY_KP2);
    keys[i++] = create_key("KEY_KP3", KEY_KP3);
    keys[i++] = create_key("KEY_KP4", KEY_KP4);
    keys[i++] = create_key("KEY_KP5", KEY_KP5);
    keys[i++] = create_key("KEY_KP6", KEY_KP6);
    keys[i++] = create_key("KEY_KP7", KEY_KP7);
    keys[i++] = create_key("KEY_KP8", KEY_KP8);
    keys[i++] = create_key("KEY_KP9", KEY_KP9);
    keys[i++] = create_key("KEY_KPMINUS", KEY_KPMINUS);
    keys[i++] = create_key("KEY_KPPLUS", KEY_KPPLUS);
    keys[i++] = create_key("KEY_KPDOT", KEY_KPDOT);
    keys[i++] = create_key("KEY_KPENTER", KEY_KPENTER);
    keys[i++] = create_key("KEY_KPSLASH", KEY_KPSLASH);
    keys[i++] = create_key("KEY_KPASTERISK", KEY_KPASTERISK);

    if (i > KEYLIST_SIZE) {
        fprintf(stderr, "Key list size is too large.\r\n");
        exit_with_error(1);
    }
}