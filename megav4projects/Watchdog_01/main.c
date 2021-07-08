/*
* Watchdog_01.c
* Created: 3.3.2021
* Author: - botch
Zweck: Demonstration des Watchdog-Reset;
Funktion: Watchdog-Reset nach 2s
Durch vorzeitiges Dr�cken von S0 wird Watchdog zur�ckgesetzt
Hardware: MEGACARD v4
LED-Status nach Reset:
=====================
LED0: PORF (Power-On Reset)
LED1: EXTRF (Externer Reset)
LED2: BORF (Brown-Out Reset)
LED3: WDRF (Watchdog Reset)
LED4: JTRF (JTAG Reset)
*/

#define F_CPU 12000000UL
#include <avr/io.h>
#include <avr/wdt.h> //Bibliothek f�r Watchdog einbinden
#include <util/delay.h>  //Delay Bibliothek Einbinden

int main(void)
{
	DDRC = 0xFF; //LED als Ausgang
	DDRA = 0x00; //Taster als Eingang
	PORTA |= (1<<PA0); // Pullup f�r Taster S0 setzen
	PORTC = (MCUCSR & 0x1F); //Watchdog Flag auf LEDs schreiben
	_delay_ms(2000); // LED status f�r 2s stehen lassen
	MCUCSR = !(MCUCSR & 0x1F); // Flags zur�cksetzen
	PORTC = 0x00; // Alle LEDs auf aus setzen
	wdt_enable(7); // Watchdog aktivieren / scharf mahen mit botcheout auf 2s
	while(1) // Arbeitsschleife
	{
		_delay_ms(100); // 200ms Warten
		PORTC++; //LED status um eines erh�hen
		
		if (!(PINA & (1<<PA0))) // Abfrage ob Taster S0 gedr�ckt wird
		{
			wdt_reset(); // Watchdog zur�cksetzen
		}
	}
}

