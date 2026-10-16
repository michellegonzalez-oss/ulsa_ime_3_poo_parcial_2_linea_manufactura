# Documentación de la clase: BandaTransportadora

> Copia este archivo como `docs/<Clase>.md` (por ejemplo, con el nombre de tu máquina) y llena tu copia. No modifiques la plantilla.

**Elaborada por:** Jesus Humberto Gonzalez Bonilla 
**Matrícula:** 25127
**Bloque:** 4

## 1. Propósito

**¿Qué máquina representa tu clase y qué operación hace sobre la pieza?**

La clase BandaT representa una banda transportadora dentro de la línea de producción. Su operación principal es trasladar la pieza hacia la siguiente estación, contabilizando el tiempo que tarda en hacerlo y registrando la pieza procesada.

**¿Cuál es su componente y por qué no existe sin la máquina?**

El componente es el Motor, que se desgasta con cada pieza transportada. La banda no puede funcionar sin el motor, ya que es el que le da movimiento. Cuando el motor se desgasta, la máquina entra en falla y requiere mantenimiento.

## 2. Decisiones de diseño

**Atributos propios de tu clase y validación de cada uno:**

segundosPorPieza: tiempo que tarda la banda en mover una pieza. Se valida que sea mayor a 0, si no se rechaza el valor.

velocidadMmS: velocidad de la banda en milímetros por segundo. También se valida que sea mayor a 0.

Motor motor: componente esencial que se desgasta con cada pieza.

**Métodos propios (los que la clase base no tiene):**

setSegundosPorPieza(int segundos): asigna el tiempo por pieza, validando que sea positivo.

setVelocidadMmS(int valor): asigna la velocidad de la banda, validando que sea positiva.

procesarPieza(): mueve una pieza, desgasta el motor, registra la pieza y suma tiempo. Si el motor se desgasta completamente, la máquina entra en falla.

darMantenimiento(): repara el motor y registra un mantenimiento.

**Método de la base que redefines, y cómo reutilizas la versión de la base:**

mostrarEstado() const: reutiliza la versión de Maquina::mostrarEstado() y agrega información específica de la banda (velocidad, segundos por pieza y estado del motor).

**¿Cómo modelaste el desgaste del componente y por qué así?**

El motor se desgasta una unidad por cada pieza transportada. Cuando el número de usos alcanza la vida útil definida, el motor se considera desgastado y la máquina entra en falla. Este modelo refleja el ciclo real de mantenimiento en una fábrica: cada pieza consume parte de la vida útil del motor.

**¿Qué usa tu clase de `Maquina` y qué agrega?**

Usa de Maquina: encendido/apagado, validación de estado (puedeProcesar()), registro de piezas, tiempo trabajado y fallas.

Agrega: atributos propios de la banda (segundosPorPieza, velocidadMmS), el motor como componente, y métodos para mover piezas y dar mantenimiento.

## 3. Diagrama

Diagrama de tu clase y su componente, hecho en draw.io. Debe mostrar la relación de herencia con `Maquina` y la de composición con tu componente. Guarda la imagen en `docs/` y enlázala aquí.

[Inserta aquí tu diagrama]

## 4. Bitácora

**Dudas que tuviste y cómo las resolviste:**

Los errores que llegaban a dar y para resolverlos le pregunte a la inteligencia artificial

**Errores que encontraste y cómo los corregiste:**

Error de compilación por override: se corrigió eliminando la palabra clave, ya que Maquina no tiene métodos virtuales.

Error de identificador Motor: se corrigió incluyendo correctamente Motor.h.

Valores inválidos en segundos o velocidad: se corrigió agregando validaciones en los setters.
