*Este proyecto ha sido creado como parte del currículo de 42 por jabad-di.*

# Push_swap

## Descripcion

push_swap es un proyecto del currículo de 42 cuyo objetivo es ordenar una pila de números utilizando un conjunto limitado de operaciones y el menor número posible de movimientos.

Para la implementación he utilizado una estructura de **listas doblemente enlazadas circulares**, lo que permite recorrer la pila en ambas direcciones de forma eficiente y optimizar las rotaciones.

El algoritmo utilizado es una variante del **Algoritmo Turk**, basado en el cálculo dinámico del coste de cada movimiento. Cada nodo de la pila contiene la siguiente información:

- `value`: el número almacenado.
- `index`: la posición que debería ocupar en la pila ordenada.
- `push_cost`: el coste total necesario para mover el nodo a su posición correcta.
- `pos`: posicion actual que ocupa el nodo.
- `target`: puntero al nodo objetivo en la pila destino.
- `next` y `prev`: punteros para la doble vinculación circular.

### Estrategia del algoritmo

1. Se calculan los índices de cada número según su posición ordenada.
2. Para cada elemento en la pila A:
   - Se determina su `target` en la pila B.
   - Se calcula su `push_cost` teniendo en cuenta las rotaciones necesarias en ambas pilas.
3. Se selecciona el nodo con menor coste y se mueve de A a B.
4. La pila B se mantiene ordenada de forma decreciente.
5. Este proceso continúa hasta que en la pila A quedan únicamente tres elementos.
6. Los tres elementos restantes en A se ordenan manualmente.
7. Finalmente, se vuelven a subir todos los elementos de B a A.
8. Se realiza la rotación final para colocar el número más pequeño en el top.

La parte bonus incluye la implementación del checker para validar si una secuencia de instrucciones ordena correctamente la pila.

## BONUS

La parte bonus implementa el programa checker, que verifica si los movimientos generados por push_swap son correctos. Se encarga de leer la lista de números correctamente parseada, manejar errores de entrada, y recibir secuencias de operaciones ya sea desde la salida de push_swap o introducidas manualmente por el usuario. Al ejecutar checker, puedes escribir los movimientos a mano, y el programa valida si las operaciones ordenan correctamente los números, mostrando si el resultado final es correcto o no.

### ejecutar el checker para validar el push_swap
```c
./push_swap 3 2 1 | ./checker 3 2 1
```

### ejecutar checker para meter movimiento manualmente
```c
./checker 3 2 1
```
despues de ejecutar el `checker 3 2 1` tendrias que poner el movimento manualmente en la terminal, en este caso, `(sa)` y una vez que finalices los movimientos presiona `crtl + d`.

---

## RESUMEN

- Implementación con listas doblemente enlazadas circulares.
- Cálculo dinámico del coste de movimiento (`push_cost`).
- Selección optimizada del movimiento más barato.
- Ordenación eficiente en pila B.
- Gestión correcta de memoria.
- Implementación del checker (bonus).
- Cumplimiento de la Norminette.

---

# Instrucciones

## Compilación

### Para el programa principal push_swap
```c
make
```
### Para el programa bonus checker
```c
make bonus
```
## Ejecución

### Para ejecutar el programa y ver la lista de instrucciones:
```c
./push_swap 3 2 1
```
### Para verificar si una secuencia de instrucciones ordena correctamente los números
```c
ARG="3 2 1"; ./push_swap $ARG | ./checker_linux $ARG
```
### Tambien un comando para hacer pruebas mas rapido y grandes
```c
ARG=$(seq -1000000 1000000 | shuf -n 500 | tr '\n' ' '); MOVIMIENTOS=$(./push_swap $ARG); echo "$MOVIMIENTOS" | ./checker_linux $ARG; echo "$MOVIMIENTOS" | wc -l
```

# Recursos
Para la realización de este proyecto se consultaron los siguientes recursos:

Documentación sobre algoritmos de ordenamiento.

Guías sobre el uso de pilas, listas dobles enlazada circular y estructuras de datos en C.

## Uso de IA

Se utilizó IA para la generación de casos de prueba (testing) y para explicar conceptos teóricos sobre la complejidad de algoritmos de ordenacion.

Partes del proyecto: La IA ayudo a informar sobre estructura del parser para la gestión de errores. Toda lógica generada fue revisada y validada manualmente para asegurar su total comprensión y cumplimiento con la Norma.

Bonus
El proyecto incluye el programa checker, el cual recibe una lista de enteros y lee las instrucciones de ordenamiento desde la entrada estándar.
+1

Si tras ejecutar las instrucciones la pila está ordenada y la pila B vacía, muestra OK.

En caso contrario, muestra KO.

Gestiona errores de formato, duplicados o instrucciones inexistentes mostrando Error.
