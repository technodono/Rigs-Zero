//Declare any variables shared between functions here
float position[3];
float position2[3];
float position3[3];
int counter;
void init(){

	/********************************************************************************************************/
	/* Sets the 1st 2nd and 3rd positions of the triange - you may need to edit these for a smaller triangle*/
	/********************************************************************************************************/
position[0] = 0.74f;
position[1] = 0.0f;
position[2] = 0.0f;
position2[0] = -0.70f;
position2[1] = -0.70f;
position2[2] = 0.0f;
position3[0] = -0.70f;
position3[1] = 0.70f;
position3[2] = 0.0f;
counter = 0;

 

	//IMPORTANT: make sure to set any variables that need an initial value.
	//Do not assume variables will be set to 0 automatically!
}

void loop(){
    api.setPositionTarget(position);
    if (counter >20 && counter <50){
    api.setPositionTarget(position2);
    }
    if (counter>50){
        api.setPositionTarget(position3);
    }
     if (counter == 19){
       game.dropSPS();
    }
    if (counter == 49){
        game.dropSPS();
    }
    if (counter == 79){
        game.dropSPS();
    }
    
    counter ++;
}
    
    

	//This function is called once per second.  Use it to control the satellite.
