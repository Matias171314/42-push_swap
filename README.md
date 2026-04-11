*Este proyecto ha sido creado como parte del currículo de 42 por <mvasquez>.*

# Descripción
El proyecto push_swap consiste en ordenar una lista de números enteros en una pila (Stack A). Para lograrlo, disponemos de una pila auxiliar (Stack B) y un conjunto limitado de instrucciones (push, swap, rotate y revrotate).

La complejidad de este proyecto radica en ordenar e imprimir la serie de operaciones más corta posible. Para garantizar la máxima eficiencia matemática y superar los benchmarks propuestos por el subject, se ha implementado un enfoque basado en cálculo de costes, conocido comúnmente como el Algoritmo del Turco.

Además del ALgoritmo del Turco, para cumplir con los benchmarks para una cantidad de números pequeños como 2, 3, 4 o 5 elementos en la pila, se ha desarrollado algoritmos de ordenación simples para mejorar y optimizar la cantidad de movimientos.

**Características principales:**
## Fase 1: Pre-ordenamiento
En lugar de pasar números al Stack B de forma aleatoria, el algoritmo calcula el punto medio. Los números de la mitad inferior (los más pequeños) se envían al Stack B de inmediato (pb), mientras que los más grandes se rotan (ra) para enviarlos más tarde. Esto crea un ordenamiento previo natural en el Stack B que ahorra muchos movimientos futuros. El proceso se detiene cuando solo quedan 3 números en el Stack A.

## Fase 2: Ordenación de la Base
Se aplica un algoritmo básico de ordenación para los 3 números restantes en el Stack A. Evaluando sus índices, el programa los ordena perfectamente utilizando un máximo de 2 movimientos (sa, ra o rra).

## Fase 3: Búsqueda de target_pos
Comienza el bucle principal. Por cada elemento del Stack B, el algoritmo recorre el Stack A buscando su "pareja ideal" o Target. Este objetivo siempre será el número en A que sea inmediatamente mayor que él. Si el número en B es el más grande de todo el conjunto, su objetivo pasa a ser el número más pequeño de A (ordenamiento de una lista circular).

## Fase 4: Cálculo de costes
Una vez emparejados, el programa calcula cuántos movimientos exactos costaría llevar cada elemento de B y su objetivo en A a la cima de sus respectivos stacks. Se utiliza el tamaño del stack para decidir el camino más corto:
- Si el nodo está en la primera mitad, el coste es positivo (rotación hacia arriba).
- Si está en la segunda mitad, el coste es negativo (rotación inversa hacia abajo).

## Fase 5: Ejecución del movimiento más barato
El algoritmo suma el valor absoluto de los costes de cada nodo en B y selecciona el que ofrezca la ruta más barata. Durante la ejecución, se buscan si ambos tienen costes o positivos o negativos para así ahorrar movimientos (rotación de ambas pilas): si ambos nodos necesitan subir o bajar, se utilizan los movimientos dobles (rr o rrr) para rotar ambos stacks simultáneamente, ahorrando el 50% de los movimientos en ese paso antes de hacer el push (pa).

## Fase 6: Ajuste de alineación
Cuando el Stack B queda completamente vacío, los números están ordenados, pero la lista circular puede estar desfasada. El algoritmo localiza el número más pequeño (índice 0) y rota el Stack A por la ruta más corta hasta dejarlo exactamente en la primera posición.

# Instrucciones
Para probar y ejecutar el proyecto, se deben seguir estos pasos desde la terminal.

## Compilación
El proyecto incluye un Makefile que automatiza la compilación. Simplemente ejecuta:

```Bash
make
```

Esto generará el archivo ejecutable llamado push_swap.

## Uso Básico
Para ejecutar el programa, pásale una lista de números enteros separados por espacios. El programa devolverá la lista de instrucciones necesarias para ordenarlos.

Opción A: Números sueltos

```Bash
./push_swap 4 67 3 87 23
```
Opción B: Números en un solo string

```Bash
./push_swap "4 67 3 87 23"
```

## Limpieza de archivos
Si deseas limpiar tu entorno de trabajo una vez hayas terminado de probar el código, el Makefile incluye reglas de limpieza estándar:
- make clean: Elimina todos los archivos objeto (.o) generados durante la compilación.
- make fclean: Elimina los archivos objeto y también el archivo ejecutable final.
- make re: Ejecuta un fclean seguido de un make (ideal para recompilar desde cero).

## Recomendaciones al momento de testear
Al momento de la evaluación se recomienda usar un generador de números para obtener una ristra de números para probar. Se sugiere usar el push-swap42-visualizer para obtener la ristra y para verificar que el algoritmo de ordenación funciona correctamente se utiliza el checker proporcionado en el proyecto.

# Recursos
Referencias:
- https://youtu.be/wRvipSG4Mmk?si=hOKkh2aMIa73foHC
- https://push-swap42-visualizer.vercel.app/
- https://www.reddit.com/r/42_school/comments/1ob6zcp/push_swap_algorithm/?tl=es-419
- https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0

## Uso de IA
Este proyecto se ha realizado siguiendo las política sobre el uso de la IA de 42. Se ha utilizado un asistente de IA utilizado para comprender conceptos teoricos para facilitar el proceso de aprendizaje, sin generación directa de código final.
