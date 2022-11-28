
#ifndef util.h

#define util.h

#define SET_BIT(var,bit_position) var=var|(1<<bit_position)
#define CLEAR_BIT(var,bit_position) var=var& (~(1<<bit_position))
#define TOGGLE_BIT(var,bit_position) var=var^(1<<bit_position)
#define WRITE_BYTE(var,value) var=value
#define READ_BYTE(var) var
#define GET_BIT(var,bit_position) (var>>bit_position)&1

#define TOGGLE_BYTE(var) var=~(var)


#endif
