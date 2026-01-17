# SIMULADOR DE TRAFICO VEHICULAR


### Menú de simulación 
Iniciar simulacion 

Detener simulacion 

Boton: Control de tráfico (default medio, bajo, alto, caotico)

Velocidad de simulacion 


## Auto 
Hover_Auto: mostrar informacion--> placa, velocidad actual, direccion, estado

Maneajar la creacion de los autos en diferentes posiciones --> si hay un auto en esa posicion, no crear otro auto ahi.

Auto tiene un Carril 

## Carril 
Posicion --> x = 210, y = 0
Ancho --> 40 (si ancho auto es 20, deja un espacio de 10 por cada lado)
Sentido --> Norte, Sur, Este, Oeste
Semaforo (carriles conjuntos con la misma direccion responden al mismo semaforo)

### Restricción de colisiones
Interseccion entre autos cercanos y el campo visual
```
	Si hay un auto delante → frenar.
	Si no hay autos en el campo visual → acelerar.

```

REBASAR: tomar la decision de adelantar otro auto
CRUCES: Realizar cruces en calles, intersecciones ---> Mensaje PopUp con flecha de la intencion de cruce (una especie de intermitente)

## SEMAFOROS (clase)
...




## Pizarra - Recursos - Notas 

https://excalidraw.com/#json=cFxMxwJ1Q8xtYcq_MDI1E,1I3Tl-rr0Up_CxOygcYY4Q