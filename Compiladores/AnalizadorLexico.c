//Definición de bibiliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaración de la función Analizador
//Recibe: La cadena y su longitud
void Analizador(char *cadena, int longitud);
//Declaración de la función principal
int main()
{
 	//Declaración de variables
	int longitud;
	char *cadena;
 	//Se reserva memoria dinámica para el arreglo que va a contener a la cadena
 	cadena = (char*)malloc(sizeof(char)*1000);
 	//Si no se reserva memoria dinámica para el arreglo, el programa finaliza
 	if(cadena == NULL)
 	{
  		printf("No se reservo memoria dinamica correctamente\n");
  		exit(0);
 	}	 

	 //Mediante la función fgets se va a leer la cadena, debido a que si existen espacios, no corte la cadena al 
 	//momento de leerla.
 	//Va a recibir la cadena con un tamaño máximo de 1000 mediante una entrada por teclado.
  	fgets(cadena, sizeof(*cadena)*1000, stdin);
  	//Se calcula la longitud de la cadena
  	longitud = strlen(cadena);
  	//Si el último caracter de la cadena es un salto de línea, lo sustituye por el caracter nulo para que se vuelva una cadena
  	if (cadena[longitud-1] == '\n')
  	{
    	cadena[longitud-1] = '\0';
    	longitud--;
  	}
   
  	//Se pasan los parámetros a la función principal
  	Analizador(cadena, longitud);
  	//Se libera la memoria dinámica del programa
  	free(cadena);

	 return 0;
}

//Lo que realiza la función Analizador es comparar cada uno de los elementos de la cadena con ciertos caracteres
//para ver si corresponden a un ID, un número, un operador o un espacio
void Analizador(char *cadena, int longitud)
{
 //Declaración de variables
	int i, j;
	char aux[100];

//Se crea un arreglo for con tamaño de la longitud de la cadena para poder recorrer todos los símbolos
	for (i = 0; i < longitud; ++i){
   //Se inicializa la variable aux para guardar los caracteres de la cadena que pertenezcan a cierto grupo
   		aux[0] = '\0';
   		//Si el caracter de la cadena esta en un rango de 0 a 9, pertenece al token número
		if (cadena[i] >= '0' && cadena[i] <= '9'){
      		//Se forma el token a partir de este punto
      		printf("<NUM, ");
      		printf("%c", cadena[i]);    
      		//Se siguen recorriendo posiciones en el arreglo, si se da el caso de que los
      		//demás caracteres también sean números, se agregaran al token creado. 
      		for (j = i+1; j < longitud; ++j){
        		if (cadena[j] >= '0' && cadena[j] <= '9'){
            	//Se imprime en pantalla el caracter y se aumenta en 1 la posición del arreglo que se recorre
            	printf("%c", cadena[j]);    
            	i++; 
        		}
         	//Si el caracter siguiente no es un número la sentencia break hace que salga del for
    			else{
        			break;
        		}
        	}
    	//Se cierra el token
    	printf(">\n");
    	}
    	
   		//Si el caracter de la cadena es + o -, el caracter pertenece a al token operador.
   		else if (cadena[i] == '+' || cadena[i] == '-')
   		{
      		//Si el siguiente caracter de la cadena es un operador, se toma como un operador no válido.
      		if (cadena[i+1] == '+' || cadena[i+1] == '-')
      		{
        		//Se imprime que es un operador no válido y se pasa a el siguiente caracter de la cadena
        		printf("<OpNoValido, %c%c>\n", cadena[i], cadena[i+1]);
        		i++;
      		}
      		//Si el operador no contiene a otro operador después, se imprime el token de operador válido
      		else
      		{      
      			printf("<OP, %c>\n", cadena[i]);
      		}		      
   		}
   		
   		//Si el caracter de la cadena se encuentra en un rango de a hasta z, se guardará en el token de ID
  		else if(cadena[i] >= 'a' && cadena[i] <='z')
   		{
      		/*Se va a recorrer el arreglo desde la posición i donde se encuentra evaluando a la cadena, si los siguientes 
      		caracteres también son letras minúsculas los tomará como válidos, siempre y cuando sólo sean 2. Si se excede
      		de 2 caracteres en letras, el ID se considerará no válido.*/ 
      		
      		for (j = i; j < longitud; ++j)
      		{
         		if (cadena[j] >= 'a' && cadena[j] <= 'z')
         		{
          			/*Debido a que j empieza en i, los caracteres se guardarán en un arreglo auxiliar que empieza desde 0, 
					lo cual me permitirá guardar correctamente los caracteres*/
            		aux[j-i] = cadena[j];          
         		}
         		//Si los demás caracteres no son letras, break me permitirá salir del for
         		else
         		{
          			break;
         		}   
      		}
      		//Se agrega el caracter nulo al final de arreglo auxiliar
      		aux[j - i] = '\0';
      		//Si la longitud del token es mayor a 2, se considera un ID no válido
      		if (strlen(aux) > 2)
      		{
            	printf("<IDNoValido, %s>\n", aux);    
      
         	} 		   
      		//Si la longitud del token es igual a 2, se considera ID válido
      		else if (strlen(aux) == 2)
         	{
           		printf("<ID, %s>\n", aux);            
         	}
      		//Si el token es menor a 2, también lo considerará como ID válido
      		else
       		{
          		printf("<ID, %s> \n", aux); 
        	} 
        	//Se coloca a i, en la posición de j, la cuál nos dice cuál fue el último 
        	//caracter que se revisó
         	i = j - 1;
    	}
    
   		//Si se trata de un espacio en blanco en la cadena, se omitirá
   		else if (cadena[i] == ' ')
   		{
   		}
  		
   		else
   		{
      		printf("<NoValido, %c >\n", cadena[i]);
   		}
  	}
   	return;
}



