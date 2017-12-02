#include <stdio.h>
#include <pthread.h>

struct reaction {
	// FILL ME IN
    int O_num;
    int H_num;
    pthread_mutex_t *lock;
    pthread_cond_t *condH;
    pthread_cond_t *condO;


};

void reaction_init(struct reaction *reaction);

void reaction_h(struct reaction *reaction);

void reaction_o(struct reaction *reaction);
