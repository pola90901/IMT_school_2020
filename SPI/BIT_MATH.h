/*
 * BIT_MATH.h
 *
 *  Created on: Aug 12, 2021
 *      Author: User
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define CLR_BIT(REG,bitno) (REG &= ~((1)<<bitno))
#define SET_BIT(REG,bitno) (REG |= ((1)<<bitno))
#define TGL_BIT(REG,bitno) (REG ^= ((1)<<bitno))
#define GET_BIT(REG,bitno) ((REG  >> bitno ) & (1))

#endif /* BIT_MATH_H_ */
