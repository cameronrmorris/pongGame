#include "Ball.h"

#include <iostream>

using namespace std ;


int main( int argc, char *argv[]) {
  
  Ball myBall( 0, 0, 1, 1, "image.jpg");

  for ( int i = 0 ; i < 5 ; i++ ) {

    myBall.update(NULL);
    
    cout << myBall.toString() << endl;


  }

  if( myBall.getX() != 5 || myBall.getY() != 5 ) {

    cout << "BALL TEST FAILED" << endl;

    return -1;

  }

  
  cout << "BALL TEST PASSED" << endl;


  return 0 ;
  

}
