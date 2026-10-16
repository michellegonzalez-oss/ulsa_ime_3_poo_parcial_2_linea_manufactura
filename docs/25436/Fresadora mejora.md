# Propuesta de mejora: Propuesta de mejora: Sistema de mantenimiento preventivo de componentes

> Crea una carpeta dentro de `docs/mejoras/` con tu número de matrícula como nombre, copia este archivo ahí como `mejora.md` y llena tu copia. No modifiques la plantilla.
>
> La propuesta es solo diseño: no se programa.

**Propuesta de mejora elaborada por:** Fernando caleb 
## 1. Impacto

**¿Es una mejora o una corrección?**
Se busca optimizar el funcionamiento de las máquinas mediante el mantenimiento preventivo de sus componentes antes de que se desgasten por completo y provoquen una falla.

**¿Qué observaste en la solución del equipo que dio origen a la propuesta?**

Observé que las máquinas pueden detectar cuando un componente se desgasta por completo y provoca una falla. Sin embargo, sería útil contar con un sistema que permita conocer la vida útil restante de los componentes y anticipar cuándo necesitan mantenimiento

**¿Qué mejora o qué corrige, y por qué vale la pena?**

La propuesta consiste en incorporar un sistema que supervise el desgaste de los componentes de cada máquina y genere una advertencia cuando estén cerca de terminar su vida útil. De esta manera, se podría programar el mantenimiento antes de que ocurra una falla. Esto ayudaría a reducir las interrupciones de producción

## 2. Qué implica

**Clases nuevas:**
Una clase llamada GestorMantenimiento, encargada de revisar la vida útil de los componentes y determinar cuándo es necesario realizar mantenimiento preventivo. 

**Comportamiento nuevo en clases existentes:**

La clase HerramientaCorte proporcionaría información sobre su vida útil restante y su nivel de desgaste. Las clases de las máquinas, como Fresadora, permitirían consultar el estado de sus componentes y comunicar al gestor cuándo necesitan mantenimiento.

**Interacciones nuevas entre objetos:**
El objeto GestorMantenimiento consultaría el estado de los componentes utilizados por las máquinas. Cuando un componente alcanzara el límite de desgaste preventivo, el gestor generaría una advertencia para que el mantenimiento pudiera programarse.

**Relaciones nuevas (herencia, composición o agregación) y por qué son de ese tipo:**

relación de agregación entre GestorMantenimiento y las máquinas, porque el gestor supervisaría varias máquinas, pero estas podrían existir y funcionar independientemente de él.

## 3. Diagrama de clases

Diagrama hecho en draw.io que muestre la solución con la mejora incorporada. Distingue lo nuevo de lo existente, por ejemplo con otro color. Guarda la imagen en esta misma carpeta y enlázala aquí.

![alt text](<mejora  fresadora.drawio.png>)
