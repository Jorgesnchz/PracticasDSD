#include "calculadora.h"

void
calculadora_1(char *host)
{
	CLIENT *clnt;
	resultado_calculadora  *result_1;
	operacion operacion_aritmetica_1_arg1;

#ifndef	DEBUG
	clnt = clnt_create (host, CALCULADORA, ARITMETICAS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	printf("Ingrese el primer entero: ");	
	scanf("%i", &operacion_aritmetica_1_arg1.a);						/* Se pide el primer entero */
	
	printf("Ingrese el operador(+,-,*,/,^,r): ");
	scanf("%s", &operacion_aritmetica_1_arg1.op);						/* Se pide el operador */
	
	printf("Ingrese el segundo entero: ");
	scanf("%i", &operacion_aritmetica_1_arg1.b);						/* Se pide el segundo entero */
	
	result_1 = operacion_aritmetica_1(operacion_aritmetica_1_arg1, clnt);	/* Envia la operacion al servidor para ser realizada */
	if (result_1 == (resultado_calculadora *) NULL) {
		clnt_perror (clnt, "call failed");
	}

	if(result_1->errnum == 10001){
		printf("Error: Division por cero\n");							/* Error asociado a la division */	
	}
	else if(result_1->errnum == 10002){
		printf("Error: Operador Incorrecto\n");							/* Error asociado al operador */
	}
	else{
		printf("El resultado de la operacion es: %f\n", result_1->resultado_calculadora_u.resultado);	/* Se imprime el resultado de la operacion si no hay errores */
	}

#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


void
calculadora_2(char *host)
{
	CLIENT *clnt;
	resultado_calculadora  *result_1;
	operacion_t operacion_trigonometrica_2_arg1;

#ifndef	DEBUG
	clnt = clnt_create (host, CALCULADORA, TRIGONOMETRICAS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	printf("Ingrese el angulo (radianes): \n");
	scanf("%lf", &operacion_trigonometrica_2_arg1.valor);						/* Se pide el angulo */
	
	printf("Ingrese el operador: \n");
	printf("0 - Seno\n");
	printf("1 - Coseno\n");
	printf("2 - Tangente\n");
	printf("3 - Cotangente\n");
	printf("4 - Secante\n");
	printf("5 - Cosecante\n");
	printf("6 - Arcoseno\n");
	printf("7 - Arcocoseno\n");
	printf("8 - Arcotangente\n");
	scanf("%i", &operacion_trigonometrica_2_arg1.func);							/* Se pide el operador */
	
	result_1 = operacion_trigonometrica_2(operacion_trigonometrica_2_arg1, clnt);	/* Envia la operacion al servidor para ser realizada */
	if(result_1->errnum == 10002){
		printf("Error: Operador Incorrecto\n");									/* Error asociado al operador */
	}
	else if(result_1->errnum == 10003){
		printf("Error: Rango de valor incorrecto\n");							/* Error asociado al rango de valores */
	}
	else{
		printf("El resultado de la operacion es: %f\n", result_1->resultado_calculadora_u.resultado);	/* Se imprime el resultado de la operacion si no hay errores */
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


void
calculadora_3(char *host)
{
	CLIENT *clnt;
	resultado_calculadora_ecuaciones  *result_1;
	operacion_e operacion_ecuaciones_3_arg1;

#ifndef	DEBUG
	clnt = clnt_create (host, CALCULADORA, ECUACIONES, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	printf("Ingrese los valores de la ecuacion de segundo grado: ax² + bx + c\n");
	
	printf("Ingrese el valor de a: ");
	scanf("%i", &operacion_ecuaciones_3_arg1.a);						/* Se pide el valor de a */
	printf("Ingrese el valor de b: ");
	scanf("%i", &operacion_ecuaciones_3_arg1.b);						/* Se pide el valor de b */
	printf("Ingrese el valor de c: ");
	scanf("%i", &operacion_ecuaciones_3_arg1.c);						/* Se pide el valor de c */
	
	result_1 = operacion_ecuaciones_3(operacion_ecuaciones_3_arg1, clnt);	/* Envia la operacion al servidor para ser realizada */
	if (result_1 == (resultado_calculadora_ecuaciones *) NULL) {
		clnt_perror (clnt, "call failed");
	}

	if(result_1->errnum == 10004){
		printf("Error: Raiz con soluciones imaginarias\n");				/* Error asociado a raices imaginarias */
	}
	else{
		printf("El resultado1 de la ecuacion es: %f\n", result_1->resultado_calculadora_ecuaciones_u.res.positivo);		/*Resultado sumando la raiz*/
		printf("El resultado2 de la ecuacion es: %f\n", result_1->resultado_calculadora_ecuaciones_u.res.negativo);		/*Resultado restando la raiz*/
	}	
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


void
calculadora_4(char *host)
{
	CLIENT *clnt;
	resultado_calculadora_vectores  *result_1;
	operacion_v operacion_vectores_4_arg1;

#ifndef	DEBUG
	clnt = clnt_create (host, CALCULADORA, VECTORES, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	printf("Ingrese el tamaño de los vectores: ");
	scanf("%i", &operacion_vectores_4_arg1.tam);														/* Se pide el tamaño de los vectores */
	
	operacion_vectores_4_arg1.a.vectores_val = malloc(operacion_vectores_4_arg1.tam * sizeof(int));		/* Se reserva la memoria */
	operacion_vectores_4_arg1.b.vectores_val = malloc(operacion_vectores_4_arg1.tam * sizeof(int));		
	operacion_vectores_4_arg1.a.vectores_len = operacion_vectores_4_arg1.tam;							/* Se asigna el tam */
	operacion_vectores_4_arg1.b.vectores_len = operacion_vectores_4_arg1.tam;
	
	for(int i = 0; i < operacion_vectores_4_arg1.tam; i++){
		printf("Ingrese el valor del vector 1 en la posicion %i: ", i);
		scanf("%i", &operacion_vectores_4_arg1.a.vectores_val[i]);			/*Se piden los valores del primer vector*/
	}

	printf("Ingrese el operador(+,-,*,^): ");
	scanf("%s", &operacion_vectores_4_arg1.op);								/* Se pide el operador */

	for(int i = 0; i < operacion_vectores_4_arg1.tam; i++){
		printf("Ingrese el valor del vector 2 en la posicion %i: ", i);
		scanf("%i", &operacion_vectores_4_arg1.b.vectores_val[i]);			/*Se piden los valores del segundo vector*/
	}

	result_1 = operacion_vectores_4(operacion_vectores_4_arg1, clnt);		/* Envia la operacion al servidor para ser realizada */
	if (result_1 == (resultado_calculadora_vectores *) NULL) {
		clnt_perror (clnt, "call failed");
	}
	
	if(result_1->errnum == 10002){
		printf("Error: Operador Incorrecto\n");					/* Error asociado al operador */
	}
	else if(result_1->errnum == 10005){
		printf("Error: El producto vectorial solo puede calcularse con vectores de tamaño 3\n");	/* Error asociado al tamaño de los vectores */
	}
	else{
		for(int i = 0; i < result_1->resultado_calculadora_vectores_u.resultado.vectores_len; i++){
			if(result_1->resultado_calculadora_vectores_u.resultado.vectores_len == 1){				/*Se muestra el resultado*/
				printf("El resultado de la operacion es: %i\n", result_1->resultado_calculadora_vectores_u.resultado.vectores_val[i]);
			}
			else{
				printf("El resultado de la operacion en la posicion %i es: %i\n", i, result_1->resultado_calculadora_vectores_u.resultado.vectores_val[i]);
			}
		}
	}
	
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	printf("Selecciona su version:\n");			/* Seleccion de la version de la calculadora */
	printf("1. Operaciones aritmeticas\n");
	printf("2. Operaciones trigonometricas\n");
	printf("3. Ecuaciones de segundo grado\n");
	printf("4. Operaciones con vectores\n");
	int seleccion;
	scanf("%i", &seleccion);
	switch(seleccion){							/* Se llama a la calculadora correspondiente */
		case 1:
			calculadora_1 (host);			
			break;
		
		case 2:
			calculadora_2 (host);	
			break;

		case 3: 
			calculadora_3 (host);
			break;
			
		case 4: 
			calculadora_4 (host);
			break;

		default:
			printf("Opcion incorrecta");
			break;
	}
	exit(0);
}
