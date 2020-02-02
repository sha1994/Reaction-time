
Timer redTimer;
bool clicked = false;
bool colorOff = false;
bool alone = true;
bool winner = false;

void setup() {
}

void loop() {

  
  byte dimness = millis() % 256;
  
  if(!isAlone()){
      if (redTimer.isExpired()) {
         setColor(OFF);
         colorOff=true;
      }else {
        setColor(dim(GREEN, dimness));
    };
    
    if(redTimer.isExpired() &&  buttonPressed()){
     clicked = true;
    };
    
    if( clicked == true && winner == false ){
      //4 is the value for winner
      FOREACH_FACE(f) {
      if (!isValueReceivedOnFaceExpired(f)) { //a neighbor!
        byte neighbor = getLastValueReceivedOnFace(f);
          if(neighbor != 4 && winner == false){
            winner = true;
            setValueSentOnAllFaces(4);
            setColor(OFF);
    }
  }
      }
    }
  }else{
    setColor(dim(CYAN, dimness));
    redTimer.set(6000);
      clicked=false;
      setValueSentOnAllFaces(0);
      winner = false;
    
  }

FOREACH_FACE(f) {
  if (!isValueReceivedOnFaceExpired(f)) { //a neighbor!
    byte neighbor = getLastValueReceivedOnFace(f);
    if(neighbor == 4 ){
      //here we check if anyone clicked
      setColor(RED);
    }
    
  }
}
}
