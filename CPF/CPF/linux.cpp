#include"pch.h"	
#include <iostream>	
#include <locale.h>	

 using namespace std;	

 int main()	
{ 	
	setlocale(LC_ALL, "portuguese");	

 	int  numero, n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11;	
	cout << "Digite os 9 digitos";	
	cin >>  numero;	
	if (numero >= 999999999 || numero <= 1 ) {  //se o numero digitado for maior que 999milhões ou menor que 1 o numero não pode ser validavel//	
		cout << "numero não validavel";	
	}	
	else {	
		n9 = numero % 10;	
		numero = numero / 10;	
		n8 = numero % 10;	
		numero = numero / 10;	
		n7 = numero % 10;	
		numero = numero / 10;	
		n6 = numero % 10;	
		numero = numero / 10;	
		n5 = numero % 10;	
		numero = numero / 10;	
		n4 = numero % 10;	
		numero = numero / 10;	
		n3 = numero % 10;	
		numero = numero / 10;	
		n2 = numero % 10;	
		numero = numero / 10;	
		n1 = numero % 10;	


 		n10 = ((n1 * 10) + (n2 * 9) + (n3 * 8) + (n4 * 7) + (n5 * 6) + (n6 * 5) + (n7 * 4) + (n8 * 3) + (n9 * 2)) % 11;	
		if (n10 <= 2) {	
			n10 = 0;	
		}	
		else {	
			n10 = 11 - n10;	
		}	
		n11 = ((n1 * 11) + (n2 * 10) + (n3 * 9) + (n4 * 8) + (n5 * 7) + (n6 * 6) + (n7 * 5) + (n8 * 4) + (n9 * 3) + (n10 * 2)) % 11;	
		if (n11 <= 2) {	
			n11 = 0;	
		}	
		else {	
			n11 = 11 - n11;	
		}	
		cout << n1 << n2 << n3 << "." << n4 << n5 << n6 << "." << n7 << n8 << n9 << "-" << n10 << n11;	


 	}	
	system("pause>>null");	
		return 0;	

 }	

