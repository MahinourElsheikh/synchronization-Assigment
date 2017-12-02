#include <pthread.h>
#include "reaction.h"

// Forward declaration. This function is implemented in reaction-runner.c,
// but you needn't care what it does. Just be sure it's called when
// appropriate within reaction_o()/reaction_h().
void make_water();


void reaction_init(struct reaction *reaction)
{
	// FILL ME IN
    reaction->H_num=0;
    reaction->O_num=0;

    int x=pthread_cond_init(reaction->condH,NULL);
    printf("%d ",x);
    printf("condH");
    pthread_cond_init(reaction->condO,NULL);
    printf("cond)");
     pthread_mutex_init(reaction->lock,NULL);
    printf("mutex-int");

}


void reaction_h(struct reaction *reaction)
{    printf("d5lH");
	// FILL ME IN
    pthread_mutex_lock ((reaction->lock));
    reaction->H_num++;
    while ((reaction->H_num<2||reaction->O_num<1))
         pthread_cond_wait ((reaction->condH), (reaction->lock));
    printf("tl3H");
    make_water();
    pthread_mutex_unlock ((reaction->lock));
    pthread_mutex_lock ((reaction->lock));
    reaction->H_num-=2;
    reaction->O_num--;
    pthread_cond_signal((reaction->condH));
    pthread_cond_signal((reaction->condH));
    pthread_cond_signal((reaction->condO));
    pthread_mutex_unlock ((reaction->lock));
}


void reaction_o(struct reaction *reaction)
{
	// FILL ME IN
    printf("d5lO");
    pthread_mutex_lock ((reaction->lock));
    reaction->O_num++;
    while ((reaction->H_num<2||reaction->O_num<1))
        pthread_cond_wait ((reaction->condO), (reaction->lock));
    printf("tl3O");
    make_water();
    pthread_mutex_unlock ((reaction->lock));
    pthread_mutex_lock ((reaction->lock));
    reaction->H_num-=2;
    reaction->O_num--;
    pthread_cond_signal((reaction->condH));
    pthread_cond_signal((reaction->condH));
    pthread_cond_signal((reaction->condO));
    pthread_mutex_unlock ((reaction->lock));
}


