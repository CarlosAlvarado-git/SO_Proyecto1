#include <linux/kernel.h>
#include <linux/syscalls.h>

SYSCALL_DEFINE2(expr_arit, char *, ex, int *, result){
	int i[255];
	i[0] = 0;
	int numeros[255];
	char operadores[255];
	operadores[0] = '$';
	int cont_numeros = 0;
	int cont_operadores = 0;
	int cont = 0;
	int bandera = 0;
	int bandera_numero = 0;
	int bandera_mult_div = 0;
	int j = 0;
	int temporal;
	int r = 0;
	int b = 0;
	int a = 0;
	char op;;
	while(*(ex+1) != 0 && bandera == 0){
		switch (*ex){
			case 40:// (
				printk("Desde la funcion:  %c\n", *ex);
				i[cont++] = 1;
				bandera_numero = 0;
				bandera_mult_div = 0;
				if (cont_operadores == 0 && cont_numeros != 0){
					operadores[cont_operadores] = '*';
					cont_operadores = cont_operadores + 1;	
				}
			break;
			case 41:// )
				printk("Desde la funcion:  %c\n", *ex);
				if (i[--cont] == 1){
					if (cont_operadores != 0){
					i[cont] = 0;		
					bandera_numero = 0;
					// sacar operandos (numeros)
					b = numeros[--cont_numeros];
					a = numeros[--cont_numeros];
					// sacar operador
					op = operadores[--cont_operadores];
					operadores[cont_operadores] = '$';
					// operar
					switch(op){
						case 42:
						   printk("Operador: *\n");
						   r = a*b;
						break;
						case 43:
						   //printk("Operador: +\n");
						   r = a+b;
						break;
						case 45:
					           //printk("Operador: -\n");
						   r = a-b;
						break;
						case 47:
						   //printk("Operador: /\n");
						   r = a/b;
						default:
						   break;
					}
					numeros[cont_numeros++] = r;
					printk("La operacion da como resultado %d \n", r);
printk("La cont de numeros es, recuerda restar 1: %d \n", cont_numeros);
					}
					else{i[cont] = 0;		
					bandera_numero = 0;}
				}
				else 
				{
					bandera = 1;
			         	printk("ERROR ARITMETICO\n");
				}
			break;
			case 91:// [
				printk("Desde la funcion:  %c\n", *ex);
				i[cont++] = 2;
				bandera_numero = 0;
				bandera_mult_div = 0;
				if (cont_operadores == 0 && cont_numeros != 0){
					operadores[cont_operadores] = '*';
					cont_operadores = cont_operadores + 1;	
				}
			break;
			case 93:// ]
				printk("Desde la funcion:  %c\n", *ex);
				if (i[--cont] == 2){
					if (cont_operadores != 0){
					i[cont] = 0;
					bandera_numero = 0;
					// sacar operandos (numeros)
					b = numeros[--cont_numeros];
					a = numeros[--cont_numeros];
					// sacar operador
					op = operadores[--cont_operadores];
					operadores[cont_operadores] = '$';
					// operar
					switch(op){
						case 42:
						   printk("Operador: *\n");
						   r = a*b;
						break;
						case 43:
						   //printk("Operador: +\n");
						   r = a+b;
						break;
						case 45:
					           //printk("Operador: -\n");
						   r = a-b;
						break;
						case 47:
						   //printk("Operador: /\n");
						   r = a/b;
						default:
						   break;
					}
					numeros[cont_numeros++] = r;	
					printk("La operacion da como resultado %d \n", r);	
printk("La cont de numeros es, recuerda restar 1: %d \n", cont_numeros);
					}
					else{i[cont] = 0;		
					bandera_numero = 0;}
				}
				else 
				{
					bandera = 1;
			         	printk("ERROR ARITMETICO\n");
				}
			break;
			case 48:
				printk("Numero: 0\n");
				if (bandera_numero == 1){
					temporal = (*ex - 48);
					numeros[(cont_numeros-1)] = (numeros[cont_numeros-1] * 10) + temporal;
				}
				else{
					temporal = (*ex - 48);
					numeros[cont_numeros++] = temporal;
				}
				if (bandera_mult_div == 1){
					// sacar operandos (numeros)
					b = numeros[--cont_numeros];
					a = numeros[--cont_numeros];
				        op = operadores[--cont_operadores];
					operadores[cont_operadores] = '$';
					// operar
					switch(op){
						case 42:
							r = a*b;
						break;
						case 47:
							r = a/b;
						break;
						default: 
							break;
					
					}
					numeros[cont_numeros++] = r;
					printk("La operacion da como resultado %d \n", r);
					bandera_mult_div = 0;
				}
				bandera_numero = 1;
			break;
			case 49:
				printk("Numero: 1\n");
				if (bandera_numero == 1){
					temporal = (*ex - 48);
					numeros[(cont_numeros-1)] = (numeros[cont_numeros-1] * 10) + temporal;
				}
				else{
					temporal = (*ex - 48);
					numeros[cont_numeros] = temporal;
					cont_numeros = cont_numeros+1;
				}
				if (bandera_mult_div == 1){
					// sacar operandos (numeros)
					b = numeros[--cont_numeros];
					a = numeros[--cont_numeros];
				        op = operadores[--cont_operadores];
					operadores[cont_operadores] = '$';
					// operar
					switch(op){
						case 42:
							r = a*b;
						break;
						case 47:
							r = a/b;
						break;
						default: 
							break;
					
					}
					numeros[cont_numeros++] = r;
					printk("La operacion da como resultado %d \n", r);
					bandera_mult_div = 0;
				}
				bandera_numero = 1;
			break;
			case 50:
				printk("Numero: 2\n");
				if (bandera_numero == 1){
					temporal = (*ex - 48);
					numeros[(cont_numeros-1)] = (numeros[cont_numeros-1] * 10) + temporal;
				}
				else{
					temporal = (*ex - 48);
					numeros[cont_numeros] = temporal;
					cont_numeros = cont_numeros+1;
				}
				if (bandera_mult_div== 1){
					// sacar operandos (numeros)
					b = numeros[--cont_numeros];
					a = numeros[--cont_numeros];
				        op = operadores[--cont_operadores];
					operadores[cont_operadores] = '$';
					// operar
					switch(op){
						case 42:
							r = a*b;
						break;
						case 47:
							r = a/b;
						break;
						default: 
							break;
					
					}
					numeros[cont_numeros++] = r;
					printk("La operacion da como resultado %d \n", r);
					bandera_mult_div = 0;
				}
				bandera_numero = 1;
			break;
			case 51:
				printk("Numero: 3\n");
				if (bandera_numero == 1){
					temporal = (*ex - 48);
					numeros[(cont_numeros-1)] = (numeros[cont_numeros-1] * 10) + temporal;
				}
				else{
					temporal = (*ex - 48);
					numeros[cont_numeros] = temporal;
					cont_numeros = cont_numeros+1;
				}
				if (bandera_mult_div == 1){
					// sacar operandos (numeros)
					b = numeros[--cont_numeros];
					a = numeros[--cont_numeros];
				        op = operadores[--cont_operadores];
					operadores[cont_operadores] = '$';
					// operar
					switch(op){
						case 42:
							r = a*b;
						break;
						case 47:
							r = a/b;
						break;
						default: 
							break;
					
					}
					numeros[cont_numeros++] = r;
					printk("La operacion da como resultado %d \n", r);
					bandera_mult_div = 0;
				}
				bandera_numero = 1;
			break;
			case 52:
				printk("Numero: 4\n");
				if (bandera_numero == 1){
					temporal = (*ex - 48);
					numeros[(cont_numeros-1)] = (numeros[cont_numeros-1] * 10) + temporal;
				}
				else{
					temporal = (*ex - 48);
					numeros[cont_numeros] = temporal;
					cont_numeros = cont_numeros+1;
				}
				if (bandera_mult_div == 1){
					// sacar operandos (numeros)
					b = numeros[--cont_numeros];
					a = numeros[--cont_numeros];
				        op = operadores[--cont_operadores];
					operadores[cont_operadores] = '$';
					// operar
					switch(op){
						case 42:
							r = a*b;
						break;
						case 47:
							r = a/b;
						break;
						default: 
							break;
					
					}
					numeros[cont_numeros++] = r;
					printk("La operacion da como resultado %d \n", r);
					bandera_mult_div = 0;
				}
				bandera_numero = 1;
			break;
			case 53:
				printk("Numero: 5\n");
				if (bandera_numero == 1){
					temporal = (*ex - 48);
					numeros[(cont_numeros-1)] = (numeros[cont_numeros-1] * 10) + temporal;
				}
				else{
					temporal = (*ex - 48);
					numeros[cont_numeros] = temporal;
					cont_numeros = cont_numeros+1;
				}
				if (bandera_mult_div == 1){
					// sacar operandos (numeros)
					b = numeros[--cont_numeros];
					a = numeros[--cont_numeros];
				        op = operadores[--cont_operadores];
					operadores[cont_operadores] = '$';
					// operar
					switch(op){
						case 42:
							r = a*b;
						break;
						case 47:
							r = a/b;
						break;
						default: 
							break;
					
					}
					numeros[cont_numeros++] = r;
					printk("La operacion da como resultado %d \n", r);
					bandera_mult_div = 0;
				}
				bandera_numero = 1;
			break;
			case 54:
				printk("Numero: 6\n");
				if (bandera_numero == 1){
					temporal = (*ex - 48);
					numeros[(cont_numeros-1)] = (numeros[cont_numeros-1] * 10) + temporal;
				}
				else{
					temporal = (*ex - 48);
					numeros[cont_numeros] = temporal;
					cont_numeros = cont_numeros+1;
				}
				if (bandera_mult_div == 1){
					// sacar operandos (numeros)
					b = numeros[--cont_numeros];
					a = numeros[--cont_numeros];
				        op = operadores[--cont_operadores];
					operadores[cont_operadores] = '$';
					// operar
					switch(op){
						case 42:
							r = a*b;
						break;
						case 47:
							r = a/b;
						break;
						default: 
							break;
					
					}
					numeros[cont_numeros++] = r;
					printk("La operacion da como resultado %d \n", r);
					bandera_mult_div = 0;
				}
				bandera_numero = 1;
			break;
			case 55:
				printk("Numero: 7\n");
				if (bandera_numero == 1){
					temporal = (*ex - 48);
					numeros[(cont_numeros-1)] = (numeros[cont_numeros-1] * 10) + temporal;
				}
				else{
					temporal = (*ex - 48);
					numeros[cont_numeros] = temporal;
					cont_numeros = cont_numeros+1;
				}
				if (bandera_mult_div == 1){
					// sacar operandos (numeros)
					b = numeros[--cont_numeros];
					a = numeros[--cont_numeros];
				        op = operadores[--cont_operadores];
					operadores[cont_operadores] = '$';
					// operar
					switch(op){
						case 42:
							r = a*b;
						break;
						case 47:
							r = a/b;
						break;
						default: 
							break;
					
					}
					numeros[cont_numeros++] = r;
					printk("La operacion da como resultado %d \n", r);
					bandera_mult_div = 0;
				}
				bandera_numero = 1;
			break;
			case 56:
				printk("Numero: 8\n");
				if (bandera_numero == 1){
					temporal = (*ex - 48);
					numeros[(cont_numeros-1)] = (numeros[cont_numeros-1] * 10) + temporal;
				}
				else{
					temporal = (*ex - 48);
					numeros[cont_numeros] = temporal;
					cont_numeros = cont_numeros+1;
				}
				if (bandera_mult_div == 1){
					// sacar operandos (numeros)
					b = numeros[--cont_numeros];
					a = numeros[--cont_numeros];
				        op = operadores[--cont_operadores];
					operadores[cont_operadores] = '$';
					// operar
					switch(op){
						case 42:
							r = a*b;
						break;
						case 47:
							r = a/b;
						break;
						default: 
							break;
					
					}
					numeros[cont_numeros++] = r;
					printk("La operacion da como resultado %d \n", r);
					bandera_mult_div = 0;
				}
				bandera_numero = 1;
			break;
			case 57:
				printk("Numero: 9\n");
				if (bandera_numero == 1){
					temporal = (*ex - 48);
					numeros[(cont_numeros-1)] = (numeros[cont_numeros-1] * 10) + temporal;
				}
				else{
					temporal = (*ex - 48);
					numeros[cont_numeros] = temporal;
					cont_numeros = cont_numeros+1;
				}
				if (bandera_mult_div == 1){
					// sacar operandos (numeros)
					b = numeros[--cont_numeros];
					a = numeros[--cont_numeros];
				        op = operadores[--cont_operadores];
					operadores[cont_operadores] = '$';
					// operar
					switch(op){
						case 42:
							r = a*b;
						break;
						case 47:
							r = a/b;
						break;
						default: 
							break;
					
					}
					numeros[cont_numeros++] = r;
					printk("La operacion da como resultado %d \n", r);
					bandera_mult_div = 0;
				}
				bandera_numero = 1;
			break;
			case 42:
				printk("Operador: *\n");
				operadores[cont_operadores] = *ex;
				cont_operadores = cont_operadores + 1;
				bandera_mult_div = 1;
				bandera_numero = 0;
			break;
			case 43:
				printk("Operador: +\n");
				operadores[cont_operadores] = *ex;
				cont_operadores = cont_operadores + 1;
				bandera_numero = 0;
			break;
			case 45:
				printk("Operador: -\n");
				operadores[cont_operadores] = *ex;
				cont_operadores = cont_operadores + 1;
				bandera_numero = 0;
			break;
			case 47:
				printk("Operador: /\n");
				operadores[cont_operadores] = *ex;
				cont_operadores = cont_operadores + 1;
				bandera_numero = 0;
				bandera_mult_div = 1;
			break;
    		default:
			break;
		}
		ex = (ex+1);
	}
	if (i[0] == 0){	
		
		while (operadores[0] != 36){	
	           // sacar operandos (numeros)
		   b = numeros[--cont_numeros];
		   a = numeros[--cont_numeros];
		// sacar operador
		   op = operadores[--cont_operadores];
		   operadores[cont_operadores] = '$';
		// operar
		   r = 0;
		   switch(op){
			   case 42:
			      //printk(" AFUERAOperador: *\n");
			      r = a*b;
			   break;
			   case 43:
			      //printk("Operador: +\n");
			      r = a+b;
			   break;
			   case 45:
		              //printk("Operador: -\n");
			      r = a-b;
			   break;
			   case 47:
			      //printk("Operador: /\n");
			      r = a/b;
			   default:
			      break;
		   }
		   numeros[cont_numeros++] = r;	
		   printk("La operacion da como resultado %d \n", r);	
		}
		printk("EXPERSION CORRECTA\n");
		printk("RESULTADO ES: %d\n", numeros[0]);
		*result = numeros[0];
		   
	}else {
		printk("EXPERSION INCORRECTA\n");				
	}
	
	return 0;
}
