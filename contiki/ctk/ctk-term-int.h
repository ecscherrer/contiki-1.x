#ifndef __CTK_TERM_INT_H__
#define __CTK_TERM_INT_H__

/* Color definitions */

#define TERM_BACKGROUNDCOLOR 0
#define TERM_WINDOWCOLOR    1
#define TERM_SEPARATORCOLOR 7 /*(TERM_WINDOWCOLOR + 6)*/
#define TERM_LABELCOLOR     13 /*(TERM_SEPARATORCOLOR + 6)*/
#define TERM_BUTTONCOLOR    19 /*(TERM_LABELCOLOR + 6)*/
#define TERM_HYPERLINKCOLOR 25 /*(TERM_BUTTONCOLOR + 6)*/
#define TERM_TEXTENTRYCOLOR 31 /*(TERM_HYPERLINKCOLOR + 6)*/
#define TERM_ICONCOLOR      37 /*(TERM_TEXTENTRYCOLOR + 6)*/
#define TERM_MENUCOLOR      43 /*(TERM_ICONCOLOR + 6)*/
#define TERM_OPENMENUCOLOR  44/*(TERM_MENUCOLOR + 1)*/
#define TERM_ACTIVEMENUCOLOR 45 /*(TERM_OPENMENUCOLOR + 1) */

/* Structure describing an updated region */
struct ctk_term_update {
  struct ctk_term_update *next;

#define UPDATE_NONE  0
#define UPDATE_PARTS 1
#define UPDATE_FULL  2

  unsigned char type;

  unsigned char x, y;
  unsigned char w, h;  
};

/* Character sequence parsing states */
enum { ANS_IDLE, ANS_ESCSEQ,ANS_ESCSEQ_1,ANS_SS3, ANS_CTRLSEQ};

struct ctk_term_state {
  unsigned char type;
  unsigned char state;
  unsigned char height, width;

  /* Variables used when sending screen updates. */
  unsigned char x, y, x1, y1, x2, y2;
  unsigned char w, h;
  unsigned char c1, c2;

#define CTK_TERM_MAX_UPDATES 8  
  struct ctk_term_update *updates_current;
  struct ctk_term_update *updates_pending;
  struct ctk_term_update *updates_free;
  struct ctk_term_update updates_pool[CTK_TERM_MAX_UPDATES];

  /* Variables used when parsing input sequences */
  unsigned char inputstate;
#define CTK_TERM_CTRLBUFLEN 5
  unsigned char ctrlbuf[CTK_TERM_CTRLBUFLEN+1];
  unsigned char ctrlCnt;
};

struct ctk_term_update * ctk_term_update_alloc(struct ctk_term_state *vs);
void ctk_term_update_free(struct ctk_term_state *ts, struct ctk_term_update *a);
void ctk_term_update_remove(struct ctk_term_state *ts, struct ctk_term_update *a);

void ctk_term_update_add(struct ctk_term_state *ts, struct ctk_term_update *a);
struct ctk_term_update * ctk_term_update_dequeue(struct ctk_term_state *ts);

void ctk_term_input_init();

#endif /* __CTK_TERM_INT_H__ */
