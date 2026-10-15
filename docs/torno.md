# Documentación de la clase: TornoCNC

**Elaborada por:** Alejandro Serrato de la Rosa

**Matrícula:** 25206

**Bloque:**  1

## 1. Propósito

**¿Qué máquina representa tu clase y qué operación hace sobre la pieza?**

La clase `TornoCNC` representa un torno de control numérico computarizado que realiza la operación de cilindrado sobre las piezas de una línea de manufactura. La máquina procesa una pieza por operación, registra el tiempo trabajado y controla el desgaste de su husillo. Cuando el componente alcanza su límite de vida útil, el torno entra en falla y requiere mantenimiento.

**¿Cuál es su componente y por qué no existe sin la máquina?**

Su componente es el husillo, representado mediante la clase `Husillo`. Este componente controla su vida útil y registra cuántas piezas ha procesado. Se utiliza composición porque el husillo forma parte de la máquina y es administrado directamente por ella. El torno utiliza este componente para realizar su trabajo y detectar cuándo necesita mantenimiento.

## 2. Decisiones de diseño

**Atributos propios de tu clase y validación de cada uno:**

- `segundosPorPieza`: almacena el tiempo necesario para procesar una pieza. Se valida mediante `setSegundosPorPieza()`, que solamente acepta valores mayores que cero.
- `rpm`: representa la velocidad de rotación del husillo en revoluciones por minuto. Se valida mediante `setRpm()`, que solamente acepta valores mayores que cero.
- `husillo`: objeto de la clase `Husillo` que administra el desgaste y la vida útil del componente mecánico.

El constructor establece inicialmente 30 segundos por pieza y 1500 RPM. Después intenta asignar los valores recibidos mediante los métodos de validación. Si un valor no es válido, conserva el valor anterior.

**Métodos propios (los que la clase base no tiene):**

- `setSegundosPorPieza(int segundos)`: valida y establece el tiempo de procesamiento de cada pieza.
- `setRpm(int valor)`: valida y establece la velocidad de rotación del husillo.
- `procesarPieza()`: comprueba si la máquina puede trabajar, desgasta el husillo, registra la pieza procesada y acumula el tiempo trabajado. Si el husillo llega a su límite, la máquina entra en falla.
- `darMantenimiento()`: reemplaza el husillo desgastado, registra el mantenimiento y muestra un mensaje de confirmación.

**Método de la base que redefines, y cómo reutilizas la versión de la base:**

Se redefine el método `mostrarEstado()` para mostrar información específica del Torno CNC, como las revoluciones por minuto, el tiempo por pieza y el estado del husillo.

Dentro de este método se llama a `Maquina::mostrarEstado()`, reutilizando la implementación de la clase base para mostrar los datos generales de la máquina. Después se imprime la información particular del torno y su componente.

**¿Cómo modelaste el desgaste del componente y por qué así?**

El desgaste se modela mediante dos atributos de la clase `Husillo`: `vidaUtil` y `usos`.

La vida útil representa la cantidad máxima de piezas que puede procesar el husillo antes de necesitar reemplazo. Cada vez que se procesa una pieza, el método `desgastar()` incrementa el contador de usos en una unidad.

Cuando el número de usos alcanza la vida útil, el método `estaDesgastado()` devuelve `true` y el torno entra en falla mediante `reportarFalla()`.

El método `reemplazar()` restablece el contador de usos a cero, simulando la instalación de un husillo nuevo.

Este modelo se eligió porque es sencillo, determinista y permite calcular manualmente las fallas durante el turno de producción.

**¿Qué usa tu clase de `Maquina` y qué agrega?**

La clase `TornoCNC` hereda públicamente de `Maquina`. Utiliza sus métodos `puedeProcesar()`, `estaEncendida()`, `registrarPieza()`, `agregarTiempo()`, `reportarFalla()`, `registrarMantenimiento()` y `mostrarEstado()`.

Además, incorpora el control de las RPM, el tiempo de procesamiento, el funcionamiento del cilindrado y la administración del desgaste del husillo mediante composición.

## 3. Diagrama

El diagrama de clases representa la herencia entre `Maquina` y `TornoCNC`, así como la composición entre `TornoCNC` y `Husillo`.

El diagrama debe elaborarse en draw.io y mostrar los atributos y métodos principales de cada clase, junto con las relaciones correspondientes.

**Imagen del diagrama:**

![Diagrama de clases de TornoCNC](TornoCNC.png)

## 4. Bitácora

**Dudas que tuviste y cómo las resolviste:**

Durante el desarrollo surgió la duda sobre la diferencia entre la pieza que recorre la línea de manufactura y el componente mecánico que forma parte del torno. Se aclaró que la pieza fabricada se representa mediante la clase `Componente`, mientras que el husillo es el componente mecánico propio del Torno CNC.

También se revisó cómo aplicar herencia y composición, así como la relación entre el desgaste del husillo y las fallas de la máquina.

Otra duda fue cómo registrar las piezas procesadas, acumular el tiempo de trabajo y contabilizar los mantenimientos. Se resolvió utilizando los métodos protegidos proporcionados por la clase base `Maquina`.

**Errores que encontraste y cómo los corregiste:**

Durante la organización del código se revisó la separación de responsabilidades entre `TornoCNC`, `Maquina` y `Husillo`. Se estableció que el torno administra el procesamiento de las piezas y el estado de la máquina, mientras que el husillo controla su propia vida útil.

También se implementaron validaciones para evitar valores no positivos en los segundos por pieza, las RPM y la vida útil inicial del husillo.

Finalmente, se verificó que el torno compruebe si puede procesar antes de registrar una pieza y que reporte una falla cuando el husillo alcanza su límite de desgaste.