/*
 * HBTN_int.h
 *
 *  Created on: May 30, 2023
 *      Author: Osman
 */

#ifndef HBTN_HBTN_INT_H_
#define HBTN_HBTN_INT_H_


typedef enum
{
	HBTN_PULLUP_CONNECTION,
	HBTN_PULLDOWN_CONNECTION

}HBTN_ConnectionType_t;

typedef struct
{
	u8 						HBTN_ID;
	u8	 					HBTN_Port;
	u8	 					HBTN_Pin;
	HBTN_ConnectionType_t	HBTN_ConnectionType;

}HBTN_Info_t;


typedef enum
{
	HBTN_PRESSED  = 0,
	HBTN_RELEASED = 1

}HBTN_BtnState_t;
/****************************************************************************************************/
/* Initializes the given button by setting the direction of its pin to INPUT 						*/
/* @param ptr_Btn Pointer to the button strcut which contains its data (ID, Port, Pin, Connection)	*/
/* The connection can be Pullup or Pulldown 														*/
/****************************************************************************************************/
ErrorState_t HBTN_enInitBtn(const HBTN_Info_t * ptr_Btn);

/****************************************************************************************************/
/* Reads and returns the state of the button if it's pressed or released and if the user holds the  */
/* button, only the first press is renderd and returnd untill the button is released 				*/
/* NOTE: THIS FUNCTION STILL MISSING THE PART WHERE IT HANDLES DIFFERENT CONNECTION TYPES!!!!! 		*/
/* @param ptr_Btn Pointer to the button strcut which contains its data (ID, Port, Pin, Connection)	*/
/* @param ptrBTNState Pointer to return the state of the button through 							*/
/****************************************************************************************************/
ErrorState_t HBTN_enReadBtn(const HBTN_Info_t * ptrBTN, u8 * ptrBTNState);


#endif /* HBTN_HBTN_INT_H_ */
 