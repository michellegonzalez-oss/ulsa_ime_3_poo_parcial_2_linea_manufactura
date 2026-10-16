# Propuesta de mejora: [Inserta aquí el título de tu propuesta]

> Crea una carpeta dentro de `docs/mejoras/` con tu número de matrícula como nombre, copia este archivo ahí como `mejora.md` y llena tu copia. No modifiques la plantilla.
>
> La propuesta es solo diseño: no se programa.

**Propuesta de mejora elaborada por:** [Inserta aquí tu nombre]

## 1. Impacto

**¿Es una mejora o una corrección?**

Es una mejora. No corrige errores del código actual, sino que agrega una nueva funcionalidad para optimizar el mantenimiento y prevenir fallas inesperadas.

**¿Qué observaste en la solución del equipo que dio origen a la propuesta?**

La máquina actual solo detecta el desgaste del motor cuando ya ha alcanzado su límite y entra en falla. Esto provoca paros en la línea de producción y pérdida de tiempo.

**¿Qué mejora o qué corrige, y por qué vale la pena?**

La mejora propone agregar un sistema de monitoreo inteligente que anticipe el desgaste del motor y avise cuando esté cerca de su límite. Esto permite programar mantenimiento preventivo y evitar fallas durante la operación.
Vale la pena porque mejora la eficiencia de la planta, reduce tiempos muertos y simula un entorno más realista de automatización industrial.

## 2. Qué implica

**Clases nuevas:**

SensorDesgaste: clase que mide el nivel de desgaste del motor y envía alertas cuando supera un umbral definido.

AlertaMantenimiento: clase que registra las alertas generadas por el sensor y las comunica al operador o al sistema de control.

**Comportamiento nuevo en clases existentes:**

En Motor: se agrega un método getNivelDesgaste() que devuelve el porcentaje de vida útil restante.

En BandaT: se integra el SensorDesgaste para consultar periódicamente el estado del motor y activar una alerta antes de que ocurra una falla.

**Interacciones nuevas entre objetos:**

BandaT consulta al SensorDesgaste cada vez que procesa una pieza.

Si el sensor detecta que el motor está por agotarse, crea una instancia de AlertaMantenimiento para registrar el evento.

**Relaciones nuevas (herencia, composición o agregación) y por qué son de ese tipo:**

Composición: BandaT tiene un SensorDesgaste, porque depende de él para monitorear su propio componente.

Agregación: SensorDesgaste usa un Motor existente para leer su estado, pero no lo crea ni lo destruye.

Asociación: SensorDesgaste genera una AlertaMantenimiento cuando detecta un nivel crítico.

## 3. Diagrama de clases


