#include "main.h"

void autonomous() {

}

void myFunction(){
  if (digitalRead(LIMIT_SWITCH) == LOW){
      printf("limit switch is low");
  }
  else {
    printf("idk bro");
  }
}
