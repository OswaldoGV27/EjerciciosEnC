Algoritmo areasperimetros
	Definir op Como Entero
	//Menú de acciones
	//Oswaldo Gil Valentin 1CV8
	Repetir
	 Escribir "Seleccione la figura que desea sacar el área y el perímetro";
	 Escribir "-----------------------------------------------------------";
	 Escribir "                   1.- Cuadrado";
	 Escribir "                   2.- Círculo";
	 Escribir "                   3.- Triángulo Rectángulo";
	 Escribir "                   4.- Rectángulo";
	 Escribir "                   5.- Pentágono";
	 Escribir "                   6.- Salir";
	 Leer op;
	 
	 //Cuadrado
	 
	 Si (op=1) entonces
		 //Área
		 
		Escribir "ÁREA DEL CUADRADO";
		definir num1 como real
		Escribir "Inserte la longitud de un lado del cuadrado";
		leer num1
		Mientras (num1<=0) Hacer
			 Escribir "El número que igresó no es válido, ingrese un numero mayor a 0";
			 num1=num1+1;
		FinMientras
		resultado1= num1*num1
		Escribir "El área de el cuadrado es ", resultado1;
		
		//Perimetro
		Escribir "PERÍMETRO DEL CUADRADO";
		definir num2 como real
		Escribir "Inserte la longitud de un lado del cuadrado";
		leer num2
		Mientras (num2<=0) Hacer
			Escribir "El número que igresó no es válido, ingrese un numero mayor a 0";
			num2=num2+1;
		FinMientras
		resultado2= num2+num2+num2+num2
		Escribir "El Perímetro del cuadrado es ", resultado2;
	 FinSi
	 
	 //Circulo
	 
	 Si (op=2) Entonces
		//Area
		Escribir "ÁREA DEL CÍRCULO";
		definir num3 Como Real
		Escribir "Inserte el radio del círculo";
		leer num3
		Mientras (num3<=0) Hacer
			Escribir "El número que igresó no es válido, ingrese un numero mayor a 0";
			num3=num3+1;
		FinMientras
		resultado3=PI*(num3*num3)
		Escribir "El área del círculo es ", resultado3;
		
		//Perimetro
		Escribir "PERÍMETRO DEL CÍRCULO";
		definir num4 Como Real
		Escribir "inserte el RADIO del círculo";
		leer num4
		Mientras (num4<=0) Hacer
			Escribir "El número que igresó no es válido, ingrese un numero mayor a 0";
			num4=num4+1;
		FinMientras
		resultado4=PI*(num4+num4)
		Escribir "El perimetro del circulo es ", resultado4;
	 FinSi
	 
	 //Triangulo rectángulo
	 
	 si (op=3) Entonces
		//Área
		Escribir "ÁREA DEL TRIÁNGULO RECTÁNGULO";
		definir num5, num6 Como Real
		Escribir "Inserte el valor de la base";
		leer num5
		Mientras (num5<=0) Hacer
			Escribir "El número que igresó no es válido, ingrese un numero mayor a 0";
			num5=num5+1;
		FinMientras
		Escribir "inserte el valor de la altura";
		leer num6
		Mientras (num6<=0) Hacer
			Escribir "El número que igresó no es válido, ingrese un numero mayor a 0";
			num6=num6+1;
		FinMientras
		resultado5=(num5*num6)/2
		Escribir "El área del triángulo rectángulo es ", resultado5;
		
		//Perimetro
		Escribir "PERIMETRO DEL TRIANGULO RECTANGULO";
		Definir num7, num8, num9 Como real
		Escribir "Inserte el valor de la base del triángulo";
		leer num7
		Mientras (num7<=0) Hacer
			Escribir "El número que igresó no es válido, ingrese un numero mayor a 0";
			num7=num7+1;
		FinMientras
		
		Escribir "Inserte el valor de la altura del triángulo";
		leer num8
		Mientras (num8<=0) Hacer
			Escribir "El número que igresó no es válido, ingrese un numero mayor a 0";
			num8=num8+1;
		FinMientras
		
		Escribir "Inserte el valor de la hipotenusa del triángulo";
		leer num9
		Mientras (num9<=0) Hacer
			Escribir "El número que igresó no es válido, ingrese un numero mayor a 0";
			num9=num9+1;
		FinMientras
		resultado6=num7+num8+num9
		Escribir "El perímetro del triángulo rectángulo es ", resultado6;
	 FinSi
	 
	 //Rectángulo
	 
	 Si (op=4) Entonces
		//Área
		Escribir "ÁREA DEL RECTÁNGULO";
		Definir num10, num11 Como Real
		Escribir "Inserte el valor de la base del Rectángulo";
		leer num10
		Mientras (num10<=0) Hacer
			Escribir "El número que igresó no es válido, ingrese un numero mayor a 0";
			num10=num10+1;
		FinMientras
		Escribir "Inserte al valor de la altura del Rectángulo";
		leer num11
		Mientras (num11<=0) Hacer
			Escribir "El número que igresó no es válido, ingrese un numero mayor a 0";
			num11=num11+1;
		FinMientras
		resultado7=num10*num11
		Escribir "El área del Rectángulo es ", resultado7;
		
		//Perímetro
		Escribir "PERÍMETRO DEL RECTÁNGULO";
		Definir num12, num13 Como Real
		Escribir "Inserte el valor de la base del Rectángulo";
		leer num12
		Mientras (num12<=0) Hacer
			Escribir "El número que igresó no es válido, ingrese un numero mayor a 0";
			num12=num12+1;
		FinMientras
		Escribir "Inserte al valor de la altura del Rectángulo";
		leer num13
		Mientras (num13<=0) Hacer
			Escribir "El número que igresó no es válido, ingrese un numero mayor a 0";
			num13=num13+1;
		FinMientras
		resultado8=(num12+num13)*2
		Escribir "El área del Rectángulo es ", resultado8;
	 FinSi
	 
	 //Pentágono
	 
	 Si (op=5) Entonces
		//Perímetro
		Escribir "PERÍMETRO DEL PENTÁGONO";
		Definir num14 Como Real
		Escribir "Inserte el valor de un lado del Pentágono";
		leer num14
		Mientras (num14<=0) Hacer
			Escribir "El número que igresó no es válido, ingrese un numero mayor a 0";
			num14=num14+1;
		FinMientras
		resultado9=num14*5
		Escribir "El área del Pentágono es ", resultado9;
		
		//Área
		Escribir "ÁREA DEL PENTÁGONO";
		Definir num15 Como Real
		Escribir "Inserte al valor del apotema del Pentágono";
		leer num15
		Mientras (num15<=0) Hacer
			Escribir "El número que igresó no es válido, ingrese un numero mayor a 0";
			num15=num15+1;
		FinMientras
		a=resultado9
		resultado10=(resultado9*num15)/2
		Escribir "El área del Pentágono es ", resultado10;
	 FinSi
	 
	 //Salir
	 Hasta Que (op==6)
FinAlgoritmo
