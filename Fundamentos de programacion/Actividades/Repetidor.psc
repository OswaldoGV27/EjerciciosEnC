Algoritmo Repetidor
	Definir a Como Entero
	a=1
	Repetir
	    Escribir "ALARMA INICIADA ", a;
		a=a+1
		Esperar 1 segundo
		Limpiar pantalla
	Hasta Que (a=11)
FinAlgoritmo

Definir a, b Como Entero
Escribir "¿En cuanto tiempo Iniciará la alarma (En Segundos)?";
Leer a
b=1
Repetir
	Escribir "ALARMA INICIADA ", a;
	b=b+1
	Esperar 1 segundo
	Limpiar pantalla
Hasta Que (b=a)
