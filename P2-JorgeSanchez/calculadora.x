/* dir.x : Protocolo de listado de directorio remoto */
const MAX = 100;                                        /*Maximo tam para los vectores*/

typedef int vectores<MAX>;                              /*Vectores sobre los que se opera*/

typedef struct operacion_arit operacion;                /*Tipo de dato para las operaciones aritmeticas*/
typedef struct operacion_trig operacion_t;              /*Tipo de dato para las operaciones trigonometricas*/
typedef struct ecuacion operacion_e;                    /*Tipo de dato para las ecuaciones de segundo grado*/
typedef struct operacion_vect operacion_v;              /*Tipo de dato para los vectores*/

struct operacion_arit{
    int a;                              /* Primer numero */
    char op;                            /* Operador */
    int b;                              /* Segundo numero */
};

enum funciones_trigonometricas {                        /*Enum usado en las operaciones trigonometricas para facilitar el codigo*/
    SENO = 0,
    COSENO = 1,
    TANGENTE = 2,
    COTANGENTE = 3,
    SECANTE = 4,
    COSECANTE = 5,
    ARCOSENO = 6,
    ARCOCOSENO = 7,
    ARCOTANGENTE = 8
};

struct operacion_trig{
    funciones_trigonometricas func;     /*Funcion a realizar*/
    double valor;                       /*Valor en radianes sobre el que se calcula*/
};

struct ecuacion{
    int a;                              /*Coeficiente de x^2*/
    int b;                              /*Coeficiente de x*/
    int c;                              /*Termino independiente */
};

struct resultado{                                   /*Struct usado para contener los dos resultados de una ecuacion de segundo grado*/
    double positivo;           
    double negativo;
};

struct operacion_vect{                  
    vectores a;                         /*Primer vector*/
    char op;                            /*Operador de ambos*/
    vectores b;                         /*Segundo vector*/
    int tam;                            /*Tamanio de ambos*/
};

union resultado_calculadora switch (int errnum) {                   /*Esta union sirve para saber si se ha producido un error en las operaciones aritmeticas y trigonometricas*/
    case 0:
      double resultado;     /* sin error: resultado calculadora */
    default:
      void;                 /* con error: nada */
};

union resultado_calculadora_ecuaciones switch (int errnum) {        /*Esta union sirve para saber si se ha producido un error en las ecuaciones*/
    case 0:
      resultado res;        /* sin error: resultado calculadora */
    default:
      void;                 /* con error: nada */
};

union resultado_calculadora_vectores switch (int errnum) {          /*Esta union sirve para saber si se ha producido un error en las operaciones con vectores*/
    case 0:
      vectores resultado;     /* sin error: resultado calculadora */
    default:
      void;                 /* con error: nada */
};

program CALCULADORA{
    version ARITMETICAS {
        resultado_calculadora OPERACION_ARITMETICA(operacion) = 1;
    } = 1; 
    version TRIGONOMETRICAS{
        resultado_calculadora OPERACION_TRIGONOMETRICA(operacion_t) = 1;
    } = 2;
    version ECUACIONES{
        resultado_calculadora_ecuaciones OPERACION_ECUACIONES(operacion_e) = 1;
    } = 3;
    version VECTORES{
        resultado_calculadora_vectores OPERACION_VECTORES(operacion_v) = 1;
    } = 4;
} = 0x20000001;         /*El numero de programa es el primero libre*/

