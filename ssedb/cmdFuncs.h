#ifndef SRC_CMDFUNCS_H
#define SRC_CMDFUNCS_H

#include "ast.h"
#include <inttypes.h>
#include <Zydis/Zydis.h>    // zydis
#include <assert.h>
#include <bfd.h>            // bfd

asymbol **symbol_table; // symbol table
long num_symbols;       // symbol number

struct breakpoint{
    long addr;
    unsigned long origin;
};

struct breakpoint bp[100];

void update_breakpoint_table(long addr, unsigned long origin);
unsigned long get_origin();


void get_symbol(char *file);

// A tedious but simple parsing function, parsing
// user input string into a command data structure.
 Cmd_t
parseCommand (char *s, int pid, char *filename);

// Given a command and execute it.
 void
execCommand (Cmd_t c);

 void
loopCommand (int pid, char *filename);

#endif //SRC_CMDFUNCS_H
