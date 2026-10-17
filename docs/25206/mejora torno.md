Propuesta de mejora: Implementación de una alerta preventiva de mantenimiento del husillo en el Torno CNC

Propuesta de mejora elaborada por: Jesús Humberto González Bonilla

1. Impacto

¿Es una mejora o una corrección?

Es una mejora, porque se busca agregar una alerta preventiva de mantenimiento al sistema actual del Torno CNC sin modificar su estructura principal ni corregir un error existente.

¿Qué observaste en la solución del equipo que dio origen a la propuesta?

Observé que el sistema actual cuenta con una clase Husillo que registra su vida útil y la cantidad de usos. También tiene métodos para desgastar el husillo y verificar si está desgastado. Sin embargo, el sistema solamente detecta el desgaste cuando el husillo llega a su límite, lo que puede provocar que la máquina entre en falla sin una advertencia previa.

¿Qué mejora o qué corrige, y por qué vale la pena?

La propuesta consiste en agregar una alerta preventiva que permita identificar cuándo el husillo está cerca de alcanzar su límite de vida útil. Para esto, se utilizarán los atributos existentes vidaUtil y usos, sin necesidad de crear nuevas clases. Esta mejora vale la pena porque permite programar el mantenimiento con anticipación, reducir las fallas inesperadas y evitar interrupciones en el procesamiento de las piezas.

2. Qué implica

Clases nuevas:

No se necesitan clases nuevas, ya que la mejora se puede implementar utilizando las clases existentes TornoCNC y Husillo.

Comportamiento nuevo en clases existentes:

La clase TornoCNC agregaría una verificación preventiva durante el procesamiento de cada pieza. Esta verificación utilizaría los atributos vidaUtil y usos de la clase Husillo para determinar si está cerca de alcanzar su límite de funcionamiento. Si se aproxima al límite, el sistema mostraría una alerta para recomendar la programación del mantenimiento. El método estaDesgastado() continuaría funcionando para detectar cuándo el husillo ya alcanzó su límite de desgaste.

Interacciones nuevas entre objetos:

La clase TornoCNC consultaría los atributos del objeto Husillo después de registrar el procesamiento de una pieza. Con esta información, verificaría si es necesario mostrar una alerta preventiva. Se mantendrían las interacciones existentes, como utilizar desgastar() y estaDesgastado(), agregando únicamente la nueva verificación durante el proceso.

Relaciones nuevas (herencia, composición o agregación) y por qué son de ese tipo:

No se agregarían relaciones nuevas entre clases. Se conservaría la composición existente entre TornoCNC y Husillo, porque el torno contiene un husillo como parte de su funcionamiento. Esta relación se mantiene porque el husillo forma parte del sistema de la máquina y la mejora solamente modifica el comportamiento del proceso, sin cambiar la estructura de las clases.