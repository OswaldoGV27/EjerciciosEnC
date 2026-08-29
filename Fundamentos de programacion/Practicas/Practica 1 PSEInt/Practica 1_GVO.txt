Algoritmo Cine
	//Programa Oswaldo Gil Valentín 1CV8
	//Practica 1
	Escribir "Bienvenido a CinESCOM";
	Escribir "Por favor ingrese su año de nacimiento";
	
	//Proceso de ingreso de edad
	Definir num1, num2 Como Entero;
	num1=2022
	leer num2;
	Resultado1=num1-num2
	Escribir "Usted tiene:", resultado1 ," años";
	
	//Proceso de selección de País utilizando estructuras Investigadas por cuenta propia
	//Usando "Repetir y Hasta que" y "Según opción Hacer"
	Escribir "Selecciona tu país:";
	Escribir "1- para México";
	Escribir "2- para Estados Unidos";
	
	Repetir
		Escribir "Ingrese el numero del País al cual pertenece";
		Leer opcion
	Hasta Que (Opcion >0 y Opcion <3)
	segun opcion hacer
		1:
			Escribir "Usted es de México";
			definir num3 Como Entero;
			num3=18
			Si (resultado1 < 18) entonces
				Escribir "Usted NO puede pasar a ver la Película";
			SiNo 
				Si(resultado1 >= 18) entonces
					Escribir "Puede pasar a ver la Película";
				FinSi
			FinSi
		2:
			Escribir "Usted es de Estados Unidos";
			definir num4 como entero;
			num4=21
			si (resultado1 < 21) Entonces
				Escribir "Usted NO puede pasar a ver la Película";
			SiNo 
				si (resultado1 >= 21) entonces
					Escribir "Puede pasar a ver la Película";
				FinSi
			FinSi
	FinSegun
	
FinAlgoritmo
