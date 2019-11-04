
#define D4 eS_PORTB4
#define D5 eS_PORTB3
#define D6 eS_PORTB2
#define D7 eS_PORTB1
#define RS eS_PORTB6
#define EN eS_PORTB5

#include <avr/io.h>
#include <util/delay.h>
#include "disp.h"


#include <avr/io.h>





int main(void)
{
   
   DDRB=0xFF;
   DDRD=0xFF;
   Lcd4_Init();
   
    DDRD &= ~(1 << DDD5);     // Clear the PD5 pin
    // PD5 is now an input

    PORTD |= (1 << PORTD5);   // turn On the Pull-up
    // PD5 is now an input with pull-up enabled

    TCCR1B |= (1 << CS12) | (1 << CS11) | (1 << CS10);
    // Turn on the counter, Clock on Rise
   
   int count=0;
   char scount[16];
   while(1)
   {
	   
	   count = TCNT1;
	   sprintf(scount,"%d",count);
	   Lcd4_Set_Cursor(1,2);
	  Lcd4_Write_String(scount);
	   
	   
   }
}