# Simulador de una Planta de Manufactura Automatizada

Proyecto del Parcial 2 de Programación Orientada a Objetos.

La guía completa del proyecto está en [PROYECTO.md](PROYECTO.md). Léanla antes de empezar.

## 1. Equipo

| Bloque | Matrícula | Nombre | Usuario de GitHub | Máquina | Componente |
| --- | --- | --- | --- | --- | --- |
| 1 | | | | | |
| 2 | 25436|Fernando caleb  |Fernando1709 | Fresadora|Herramienta de corte |
| 3 |25160 | brayan lopez| brayanlopez-ux| Robot soldador|Soldar |
| 4 | | | |  |
| 5 |25069 |Michelle González Barrera|michellegonzalez-oss |Estación de Inspección |Sensor |

## 2. Orden de la línea

Escriban el orden en que una pieza recorre las estaciones.

Torno CNC → Banda Transportadora → Fresadora → Banda Transportadora → Robot Soldador → Banda Transportadora → Estación de Inspección

## 3. Cómo compilar y ejecutar

Escriban el comando exacto que usa el equipo para compilar y el comando para ejecutar.

Compilar: g++ -Wall -Wextra -std=c++17 -Iinclude src/*.cpp -o planta
Ejecutar: ./planta

## 4. Reglas de la simulación

**¿En qué momento exacto falla una máquina?**

Una máquina falla justo después de procesar la pieza que agota su componente, es decir, cuando el desgaste del componente llega a su vida útil. Esa pieza sí se termina de procesar y la falla se reporta al terminar con `reportarFalla()`. A partir de ese momento la máquina rechaza las piezas siguientes (`puedeProcesar()` es falso) hasta que recibe mantenimiento.

**¿El mantenimiento suma tiempo al turno? ¿Cuánto?**

No suma tiempo al turno. El mantenimiento restaura el componente, quita la falla y cuenta un paro (`registrarMantenimiento()`).


## 5. Cálculo a mano del reporte

Lote de 20 piezas. Una fila por máquina.

| Máquina | Segundos por pieza | Límite del componente | Fallas en 20 piezas | Tiempo trabajado |
| --- | --- | --- | --- | --- |
Banda transportadora |5 s | 50| 1| 300 s
Estación de inspección |12 s | 30| 0| 240 s
Fresadora |45 s | 20| 1| 900 s
Robot soldador |25 s | 15| 1| 500 s
Torno CNC |30 s | 10| 2| 600 s

**Reporte esperado (piezas terminadas, tiempo total y paros):**

En el reporte se espera observar 20 piezas terminadas, en un tiempo total de 2540 segundos y con un total de 5 paros (2 de Torno CNC, 1 de Fresadora, 1 de Robot Soldador y 1 de Banda Transportadora).

**¿Coincide con lo que imprime el programa? Si no coincidió al primer intento, ¿qué encontraron?**

Sí coincide con el programa, aunque no en el primer intento, se tuvo que corregir n veces el código (cada clase, modificamos a un solo componente, volvimos a modificar a componentes específicos de cada máquina y verificar que todas las máquinas se pudieran interlazar y trabajar juntas por medio de planta.cpp y main.cpp) para que finalmente compilara en general, y al lograr compilarlo el resultado coincidió con nuestras expectativas.

## 6. Diagrama general

Diagrama de clases de la solución completa, hecho en draw.io. Guarden la imagen como `docs/diagrama_general.png`.

![Diagrama general](docs/Diagrama G.drawio.png)
<img src="./Diagrama G.png">

## 7. Documentación individual

| Integrante | Documentación de su clase | Propuesta de mejora |
| --- | --- | --- |
|brayan lopez | `docs/25160/RobotSoldador+.md` | `docs/mejoras/<25160>/mejora brayan.md` |
|Michelle González Barrera |`docs/25069/EstacionI.md`|`docs/25069/mejora.md`|
|Fernando caleb |docs/25436/Fresadora.md |docs/25436/Fresadora mejora.md |
| | | |
| | | |

## 8. Cambios a `Maquina.h`

Si el equipo modificó la interfaz de la clase base, expliquen qué cambió y por qué. Si no hubo cambios, escriban "Sin cambios".

"Sin cambios