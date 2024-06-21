#ifndef COMMANDS_H
#define COMMANDS_H

#include "fat16.h"

/* list files in fat_bpb */
struct fat_dir *ls(FILE *, struct fat_bpb *);

/* write content to directory */
int write_dir (FILE *, char *, struct fat_dir *);

/* write file content to fat directory */
int write_data(FILE *, char *, struct fat_dir *, struct fat_bpb *);

/*
 * NOTE - Modificação
 * Motivo: caminho 'dest' faltando.
 * Diff: mv(FILE*, char*, struct fat_bpb*) → mv(FILE*, char*, char*, struct fat_bpb*);
 */

/* move um arquivo da fonte ao destino */
void mv(FILE* fp, char* source, char* dest, struct fat_bpb* bpb);

/* delete the file from the fat directory */
void rm(FILE* fp, char* filename, struct fat_bpb* bpb);

// TODO
/* copy the file to the fat directory */
void cp(FILE* fp, char* filename, struct fat_bpb* bpb);

/* NOTE - Modificado */
/* helper function: find specific filename in fat_dir */
struct far_dir_searchres find(struct fat_dir *dirs, char *filename, struct fat_bpb *bpb);

#endif
