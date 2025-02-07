/***************************************************************************
 *  Original Diku Mud copyright (C) 1990, 1991 by Sebastian Hammer,        *
 *  Michael Seifert, Hans Henrik Strfeldt, Tom Madsen, and Katja Nyboe.    *
 *                                                                         *
 *  Merc Diku Mud improvments copyright (C) 1992, 1993 by Michael          *
 *  Chastain, Michael Quan, and Mitchell Tse.                              *
 *                                                                         *
 *  In order to use any part of this Merc Diku Mud, you must comply with   *
 *  both the original Diku license in 'license.doc' as well the Merc       *
 *  license in 'license.txt'.  In particular, you may not remove either of *
 *  these copyright notices.                                               *
 *                                                                         *
 *  Much time and thought has gone into this software and you are          *
 *  benefitting.  We hope that you share your changes too.  What goes      *
 *  around, comes around.                                                  *
 ***************************************************************************/

/***************************************************************************
 *  ROM 2.4 is copyright 1993-1998 Russ Taylor                             *
 *  ROM has been brought to you by the ROM consortium                      *
 *      Russ Taylor (rtaylor@hypercube.org)                                *
 *      Gabrielle Taylor (gtaylor@hypercube.org)                           *
 *      Brian Moore (zump@rom.org)                                         *
 *  By using this code, you have agreed to follow the terms of the         *
 *  ROM license, in the file Rom24/doc/rom.license                         *
 ***************************************************************************/

#ifndef __ROM_RECYCLE_H
#define __ROM_RECYCLE_H

#include "merc.h"

/* externs */
extern int mobile_count;
extern long last_pc_id;
extern long last_mob_id;

/* stuff for providing a crash-proof buffer */

#define MAX_BUF          16384
#define MAX_BUF_LIST     10
#define BASE_BUF         1024

/* valid states */
#define BUFFER_SAFE      0
#define BUFFER_OVERFLOW  1
#define BUFFER_FREED     2

/* Function prototypes (recycle operations). */
void *recycle_new (int type);
void recycle_free (int type, void *obj);
void *recycle_get_first_obj (int type);

/* Recycle globals and necessary functions. */
#define DEC_RECYCLE(name, vtype)                  \
    vtype * name ## _new (void);                  \
    void name ## _free (vtype *);                 \
    vtype * name ## _get_first (void);            \
    vtype * name ## _get_next (const vtype * obj) \

DEC_RECYCLE (ban,         BAN_DATA);
DEC_RECYCLE (area,        AREA_DATA);
DEC_RECYCLE (extra_descr, EXTRA_DESCR_DATA);
DEC_RECYCLE (exit,        EXIT_DATA);
DEC_RECYCLE (room_index,  ROOM_INDEX_DATA);
DEC_RECYCLE (obj_index,   OBJ_INDEX_DATA);
DEC_RECYCLE (shop,        SHOP_DATA);
DEC_RECYCLE (mob_index,   MOB_INDEX_DATA);
DEC_RECYCLE (reset_data,  RESET_DATA);
DEC_RECYCLE (help,        HELP_DATA);
DEC_RECYCLE (mpcode,      MPROG_CODE);
DEC_RECYCLE (descriptor,  DESCRIPTOR_DATA);
DEC_RECYCLE (gen_data,    GEN_DATA);
DEC_RECYCLE (affect,      AFFECT_DATA);
DEC_RECYCLE (obj,         OBJ_DATA);
DEC_RECYCLE (char,        CHAR_DATA);
DEC_RECYCLE (pcdata,      PC_DATA);
DEC_RECYCLE (mem_data,    MEM_DATA);
DEC_RECYCLE (buf,         BUFFER);
DEC_RECYCLE (mprog,       MPROG_LIST);
DEC_RECYCLE (had,         HELP_AREA);
DEC_RECYCLE (note,        NOTE_DATA);
DEC_RECYCLE (social,      SOCIAL_TYPE);
DEC_RECYCLE (portal_exit, PORTAL_EXIT_TYPE);
DEC_RECYCLE (portal,      PORTAL_TYPE);

/* Initialization / disposal functions. */
void ban_init (void *obj);
void ban_dispose (void *obj);
void descriptor_init (void *obj);
void descriptor_dispose (void *obj);
void extra_descr_init (void *obj);
void extra_descr_dispose (void *obj);
void obj_dispose (void *vobj);
void char_init (void *obj);
void char_dispose (void *vobj);
void pcdata_init (void *obj);
void pcdata_dispose (void *obj);
void buf_dispose (void *obj);
void mprog_init (void *obj);
void mprog_dispose (void *obj);
void had_dispose (void *obj);
void help_dispose (void *obj);
void reset_data_init (void *obj);
void area_init (void *obj);
void area_dispose (void *obj);
void exit_init (void *obj);
void exit_dispose (void *obj);
void room_index_init (void *obj);
void room_index_dispose (void *obj);
void shop_init (void *obj);
void obj_index_init (void *vobj);
void obj_index_dispose (void *vobj);
void mob_index_init (void *obj);
void mob_index_dispose (void *obj);
void mpcode_init (void *obj);
void mpcode_dispose (void *obj);
void buf_init (void *obj);
void note_dispose (void *obj);
void social_dispose (void *obj);
void portal_exit_dispose (void *obj);
void portal_dispose (void *obj);

/* Functions related to specific recycleable objects. */
int      get_size      (int val);
BUFFER   *new_buf_size (int size);
bool     add_buf       (BUFFER *buffer, char *string);
void     clear_buf     (BUFFER *buffer);
char     *buf_string   (BUFFER *buffer);
MEM_DATA *find_memory  (MEM_DATA *memory, long id);
long     get_pc_id     (void);
long     get_mob_id    (void);

#endif
