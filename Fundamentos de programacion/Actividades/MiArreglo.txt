Algoritmo MiArreglo
	//Oswaldo Gil Valentin 1CV8
	//Creación de las casillas
	Definir var Como Entero
	Definir repetido como logico
	var=1;
	Dimension Arreglo[20]
	
	//Valores de las casillas originales
	repetir
		var=1;
		Mientras (var<=20) Hacer
			num=1+azar(100);
			repetido=falso
			Escribir "________________";
			Escribir "CASILLA ORIGINAL";
			Escribir "EL valor de la casilla ", var, " es ", num;
			Escribir "EL TRIPLE DEL VALOR DE LA CASILLA ORIGINAL";
			Escribir "El triple del valor de la casilla ", var, " es ", num*3;
			Escribir "NUMERO PAR DE LA CASILLA";
			Si num mod 2==0 Entonces
				Escribir "Numero par de la casilla ", var, " es ", num;
			SiNo 
				Escribir "La casilla ", var, " no tiene numero par";
			FinSi
			Escribir "________________";
			var=var+1; 
		FinMientras
	Hasta que (repetido=Falso)
FinAlgoritmo
