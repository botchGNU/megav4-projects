/*
 * Funktion_02.c
 *
 * Created: 18.03.2021 08:39:20
 * Author : - botch
 * Hardware: ATMega16
 * Use : Mithilfe einer Funktion soll der arithmetische Mittelwert aller Elemente eines eindimensionalen Feldes
 (16 Bit vorzeichenbehaftete Ganzzahltypen) berechnet und mittels R�ckgabeparameter an das Hauptprogramm
 zur�ckgegeben werden. Das Programm muss abschlie�end mittels Simulator verifiziert werden.
 */ 

#include <avr/io.h>

signed int arith_mitt(signed char feld[], signed char length) //Referenz des Feldes wird �bergeben
{
	signed long myVal = 0; //Hilfsvariable wird deklariert und auf 0 gesetzt
	
	for (signed char i = 0 ; i < length; i++) //For Schleife f�r jedes Element im Array
	{
		myVal += feld[i];
	}
	myVal = myVal / length; //Wert wird durch Anzahl der Elemente geteilt
	return myVal; //Ergebnis wird zur�ckgegeben
}

int main(void)
{
    signed char zahl1[] = {3,5};  //Array wird deklariert
		
	signed int result_mitt = arith_mitt(zahl1, 2); //Ergebnis wird in Variable gespeichert
	
	while (1){}
}

