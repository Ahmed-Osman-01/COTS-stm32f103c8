/****************************************************************************************************/
/* AUTHOR               :     Ahmed Osman                                                           */
/* Origin Date          :     19/07/2023                                                            */
/* Version              :     1.0.0                                                                 */
/* SWC                  :     NVIC                                                                  */
/****************************************************************************************************/

#ifndef MNVIC_PRIV_H
#define MNVIC_PRIV_H

/* System Control Block - Application Interrupt and Reset Control Register [31:16] required key for writing */
#define MSCB_AIRCR_KEY   ((0x05FA) << 16)

#define MSCB_AIRCR_PRIGROUP_START_BIT    8


/****************************************************************************************************/
/* Binary points specify the number of group-priorities and sub-priorities by specifying the number */
/* of bits for each of them that can be configured in the NVIC Interrupt Periority registers        */
/****************************************************************************************************/
#define   GROUP_4_SUB_0     0b011 
#define   GROUP_3_SUB_1     0b100 
#define   GROUP_2_SUB_2     0b101 
#define   GROUP_1_SUB_3     0b110 
#define   GROUP_0_SUB_4     0b111


#endif