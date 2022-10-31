/* ********************************************************************************************
/* @name     : QUEUE.C
/* @brief    : PROGRAM OF THE QUEUE
/* @author   : TAREK ALLAM
/***********************************************************************************************/

/*************************************** START INCLUDES ****************************************/
#include "queue.h"
#include "errorState.h"
#include "stdTypes.h"

#include <stdio.h> // for display queue

/*************************************** END INCLUDES ******************************************/

/*************************************** START PROGRAMS ************************************/
ES_t q_Intial(queue_t *myQ)
{
    ES_t ErrorState_local = ES_NOK;
    if (myQ)
    {
        myQ->q_Elemnts = 0;
        myQ->q_Fornt = -1;
        myQ->q_Rare = -1;
        ErrorState_local = ES_OK;
    }
    else
    {
        ErrorState_local = ES_NULL_POINTER;
    }
    return ErrorState_local;
}

ES_t q_enqueue(queue_t *myQ, uint32 datain)
{
    ES_t ErrorState_local = ES_NOK;
    if (myQ)
    {
        if (!(myQ->q_Elemnts)) // if no elements
        {
            myQ->q_Elemnts = 1;
            myQ->q_Fornt = 0;
            myQ->q_Rare = 0;
            myQ->queueArry[0] = datain;

            ErrorState_local = ES_OK;
        }
        else if ((myQ->q_Elemnts) == QUEUE_MAX_ELEMENTS) // if full queue
        {

            ErrorState_local = ES_NOK;
        }
        else
        {
            myQ->q_Elemnts++;
            if (myQ->q_Rare == QUEUE_MAX_ELEMENTS-1)
            {
                myQ->q_Rare = 0;
            }
            else
            {
                myQ->q_Rare++;
            }
            myQ->queueArry[myQ->q_Rare] = datain;
            ErrorState_local = ES_OK;
        }
    }
    else
    {
        ErrorState_local = ES_NULL_POINTER;
    }

    return ErrorState_local;
}

ES_t q_dequeue(queue_t *myQ, uint32 *dataout)
{
    ES_t ErrorState_local = ES_NOK;

    if (myQ)
    {
        if (myQ->q_Elemnts)
        {
            myQ->q_Elemnts--;
            *dataout = myQ->queueArry[myQ->q_Fornt];
            myQ->q_Fornt++;
            if (myQ->q_Elemnts == 0)
            {
                q_Intial(myQ);
            }
            if ((myQ->q_Fornt > QUEUE_MAX_ELEMENTS))
            {
                myQ->q_Fornt = 0;
            }

            ErrorState_local = ES_OK;
        }
    }

    return ErrorState_local;
}

ES_t q_showFont(queue_t *myQ, uint32 *data)
{
    ES_t ErrorState_local = ES_NOK;
    if ((myQ) && (myQ->q_Elemnts))
    {
        *data = myQ->queueArry[myQ->q_Fornt];
        ErrorState_local = ES_OK;
    }
    return ErrorState_local;
}

ES_t q_showRare(queue_t *myQ, uint32 *data)
{
    ES_t ErrorState_local = ES_NOK;
    if ((myQ) && (myQ->q_Elemnts))
    {
        *data = myQ->queueArry[myQ->q_Rare];
        ErrorState_local = ES_OK;
    }
    return ErrorState_local;
}

ES_t q_showItems(queue_t *myQ)
{
    ES_t ErrorState_local = ES_NOK;
    uint32 counter_1, counter_2 = 1;
    if (myQ)
    {
        for (counter_1 = (myQ->q_Fornt); counter_2 <= myQ->q_Elemnts; counter_1++)
        {
            printf("element %d = %d \n", counter_1, myQ->queueArry[counter_1]);
            counter_2++;
            if (counter_1 >= QUEUE_MAX_ELEMENTS - 1)
            {
                counter_1 = -1;
            }
        }
        printf("number of elments = %d\n", myQ->q_Elemnts);
        ErrorState_local = ES_OK;
    }
    else
    {
    }

    return ErrorState_local;
}
/*************************************** END DECLERATION ******************************************/
/************************************************************************************************
 * AUTHOR              DATE                    BRIEF
 ************************************************************************************************
 * TAREK ALLAM         31 oct 2022             write program's functions
 *
 */