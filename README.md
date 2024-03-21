# PRÁCTICA 2: Llamada a procedimiento remoto (RPC)
## Introducción
Esta práctica consiste en la realización de una calculadora en C usando la herramienta RPC, para así obtener una calculadora cliente-servidor.

Para realizar la práctica primero se programa el archivo calculadora.x, tras esto se usa el comando **rpcgen -NCa calculadora.x** y se generan los archivos sobre los que trabajamos.

Tras programar calculadora_client.c y calculadora_server.c podemos compilar usando el comando **make -f Makefile.calculadora**, fichero al que le hemos añadido las librerías a usar y los flags deseados.

## Funcionamiento

El funcionamiento de la calculadora es el siguiente:
  -  En un terminal ejecutar el servidor: **./calculadora_servidor**
  -  En un segundo terminal, mientras el primero sigue funcionando, ejecutar el cliente: **./calculadora_server localhost**

Una vez tienes las dos terminales abiertas saltará un mensaje por la terminal pidiendo que selecciones que tipo de operación quieres realizar, las opciones son:  
![](https://github.com/Jorgesnchz/PracticasDSD/assets/127404109/592e40a1-e4da-4556-898c-d8da3bbe2d52)
  -  1 - Operaciones aritméticas (+,-,*,/,^,r)
  -  2 - Operaciones trigonométricas (Seno, Coseno, Tangente ...)
  -  3 - Ecuaciones de segundo grado
  -  4 - Operaciones con vectores (+,-,*,^)

Tras esta selección cada una de las versiones de la calculadora pedirá por pantalla los valores necesarios para continuar: 
  -  Operaciones aritméticas: ![](https://github.com/Jorgesnchz/PracticasDSD/assets/127404109/1276c289-b9ba-45c7-bb9a-7ceb698c44e6)
  -  Operaciones trigonométricas: ![](https://github.com/Jorgesnchz/PracticasDSD/assets/127404109/4c50465c-e3b4-4703-ad32-f7c7352ff866)
  -  Ecuaciones de segundo grado: ![](https://github.com/Jorgesnchz/PracticasDSD/assets/127404109/cf752b78-3320-4f29-ae16-1ca707b990b4)
  -  Operaciones con vectores: ![](https://github.com/Jorgesnchz/PracticasDSD/assets/127404109/7a6be4ae-a1c5-406e-ac4b-05e99ea31829)

Una vez introducidos los parámetros se envia al servidor la petición y se calcula la solución a esta, tras esto se muestra por pantalla el resultado, o en el caso de un error se muestra el motivo del error

## Desarrollo
  La realización de esta práctica se compone en 3 archivos implementados, ya que el resto los genera rpc.

  ### Calculadora.x
    
   Este archivo está compuesto por las estructuras de datos que usaremos para implementar las funciones:
    
    - struct operacion_arit: Usado para las operaciones aritméticas
    - enum funciones_trigonometricas: Usado para que al implementar el switch se ve claramente cada caso en las operaciones trigonométricas
    - struct operacion_trig: Usado para las operaciones trigonométricas
    - struct ecuacion: Usado para almecenar los coeficientes de las operaciones de segundo grado
    - struct resultado: Usado para almacenar los resultados de la ecuación
    - struct operacion_vect: Usado para las operaciones con vectores

   Ademas en el archivo se unen uniones para la comprobación de errores (visto en el ejemplo de código ej2):

    - union resultado_calculadora: Usada por las operaciones trigonométricas y aritméticas
    - union resultado_calculadora_ecuaciones: Usada por las ecuaciones
    - union resultado_calculadora_vectores: Usada por los vectores

   Finalmente en este archivo se incluyen las versiones de la calculadora, siendo estas: 
   
    - 1: ARITMETICAS
    - 2: TRIGONOMETRICAS
    - 3: ECUACIONES
    - 4: VECTORES

  
   En este archivo se recogen las estructuras de datos, funciones y versiones para la realización.


  ### Calculadora_cliente.c
  
  El archivo contiene la llamada a la función main además de la recopilación de datos mediante un menú interactivo para enviar la información al servidor

  Métodos calculadora_x, todos estos métodos tienen un funcionamiento igual: 

    - Se piden los datos por pantalla
    - Se envía la petición al servidor para resolverla
    - Si no hay errores se muestra por pantalla, en el caso de error se informa del error
  

  Main: 
  
    Se muestran las diferentes posibilidades y se pide la selección de una de ellas, 
    si se ha introducido un valor válido realiza la función correspondiente

  - Aclaraciones:
    
      En las operaciones aritméticas el operador r indica raiz n-ésima, siendo el valor de n el primero introducido

      En las operaciones con vectores * indica producto escalar y ^ indica producto vectorial
    
    

### Calculadora_server.c

  En este archivo se ha incluido la librería math.h para realizar las funciones trigonométricas y las raices

  El funcionamiento del archivo consiste en:
  
  - Método operacion_aritmetica_1_svc:

      Mediante un switch se comprueba si el operador introducido es correcto, en 
      el caso de serlo se devuelve el valor correspondiente y en el caso de no serlo se devuelve un error

  - Método operacion_trigonometrica_2_svc:

      Se comprueba que se haya introducido un valor dentro del enum, en caso de que se haya introducido
      un valor incorrecto salta error, sino se muestra el resultado

  - Método operacion_ecuaciones_3_svc:

      Comprueba si los valores que obtiene como argumento tienen soluciones reales y se realiza el cálculo 
      de los valores en caso negativo se informa del problema

  - Método operacion_vectores_4_svc:

      Mediante un switch elige la operación y la calcula o informa de algún error  
