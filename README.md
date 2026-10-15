# Simulador de una Planta de Manufactura Automatizada

Proyecto del Parcial 2 de Programación Orientada a Objetos.

La guía completa del proyecto está en [PROYECTO.md](PROYECTO.md). Léanla antes de empezar.

## 1. Equipo

| Bloque | Matrícula | Nombre | Usuario de GitHub | Máquina | Componente |
| --- | --- | --- | --- | --- | --- |
| 1 | | | | | |
| 2 | | | | | |
| 3 |25160 | brayan lopez| brayanlopez-ux| Robot soldador|Soldar |
| 4 | | | |  |
| 5 |25069 |Michelle González Barrera|michellegonzalez-oss |Estación de Inspección |Sensor |

## 2. Orden de la línea

Escriban el orden en que una pieza recorre las estaciones.

TTorno CNC → Banda Transportadora → Fresadora → Banda Transportadora → Robot Soldador → Banda Transportadora → Estación de Inspección

## 3. Cómo compilar y ejecutar

Escriban el comando exacto que usa el equipo para compilar y el comando para ejecutar.

[Inserta aquí tu respuesta]

## 4. Reglas de la simulación

**¿En qué momento exacto falla una máquina?**

Una máquina falla justo después de procesar la pieza que agota su componente, es decir, cuando el desgaste del componente llega a su vida útil. Esa pieza sí se termina de procesar y la falla se reporta al terminar con `reportarFalla()`. A partir de ese momento la máquina rechaza las piezas siguientes (`puedeProcesar()` es falso) hasta que recibe mantenimiento.

**¿El mantenimiento suma tiempo al turno? ¿Cuánto?**

No suma tiempo al turno. El mantenimiento restaura el componente, quita la falla y cuenta un paro (`registrarMantenimiento()`).


## 5. Cálculo a mano del reporte

Lote de 20 piezas. Una fila por máquina.

| Máquina | Segundos por pieza | Límite del componente | Fallas en 20 piezas | Tiempo trabajado |
| --- | --- | --- | --- | --- |
| | | | | |
| | | | | |
| | | | | |
| | | | | |
| | | | | |

**Reporte esperado (piezas terminadas, tiempo total y paros):**

[Inserta aquí tu respuesta]

**¿Coincide con lo que imprime el programa? Si no coincidió al primer intento, ¿qué encontraron?**

[Inserta aquí tu respuesta]

## 6. Diagrama general

Diagrama de clases de la solución completa, hecho en draw.io. Guarden la imagen como `docs/diagrama_general.png`.

![Diagrama general](docs/diagrama_general.png)

## 7. Documentación individual

| Integrante | Documentación de su clase | Propuesta de mejora |
| --- | --- | --- |
|brayan lopez | `docs/25160/RobotSoldador+.md` | `docs/mejoras/<matrícula>/mejora.md` |
| | | |
| | | |
| | | |
| | | |

## 8. Cambios a `Maquina.h`

Si el equipo modificó la interfaz de la clase base, expliquen qué cambió y por qué. Si no hubo cambios, escriban "Sin cambios".

[Inserta aquí tu respuesta]
