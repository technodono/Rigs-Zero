//Declare any variables shared between functions here
int movNum;
float position[3];
float state[12];
void init(){
	//This function is called once when your code is first loaded.

	//IMPORTANT: make sure to set any variables that need an initial value.
	//Do not assume variables will be set to 0 automatically!
position[0]	=	0.5f;	
position[1]	=	0.0f;	
position[2]	=	0.0f;
movNum = 0;
}

void loop(){
	//This function is called once per second.  Use it to control the satellite.
	api.getMyZRState(state);
	float xDiff = state[0] - position[0];
	float yDiff = state[1] - position[1];
	float zDiff = state[2] - position[2];
	DEBUG(("%d\n", movNum));
    if (fabsf(xDiff) < 0.1 && fabsf(yDiff) < 0.1 && fabsf(zDiff) < 0.1) {
        switch (movNum) {
            case 0:
                position[0] = -0.5f;
                position[1] = 0.0f;
                position[2]	= 0.0f;
                movNum = 1;
                break;
            case 1:
                position[0] = 0.0f;
                position[1] = 0.5f;
                position[2]	= 0.0f;
                movNum = 2;
                break;
            case 2:
                position[0] = 0.0f;
                position[1] = -0.5f;
                position[2]	= 0.0f;
                movNum = 3;
                break;
        }
    }
    api.setPositionTarget(position); 
}
