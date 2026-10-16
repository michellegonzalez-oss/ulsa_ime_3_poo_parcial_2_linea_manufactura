# Propuesta de mejora: [Inserta aquí el título de tu propuesta]

> Crea una carpeta dentro de `docs/mejoras/` con tu número de matrícula como nombre, copia este archivo ahí como `mejora.md` y llena tu copia. No modifiques la plantilla.
>
> La propuesta es solo diseño: no se programa.

**Propuesta de mejora elaborada por:** [brayan lopez]

## 1. Impacto

**¿Es una mejora o una corrección?**
[Es una mejora: la planta hoy no hace algo que sí podría hacer, que es recordar qué pasó durante el turno]

**¿Qué observaste en la solución del equipo que dio origen a la propuesta?**

[El reporte del turno solo entrega totales por máquina. No dice en qué pieza falló cada una ni cuándo se le dio mantenimiento. Eso solo sale como mensajes en la consola durante la corrida y después se pierde, porque la Planta no guarda nada de lo que ocurrió.

El caso más claro es la banda transportadora. En nuestra solución la banda traslada la pieza entre cada estación (3 traslados por pieza), así que una sola pieza genera 7 operaciones y todo el lote deja más de 150 líneas en pantalla. El reporte solo dice "Banda transportadora: 60 piezas, 1 paro". No dice que la banda falló en el traslado 50, a la mitad de la pieza 17 (entre la fresadora y el robot), ni cuándo se reparó. Para comprobar nuestro cálculo a mano hay que buscar esas líneas a ojo entre toda la salida.]

**¿Qué mejora o qué corrige, y por qué vale la pena?**

[La planta llevaría una bitácora del turno: una lista de textos, uno por evento, que se imprime al final del reporte. Con nuestros números quedaría así:

=== Bitacora del turno ===
Pieza 9: falla Torno CNC
Pieza 10: mantenimiento Torno CNC
Pieza 15: falla Robot soldador
Pieza 16: mantenimiento Robot soldador
Pieza 17: falla Banda transportadora
Pieza 17: mantenimiento Banda transportadora
Pieza 18: falla Torno CNC
Pieza 19: mantenimiento Torno CNC

Vale la pena porque:

el cálculo a mano se compara directamente con la bitácora (fallas del torno después de las piezas 9 y 18, del robot en la 15 y de la banda en la 17), no solo con los totales;
el reporte explica por qué hubo 4 paros y no solo cuántos;
aclara el caso de la banda, donde "60 piezas" son en realidad 60 traslados de 20 piezas.]

## 2. Qué implica

**Clases nuevas:**

[Bitacora, con un arreglo de textos (eventos, capacidad 100) y un contador (cantidad). Métodos: registrar(texto), que agrega un evento (si se llena, avisa y no agrega), y mostrar().]

**Comportamiento nuevo en clases existentes:**

[Planta tiene un atributo bitacora. En procesarPieza(), cada vez que detecta una máquina en falla anota el evento de falla y el de mantenimiento, con el número de pieza (piezasTerminadas + 1). Se agrega mostrarBitacora(), que generarReporte() puede llamar al final. Maquina y todas las derivadas no cambia]

**Interacciones nuevas entre objetos:**

[Planta → Bitacora: la planta llama a bitacora.registrar(...) cada vez que ocurre un evento. La planta ya conoce el nombre de la máquina con getNombre() y lo escribe dentro del texto.]

**Relaciones nuevas (herencia, composición o agregación) y por qué son de ese tipo:**

[Planta ◆— Bitacora: composición. La bitácora es del turno de esa planta: se crea con ella y desaparece con ella. No es agregación porque la planta no la recibe de afuera como las máquinas (que se crean en main); es su dueña.
No hay herencia nueva: Bitacora no es un tipo especial de ninguna clase existente.
No hay relación nueva con las máquinas: la bitácora solo guarda texto, no apuntadores a máquinas. La agregación de Planta con las máquinas queda igual.]

## 3. Diagrama de clases

Diagrama hecho en draw.io que muestre la solución con la mejora incorporada. Distingue lo nuevo de lo existente, por ejemplo con otro color. Guarda la imagen en esta misma carpeta y enlázala aquí.

<img src="./diagrama_mejora.png">
