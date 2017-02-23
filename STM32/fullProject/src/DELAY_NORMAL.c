#include "DELAY_NORMAL.h"

/*----------------------------Delay_ms normal-----------------------------------------*/
void Delay_ms_normal( uint32_t num)
{
uint32_t index = 0;
/* default system clock is 168MHz */
for(index = (168000 * num); index != 0; index--)
{}
}

/*----------------------------Delay_us normal-----------------------------------------*/
void Delay_us_normal( uint32_t num)
{
uint32_t index = 0;
/* default system clock is 168MHz */
for(index = (168 * num); index != 0; index--)
{}
}
