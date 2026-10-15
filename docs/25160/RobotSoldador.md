**Elaborada por:** [BRAYAN LOPEZ]
**Matrícula:** [25160]
**Bloque:** [3]

## 1. Propósito

**¿Qué máquina representa tu clase y qué operación hace sobre la pieza?**

`RobotSoldador` representa un robot de soldadura dentro de la línea de producción. Su operación sobre la pieza es **soldarla**. Cada llamada a `procesarPieza()` procesa una sola pieza: la suelda, le avisa a la base que se procesó una pieza (`registrarPieza()`) y le suma el tiempo que tardó (`agregarTiempo(segundosPorPieza)`). El robot solo trabaja si está encendido y sin falla; en cualquier otro caso rechaza la pieza, lo informa en pantalla y devuelve `false`. Además del tiempo por pieza, maneja la corriente de soldadura en amperes, que se reporta en su estado.

**¿Cuál es su componente y por qué no existe sin la máquina?**

El componente es la **`Antorcha`** (con su alambre). Es la parte que se consume al soldar: cada pieza la desgasta y, cuando llega a su límite, el robot entra en falla.
No existe sin la máquina porque su ciclo de vida depende del robot:

- Es un objeto miembro (no un puntero), así que se construye en la lista de inicialización del constructor de `RobotSoldador` y se destruye automáticamente cuando el robot se destruye. Nadie más la recibe, la comparte ni la conserva.
- Solo el robot la desgasta (`desgastar()`), la consulta (`estaDesgastada()`) y la restaura (`cambiarAlambre()`).
- Conceptualmente, una antorcha sin robot no tiene quién la use ni quién cuente las piezas que suelda; su desgaste solo tiene sentido porque provoca la falla de la máquina que la contiene.

Por eso la relación es de **composición**: `RobotSoldador` *tiene* una `Antorcha` y es responsable de ella.

## 2. Decisiones de diseño

**Atributos propios de tu clase y validación de cada uno:**

`RobotSoldador`:

| Atributo | Tipo | Validación | Si no es válido |
|---|---|---|---|
| `segundosPorPieza` | `int` | Debe ser `> 0` (lo valida `setSegundosPorPieza`) | No se asigna, se avisa en pantalla y queda el valor anterior; en el constructor queda el valor por defecto de 20 |
| `corrienteAmperes` | `int` | Debe ser `> 0` (lo valida `setCorrienteAmperes`) | No se asigna, se avisa en pantalla y queda el valor anterior; en el constructor queda el valor por defecto de 200 |
| `antorcha` | `Antorcha` | Su vida útil se valida dentro del constructor de `Antorcha` | Ver `vidaUtil` abajo |

`Antorcha`:

| Atributo | Tipo | Validación | Si no es válido |
|---|---|---|---|
| `vidaUtil` | `int` | Debe ser `> 0` (piezas que aguanta) | Se usan 15 y se avisa en pantalla. No tiene setter, así que después de construida nunca puede quedar inválida |
| `usos` | `int` | No recibe datos de fuera: empieza en 0 y solo cambia con `desgastar()` (+1) y `cambiarAlambre()` (vuelve a 0) | No aplica; nunca es negativo |

En el constructor de `RobotSoldador` primero inicializo los atributos con sus valores por defecto y luego llamo a los setters. Así la validación está escrita una sola vez y, si el valor recibido es inválido, el objeto queda en un estado correcto de todos modos.

**Métodos propios (los que la clase base no tiene):**

`RobotSoldador`:

- `setSegundosPorPieza(int)`: valida que sea `> 0` antes de asignar.
- `setCorrienteAmperes(int)`: valida que sea `> 0` antes de asignar.
- `procesarPieza()`: procesa UNA pieza. Rechaza (devuelve `false`) si la máquina está apagada o en falla. Si acepta, desgasta la antorcha, registra la pieza y el tiempo en la base y, si la antorcha se agotó con esa pieza, reporta la falla. Devuelve `true`.
- `darMantenimiento()`: cambia el alambre de la antorcha y le avisa a la base (`registrarMantenimiento()`) para que quite la falla y cuente el paro.

`Antorcha` (componente):

- `desgastar()`: suma un uso.
- `estaDesgastada() const`: dice si ya llegó a su límite.
- `cambiarAlambre()`: la deja como nueva (`usos = 0`).
- `mostrar() const`: imprime cuántas piezas lleva de las que aguanta.

**Método de la base que redefines, y cómo reutilizas la versión de la base:**
Redefino `mostrarEstado() const`. Lo primero que hace es llamar a `Maquina::mostrarEstado()` para que la base imprima lo que ya sabe mostrar de toda máquina. Después agrega lo propio del robot: la corriente en amperes, los segundos por pieza y, delegando en `antorcha.mostrar()`, el desgaste de la antorcha.

