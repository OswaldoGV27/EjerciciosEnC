Algoritmo sin_titulo
	Definir var1 Como Entero
	var1=1;
	
	Dimension arreglo[100]; // se puede cambiar la palabra arreglo por lo que yo quiera
	//arreglo[1]="Tres";
	//arreglo[2]=15.23;   Asi se accede a un arreglo en especifico
	
	//Llenando el arreglo
	Mientras (var1<=100) Hacer
		arreglo[var1]=var1;
		var1=var1+1;
		
	FinMientras
	
	var1=1; 
	Mientras (var1<=100) Hacer
		Escribir "El valor en la casilla: ", var1, " del contenedor es: ", arreglo[Var1];
		var1=var1+1;
	FinMientras
	
FinAlgoritmo
