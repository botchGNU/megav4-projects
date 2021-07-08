/*
 * Funktion_01.c
 *
 * Created: 18.03.2021 08:39:20
 * Author : - botch
 * Hardware: ATMega16
 * Use : Mittels Funktion sollen zwei Variableninhalte (8 Bit vorzeichenbehaftete Ganzzahltypen) multipliziert und
 das Ergebnis �ber einen R�ckgabeparameter an das Hauptprogramm �bergeben werden. Das Programm
 muss abschlie�end mittels Simulator verifiziert werden.
 */ 

#include <avr/io.h>

signed int mult_val(signed char a, signed char b) //Funktion Multiplikkation Call by Value
{
	signed int myValVal = a*b; //Kopierte Werte werden multipliziert und in eine Hilfsvariable gespeichert
	return myValVal; //Hilfsvariable wird zur�ckgegeben
}
signed int mult_ref(signed char *a, signed char *b) //Funktion Multiplikkation Call by Reference
{
	signed  int myValRef = (*a)*(*b); //Referenzen werden multipliziert und in eine Hilfsvariable gespeichert
	return  myValRef; //Hilfsvariable wird zur�ckgegeben
}
int main(void)
{
    signed char zahl1 = 4; // Variablen mit 8 Bit vorzeichenbehaftete Ganzzahltyp wird initialisiert
	signed char zahl2 = 3;    
	
	signed int result_val = mult_val(zahl1,zahl2); 
	signed int result_ref = mult_ref(&zahl1,&zahl2);
	//Short wird verwendet, da es sonst zu einem �berlauf kommen kann
	while (1)
	{
		
	}
    
}