Con esto no repito código de la base, y si la base cambia su forma de mostrar el estado, mi clase lo hereda automáticamente.

**¿Cómo modelaste el desgaste del componente y por qué así?**

Lo modelé como un contador de usos contra una vida útil, ambos medidos en **piezas**. La `Antorcha` guarda `vidaUtil` (cuántas piezas aguanta) y `usos` (cuántas lleva desde que es nueva).

1. Cada pieza que acepta el robot llama a `antorcha.desgastar()`, que suma 1 a `usos`.
2. `estaDesgastada()` devuelve `true` cuando `usos >= vidaUtil`. Usé `>=` y no `==` para que siga siendo verdadero aunque `usos` se pase del límite.
3. Justo después de soldar, el robot pregunta si la antorcha ya se desgastó y, si sí, llama a `reportarFalla()` de la base. A partir de ahí `puedeProcesar()` es falso y el robot rechaza piezas.
4. `darMantenimiento()` regresa `usos` a 0 con `cambiarAlambre()` (la `vidaUtil` no cambia) y avisa a la base con `registrarMantenimiento()`.

**Elegí este modelo por estas razones:**

- **La unidad es la pieza.** Es lo que la máquina procesa, así que medir el desgaste en piezas no requiere conversiones ni cálculos de tiempo.
- **Es simple y predecible.** Cada pieza gasta exactamente 1, lo que lo hace fácil de probar: con vida 3, la tercera pieza provoca la falla.
- **Está encapsulado.** La antorcha es dueña de su estado y la regla de cuándo está desgastada vive en un solo lugar. El robot solo pregunta `estaDesgastada()` y decide qué hacer con la respuesta.
- **La pieza que agota la antorcha sí se suelda.** La falla se reporta después de procesarla, así que la primera pieza rechazada es la siguiente.

**¿Qué usa tu clase de `Maquina` y qué agrega?**


*Usa de `Maquina`:*

- El constructor `Maquina(id, nombre)`, para inicializar la parte heredada.
- `getNombre()`, para identificarse en los mensajes.
- `puedeProcesar()` y `estaEncendida()`, para decidir si acepta la pieza y para explicar por qué la rechaza.
- `registrarPieza()` y `agregarTiempo(segundos)`, para reportar el trabajo hecho.
- `reportarFalla()` y `registrarMantenimiento()`, para el ciclo de falla y mantenimiento.
- `Maquina::mostrarEstado()`, como base de su propia versión.

El robot no toca directamente los datos de la base; todo lo hace a través de su interfaz.

*Agrega:*

- Los atributos `segundosPorPieza`, `corrienteAmperes` y el componente `antorcha`, con su validación.
- Los métodos `setSegundosPorPieza`, `setCorrienteAmperes`, `procesarPieza` y `darMantenimiento`.
- El desgaste del componente y la regla que lo conecta con la falla de la máquina.
- Una versión extendida de `mostrarEstado()` que incluye los datos del robot y de la antorcha.

## 3. Diagrama

Diagrama de tu clase y su componente, hecho en draw.io. Debe mostrar la relación de herencia con `Maquina` y la de composición con tu componente. Guarda la imagen en `docs/` y enlázala aquí.

<img src="./RobotSoldador.png"> 
## 4. Bitácora

**Dudas que tuviste y cómo las resolviste:**

- **¿La antorcha debía ser un puntero o un objeto normal?** Al principio no sabía cuál usar. Como la antorcha no puede existir sin el robot, la dejé como objeto miembro. Así se crea y se destruye junto con el robot sin usar `new` ni `delete`, y eso es la composición.
- **¿Cómo reutilizo el `mostrarEstado()` de la base sin copiar su código?** Lo resolví llamando a `Maquina::mostrarEstado()` al principio de mi método y agregando después solo lo que le toca al robot.
- **¿Cuándo debía reportar la falla, antes o después de soldar?** Decidí que después. La pieza que agota la antorcha sí se suelda y la falla se reporta al terminar, así que la siguiente pieza es la primera que se rechaza.

**Errores que encontraste y cómo los corregiste:**

- **Error de compilación por la antorcha.** `Antorcha` no tiene constructor sin parámetros (necesita la vida útil), así que el compilador marcaba error en el constructor del robot. Lo corregí inicializándola en la lista de inicialización: `antorcha(vidaAntorcha)`.
- **Valores inválidos en el constructor.** Al principio asignaba los valores directo y podían quedar en cero o negativos. Lo corregí inicializando con valores por defecto (20 y 200) y llamando a los setters, que ya validan.
- **El robot seguía en falla después del mantenimiento.** Solo había reiniciado el desgaste de la antorcha. Lo corregí llamando también a `registrarMantenimiento()` en `darMantenimiento()`.
