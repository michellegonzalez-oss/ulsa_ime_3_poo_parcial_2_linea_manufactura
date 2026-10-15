# Documentación de la clase: Fresadora

> Copia este archivo como `docs/<Clase>.md` (por ejemplo, con el nombre de tu máquina) y llena tu copia. No modifiques la plantilla.

**Elaborada por:** Fernando Caleb Román Zamarripa
**Matrícula:**25436
**Bloque:** 2

## 1. Propósito

**¿Qué máquina representa tu clase y qué operación hace sobre la pieza?**

La clase fresadora  representa una maquina usada en la industria   que realiza ranuras en una pieza  mediante la herramienta de corte la cual es un componente , en cada pieza se requiere un tiempo  una profundidad usada 5mm , con verficadores de encendido  y sin fallas  para aceptar una pieza
**¿Cuál es su componente y por qué no existe sin la máquina?**

El componente quue fue usado para el funcionamiento de fresadora  fue la clase herramienta corte , la herramienta  usada para generar el corte , existe una relacion de ccomposicion por que  la fresadora  contiene y trabaja con su herramienta  , la cual es utilizada para generar la operacion de generar corte  

## 2. Decisiones de diseño

**Atributos propios de tu clase y validación de cada uno:**

-segundosPorPieza: almacena el tiempo que tarda en procesarse una pieza. Su valor debe ser mayor que cero.

-profundidadMm: almacena la profundidad de la ranura en milímetros. Su valor también debe ser mayor que cero.

-herramienta: es un objeto de HerramientaCorte que representa el componente encargado del corte y cuyo desgaste se controla durante el procesamiento.

Los dos primeros atributos son privados y se modifican mediante métodos
**Métodos propios (los que la clase base no tiene):**
setSegundosPorPieza(int segundos): cambia el tiempo de procesamiento cuando el valor es mayor que cero.

setProfundidadMm(int valor): cambia la profundidad de la ranura cuando el valor es mayor que cero.

procesarPieza(): verifica si la máquina puede trabajar. Si está apagada o presenta una falla, rechaza la pieza. De lo contrario, desgasta la herramienta, registra la pieza procesada y suma el tiempo de operación. Si la herramienta se desgasta por completo, reporta una falla.

darMantenimiento(): restaura la herramienta mediante afilar(), registra el mantenimiento y muestra un mensaje.

mostrarEstado(): redefine el método de la clase base para mostrar también la profundidad de la ranura, el tiempo por pieza y el estado de la herramienta.

**Método de la base que redefines, y cómo reutilizas la versión de la base:**
El método mostrarEstado() de la clase Maquina. Dentro de su implementación llamo a Maquina::mostrarEstado(), que muestra la información general de la máquina. Después agrego los datos particulares de la fresadora y llamo a herramienta.mostrar() para mostrar la información de su componente

**¿Cómo modelaste el desgaste del componente y por qué así?**
El desgaste se verifica en  la clase de herramienta de corte  y cada vez que se procesa una pieza  correctamente se desgasta  se llama al metodo herramienta desgastar  que va restandole vida util , al  reportar una falla  se dejan de procesar  piezas y  se le da mantenimiento,  dar mantenimiento ()  llamar  herramienta.afilar () y se reinicia la vida util.

**¿Qué usa tu clase de `Maquina` y qué agrega?**

La clase Fresadora hereda de Maquina mediante public Maquina. Reutiliza sus funciones generales para verificar si puede procesar, consultar si está encendida, registrar piezas, acumular tiempo de operación, reportar fallas y registrar mantenimientos. 

## 3. Diagrama

Diagrama de tu clase y su componente, hecho en draw.io. Debe mostrar la relación de herencia con `Maquina` y la de composición con tu componente. Guarda la imagen en `docs/` y enlázala aquí.

[Inserta aquí tu diagrama]

## 4. Bitácora

**Dudas que tuviste y cómo las resolviste:**

[Inserta aquí tu respuesta]

**Errores que encontraste y cómo los corregiste:**

[Inserta aquí tu respuesta]
