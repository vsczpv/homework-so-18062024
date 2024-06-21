#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdbool.h>
#include "fat16.h"

/*
 * Esta struct encapsula o resultado de find(), carregando informações sobre a
 * busca consigo.
 */
struct far_dir_searchres
{
	struct fat_dir fdir; // Diretório encontrado
	bool          found; // Encontrou algo?
	int             idx; // Index relativo ao diretório de busca
};

/* list files in fat_bpb */
struct fat_dir *ls(FILE *, struct fat_bpb *);

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
struct far_dir_searchres find_in_root(struct fat_dir *dirs, char *filename, struct fat_bpb *bpb);

///

/* int write_dir (FILE *, char *, struct fat_dir *); */
/* int write_data(FILE *, char *, struct fat_dir *, struct fat_bpb *); */

#endif
