#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "song_node.c"
#include <time.h> ///////////////////////////////////"


list *table[26];
list *song_table[26];
//srand(time(NULL));



int main (){

 
  /* foo x;
     x.me = 1;
     foo y;
     y.me = 2;
     x.next = &y;
     y.next = 0;*/
  foo *start = insert_front(0,3);
  start = insert_front(start,2);
  start = insert_front(start,1);
  start = insert_front(start,0);
  //foo here = *insert_front(&x, 0);
  printf("TESTING print_list (0, 1, 2, 3)\n");
  print_list(start);
  foo hey =*free_list(start);
  //printf("Return of free_list: %d\n",*free_list(start));
 
  
}

song_node * insert_ordered( song_node *start, char *song, char *artist){
  song_node *here = (song_node *)malloc(1 * sizeof(song_node));
  here->name = data;
  here->artist = artist;
  int x = to_lower(*artist) + 'A';
  list curr_list = table[x];
  song_node *current;
  for (current = curr_list->head; current->next;current = current->next){
    if (song_cmp(current, here)  < 0){
      break; 
    }
  }
  song_node* save = current->next;
  current->next = here;
  here-> = save;
  
  //Creating list based on song name
  int d = to_lower(*song) + 'A';
  curr_list = song_table[d];
  //song_node *current;
  for (current = curr_list->head; current->next;current = current->next){
    if (song_cmp(current, here)  < 0){
      break; 
    }
  }
  save = current->next;
  current->next = here;
  here-> = save;

  return here;
}
song_node * find_song( char *song){
  int x = to_lower(*song) + 'A';
  list curr_list = song_table[x];
  song_node *current;
  for (current = curr_list->head; current->next;current = current->next){
    if (! str_cmp(song, current->name)){
	return current;
      }
  }
 
}
song_node * get_random(){
  srand(time(NULL));
  int x = rand()%26;
  list curr_list = song_table[x];
  int d = rand()%100;
  song_node *current = curr_list->head;
  while (d > 0){
    if (!current->){
      current = curr_list->head;
    }
    else {
      current = current->next
	}
  }
  return current;
}

song_node * find_artist( char *artist){
  int x = to_lower(*artist) + 'A';
  list curr_list = table[x];
  song_node *current;
  for (current = curr_list->head; current->next;current = current->next){
    if (! str_cmp(artist, current->artist)){
	return current;
      }
  } 
 
}

song_node * delete_song( char *song){
  int x = to_lower(*song) + 'A';
  list curr_list = song_table[x];
  song_node *current;
  for (current = curr_list->head; current->next->next;current = current->next){
    if (! str_cmp(song, current->next->name)){
      break;
      }
  }
  song_node *ret = current->next;
  current->next = ret->next;
  //Now we need to find the same song but in the other table thanks to Gideon's genius implementation thank the lord
  delete_song_artist(song, ret->artist);


  return ret;
}
  
song_node * delete_song_artst( char *song, char* artist){
  //Should not be refered too directly, only from delete_song
  int x = to_lower(*arist) + 'A';
  list curr_list = table[x];
  song_node *current;
  for (current = curr_list->head; current->next->next;current = current->next){
    if (! str_cmp(song, current->next->name) && ! str_cmp(artist, current->next->artist)){
      break;
    }
  }
  song_node *ret = current->next;
  current->next = ret->next;
  return ret;
}
    


char to_lower(char start){
  //char[26] upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  //char[26] lower = "abcdefghijklmnopqrstuvwxyz";
  if (start >= 'A' && start <='Z'){
    start = start - 'A' + 'a';
  }
  return start;
}
int free_list(){
  int x = 25;
  while (x >= 0){
    list curr_list = table[x];
    song_node current = curr_list->head;
    while (current){
      song_node now = current;
      current = current->next;
      free(now);
      
    }
    curr_list = song_table[x];
    current = curr_list->head;
    while (current){
      song_node now = current;
      current = current->next;
      free(now);
      
    }
    
  }
}



  foo *retfoo = start;
  if (! start){
    return start;
  }
  free_list(start->next);
  printf("Testing free: %d\n",start->me);
  free(start);
  return retfoo;
  
}




