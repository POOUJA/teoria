# Cambios respecto a ejemplo T_4_5_Excepciones

1. Nueva clase **Catálogo** para gestionar Ejemplares
  * Todos los métodos de utilidad del vector de Ejemplares se pasan a métodos de Catálogo
  * Se añade un método para **recuperar los ejemplares** de un catálogo desde un fichero en formato CSV
  * Se utilizar **RTTI mediante dynamic_cast<T>()** para identificar el tipo de ejemplar en cada línea de un fichero CSV a la hora de almacenarlos
2. Nuevo **módulo util_catalogo** con funciones para visualizar diferentes tipos de ejemplares y un Catálogo completo
  * función **Visualiza(Ejemplar)** que utiliza RTTI mediante dynamic_cast<T>() para seleccionar la forma concreta de mostrar cada tipo de ejemplar
3. Las clases derivadas de Ejemplar deben implementar los métodos de una nueva **Interfaz Duplicable** para que cualquier ejemplar pueda devolver una copia suya en memoria dinámica
  * Implementado **constructor de copia de catálogo** utilizando poliformismo para duplicar todos los ejemplares del catálogo original.
4. Se crean **métodos específicos para iterar sobre los Ejemplares** del catálogo
