# Documentación de la clase: EstacionI

**Elaborada por:** Michelle González Barrera
**Matrícula:** 25069
**Bloque:** 5

## 1. Propósito

**¿Qué máquina representa tu clase y qué operación hace sobre la pieza?**

Mi máquina representa la estación de inspección,su funcion es medir y verificar la calidad o especificaciones de una pieza dentro de un proceso de producción mediante el método procesarPieza().

**¿Cuál es su componente y por qué no existe sin la máquina?**

Su componente es un sensor de calibración y no puede funcionar sin la máquina porque la relación entre ambos es de composición: la propia EstacionI crea y destruye la instancia del Sensor como miembro privado de su estructura.Sin la máquina que lo aloje, controle sus mediciones y gestione su consumo, el sensor carece de contexto operativo y ciclo de vida.

## 2. Decisiones de diseño

**Atributos propios de tu clase y validación de cada uno:**

toleranciaMicras, segundosPorPieza y sensor

**Métodos propios (los que la clase base no tiene):**

procesarPieza(), setToleranciaMicras() y setSegundosPorPieza().

**Método de la base que redefines, y cómo reutilizas la versión de la base:**

Redefino mostrarEstado(). Se reutiliza llamando a Maquina::mostrarEstado() dentro de su implementación para imprimir la información general de la máquina (como ID, nombre o fallas) y, luego, agregar los datos específicos de la estación (segundosPorPieza, toleranciaMicras) y el estado interno del sensor.
**¿Cómo modelaste el desgaste del componente y por qué así?**

El desgaste del componente se modeló de forma discreta a través de la cantidad de mediciones que el Sensor puede realizar. Cada vez que se ejecuta procesarPieza(), el sensor decrementa sus mediciones disponibles. Cuando la pieza actual agota las mediciones del sensor, la máquina entra automáticamente en estado de falla. Se modeló así para simular la descalibración o desgate físico real de un instrumento de precisión por uso acumulado.

**¿Qué usa tu clase de `Maquina` y qué agrega?**

Usa de Maquina los atributos y métodos heredados para el control general de la máquina (identificador id, nombre, estado de encendido/apagado, detección de fallas y la lógica general de mantenimiento con darMantenimiento()).
Agrega los parámetros operativos específicos de inspección (segundosPorPieza, toleranciaMicras), la integración del componente de medición Sensor vía composición, y la lógica de validación de piezas.

## 3. Diagrama

Diagrama de tu clase y su componente, hecho en draw.io. Debe mostrar la relación de herencia con `Maquina` y la de composición con tu componente. Guarda la imagen en `docs/` y enlázala aquí.

<img src="Diagrama_EstacionI.drawio.png">

## 4. Bitácora

**Dudas que tuviste y cómo las resolviste:**

Existía la duda de si el Sensor debía pasarse como un puntero o instanciarse como un atributo directo. Se resolvió instanciándolo como miembro directo de EstacionI para garantizar una relación de composición estricta donde la máquina es la única responsable de crear y destruir el sensor.
No quedaba claro cómo evitar duplicar código al mostrar el estado de la máquina. Se resolvió invocando explícitamente el método de la clase base Maquina::mostrarEstado() antes de desplegar los datos propios de la estación de inspección.

**Errores que encontraste y cómo los corregiste:**

Al modificar atributos con valores menores o iguales a cero, el estado interno se corrompía. Se corrigió agregando condicionales de validación (if (segundos > 0)) dentro de las funciones setter para ignorar las asignaciones no válidas.
