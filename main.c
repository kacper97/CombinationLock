
#include <DAVE.h>                 //Declarations from DAVE Code Generation (includes SFR declaration)


 /*
 CODE NOT IMPLEMENTED  == ERRORS  of  1 sec and 5 min flash
 
 CODE TO IMPLEMENT USING STATES , also not used
 currentState=0;
 while(1)
 {
 event=getEvent();
 currentState = set NextState(currentState,nstate,event);
 }
 int setNextState(int currentState, int nState[][], intevent
 if( nState[currentState(event)]<>-1
 {
 return (nstate[current state]( event);
 }
 else
 {
 return (current state);
 }
 */
 
int32_t defaultcomb[4] = {1, 2, 3, 4}; //initializing combination as 1234
int32_t input[4]; // initialzing an array of inputs 
int32_t inputcounter = 0; //input counter corresponds to number of indexes in the array
// cant name the below to push as already have push as digital io
int32_t pushb1; //intitializing push 1
int32_t pushb2; //intitializing push 2
int32_t pushb3; //intitializing push 3
int32_t pushb4; //intitializing push 4
int32_t pushreset; //reset button initialized
int32_t lock;    //Status of the lock
int32_t error; //Status of the error led.
int32_t resetflag = 0; //1 when reset button is pushed, set back to 0 after lock reset


//Clears timer , and resets all the inputs to 0 
void initialize()
{
     TIMER_Stop ( &InputTimer );
     TIMER_Clear( &InputTimer );
     inputcounter = 0;
     input[0] = 0;
     input[1] = 0;
     input[2] = 0;
     input[3] = 0;
}

//Clears timer and resets status of interrupt
void DebounceClear(void)
{
    TIMER_ClearEvent( &DebounceTimer );
    TIMER_Clear( &DebounceTimer );
}

//Clears timer and runs the initialize method
void InputClear(void)
{
    TIMER_ClearEvent( &InputTimer );
    initialize();
}

//Stalls program for 20 miliseconds
void debounce(void)
{
    TIMER_Start( &DebounceTimer );
    while(!TIMER_GetInterruptStatus( &DebounceTimer ));
}  

//If the reset button is pressed
void reset(void)
{
    debounce();
    initialize();
    DIGITAL_IO_SetOutputHigh( &pushReset ); // set the reset pin to high
    debounce(); 			
    resetflag = 1;		//change the int value of reset
    DIGITAL_IO_SetOutputLow( &pushReset  ); // set the reset pin to low
} 

//checks to see if the input is the same as the combination, if yes toggles the lock and clears the input, if no changes value of reset flag
void addEntered(void)
{
    if(resetflag == 0)
    {
        if(input[0] == defaultcomb[0] && input[1] == defaultcomb[1] && input[2] == defaultcomb[2] && input[3] == defaultcomb[3])
        {
            lock = DIGITAL_IO_GetInput( &LockedLed); //a variable for micro Probe programme
						DIGITAL_IO_ToggleOutput( &LockedLed ); //set pin from low to high or vice versa (Default is low)
        }
        else
        {
						error = DIGITAL_IO_GetInput( &ErrorLed );  //a variable for micro Probe programme
            DIGITAL_IO_ToggleOutput( &ErrorLed );      
        }
		initialize(); // this stops input timer  and assigns all inputs to 0 when programme is done
    }
    else // if reset flag is 1, when reset button is pressed
    {
			  initialize();    // reseets all  of these to 0000
        defaultcomb[0] = input[0];
        defaultcomb[1] = input[1];
        defaultcomb[2] = input[2];
        defaultcomb[3] = input[3];
  
        resetflag = 0; // changes value of this variable
    }
}
 
//takes number of button pressed as argument
void buttonPress(int32_t pushbuttonNumber)
{
        TIMER_Start( &InputTimer ); //starts 10 seconds timer for the 4 pushbuttons to be pressed
        debounce();//20 ms delay
 
        if (  pushbuttonNumber ==  1 && pushb1 == 1 )
					{
            DIGITAL_IO_SetOutputHigh( &push1 );
					}
					else if( pushbuttonNumber == 2 && pushb2 == 1 )
					{
            DIGITAL_IO_SetOutputHigh( &push2 );
					}
					else if(  pushbuttonNumber == 3 && pushb3 == 1 )
					{
            DIGITAL_IO_SetOutputHigh( &push3 );
					}
					else if(  pushbuttonNumber == 4 && pushb4 == 1 )
					{
            DIGITAL_IO_SetOutputHigh( &push4 );
					}
				input[inputcounter] = pushbuttonNumber; //sets index of input array to the pushbutton number
        debounce(); //20 ms delay
        inputcounter++; // increment input counter 
}
 
int32_t main(void)
{
 
  DAVE_STATUS_t status;
  status = DAVE_Init();           /* Initialization of DAVE APPs  */
 
  if(status != DAVE_STATUS_SUCCESS)
  {
 
    /* Placeholder for error handler code. The while loop below can be replaced with an user error handler. */
    XMC_DEBUG("DAVE APPs initialization failed\n");
    while(1U)
    {
 
    }
  }
 
  /* Placeholder for user application code. The while loop below can be replaced with user application code. */
  while(1U)
  {
      if( pushb1 == 1 ) //if button1 is pressed, set output == high, add 1 to input array, increment input counter by 1 and this continues down bellow
      {
            buttonPress(1);
        }
      if( pushb2 == 1 )
      {
          buttonPress(2);
      }
      if( pushb3 == 1 )
      {
          buttonPress(3);
      }
      if( pushb4 == 1 )
      {
            buttonPress(4);
      }
      if( pushreset == 1 )
      {
          reset();
      }
      if( inputcounter == 4 ) //if 4 buttons have been pushed, reset inputcounter and check input
      {
            addEntered();
      }
	}
}
