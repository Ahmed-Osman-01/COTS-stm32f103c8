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
	BTN_PULLUP_CONNECTION,
	BTN_PULLDOWN_CONNECTION

}BTN_ConnectionType_t;

typedef struct
{
	u8 						BTN_ID;
	u8	 					BTN_Port;
	u8	 					BTN_Pin;
	BTN_ConnectionType_t	BTN_ConnectionType;

}BTN_Info_t;


typedef enum
{
	BTN_PRESSED  = 0,
	BTN_RELEASED = 1

}BTN_BtnState_t;

/* Initializes the given button by setting the direction of its pin to INPUT */
ErrorState_t BTN_enInitBtn(const BTN_Info_t * ptr_Btn);
ErrorState_t BTN_enReadBtn(const BTN_Info_t * ptrBTN, u8 * ptrBTNState);


#endif /* HBTN_HBTN_INT_H_ */
