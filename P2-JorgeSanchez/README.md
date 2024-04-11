# PRÁCTICA 2: Apache thrift
## Introducción

Esta práctica consiste en la realización de una calculadora en python usando la herramienta thrift, para así obtener una calculadora cliente-servidor.

Para realizar la práctica primero se programa el archivo calculadora.thrift, tras esto se usa el comando thrift -gen py calculadora.thrift y se generan los archivos sobre los que trabajamos, exceptuando el servidor.py y el cliente.py.

Tras programar cliente.py y servidor.py podemos ejecutar usando una termina para cada y el comando python servidor.py/cliente.py

## Funcionamiento

El funcionamiento de la calculadora es el siguiente:
- En un terminal ejecutar el servidor: python servidor.py
- En un segundo terminal, mientras el primero sigue funcionando, ejecutar el cliente: python cliente.py    

    

Una vez tienes las dos terminales abiertas saltará un mensaje por la terminal pidiendo que selecciones que tipo de operación quieres realizar, las opciones son:

![imagen](https://github.com/Jorgesnchz/PracticasDSD/assets/127404109/e6f01930-1e5a-4e45-9836-79c6a3ba55b0)

Una vez seleccionada una de las obciones saltarán los mensajes correspondientes al tipo de operación seleccionada:
 - Operaciones aritméticas:
   
![imagen](https://github.com/Jorgesnchz/PracticasDSD/assets/127404109/c17cc545-a9cb-44b0-87e6-8632d455d36a)
 - Operaciones trigonométricas:
   
![imagen](https://github.com/Jorgesnchz/PracticasDSD/assets/127404109/ef79d6e4-b584-4c13-98c5-2a844d6cfc75)
 - Ecuaciones de segundo grado:
   
![imagen](https://github.com/Jorgesnchz/PracticasDSD/assets/127404109/2493da39-1c4a-4db3-93d7-5f01d4eb1e3a)
 - Operaciones con vectores:
   
![imagen](https://github.com/Jorgesnchz/PracticasDSD/assets/127404109/607fd763-4e41-49bc-832f-c628787c28b8)

## Desarrollo 
 La realización de esta práctica se basa en 3 archivos:

 ### calculadora.thift
   Similar a calculadora.x en la práctica anterior, genera todos los archivos necesarios para la ejecución, los tipos de datos vienen definidos en esta

### cliente.py 
   Pide por pantalla los valores necesarios para enviar la petición al servidor y muestra los resultados de esta

### servidor.py 
   Realiza las operaciones definidas por calculadora.thift permitiendo dar respuesta a las peticiones de cliente.py 


## Aclaraciones: 
En las operaciones aritméticas el operador r indica raiz n-ésima, siendo el valor de n el primero introducido

En las operaciones con vectores * indica producto escalar y ^ indica producto vectorial
