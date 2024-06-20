#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <stdbool.h>
#include "commands.h"
#include "fat16.h"
#include "support.h"

/*
 * NOTE - Modificação
 * Motivo: off_t não definido
 * Diff: ø → #include <sys/types.h>
 */
#include <sys/types.h>

off_t fsize(const char *filename){
    struct stat st;
    if (stat(filename, &st) == 0)
        return st.st_size;
    return -1;
}

/*
 * NOTE - Modificação
 *
 * Motivo: É necessário representar o estado no qual o find não achou o arquivo.
 */

struct far_dir_searchres {
    struct fat_dir fdir;
    bool          found;
	int             idx;
};

struct far_dir_searchres find(struct fat_dir *dirs, char *filename, struct fat_bpb *bpb){

	(void) bpb;

    struct far_dir_searchres res = { .found = false };

    for (int i = 0; i < 16; i++) {
        if (dirs[i].name[0] == '\0') continue;
        if (strcmp((char *) dirs[i].name, filename) == 0){
            res.found = true;
            res.fdir  = dirs[i];
			res.idx   = i;
            break;
        }
    }

    return res;
}

struct fat_dir *ls(FILE *fp, struct fat_bpb *bpb){
    int i;
    struct fat_dir *dirs = malloc(sizeof (struct fat_dir) * bpb->possible_rentries);

    for (i=0; i < bpb->possible_rentries; i++){
        uint32_t offset = bpb_froot_addr(bpb) + i * 32;
        read_bytes(fp, offset, &dirs[i], sizeof(dirs[i]));
    }
    return dirs;
}

/*
 * NOTE - Remoção
 * Motivo: Fazer na mão é mais facíl.
 *
int write_dir(FILE *fp, char *fname, struct fat_dir *dir){
    char* name = padding(fname);
    strcpy((char *) dir->name, (char *) name);
    if (fwrite(dir, 1, sizeof(struct fat_dir), fp) <= 0)
        return -1;
    return 0;
}
*/

int write_data(FILE *fp, char *fname, struct fat_dir *dir, struct fat_bpb *bpb){

	/*
	 * NOTE - Modificação
	 * Motivo: Variáveis não usadas
	 * Diff: ø → (void) dir, (void) bpb;
	 */
	(void) dir, (void) bpb;

    FILE *localf = fopen(fname, "r");
    int c;

    while ((c = fgetc(localf)) != EOF){
        if (fputc(c, fp) != c)
            return -1;
    }
    return 0;
}

int wipe(FILE *fp, struct fat_dir *dir, struct fat_bpb *bpb){
    int start_offset = bpb_froot_addr(bpb) + (bpb->bytes_p_sect * \
            dir->starting_cluster);
    int limit_offset = start_offset + dir->file_size;

    while (start_offset <= limit_offset){
        fseek(fp, ++start_offset, SEEK_SET);
        if(fputc(0x0, fp) != 0x0)
            return 01;
    }
    return 0;
}

void mv(FILE *fp, char *source, char* dest, struct fat_bpb *bpb)
{

	(void) fp, (void) source, (void) dest, (void) bpb;

    ;; /* TODO */
}

void rm(FILE *fp, char *filename, struct fat_bpb *bpb)
{

	(void) fp, (void) filename, (void) bpb;

    ;; /* TODO */
}

void cp(FILE *fp, char *filename, struct fat_bpb *bpb)
{

	(void) fp, (void) filename, (void) bpb;

    ;; /* TODO */
}

