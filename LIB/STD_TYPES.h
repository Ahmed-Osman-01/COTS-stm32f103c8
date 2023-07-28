/*
 * STD_TYPES.h
 *
 *  Created on: Jun 22, 2023
 *      Author: Osman
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef  unsigned char         u8;
typedef  signed char           s8;
typedef  unsigned short int   u16;
typedef  signed short int 	  s16;
typedef  unsigned long int    u32;
typedef  signed long int 	  s32;
typedef  float                f32;
typedef  double		          f64;


#define NULL 				(void*)0

typedef enum
{

    NOK,
    OK,
    OUT_OF_RANGE_ERR,
    NULL_POINTER_ERR

}ErrorState_t;

#endif /* STD_TYPES_H_ */
