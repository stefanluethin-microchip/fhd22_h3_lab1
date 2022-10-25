/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include "definitions.h"                // SYS function prototypes


// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************
volatile uint32_t myCnt;
const uint32_t cEchoCnt=0xA;
#define cEchoCnt 10
volatile bool tmrExFlag;

typedef enum states {LOWSTATE, HIGHSTATE, SWITCHSTATE} cntStates;
cntStates cntState;
//#define VERS1 //-simple if-else
#define VERS2   //-switch-case

void sysTmr_handler(uintptr_t context)
{
    tmrExFlag=true;
}

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    
    printf("Start Lab1...\n\r");
    
    myCnt=0;
    tmrExFlag=false;
    cntStates cntState = LOWSTATE;

    
    SYSTICK_TimerCallbackSet(&sysTmr_handler, (uintptr_t) NULL);
    SYSTICK_TimerStart();

    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        //SYS_Tasks ( );
        if(tmrExFlag)
        {
            tmrExFlag=false;
            LED_Toggle();
            myCnt++;

#ifdef VERS1
            //cEchoCnt=10 -> cEchoCnt/2=5
            //0 < myCnt <= 5  -> 1,2,3,4,5  -> 'a'
            //5 < myCnt <= 10 -> 6,7,8,9,10 -> 'b'
            if(      0<myCnt          && cEchoCnt/2>=myCnt)
                printf("%d: a, ",(int)myCnt);
            else if (cEchoCnt/2<myCnt && cEchoCnt>=myCnt)
            {
                printf("%d: b, ",(int)myCnt);
                if (cEchoCnt==myCnt)
                {
                    myCnt=0;
                    printf("%d: c, \n\r",(int)myCnt);
                }
            }
            else
                printf("%d: d",(int)myCnt); //-should never get here!!
#endif
#ifdef VERS2
            //cEchoCnt=10 -> cEchoCnt/2=5
            //0 < myCnt <= 5  -> 1,2,3,4,5  -> 'a'
            //5 < myCnt <= 10 -> 6,7,8,9,10 -> 'b'
            //typedef enum states {LOWSTATE, HIGHSTATE, SWITCHSTATE} cntStates;
            //cntStates cntState = LOWSTATE;
            switch(cntState)
            {
                case LOWSTATE:
                {
                    printf("%d: a, ",(int)myCnt);
                    if((cEchoCnt/2)==myCnt)
                        cntState=HIGHSTATE;
                    break;
                }
                case HIGHSTATE:
                {
                    printf("%d: b, ",(int)myCnt);
                    if (cEchoCnt==myCnt)
                        cntState=SWITCHSTATE;
                    break;
                }
                case SWITCHSTATE:
                {
                    myCnt=0;
                    printf("%d: c, \n\r",(int)myCnt);
                    cntState=LOWSTATE;
                    break;
                }
                default:
                printf("%d: d",(int)myCnt); //-should never get here!!
            }
#endif 
        } //-end 'if(tmrExFlag...
    } //-end 'while'

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
} //-end main())


/*******************************************************************************
 End of File
*/

