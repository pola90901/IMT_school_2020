#ifndef util_h
#define util_h
#define SET_BIT(var,bitpos) (var=var |(1<<bitpos))
#define CLR_BIT(var,bitpos) var =var &~(1<<bitpos)
#define toggle_bit(var,bitpos) var=var ^ (1<<bitpos)
#define write_byte(var,value)    var =value
#define read_byte(var)    var
#define Get_bit(var,bitpos)   (var>>bitpos)&1

//#define Get_bit(var,bitpos)   (var&(1<<bitpos))>>bitpos
//#define Get_bit(var,bitpos)   (var&(1<<bitpos))?1:0
//#define Get_bit(var,bitpos)   !!(var&(1<<bitpos))

#define toggle_byte(var)  var=var^255
#endif
