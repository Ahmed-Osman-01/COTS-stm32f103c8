/****************************************************************************************************/
/* AUTHOR               :     Ahmed Osman                                                           */
/* Origin Date          :     1/08/2023                                                             */
/* Version              :     1.0.0                                                                 */
/* SWC                  :     IR Reciever                                                           */
/****************************************************************************************************/

#ifndef HIR_PRIV_H
#define HIR_PRIV_H

/****************************************************************************************************/
/* This function is called everytime the IR reciever changes its output to low (when external       */
/* interrupt connected to IR sense a falling edge) which indicates that a frame is being sent by the*/
/* transmitter and this function starts to build this frame into an array where each element is the */
/* time between each consectuive falling edge in the sent frame.                                    */
/****************************************************************************************************/
static void HIR_voidBuildFrame(void);

/****************************************************************************************************/
/* This function is called when the transmission of the frame is completed. It then does a sequence */
/* of actions (extract the address, reverse address, data, and reverse data and then checks if there*/
/* is corruption in the sent frame and then calls the callback function.                            */
/****************************************************************************************************/
static void HIR_voidTakeAction(void);

/****************************************************************************************************/
/* Extracts the Address from the built array which corresponds to the sent frame.                   */
/****************************************************************************************************/
static void HIR_voidExtractAddress(void);

/****************************************************************************************************/
/* Extracts the Reverse Address from the built array which corresponds to the sent frame.           */
/****************************************************************************************************/
static void HIR_voidExtractReverseAddress(void);

/****************************************************************************************************/
/* Extracts the Data from the built array which corresponds to the sent frame.                      */
/****************************************************************************************************/
static void HIR_voidExtractData(void);

/****************************************************************************************************/
/* Extracts the Reverse Data from the built array which corresponds to the sent frame.              */
/****************************************************************************************************/
static void HIR_voidExtractReverseData(void);

/****************************************************************************************************/
/* Checks if there is any fault in the Address or Data by comparing them to the Reverse Address and */
/* Reverse Data                                                                                     */
/****************************************************************************************************/
static void HIR_voidCheckAddressAndData(void);

#endif