# Cambios respecto a ejemplo T_4_4_Clases_Abstractas

1. El vector de ejemplares se pasa a **memoria dinámica**
.* Se implementan funciones de utilidad para gestionar tareas habituales con el vector de Ejemplares: NuevoEjemplar y BorraEjemplar
2. Captura de excepción **std::bad_alloc** en apartados que utilizan new
3. **Comprobación de valores válidos para atributos** de Ejemplares (métodos set y constructores)
.* Se lanzan excepciones **std::domain_error** para notificar valores no válidos en atributos
4. **Nuevos tipos de excepciones** personalizados en jerarquía de excepciones de STL para detectar situaciones específicas:
.* **ExConversion** derivada de std::logic_error para representar errores de conversión de formato
..* Se modifican los métodos fromCSV para lanzar excepciones ExConversion y std::domain_error si ocurren errores durante el proceso de conversión
.* **ExNoEncontrado** derivada de std::logic_error para indicar errores en búsqueda elementos en general
..* Lanzada por método de utilidad BorrarEjemplar si no se encuentra el ejemplar a borrar del vector
5. Se modifica el programa principal para capurar las excepciones correspondientes a cada parte del código
